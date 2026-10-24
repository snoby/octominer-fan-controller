/* BYTE0x0054; WORDcode:002a; vector_USART0_UDRE */

void vector_USART0_UDRE(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

