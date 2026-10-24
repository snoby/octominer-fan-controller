/* BYTE0x000c; WORDcode:0006; vector_INT2 */

void vector_INT2(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

