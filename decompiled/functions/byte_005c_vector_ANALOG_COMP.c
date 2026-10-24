/* BYTE0x005c; WORDcode:002e; vector_ANALOG_COMP */

void vector_ANALOG_COMP(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

