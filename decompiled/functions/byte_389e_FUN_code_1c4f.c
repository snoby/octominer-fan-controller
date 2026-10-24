/* BYTE0x389e; WORDcode:1c4f; FUN_code_1c4f */

void FUN_code_1c4f(void)

{
  byte bVar1;
  char in_Hflg;
  char in_Tflg;
  char in_Iflg;
  
  R1 = 0;
  do {
    bVar1 = EECR;
  } while ((bVar1 & 2) != 0);
  EEAR._1_1_ = R25R24._1_1_;
  EEAR._0_1_ = (undefined1)R25R24;
  bVar1 = EECR;
  EECR = bVar1 | 1;
  R25R24 = R25R24 + -1;
  R0 = EEDR;
  if (R0 != R18) {
    EECR = 0;
    EEDR = R18;
    R0 = R0 < R18 | ((char)(R0 - R18) < '\0') << 2 | SBORROW1(R0,R18) << 3 |
         ((char)R0 < (char)R18) << 4 | (in_Hflg == '\x01') << 5 | (in_Tflg == '\x01') << 6 |
         (in_Iflg == '\x01') << 7;
    SREG = R0;
    bVar1 = EECR;
    EECR = bVar1 | 4;
    bVar1 = EECR;
    EECR = bVar1 | 2;
    SREG = R0;
  }
  return;
}

