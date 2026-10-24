"""Readback core; only mode entry and reads, no flash/fuse programming."""
def enter_boot(transfer):
    for n in range(1,11):
        try:transfer(147,0,0,256)
        except OSError:return n
    return 10
def read_flash(transfer, product, size=32768):
    if product!='USBasp':
        raise ValueError('bootloader identity required')
    data=bytearray()
    for address in range(0,size,8):
        length=min(8,size-address)
        block=transfer(4,address,0,length)
        if len(block)!=length:
            raise IOError(f'short flash response at {address:#x}: {len(block)} != {length}')
        data.extend(block)
    return bytes(data)
