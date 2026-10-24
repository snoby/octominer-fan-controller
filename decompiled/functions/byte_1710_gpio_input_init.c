/* BYTE0x1710; WORDcode:0b88; gpio_input_init */

void gpio_input_init(void)

{
  byte bVar1;
  
  R1 = 0;
  bVar1 = DDRA;
  DDRA = bVar1 & 0xfe;
  bVar1 = DDRA;
  DDRA = bVar1 & 0xfd;
  bVar1 = DDRA;
  DDRA = bVar1 & 0xfb;
  bVar1 = DDRA;
  DDRA = bVar1 & 0xf7;
  bVar1 = DDRB;
  DDRB = bVar1 & 0xfe;
  bVar1 = DDRB;
  DDRB = bVar1 & 0xfd;
  bVar1 = DDRB;
  DDRB = bVar1 & 0xfb;
  bVar1 = DDRB;
  DDRB = bVar1 & 0xdf;
  bVar1 = DDRB;
  DDRB = bVar1 & 0xbf;
  bVar1 = DDRB;
  DDRB = bVar1 & 0x7f;
  bVar1 = DDRC;
  DDRC = bVar1 & 0xfb;
  bVar1 = DDRD;
  DDRD = bVar1 & 0xfe;
  bVar1 = DDRE;
  DDRE = bVar1 & 0xfb;
  bVar1 = DDRE;
  DDRE = bVar1 & 0xdf;
  bVar1 = DDRE;
  DDRE = bVar1 & 0xbf;
  bVar1 = PORTA;
  PORTA = bVar1 | 1;
  bVar1 = PORTA;
  PORTA = bVar1 | 2;
  bVar1 = PORTA;
  PORTA = bVar1 | 4;
  bVar1 = PORTA;
  PORTA = bVar1 | 8;
  bVar1 = PORTB;
  PORTB = bVar1 | 1;
  bVar1 = PORTB;
  PORTB = bVar1 | 2;
  bVar1 = PORTB;
  PORTB = bVar1 | 4;
  bVar1 = PORTB;
  PORTB = bVar1 | 0x20;
  bVar1 = PORTB;
  PORTB = bVar1 | 0x40;
  bVar1 = PORTB;
  PORTB = bVar1 | 0x80;
  bVar1 = PORTC;
  PORTC = bVar1 | 4;
  bVar1 = PORTD;
  PORTD = bVar1 | 1;
  bVar1 = PORTE;
  PORTE = bVar1 | 4;
  bVar1 = PORTE;
  PORTE = bVar1 | 0x20;
  bVar1 = PORTE;
  PORTE = bVar1 | 0x40;
  PCMSK0 = 0xf;
  PCMSK1 = 0x67;
  PCMSK3 = 1;
  PCMSK4 = 0x60;
  Z = 0x68;
  R24 = PCICR;
  R24 = R24 | 0x1b;
  PCICR = R24;
  ADMUX = 0x44;
  R24 = 0xcf;
  ADCSRA = 0xcf;
  return;
}

