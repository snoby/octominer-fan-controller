/* BYTE0x0038; WORDcode:001c; vector_TIMER1_COMPB */

void vector_TIMER1_COMPB(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

