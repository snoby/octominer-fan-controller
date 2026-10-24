/* BYTE0x001c; WORDcode:000e; vector_PCINT3 */

void vector_PCINT3(void)

{
  R1 = 0;
  isr_PCINT3();
  return;
}

