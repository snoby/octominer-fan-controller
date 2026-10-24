/* BYTE0x0098; WORDcode:004c; vector_CFD */

void vector_CFD(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

