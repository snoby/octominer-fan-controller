/* BYTE0x00a8; WORDcode:0054; vector_TWI1 */

void vector_TWI1(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

