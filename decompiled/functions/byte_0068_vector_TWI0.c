/* BYTE0x0068; WORDcode:0034; vector_TWI0 */

void vector_TWI0(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

