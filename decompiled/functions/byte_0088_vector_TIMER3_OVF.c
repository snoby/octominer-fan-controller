/* BYTE0x0088; WORDcode:0044; vector_TIMER3_OVF */

void vector_TIMER3_OVF(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

