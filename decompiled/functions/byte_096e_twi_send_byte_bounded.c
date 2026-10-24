/* BYTE0x096e; WORDcode:04b7; twi_send_byte_bounded */

void twi_send_byte_bounded(void)

{
  R1 = 0;
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
  R25R24 = DAT_mem_04c5 | 4;
  DAT_mem_04c5 = (byte)R25R24;
  return;
}

