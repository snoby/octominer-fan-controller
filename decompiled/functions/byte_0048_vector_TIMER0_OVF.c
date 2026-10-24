/* BYTE0x0048; WORDcode:0024; vector_TIMER0_OVF */

void vector_TIMER0_OVF(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

