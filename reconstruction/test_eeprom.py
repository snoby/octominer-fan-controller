import hashlib
from pathlib import Path
import unittest
try:
    from avr_slice import AvrSlice
except ModuleNotFoundError:
    AvrSlice = None

ROOT=Path(__file__).resolve().parent
EXPECTED_SHA='186930d0fe8e4caa6fa2873e151225df6c7d1a6f6c4811a82601b113f65c6ddf'

class InstructionTests(unittest.TestCase):
    def test_captured_word_reader_returns_eeprom_via_register_alias(self):
        self.assertIsNotNone(AvrSlice,'Instruction executor has not been implemented')
        flash=(ROOT/'firmware.bin').read_bytes()
        self.assertEqual(hashlib.sha256(flash).hexdigest(),EXPECTED_SHA)
        eeprom=bytearray(1024);eeprom[0x67:0x69]=b'\x34\x12'
        cpu=AvrSlice(flash,eeprom)
        cpu.set16(24,0x67)
        cpu.run(0x3890)
        self.assertEqual(cpu.get16(24),0x1234)
        self.assertNotEqual(cpu.get16(24),0x67)
        self.assertEqual(cpu.reads,[0x67,0x68])
        self.assertEqual(cpu.writes,[])

    def test_captured_update_byte_skips_equal_and_masks_strobes(self):
        self.assertIsNotNone(AvrSlice)
        flash=(ROOT/'firmware.bin').read_bytes()
        for enabled in (False,True):
            for value in (0x11,0x22):
                with self.subTest(interrupts=enabled,value=value):
                    eeprom=bytearray(1024);eeprom[0x67]=0x11
                    cpu=AvrSlice(flash,eeprom,interrupts_enabled=enabled)
                    cpu.set16(24,0x67);cpu.mem[22]=value;cpu.run(0x389c)
                    self.assertEqual(cpu.eeprom[0x67],value)
                    self.assertEqual(cpu.writes,[] if value==0x11 else [(0x67,value)])
                    self.assertEqual(bool(cpu.mem[cpu.SREG]&0x80),enabled)
                    self.assertTrue(all(not x['interrupts_enabled'] for x in cpu.strobes))
                    self.assertEqual(cpu.get16(24),0x66)

    def test_word_helpers_preserve_distinct_byte_write_orders(self):
        flash=(ROOT/'firmware.bin').read_bytes()
        for entry,expected in [(0x38c0,[(0x68,0x33),(0x67,0x44)]),(0x38cc,[(0x67,0x44),(0x68,0x33)])]:
            with self.subTest(entry=hex(entry)):
                cpu=AvrSlice(flash,bytearray(1024))
                cpu.set16(24,0x67);cpu.set16(22,0x3344);cpu.run(entry)
                self.assertEqual(cpu.eeprom[0x67:0x69],b'\x44\x33')
                self.assertEqual(cpu.writes,expected)
                self.assertTrue(all(not x['interrupts_enabled'] for x in cpu.strobes))
                self.assertTrue(cpu.mem[cpu.SREG]&0x80)

    def test_compiled_c_matches_captured_helpers_across_valid_addresses(self):
        import ctypes as ct
        import json,os,shutil,subprocess,sys
        source=Path(os.environ.get('EE_REFERENCE_SOURCE',str(ROOT/'eeprom_reference.c')))
        self.assertTrue(source.exists(),'Clean C reconstruction has not been implemented')
        build=ROOT/'build';build.mkdir(exist_ok=True)
        library=build/('libeeprom_reference.dylib' if sys.platform=='darwin' else 'libeeprom_reference.so')
        compiler=shutil.which('clang') or shutil.which('cc')
        self.assertIsNotNone(compiler)
        flags=['-dynamiclib'] if sys.platform=='darwin' else ['-shared']
        subprocess.run([compiler,'-std=c11','-O2','-Wall','-Wextra','-Werror','-fPIC',*flags,str(source),'-o',str(library)],check=True)
        class Model(ct.Structure):
            _fields_=[('data',ct.c_uint8*1024),('writes',ct.c_uint32),('addresses',ct.c_uint16*2),('values',ct.c_uint8*2),('write_irq',ct.c_uint8*2),('irq',ct.c_uint8)]
        lib=ct.CDLL(str(library));lib.ee_model_size.restype=ct.c_size_t
        self.assertEqual(lib.ee_model_size(),ct.sizeof(Model))
        pattern=bytes((n*37+11)&255 for n in range(1024));flash=(ROOT/'firmware.bin').read_bytes()
        self.assertEqual(hashlib.sha256(flash).hexdigest(),EXPECTED_SHA)
        specs=[('ee_read_byte',0x3880,False,False),('ee_read_word',0x3890,True,False),('ee_update_byte',0x389c,False,True),('ee_update_word',0x38c0,True,True),('ee_write_byte',0x38f6,False,True),('ee_write_word',0x38cc,True,True)]
        stats={};coverage=set();total_steps=0
        for name,entry,word,write in specs:
            fn=getattr(lib,name);fn.argtypes=[ct.POINTER(Model),ct.c_uint16]+([ct.c_uint16 if word else ct.c_uint8] if write else [])
            fn.restype=None if write else (ct.c_uint16 if word else ct.c_uint8)
            count=0
            for enabled in (False,True):
                for address in range(1023 if word else 1024):
                    old=int.from_bytes(pattern[address:address+(2 if word else 1)],'little')
                    values=[old,old^255,old^65280,old^65535] if word else [old,old^255]
                    if not write:values=[None]
                    for value in values:
                        cpu=AvrSlice(flash,pattern,interrupts_enabled=enabled);cpu.set16(24,address)
                        if write:cpu.set16(22,value)
                        cpu.run(entry)
                        model=Model();model.data[:]=pattern;model.irq=int(enabled)
                        result=fn(ct.byref(model),address,*([value] if write else []))
                        where=f'{name} address={address:#x} value={value} IRQ={enabled}'
                        if not write:self.assertEqual(result,cpu.get16(24),where)
                        self.assertEqual(bytes(model.data),bytes(cpu.eeprom),where)
                        self.assertEqual([(model.addresses[i],model.values[i]) for i in range(model.writes)],cpu.writes,where)
                        self.assertEqual(bool(model.irq),bool(cpu.mem[cpu.SREG]&128),where)
                        self.assertTrue(all(not model.write_irq[i] for i in range(model.writes)),where)
                        self.assertTrue(all(not x['interrupts_enabled'] for x in cpu.strobes),where)
                        coverage.update(pc for pc,_ in cpu.trace);total_steps+=len(cpu.trace);count+=1
            stats[name]=count
        summary={'firmware_sha256':hashlib.sha256(flash).hexdigest(),'reference_c_sha256':hashlib.sha256(source.read_bytes()).hexdigest(),'executor_sha256':hashlib.sha256((ROOT/'avr_slice.py').read_bytes()).hexdigest(),'cases_by_helper':stats,'total_differential_cases':sum(stats.values()),'interpreted_opcode_steps':total_steps,'covered_byte_addresses':[hex(x) for x in sorted(coverage)],'all_passed':True,'scope':'Sequential selected-helper execution with modeled EEPROM, no interrupts/cycle-accurate hardware or out-of-range wrapping'}
        (ROOT/'results.json').write_text(json.dumps(summary,indent=2)+'\n')
        print('\nDIFFERENTIAL_RESULT '+json.dumps({k:v for k,v in summary.items() if k!='covered_byte_addresses'}),flush=True)

if __name__=='__main__':unittest.main(verbosity=2)
