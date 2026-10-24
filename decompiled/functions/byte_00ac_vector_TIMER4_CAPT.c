/* BYTE0x00ac; WORDcode:0056; vector_TIMER4_CAPT */

void vector_TIMER4_CAPT(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

