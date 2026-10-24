/* BYTE0x007c; WORDcode:003e; vector_TIMER3_CAPT */

void vector_TIMER3_CAPT(void)

{
  R1 = 0;
  isr_TIMER3_CAPT();
  return;
}

