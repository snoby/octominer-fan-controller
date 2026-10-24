/* BYTE0x0094; WORDcode:004a; vector_PCINT4 */

void vector_PCINT4(void)

{
  R1 = 0;
  isr_PCINT4();
  return;
}

