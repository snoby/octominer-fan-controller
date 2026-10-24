/* BYTE0x0030; WORDcode:0018; vector_TIMER1_CAPT */

void vector_TIMER1_CAPT(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

