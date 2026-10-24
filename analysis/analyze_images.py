#!/usr/bin/env python3
"""Validate copied firmware without device access; preserve addresses."""
import hashlib,json,pathlib,struct,subprocess,collections
ROOT=pathlib.Path('/Users/snoby/octominer-re'); SRC=ROOT/'artifacts/192.168.2.106'; OUT=ROOT/'analysis'
remote={line.split()[1].split('/')[-1]:line.split()[0] for line in (OUT/'remote-sha256.txt').read_text().splitlines()}
manifest=[]
for p in sorted(SRC.iterdir()):
 h=hashlib.sha256(p.read_bytes()).hexdigest()
 assert h==remote[p.name],p.name
 manifest.append({'file':p.name,'size':p.stat().st_size,'sha256':h,'remote_verified':True})
images={}
for p in sorted(SRC.glob('firmware_*.hex')):
 mem={}; records=collections.Counter(); entry=None
 for n,line in enumerate(p.read_text().splitlines(),1):
  line=line.strip()
  if not line:continue
  assert line.startswith('S'),(p,n)
  t=line[1]; b=bytes.fromhex(line[2:]); assert len(b)==b[0]+1,(p,n,'length')
  assert sum(b)&255==255,(p,n,'checksum')
  records[t]+=1
  alen={'0':2,'1':2,'2':3,'3':4,'5':2,'6':3,'7':4,'8':3,'9':2}[t]
  addr=int.from_bytes(b[1:1+alen],'big'); data=b[1+alen:-1]
  if t in '123':
   for i,v in enumerate(data):
    assert addr+i not in mem or mem[addr+i]==v,(p,n,'overlap')
    mem[addr+i]=v
  elif t in '789':entry=addr
 keys=sorted(mem); segments=[]
 for a in keys:
  if not segments or a!=segments[-1][1]+1:segments.append([a,a])
  else:segments[-1][1]=a
 lo,hi=keys[0],keys[-1]; blob=bytes(mem.get(a,255) for a in range(lo,hi+1))
 name=p.stem; (OUT/(name+'.bin')).write_bytes(blob)
 vectors=[]
 for a in range(0,min(0xcc,len(blob)),4):
  w=int.from_bytes(blob[a:a+2],'little')
  if w&0xfe0e!=0x940c:break
  k=((w&0x1f0)<<13)|((w&1)<<16)|int.from_bytes(blob[a+2:a+4],'little')
  vectors.append({'byte_offset':hex(a),'target_byte':hex(k*2)})
 asm=OUT/(name+'.s'); asm.write_text('.section .text,"ax",@progbits\n.global image_start\nimage_start:\n.incbin "'+str(OUT/(name+'.bin'))+'"\n')
 llvm='/opt/homebrew/opt/llvm/bin/'
 subprocess.run([llvm+'llvm-mc','-triple=avr','-mcpu=atmega324p','-filetype=obj',str(asm),'-o',str(OUT/(name+'.o'))],check=True)
 with (OUT/(name+'-disassembly.txt')).open('w') as f:
  subprocess.run([llvm+'llvm-objdump','-d','--mcpu=atmega324p','--print-imm-hex',str(OUT/(name+'.o'))],stdout=f,check=True)
 utf=[]
 for a in keys:
  if mem[a] in range(4,100,2) and mem.get(a+1)==3:
   raw=bytes(mem.get(x,0) for x in range(a+2,a+mem[a]))
   try:s=raw.decode('utf-16le')
   except UnicodeDecodeError:continue
   if s and all(32<=ord(c)<127 for c in s):utf.append({'address':hex(a),'text':s})
 images[name]={'record_counts':dict(records),'segments_inclusive':[[hex(a),hex(b)] for a,b in segments],'data_bytes':len(mem),'linear_size':len(blob),'fill':255,'entry_record':hex(entry) if entry is not None else None,'leading_jmp_vectors':vectors,'utf16_usb_string_candidates':utf}
(OUT/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n'); (OUT/'images.json').write_text(json.dumps(images,indent=2)+'\n')
print(json.dumps({'files_hash_verified':len(manifest),'images':images},indent=2))
