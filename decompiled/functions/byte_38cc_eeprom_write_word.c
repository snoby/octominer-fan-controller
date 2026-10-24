/* BYTE0x38cc; WORDcode:1c66; eeprom_write_word */

void eeprom_write_word(void)

{
  byte bVar1;
  char in_Cflg;
  char in_Zflg;
  char in_Nflg;
  char in_Vflg;
  char in_Sflg;
  char in_Hflg;
  char in_Tflg;
  char in_Iflg;
  
  R1 = 0;
  eeprom_write_byte();
  R18 = R23;
  do {
    bVar1 = EECR;
  } while ((bVar1 & 2) != 0);
  EECR = 0;
  EEAR._1_1_ = R25R24._1_1_;
  EEAR._0_1_ = (undefined1)R25R24;
  EEDR = R23;
  R0 = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
       (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | (in_Hflg == '\x01') << 5 |
       (in_Tflg == '\x01') << 6 | (in_Iflg == '\x01') << 7;
  SREG = R0;
  bVar1 = EECR;
  EECR = bVar1 | 4;
  bVar1 = EECR;
  EECR = bVar1 | 2;
  SREG = R0;
  R25R24 = R25R24 + 1;
  return;
}

