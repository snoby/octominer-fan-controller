/* BYTE0x38c0; WORDcode:1c60; eeprom_update_word */

void eeprom_update_word(void)

{
  R1 = 0;
  FUN_code_1c4f();
  eeprom_update_byte();
  return;
}

