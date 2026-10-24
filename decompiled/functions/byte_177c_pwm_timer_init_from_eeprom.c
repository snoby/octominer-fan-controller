/* BYTE0x177c; WORDcode:0bbe; pwm_timer_init_from_eeprom */

void pwm_timer_init_from_eeprom(void)

{
  byte bVar1;
  
  R1 = 0;
  bVar1 = DDRB;
  DDRB = bVar1 | 8;
  bVar1 = DDRB;
  DDRB = bVar1 | 0x10;
  bVar1 = DDRD;
  DDRD = bVar1 | 0x10;
  bVar1 = DDRD;
  DDRD = bVar1 | 0x20;
  bVar1 = DDRD;
  DDRD = bVar1 | 0x40;
  bVar1 = DDRD;
  DDRD = bVar1 | 0x80;
  TCCR0A = 0xa1;
  TCCR0B = 1;
  TCCR1A = 0xa1;
  TCCR1B = 1;
  TCCR2A = 0xa1;
  TCCR2B = 1;
  R25R24 = 0;
  R25R24._0_1_ = eeprom_read_byte(0);
  OCR0A = (byte)R25R24;
  R25R24 = 1;
  R25R24._0_1_ = eeprom_read_byte(1);
  OCR0B = (byte)R25R24;
  R25R24 = 2;
  R25R24._0_1_ = eeprom_read_byte(2);
  OCR1A._1_1_ = 0;
  OCR1A._0_1_ = (byte)R25R24;
  R25R24 = 3;
  R25R24._0_1_ = eeprom_read_byte(3);
  OCR1B._1_1_ = 0;
  OCR1B._0_1_ = (byte)R25R24;
  R25R24 = 4;
  R25R24._0_1_ = eeprom_read_byte(4);
  OCR2A = (byte)R25R24;
  R25R24 = 5;
  R25R24._0_1_ = eeprom_read_byte(5);
  OCR2B = (byte)R25R24;
  bVar1 = PORTC;
  PORTC = bVar1 & 0xf7;
  bVar1 = PORTC;
  PORTC = bVar1 & 0xef;
  bVar1 = PORTC;
  PORTC = bVar1 & 0xdf;
  bVar1 = PORTC;
  PORTC = bVar1 & 0xbf;
  bVar1 = PORTC;
  PORTC = bVar1 & 0x7f;
  bVar1 = DDRC;
  DDRC = bVar1 | 8;
  bVar1 = DDRC;
  DDRC = bVar1 | 0x10;
  bVar1 = DDRC;
  DDRC = bVar1 | 0x20;
  bVar1 = DDRC;
  DDRC = bVar1 | 0x40;
  bVar1 = DDRC;
  DDRC = bVar1 | 0x80;
  bVar1 = PORTE;
  PORTE = bVar1 & 0xf7;
  bVar1 = DDRE;
  DDRE = bVar1 | 8;
  TCCR3A = 0;
  TCCR3B = 0x1d;
  ICR3._1_1_ = 0x89;
  ICR3._0_1_ = 0x54;
  OCR3A._1_1_ = 0x2d;
  OCR3A._0_1_ = 199;
  OCR3B._1_1_ = 4;
  OCR3B._0_1_ = 0x4b;
  R25R24 = 0x426;
  TIMSK3 = 0x26;
  return;
}

