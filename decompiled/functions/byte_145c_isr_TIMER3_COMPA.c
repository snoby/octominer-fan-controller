/* BYTE0x145c; WORDcode:0a2e; isr_TIMER3_COMPA */

void isr_TIMER3_COMPA(void)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  char in_Cflg;
  char in_Zflg;
  char in_Nflg;
  char in_Vflg;
  char in_Sflg;
  char in_Hflg;
  char in_Tflg;
  
  uVar4 = R25R24;
  uVar3 = R0;
  R0 = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
       (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | (in_Hflg == '\x01') << 5 |
       (in_Tflg == '\x01') << 6 | 0x80;
  SREG = R0;
  bVar1 = OCR3A._0_1_;
  cVar2 = OCR3A._1_1_;
  OCR3A._1_1_ = cVar2 - ((bVar1 < 0x39) + -0x2e);
  OCR3A._0_1_ = bVar1 - 0x39;
  R25R24 = host_elapsed_ticks + 1;
  host_elapsed_ticks = R25R24;
  if (led_modes[0] == 3) {
    R25R24._0_1_ = PORTC;
    R25R24._0_1_ = (byte)R25R24 ^ 0x20;
    PORTC = (byte)R25R24;
  }
  if (led_modes[1] == 3) {
    R25R24._0_1_ = PORTC;
    R25R24._0_1_ = (byte)R25R24 ^ 0x40;
    PORTC = (byte)R25R24;
  }
  if (led_modes[2] == 3) {
    bVar1 = PORTC;
    PORTC = bVar1 + 0x80;
  }
  if (led_modes[3] == 3) {
    R25R24._0_1_ = PORTE;
    R25R24._0_1_ = (byte)R25R24 ^ 8;
    PORTE = (byte)R25R24;
  }
  R25R24 = uVar4;
  SREG = R0;
  R0 = uVar3;
  R1 = 0;
  return;
}

