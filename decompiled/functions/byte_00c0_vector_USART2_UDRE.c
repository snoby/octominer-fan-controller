/* BYTE0x00c0; WORDcode:0060; vector_USART2_UDRE */

void vector_USART2_UDRE(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

