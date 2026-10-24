/* BYTE0x0008; WORDcode:0004; vector_INT1 */

void vector_INT1(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}

