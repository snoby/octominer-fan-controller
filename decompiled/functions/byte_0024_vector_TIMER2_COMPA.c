/* BYTE0x0024; WORDcode:0012; vector_TIMER2_COMPA */

void vector_TIMER2_COMPA(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

