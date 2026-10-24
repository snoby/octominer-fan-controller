/* BYTE0x0074; WORDcode:003a; vector_USART1_UDRE */

void vector_USART1_UDRE(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

