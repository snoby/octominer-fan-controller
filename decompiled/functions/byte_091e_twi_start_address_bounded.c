/* BYTE0x091e; WORDcode:048f; twi_start_address_bounded */

void twi_start_address_bounded(void)

{
  byte bVar1;
  byte bVar2;
  
  R1 = 0;
  TWCR0 = 0xa4;
  R18 = 0x40;
  R19 = '\x01';
  do {
    bVar2 = TWCR0;
    if ((bVar2 & 0x80) != 0) {
      TWDR0 = (byte)R25R24;
      TWCR0 = 0x84;
      R25R24 = 0x140;
      do {
        R18 = TWCR0;
        if ((R18 & 0x80) != 0) {
          return;
        }
        R25R24 = R25R24 + -1;
      } while (R25R24 != 0);
      R25R24 = DAT_mem_04c5 | 2;
      goto LAB_code_04af;
    }
    bVar1 = R18 - 1;
    R19 = R19 - (R18 == 0);
    R18 = bVar1;
  } while (bVar1 != 0 || R19 != '\0');
  R25R24 = CONCAT11(bVar2,DAT_mem_04c5) | 1;
LAB_code_04af:
  DAT_mem_04c5 = (byte)R25R24;
  return;
}

