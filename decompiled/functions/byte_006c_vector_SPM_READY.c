/* BYTE0x006c; WORDcode:0036; vector_SPM_READY */

void vector_SPM_READY(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

