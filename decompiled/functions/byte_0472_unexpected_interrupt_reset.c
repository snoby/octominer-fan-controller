/* BYTE0x0472; WORDcode:0239; unexpected_interrupt_reset */

void unexpected_interrupt_reset(void)

{
  undefined1 *puVar1;
  
  R1 = 0;
  SREG = 0;
  Ylo = 0xff;
  Yhi = 8;
  R17 = '\x03';
  X = &DAT_mem_0100;
  Z = &DAT_codebyte_3916;
  while (puVar1 = X, (byte)X != 0x50 || X._1_1_ != (char)(R17 + ((byte)X < 0x50))) {
    R0 = *Z;
    Z = Z + 1;
    X = X + 1;
    *puVar1 = R0;
  }
  R18 = '\x05';
  X = &DAT_mem_0350;
  while (puVar1 = X, (byte)X != 0x9f || X._1_1_ != (char)(R18 + ((byte)X < 0x9f))) {
    X = X + 1;
    *puVar1 = R1;
  }
  DAT_mem_08fe = 0x237;
  application_main();
  terminal_exit_loop();
  return;
}

