/* BYTE0x004c; WORDcode:0026; vector_SPI0_STC */

void vector_SPI0_STC(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

