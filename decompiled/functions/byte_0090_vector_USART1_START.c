/* BYTE0x0090; WORDcode:0048; vector_USART1_START */

void vector_USART1_START(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

