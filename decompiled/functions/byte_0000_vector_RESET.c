/* BYTE0x0000; WORDcode:0000; vector_RESET */

/* ACTUAL installed FW3.0 read twice from cmp-100.
   SHA256186930d0fe8e4caa6fa2873e151225df6c7d1a6f6c4811a82601b113f65c6ddf. Code display addresses
   are WORDS; exported index uses BYTE offsets. Register labels corrected from AVR-libc iom324pb.h.
   Inferred function names are NOT original symbols. */

void vector_RESET(void)

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

