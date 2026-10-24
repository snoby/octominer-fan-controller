/* BYTE0x0020; WORDcode:0010; vector_WDT */

void vector_WDT(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

