import unittest
import readback_core as core

class ReadbackTests(unittest.TestCase):
    def test_reader_requires_bootloader_identity_before_any_transfer(self):
        calls=[]
        with self.assertRaisesRegex(ValueError,'bootloader'):
            core.read_flash(lambda *a:calls.append(a),'Fan-Controller',32)
        self.assertEqual(calls,[])

    def test_flash_stream_reads_only_request_four_with_byte_addresses(self):
        memory=bytes(range(32)); calls=[]
        def transfer(request,address,index,length):
            calls.append((request,address,index,length))
            return memory[address:address+length]
        self.assertEqual(core.read_flash(transfer,'USBasp',32),memory)
        self.assertEqual(calls,[(4,0,0,8),(4,8,0,8),(4,16,0,8),(4,24,0,8)])

    def test_short_reply_aborts_instead_of_fabricating_bytes(self):
        with self.assertRaisesRegex(IOError,'short'):
            core.read_flash(lambda *a:b'\x00','USBasp',32)

    def test_boot_entry_matches_ten_request_vendor_sequence(self):
        calls=[]
        self.assertEqual(core.enter_boot(lambda *a:calls.append(a) or b''),10)
        self.assertEqual(calls,[(147,0,0,256)]*10)

    def test_boot_entry_stops_on_expected_disconnect(self):
        calls=[]
        def transfer(*args):
            calls.append(args)
            if len(calls)==5:raise OSError('device disconnected')
            return b''
        self.assertEqual(core.enter_boot(transfer),5)
        self.assertEqual(len(calls),5)

if __name__=='__main__':unittest.main()
