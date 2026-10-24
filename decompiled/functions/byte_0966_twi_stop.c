/* BYTE0x0966; WORDcode:04b3; twi_stop */

void twi_stop(void)

{
  R1 = 0;
  R24 = 0x94;
  TWCR0 = 0x94;
  return;
}

