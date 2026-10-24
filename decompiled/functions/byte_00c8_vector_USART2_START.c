/* BYTE0x00c8; WORDcode:0064; vector_USART2_START */

void vector_USART2_START(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

