/* BYTE0x0070; WORDcode:0038; vector_USART1_RX */

void vector_USART1_RX(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

