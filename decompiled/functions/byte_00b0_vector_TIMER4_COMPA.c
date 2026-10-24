/* BYTE0x00b0; WORDcode:0058; vector_TIMER4_COMPA */

void vector_TIMER4_COMPA(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

