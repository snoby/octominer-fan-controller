/* BYTE0x0014; WORDcode:000a; vector_PCINT1 */

void vector_PCINT1(void)

{
  R1 = 0;
  isr_PCINT1();
  return;
}

