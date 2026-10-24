/* BYTE0x009c; WORDcode:004e; vector_PTC_EOC */

void vector_PTC_EOC(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

