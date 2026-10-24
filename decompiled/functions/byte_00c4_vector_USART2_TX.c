/* BYTE0x00c4; WORDcode:0062; vector_USART2_TX */

void vector_USART2_TX(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

