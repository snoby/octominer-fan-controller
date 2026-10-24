/* BYTE0x0034; WORDcode:001a; vector_TIMER1_COMPA */

void vector_TIMER1_COMPA(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

