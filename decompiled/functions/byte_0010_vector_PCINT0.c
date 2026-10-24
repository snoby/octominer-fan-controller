/* BYTE0x0010; WORDcode:0008; vector_PCINT0 */

void vector_PCINT0(void)

{
  R1 = 0;
  isr_PCINT0();
  return;
}

