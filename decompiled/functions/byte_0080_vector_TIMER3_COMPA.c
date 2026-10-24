/* BYTE0x0080; WORDcode:0040; vector_TIMER3_COMPA */

void vector_TIMER3_COMPA(void)

{
  R1 = 0;
  isr_TIMER3_COMPA();
  return;
}

