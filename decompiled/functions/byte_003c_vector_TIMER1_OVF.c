/* BYTE0x003c; WORDcode:001e; vector_TIMER1_OVF */

void vector_TIMER1_OVF(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

