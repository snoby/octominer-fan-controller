/* BYTE0x0064; WORDcode:0032; vector_EE_READY */

void vector_EE_READY(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

