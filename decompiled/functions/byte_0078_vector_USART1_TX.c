/* BYTE0x0078; WORDcode:003c; vector_USART1_TX */

void vector_USART1_TX(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

