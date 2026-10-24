/* BYTE0x0028; WORDcode:0014; vector_TIMER2_COMPB */

void vector_TIMER2_COMPB(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

