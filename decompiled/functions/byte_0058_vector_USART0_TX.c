/* BYTE0x0058; WORDcode:002c; vector_USART0_TX */

void vector_USART0_TX(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

