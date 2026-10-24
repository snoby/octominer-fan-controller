/* BYTE0x3880; WORDcode:1c40; eeprom_read_byte */

byte eeprom_read_byte(ushort eeprom_address)

{
  byte bVar1;
  ushort uVar2;
  
  R1 = 0;
  do {
    bVar1 = EECR;
  } while ((bVar1 & 2) != 0);
  EEAR._1_1_ = eeprom_address._1_1_;
  EEAR._0_1_ = (byte)eeprom_address;
  bVar1 = EECR;
  EECR = bVar1 | 1;
  bVar1 = EEDR;
  eeprom_address = (ushort)bVar1;
  uVar2 = eeprom_address;
  eeprom_address._0_1_ = bVar1;
  bVar1 = (byte)eeprom_address;
  eeprom_address = uVar2;
  return bVar1;
}

