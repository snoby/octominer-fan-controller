/* BYTE0x0040; WORDcode:0020; vector_TIMER0_COMPA */

void vector_TIMER0_COMPA(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

