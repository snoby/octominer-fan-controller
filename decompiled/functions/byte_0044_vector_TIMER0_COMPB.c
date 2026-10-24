/* BYTE0x0044; WORDcode:0022; vector_TIMER0_COMPB */

void vector_TIMER0_COMPB(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

