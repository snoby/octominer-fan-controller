/* BYTE0x00b8; WORDcode:005c; vector_TIMER4_OVF */

void vector_TIMER4_OVF(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

