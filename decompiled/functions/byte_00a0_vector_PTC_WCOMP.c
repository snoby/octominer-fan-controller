/* BYTE0x00a0; WORDcode:0050; vector_PTC_WCOMP */

void vector_PTC_WCOMP(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

