/* BYTE0x0084; WORDcode:0042; vector_TIMER3_COMPB */

void vector_TIMER3_COMPB(void)

{
  R1 = 0;
  isr_TIMER3_COMPB();
  return;
}

