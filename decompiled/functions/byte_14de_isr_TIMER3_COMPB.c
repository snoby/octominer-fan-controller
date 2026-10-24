/* BYTE0x14de; WORDcode:0a6f; isr_TIMER3_COMPB */

undefined2 isr_TIMER3_COMPB(undefined1 R25,byte R24)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  char in_Cflg;
  char in_Zflg;
  char in_Nflg;
  char in_Vflg;
  char in_Sflg;
  char in_Hflg;
  char in_Tflg;
  
  uVar4 = R24;
  uVar3 = R0;
  R0 = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
       (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | (in_Hflg == '\x01') << 5 |
       (in_Tflg == '\x01') << 6 | 0x80;
  SREG = R0;
  bVar1 = OCR3B._0_1_;
  cVar2 = OCR3B._1_1_;
  OCR3B._1_1_ = cVar2 - ((bVar1 < 0xb5) + -5);
  OCR3B._0_1_ = bVar1 + 0x4b;
  if (led_modes[0] == 2) {
    R24 = PORTC;
    R24 = R24 ^ 0x20;
    PORTC = R24;
  }
  if (led_modes[1] == 2) {
    R24 = PORTC;
    R24 = R24 ^ 0x40;
    PORTC = R24;
  }
  if (led_modes[2] == 2) {
    bVar1 = PORTC;
    PORTC = bVar1 + 0x80;
  }
  if (led_modes[3] == 2) {
    R24 = PORTE;
    R24 = R24 ^ 8;
    PORTE = R24;
  }
  R24 = uVar4;
  SREG = R0;
  R0 = uVar3;
  R1 = 0;
  return CONCAT11(uVar4,R25);
}

