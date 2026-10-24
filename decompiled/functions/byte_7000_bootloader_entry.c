/* BYTE0x7000; WORDcode:3800; bootloader_entry */

void bootloader_entry(void)

{
  R1 = 0;
  bootloader_runtime_startup();
  return;
}

