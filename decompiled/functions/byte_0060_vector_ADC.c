/* BYTE0x0060; WORDcode:0030; vector_ADC */

void vector_ADC(void)

{
  R1 = 0;
  isr_ADC();
  return;
}

