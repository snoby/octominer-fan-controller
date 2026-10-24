/* BYTE0x0050; WORDcode:0028; vector_USART0_RX */

void vector_USART0_RX(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

