/* BYTE0x0018; WORDcode:000c; vector_PCINT2 */

void vector_PCINT2(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

