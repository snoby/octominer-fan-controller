/* BYTE0x002c; WORDcode:0016; vector_TIMER2_OVF */

void vector_TIMER2_OVF(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

