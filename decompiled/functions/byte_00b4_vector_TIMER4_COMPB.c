/* BYTE0x00b4; WORDcode:005a; vector_TIMER4_COMPB */

void vector_TIMER4_COMPB(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

