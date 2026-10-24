/* BYTE0x389c; WORDcode:1c4e; eeprom_update_byte */

void eeprom_update_byte(void)

{
  byte bVar1;
  char in_Hflg;
  char in_Tflg;
  char in_Iflg;
  
  R1 = 0;
  R18 = R22;
  do {
    bVar1 = EECR;
  } while ((bVar1 & 2) != 0);
  EEAR._1_1_ = R25R24._1_1_;
  EEAR._0_1_ = (undefined1)R25R24;
  bVar1 = EECR;
  EECR = bVar1 | 1;
  R25R24 = R25R24 + -1;
  R0 = EEDR;
  if (R0 != R22) {
    EECR = 0;
    EEDR = R22;
    R0 = R0 < R22 | ((char)(R0 - R22) < '\0') << 2 | SBORROW1(R0,R22) << 3 |
         ((char)R0 < (char)R22) << 4 | (in_Hflg == '\x01') << 5 | (in_Tflg == '\x01') << 6 |
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

