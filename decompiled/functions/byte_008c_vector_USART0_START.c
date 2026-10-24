/* BYTE0x008c; WORDcode:0046; vector_USART0_START */

void vector_USART0_START(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

