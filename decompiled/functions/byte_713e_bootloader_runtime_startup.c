/* BYTE0x713e; WORDcode:389f; bootloader_runtime_startup */

void bootloader_runtime_startup(void)

{
  undefined1 *puVar1;
  
  R1 = 0;
  SREG = 0;
  DAT_mem_013b = MCUSR;
  Y = 0x900;
  R19 = DAT_mem_08fe._1_1_;
  if ((char)DAT_mem_08fe != '8') {
    R19 = 0xff;
  }
  DAT_mem_013c = R19;
  R17 = '\x01';
  X = &DAT_mem_0100;
  Z = &DAT_codebyte_799e;
  while (puVar1 = X, (byte)X != 6 || X._1_1_ != (char)(R17 + ((byte)X < 6))) {
    R0 = *Z;
    Z = Z + 1;
    X = X + 1;
    *puVar1 = R0;
  }
  R18 = '\x01';
  X = &DAT_mem_0106;
  while (puVar1 = X, (byte)X != 0x3b || X._1_1_ != (char)(R18 + ((byte)X < 0x3b))) {
    X = X + 1;
    *puVar1 = R1;
  }
  DAT_mem_08fe = 0x38c5;
  bootloader_usb_main();
  FUN_code_3ccd();
  return;
}

