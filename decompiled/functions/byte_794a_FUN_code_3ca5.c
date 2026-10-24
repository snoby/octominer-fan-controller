/* BYTE0x794a; WORDcode:3ca5; FUN_code_3ca5 */

int FUN_code_3ca5(undefined1 R25,byte R24)

{
  byte bVar1;
  
  R1 = 0;
  do {
    bVar1 = EECR;
  } while ((bVar1 & 2) != 0);
  EEAR._1_1_ = R25;
  EEAR._0_1_ = R24;
  bVar1 = EECR;
  EECR = bVar1 | 1;
  R25 = 0;
  R24 = EEDR;
  return (uint)R24 << 8;
}

