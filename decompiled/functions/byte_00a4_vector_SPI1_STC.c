/* BYTE0x00a4; WORDcode:0052; vector_SPI1_STC */

void vector_SPI1_STC(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

