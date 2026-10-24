/* BYTE0x0004; WORDcode:0002; vector_INT0 */

void vector_INT0(void)

{
  R1 = 0;
  isr_INT0();
  return;
}

