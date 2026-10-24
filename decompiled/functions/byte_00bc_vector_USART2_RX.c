/* BYTE0x00bc; WORDcode:005e; vector_USART2_RX */

void vector_USART2_RX(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

