/* BYTE0x090c; WORDcode:0486; twi_init */

void twi_init(void)

{
  R1 = 0;
  TWSR0 = 0;
  TWBR0 = 0x48;
  R24 = 4;
  TWCR0 = 4;
  return;
}

