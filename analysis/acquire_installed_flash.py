#!/usr/bin/env python3
"""Authorized, bounded maintenance acquisition; never writes flash/fuses."""
import ctypes,datetime,hashlib,json,os,pathlib,signal,subprocess,time,traceback
from readback_core import read_flash, enter_boot
ROOT=pathlib.Path(__file__).resolve().parent
OUT=ROOT/('capture-'+datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%SZ'))
OUT.mkdir()
report={'started_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'host':os.uname().nodename,'events':[]}
paused=[]; mining_stopped=False; boot_entered=False; boot_time=None

def log(event,**data):
    row={'utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'event':event,**data}
    report['events'].append(row);print(json.dumps(row),flush=True)
    (OUT/'report.json').write_text(json.dumps(report,indent=2)+'\n')

def cmd(args,timeout=30):
    p=subprocess.run(args,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True,timeout=timeout)
    log('command',args=args,returncode=p.returncode,output=p.stdout[-4000:])
    if p.returncode:raise RuntimeError('Command failed: '+str(args))
    return p.stdout

def devices(product):
    found=[]
    for p in pathlib.Path('/sys/bus/usb/devices').iterdir():
        try:
            if (p/'idVendor').read_text().strip()=='16c0' and (p/'idProduct').read_text().strip()=='05dc' and (p/'product').read_text().strip()==product:
                found.append(p)
        except (FileNotFoundError,PermissionError):pass
    return found

class Control(ctypes.Structure):
    _fields_=[('typ',ctypes.c_uint8),('req',ctypes.c_uint8),('value',ctypes.c_uint16),('index',ctypes.c_uint16),('length',ctypes.c_uint16),('timeout',ctypes.c_uint32),('data',ctypes.c_void_p)]
assert ctypes.sizeof(Control)==24
libc=ctypes.CDLL(None,use_errno=True);libc.ioctl.restype=ctypes.c_int
libc.ioctl.argtypes=[ctypes.c_int,ctypes.c_ulong,ctypes.POINTER(Control)]
class USB:
    def __init__(self,product):
        paths=devices(product)
        if len(paths)!=1:raise RuntimeError(f'Expected one {product}, found {len(paths)}')
        self.path=paths[0];self.product=product
        manufacturer=(self.path/'manufacturer').read_text().strip()
        expected={'USBasp':'www.fischl.de','Fan-Controller':'info@octominer.com'}[product]
        if manufacturer!=expected:raise RuntimeError('Unexpected manufacturer: '+manufacturer)
        bus=int((self.path/'busnum').read_text());dev=int((self.path/'devnum').read_text())
        self.node=f'/dev/bus/usb/{bus:03d}/{dev:03d}'
        self.fd=os.open(self.node,os.O_RDWR|os.O_CLOEXEC)
    def close(self):
        if self.fd>=0:os.close(self.fd);self.fd=-1
    def transfer(self,request,value=0,index=0,length=8):
        if self.product=='Fan-Controller' and request not in (1,3,6,9,10,14,147):raise ValueError('Forbidden application request')
        if self.product=='USBasp' and request not in (1,2,3,4):raise ValueError('Forbidden bootloader request')
        if self.product=='USBasp' and request==3 and (value,index)!=(65535,65535):raise ValueError('Only audited boot-exit magic is allowed')
        if self.fd<0 or (self.path/'product').read_text().strip()!=self.product:raise OSError(19,'USB identity changed')
        data=(ctypes.c_uint8*max(1,length))();ctrl=Control(0xc0,request,value,index,length,2000,ctypes.addressof(data))
        n=libc.ioctl(self.fd,(3<<30)|(24<<16)|(ord('U')<<8),ctypes.byref(ctrl))
        if n<0:
            e=ctypes.get_errno();raise OSError(e,os.strerror(e))
        if n>length:raise RuntimeError('Reply exceeded allocation')
        return bytes(data[:n])

def temps():
    p=subprocess.run(['nvidia-smi','--query-gpu=temperature.gpu,utilization.gpu,power.draw','--format=csv,noheader,nounits'],capture_output=True,text=True,timeout=10)
    if p.returncode:raise RuntimeError('GPU monitor failed: '+p.stderr)
    rows=[[float(x.strip()) for x in l.split(',')] for l in p.stdout.splitlines() if l.strip()]
    if len(rows)!=5:raise RuntimeError('GPU enumeration changed')
    return rows

def snapshot(label):
    u=USB('Fan-Controller')
    try:
        version=u.transfer(10,length=256)
        if len(version)<3 or version[0]!=30 or version[1]!=12 or version[2]!=20:raise RuntimeError('Not the expected FW3.0/HW1.2/BL2.0 controller')
        fans=[]
        for i in range(12):
            fans.append({str(r):u.transfer(r,index=i,length=8).hex() for r in (1,3,9,14)})
        out={'version_hex':version.hex(),'watchdog_hex':u.transfer(6,length=8).hex(),'fans':fans}
        (OUT/(label+'.json')).write_text(json.dumps(out,indent=2)+'\n')
        log(label,version=version.hex(),gpu=temps())
        return out
    finally:u.close()

def wait_mode(product,timeout=15):
    until=time.monotonic()+timeout
    while time.monotonic()<until:
        if len(devices(product))==1:return
        time.sleep(.2)
    raise TimeoutError('USB mode did not become '+product)

def stop_parents():
    parents=[]
    for p in pathlib.Path('/proc').iterdir():
        if not p.name.isdigit():continue
        try:argv=(p/'cmdline').read_bytes().split(b'\x00')
        except (FileNotFoundError,PermissionError,ProcessLookupError):continue
        if len(argv)>=3 and argv[0].split(b'/')[-1]==b'bash' and argv[1] in (b'/hive/opt/octofan/octofan',b'/hive/opt/octofan/watchdog-octofan') and argv[2] in (b'run',b'ping'):
            pid=int(p.name)
            # Bash command substitutions inherit argv; only pause the two
            # original session-leader shells, not their transient subshells.
            try:
                if os.getsid(pid)==pid:parents.append(pid)
            except ProcessLookupError:pass
    if len(parents)!=2:raise RuntimeError('Unexpected controller parent processes: '+str(parents))
    for pid in parents:os.kill(pid,signal.SIGSTOP);paused.append(pid)
    log('controller_parents_paused',pids=paused)
    until=time.monotonic()+12
    while time.monotonic()<until:
        active=[]
        for p in pathlib.Path('/proc').iterdir():
            if not p.name.isdigit():continue
            try:a=(p/'cmdline').read_bytes().split(b'\x00')
            except (FileNotFoundError,PermissionError,ProcessLookupError):continue
            if a and a[0]==b'/hive/opt/octofan/fan_controller_cli':active.append(int(p.name))
        if not active:return
        time.sleep(.1)
    raise RuntimeError('Controller CLI still active: '+str(active))

def exit_boot():
    global boot_entered
    if devices('USBasp'):
        u=USB('USBasp')
        try:
            for req,value,index,length in [(1,0,0,8),(3,65535,65535,4),(2,0,0,8)]:
                try:log('boot_exit_request',request=req,reply=u.transfer(req,value,index,length).hex())
                except OSError as e:log('boot_exit_disconnect',request=req,error=str(e))
        finally:u.close()
    wait_mode('Fan-Controller',20)
    boot_entered=False
    log('application_reenumerated')

def abort_signal(signum,frame):raise RuntimeError('Maintenance interrupted by signal '+str(signum))
for s in (signal.SIGTERM,signal.SIGINT,signal.SIGHUP):signal.signal(s,abort_signal)

before=None; success=False
try:
    if os.geteuid()!=0:raise RuntimeError('Root required')
    before=snapshot('before')
    cmd(['/hive/bin/miner','stop'],60);mining_stopped=True
    log('cooldown_started')
    until=time.monotonic()+120
    while True:
        rows=temps();log('cooldown_sample',gpu=rows)
        if max(r[0] for r in rows)<=55 and max(r[1] for r in rows)<=5:break
        if time.monotonic()>until:raise RuntimeError('GPUs did not cool or mining remained active')
        time.sleep(5)
    stop_parents()
    # No child controller calls can overlap mode transition now.
    u=USB('Fan-Controller')
    try:
        log('boot_entry_requested')
        boot_entered=True
        attempts=enter_boot(u.transfer)
        log('boot_entry_sequence_sent',attempts=attempts)
    finally:u.close()
    wait_mode('USBasp',15);boot_time=time.monotonic();log('bootloader_identified')
    u=USB('USBasp')
    try:
        log('boot_hold',reply=u.transfer(1,length=8).hex())
        def limited_transfer(req,address,index,length):
            if time.monotonic()-boot_time>85:raise TimeoutError('Boot readback time budget exceeded')
            if address%4096==0:
                rows=temps();log('read_progress',offset=address,gpu=rows)
                if max(r[0] for r in rows)>65:raise RuntimeError('GPU thermal abort')
            return u.transfer(req,address,index,length)
        prefix=limited_transfer(4,0,0,8);log('flash_prefix',hex=prefix.hex())
        if len(prefix)!=8 or len(set(prefix))<2 or not (prefix[:2]==b'\x0c\x94' or prefix[1]&0xf0==0xc0):raise RuntimeError('Readback denied or unrecognizable AVR reset vector')
        copies=[]
        for n in (1,2):
            data=read_flash(limited_transfer,'USBasp',32768)
            dest=OUT/f'firmware-3.0-pass{n}.bin';dest.write_bytes(data);copies.append(data)
            log('dump_saved',pass_number=n,bytes=len(data),sha256=hashlib.sha256(data).hexdigest())
        if copies[0]!=copies[1]:raise RuntimeError('Independent flash dumps differ')
        report['dump_verified']=True;report['flash_sha256']=hashlib.sha256(copies[0]).hexdigest()
        success=True;log('two_dumps_match')
    finally:u.close()
except Exception as e:
    report['error']=str(e);log('acquisition_error',error=str(e),traceback=traceback.format_exc())
finally:
    restored=False
    try:
        if boot_entered or devices('USBasp'):exit_boot()
        after=snapshot('after')
        if before and any(a['1']!=b['1'] or a['14']!=b['14'] for a,b in zip(before['fans'],after['fans'])):
            raise RuntimeError('Persistent fan settings changed; leave mining stopped for inspection')
        for pid in paused:os.kill(pid,signal.SIGCONT)
        paused.clear();log('original_controller_processes_resumed')
        time.sleep(6)
        post=snapshot('restored')
        rows=temps()
        rpms=[int.from_bytes(bytes.fromhex(f['3']),'little') for f in post['fans']]
        if not any(r>0 for r in rpms):raise RuntimeError('No fan RPM observed after controller restoration')
        restored=True
        if mining_stopped:cmd(['/hive/bin/miner','start'],60);log('mining_start_requested')
    except Exception as e:
        report['restoration_error']=str(e);log('restoration_error',error=str(e),traceback=traceback.format_exc())
        # Resume pre-existing pinger/control when app is present, but never restart mining blindly.
        if devices('Fan-Controller'):
            for pid in paused:
                try:os.kill(pid,signal.SIGCONT)
                except ProcessLookupError:pass
    report['restored']=restored;report['finished_utc']=datetime.datetime.now(datetime.timezone.utc).isoformat()
    (OUT/'report.json').write_text(json.dumps(report,indent=2)+'\n')
    print('CAPTURE_DIRECTORY='+str(OUT),flush=True)
if not success or not report.get('restored'):raise SystemExit(1)
