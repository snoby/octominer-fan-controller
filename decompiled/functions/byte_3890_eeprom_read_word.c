/* BYTE0x3890; WORDcode:1c48; eeprom_read_word */

ushort eeprom_read_word(ushort eeprom_address)

{
  R1 = 0;
  FUN_code_1c6d();
  return eeprom_address;
}

