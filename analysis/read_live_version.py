#!/usr/bin/env python3
"""Read ONLY vendor version request 0x0a; never reset/claim/detach USB."""
import ctypes,datetime,json,os,pathlib,time
class Control(ctypes.Structure):
    _fields_=[('request_type',ctypes.c_uint8),('request',ctypes.c_uint8),('value',ctypes.c_uint16),('index',ctypes.c_uint16),('length',ctypes.c_uint16),('timeout',ctypes.c_uint32),('data',ctypes.c_void_p)]
assert ctypes.sizeof(Control)==24,'This reader requires the audited 64-bit Linux ABI'
libc=ctypes.CDLL(None,use_errno=True)
libc.ioctl.argtypes=[ctypes.c_int,ctypes.c_ulong,ctypes.POINTER(Control)]
libc.ioctl.restype=ctypes.c_int
matches=[]
for p in pathlib.Path('/sys/bus/usb/devices').iterdir():
    try:
        if (p/'idVendor').read_text().strip()=='16c0' and (p/'idProduct').read_text().strip()=='05dc' and (p/'product').read_text().strip()=='Fan-Controller' and (p/'manufacturer').read_text().strip()=='info@octominer.com':matches.append(p)
    except (FileNotFoundError,PermissionError):pass
assert len(matches)==1,f'Expected exactly one application-mode controller, found {len(matches)}'
p=matches[0]; bus=int((p/'busnum').read_text()); dev=int((p/'devnum').read_text())
node=f'/dev/bus/usb/{bus:03d}/{dev:03d}'
ioctl=(3<<30)|(ctypes.sizeof(Control)<<16)|(ord('U')<<8)
result={'host':os.uname().nodename,'utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'sysfs':str(p),'usb_node':node,'request':{'bmRequestType':'0xc0','bRequest':'0x0a','wValue':0,'wIndex':0,'wLength':256,'timeout_ms':5000},'samples':[]}
fd=os.open(node,os.O_RDWR|os.O_CLOEXEC)
try:
    for _ in range(2):
        data=(ctypes.c_uint8*256)()
        ctrl=Control(0xc0,0x0a,0,0,256,5000,ctypes.addressof(data))
        n=libc.ioctl(fd,ioctl,ctypes.byref(ctrl))
        if n<0:
            err=ctypes.get_errno();raise OSError(err,os.strerror(err))
        assert 3<=n<=256,f'Invalid version reply length: {n}'
        raw=bytes(data[:n]); v=lambda b:f'{b//10}.{b%10}'
        sample={'length':n,'raw_hex':raw.hex(' '),'firmware':v(raw[0]),'hardware':v(raw[1]),'bootloader':v(raw[2])}
        if n>=4:sample['firmware_target_hardware']=v(raw[3]);sample['target_matches_hardware']=raw[3]==raw[1]
        result['samples'].append(sample)
        time.sleep(0.25)
finally:os.close(fd)
result['repeat_matches']=result['samples'][0]['raw_hex']==result['samples'][1]['raw_hex']
assert result['repeat_matches'],'Version replies disagree'
print(json.dumps(result,indent=2))
