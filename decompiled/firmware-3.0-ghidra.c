/* MACHINE-GENERATED GHIDRA PSEUDOCODE, NOT ORIGINAL OR BUILDABLE SOURCE. */
/* FW3.0 SHA256186930d0fe8e4caa6fa2873e151225df6c7d1a6f6c4811a82601b113f65c6ddf */
/* AVR code labels use WORD addresses. Every section below also states BYTE address. */
/* BYTE0x0000; WORDcode:0000; vector_RESET */

/* ACTUAL installed FW3.0 read twice from cmp-100.
   SHA256186930d0fe8e4caa6fa2873e151225df6c7d1a6f6c4811a82601b113f65c6ddf. Code display addresses
   are WORDS; exported index uses BYTE offsets. Register labels corrected from AVR-libc iom324pb.h.
   Inferred function names are NOT original symbols. */

void vector_RESET(void)

{
  undefined1 *puVar1;
  
  R1 = 0;
  SREG = 0;
  Ylo = 0xff;
  Yhi = 8;
  R17 = '\x03';
  X = &DAT_mem_0100;
  Z = &DAT_codebyte_3916;
  while (puVar1 = X, (byte)X != 0x50 || X._1_1_ != (char)(R17 + ((byte)X < 0x50))) {
    R0 = *Z;
    Z = Z + 1;
    X = X + 1;
    *puVar1 = R0;
  }
  R18 = '\x05';
  X = &DAT_mem_0350;
  while (puVar1 = X, (byte)X != 0x9f || X._1_1_ != (char)(R18 + ((byte)X < 0x9f))) {
    X = X + 1;
    *puVar1 = R1;
  }
  DAT_mem_08fe = 0x237;
  application_main();
  terminal_exit_loop();
  return;
}


/* BYTE0x0004; WORDcode:0002; vector_INT0 */

void vector_INT0(void)

{
  R1 = 0;
  isr_INT0();
  return;
}


/* BYTE0x0008; WORDcode:0004; vector_INT1 */

void vector_INT1(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x000c; WORDcode:0006; vector_INT2 */

void vector_INT2(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0010; WORDcode:0008; vector_PCINT0 */

void vector_PCINT0(void)

{
  R1 = 0;
  isr_PCINT0();
  return;
}


/* BYTE0x0014; WORDcode:000a; vector_PCINT1 */

void vector_PCINT1(void)

{
  R1 = 0;
  isr_PCINT1();
  return;
}


/* BYTE0x0018; WORDcode:000c; vector_PCINT2 */

void vector_PCINT2(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x001c; WORDcode:000e; vector_PCINT3 */

void vector_PCINT3(void)

{
  R1 = 0;
  isr_PCINT3();
  return;
}


/* BYTE0x0020; WORDcode:0010; vector_WDT */

void vector_WDT(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0024; WORDcode:0012; vector_TIMER2_COMPA */

void vector_TIMER2_COMPA(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0028; WORDcode:0014; vector_TIMER2_COMPB */

void vector_TIMER2_COMPB(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x002c; WORDcode:0016; vector_TIMER2_OVF */

void vector_TIMER2_OVF(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0030; WORDcode:0018; vector_TIMER1_CAPT */

void vector_TIMER1_CAPT(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0034; WORDcode:001a; vector_TIMER1_COMPA */

void vector_TIMER1_COMPA(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0038; WORDcode:001c; vector_TIMER1_COMPB */

void vector_TIMER1_COMPB(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x003c; WORDcode:001e; vector_TIMER1_OVF */

void vector_TIMER1_OVF(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0040; WORDcode:0020; vector_TIMER0_COMPA */

void vector_TIMER0_COMPA(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0044; WORDcode:0022; vector_TIMER0_COMPB */

void vector_TIMER0_COMPB(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0048; WORDcode:0024; vector_TIMER0_OVF */

void vector_TIMER0_OVF(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x004c; WORDcode:0026; vector_SPI0_STC */

void vector_SPI0_STC(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0050; WORDcode:0028; vector_USART0_RX */

void vector_USART0_RX(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0054; WORDcode:002a; vector_USART0_UDRE */

void vector_USART0_UDRE(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0058; WORDcode:002c; vector_USART0_TX */

void vector_USART0_TX(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x005c; WORDcode:002e; vector_ANALOG_COMP */

void vector_ANALOG_COMP(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0060; WORDcode:0030; vector_ADC */

void vector_ADC(void)

{
  R1 = 0;
  isr_ADC();
  return;
}


/* BYTE0x0064; WORDcode:0032; vector_EE_READY */

void vector_EE_READY(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0068; WORDcode:0034; vector_TWI0 */

void vector_TWI0(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x006c; WORDcode:0036; vector_SPM_READY */

void vector_SPM_READY(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0070; WORDcode:0038; vector_USART1_RX */

void vector_USART1_RX(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0074; WORDcode:003a; vector_USART1_UDRE */

void vector_USART1_UDRE(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0078; WORDcode:003c; vector_USART1_TX */

void vector_USART1_TX(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x007c; WORDcode:003e; vector_TIMER3_CAPT */

void vector_TIMER3_CAPT(void)

{
  R1 = 0;
  isr_TIMER3_CAPT();
  return;
}


/* BYTE0x0080; WORDcode:0040; vector_TIMER3_COMPA */

void vector_TIMER3_COMPA(void)

{
  R1 = 0;
  isr_TIMER3_COMPA();
  return;
}


/* BYTE0x0084; WORDcode:0042; vector_TIMER3_COMPB */

void vector_TIMER3_COMPB(void)

{
  R1 = 0;
  isr_TIMER3_COMPB();
  return;
}


/* BYTE0x0088; WORDcode:0044; vector_TIMER3_OVF */

void vector_TIMER3_OVF(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x008c; WORDcode:0046; vector_USART0_START */

void vector_USART0_START(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0090; WORDcode:0048; vector_USART1_START */

void vector_USART1_START(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0094; WORDcode:004a; vector_PCINT4 */

void vector_PCINT4(void)

{
  R1 = 0;
  isr_PCINT4();
  return;
}


/* BYTE0x0098; WORDcode:004c; vector_CFD */

void vector_CFD(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x009c; WORDcode:004e; vector_PTC_EOC */

void vector_PTC_EOC(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x00a0; WORDcode:0050; vector_PTC_WCOMP */

void vector_PTC_WCOMP(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x00a4; WORDcode:0052; vector_SPI1_STC */

void vector_SPI1_STC(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x00a8; WORDcode:0054; vector_TWI1 */

void vector_TWI1(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x00ac; WORDcode:0056; vector_TIMER4_CAPT */

void vector_TIMER4_CAPT(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x00b0; WORDcode:0058; vector_TIMER4_COMPA */

void vector_TIMER4_COMPA(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x00b4; WORDcode:005a; vector_TIMER4_COMPB */

void vector_TIMER4_COMPB(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x00b8; WORDcode:005c; vector_TIMER4_OVF */

void vector_TIMER4_OVF(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x00bc; WORDcode:005e; vector_USART2_RX */

void vector_USART2_RX(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x00c0; WORDcode:0060; vector_USART2_UDRE */

void vector_USART2_UDRE(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x00c4; WORDcode:0062; vector_USART2_TX */

void vector_USART2_TX(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x00c8; WORDcode:0064; vector_USART2_START */

void vector_USART2_START(void)

{
  R1 = 0;
  unexpected_interrupt_reset();
  return;
}


/* BYTE0x0438; WORDcode:021c; reset_startup */

void reset_startup(void)

{
  undefined1 *puVar1;
  
  R1 = 0;
  SREG = 0;
  Ylo = 0xff;
  Yhi = 8;
  R17 = '\x03';
  X = &DAT_mem_0100;
  Z = &DAT_codebyte_3916;
  while (puVar1 = X, (byte)X != 0x50 || X._1_1_ != (char)(R17 + ((byte)X < 0x50))) {
    R0 = *Z;
    Z = Z + 1;
    X = X + 1;
    *puVar1 = R0;
  }
  R18 = '\x05';
  X = &DAT_mem_0350;
  while (puVar1 = X, (byte)X != 0x9f || X._1_1_ != (char)(R18 + ((byte)X < 0x9f))) {
    X = X + 1;
    *puVar1 = R1;
  }
  DAT_mem_08fe = 0x237;
  application_main();
  terminal_exit_loop();
  return;
}


/* BYTE0x0472; WORDcode:0239; unexpected_interrupt_reset */

void unexpected_interrupt_reset(void)

{
  undefined1 *puVar1;
  
  R1 = 0;
  SREG = 0;
  Ylo = 0xff;
  Yhi = 8;
  R17 = '\x03';
  X = &DAT_mem_0100;
  Z = &DAT_codebyte_3916;
  while (puVar1 = X, (byte)X != 0x50 || X._1_1_ != (char)(R17 + ((byte)X < 0x50))) {
    R0 = *Z;
    Z = Z + 1;
    X = X + 1;
    *puVar1 = R0;
  }
  R18 = '\x05';
  X = &DAT_mem_0350;
  while (puVar1 = X, (byte)X != 0x9f || X._1_1_ != (char)(R18 + ((byte)X < 0x9f))) {
    X = X + 1;
    *puVar1 = R1;
  }
  DAT_mem_08fe = 0x237;
  application_main();
  terminal_exit_loop();
  return;
}


/* BYTE0x0476; WORDcode:023b; FUN_code_023b */

byte FUN_code_023b(byte R25,byte R24,byte R23,char R22)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  bool bVar5;
  
  R1 = 0;
  X = (byte *)CONCAT11(R25,R24);
  R24 = 0xff;
  R25 = 0xff;
  while (pbVar4 = X, cVar1 = R22 + -1, bVar5 = R22 != '\0', R22 = cVar1, bVar5) {
    X = X + 1;
    R18 = *pbVar4;
    R24 = R24 ^ R18;
    bVar3 = R24;
    R18 = R24 >> 4 ^ R24;
    bVar2 = R18;
    R18 = R18 >> 2;
    R18 = R18 ^ bVar2;
    R18 = R18 + 1;
    R18 = R18 >> 1;
    R18 = R18 & 1;
    R24 = R25 ^ R18;
    R18 = -R18;
    R18 = R18 & 0xc0;
    R23 = bVar3 >> 1;
    bVar2 = R23;
    R25 = R18 ^ R23;
    R24 = R24 ^ bVar3 << 7;
    R23 = bVar3 >> 2;
    R18 = bVar2 << 7 | (bVar3 & 1) << 6;
    R25 = R25 ^ R23;
    R24 = R24 ^ R18;
  }
  R24 = ~R24;
  R25 = ~R25;
  return R25;
}


/* BYTE0x04c0; WORDcode:0260; FUN_code_0260 */

undefined1 FUN_code_0260(void)

{
  undefined1 *puVar1;
  
  R1 = 0;
  FUN_code_023b();
  puVar1 = X;
  X = X + 1;
  *puVar1 = R24;
  puVar1 = X;
  X = X + 1;
  *puVar1 = R25;
  return R25;
}


/* BYTE0x04c8; WORDcode:0264; isr_INT0 */

void isr_INT0(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  byte bVar10;
  undefined2 uVar11;
  byte *pbVar12;
  char in_Cflg;
  bool bVar13;
  bool bVar14;
  char in_Zflg;
  char in_Nflg;
  char in_Vflg;
  char in_Sflg;
  char in_Hflg;
  char in_Tflg;
  char in_Iflg;
  
  uVar11 = Y;
  uVar8 = R20;
  uVar7 = R19;
  uVar6 = R18;
  uVar5 = R17;
  uVar4 = R16;
  R1 = 0;
  Y._0_1_ = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
            (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | (in_Hflg == '\x01') << 5 |
            (in_Tflg == '\x01') << 6 | (in_Iflg == '\x01') << 7;
  bVar10 = (byte)Y;
  SREG = (byte)Y;
LAB_code_0267:
  do {
    Y._0_1_ = (byte)Y + 1;
    bVar2 = PIND;
    if ((bVar2 & 8) == 0) {
      if ((byte)Y != 0) goto LAB_code_0267;
    }
    do {
      bVar2 = PIND;
      if (((((bVar2 & 8) != 0) && (bVar2 = PIND, (bVar2 & 8) != 0)) &&
          (bVar2 = PIND, (bVar2 & 8) != 0)) &&
         ((bVar2 = PIND, (bVar2 & 8) != 0 && (bVar2 = PIND, (bVar2 & 8) != 0)))) goto LAB_code_0316;
      Y = (byte *)CONCAT11(-((DAT_mem_04a8 < 0x51) + -5),DAT_mem_04a8 + 0xaf);
      bVar2 = PIND;
    } while ((bVar2 & 8) != 0);
    bVar2 = PIND;
    R17 = PIND;
    R20 = 0xff;
    R16 = bVar2 ^ R17;
    R18 = bVar2 >> 3 & 1 | 0xfc | (R16 >> 3 & 1) << 1;
    R19 = '\v';
    while( true ) {
      pbVar12 = Y;
      bVar2 = PIND;
      R18 = R18 & 0xf3;
      R16 = bVar2;
      if (R18 == 0) {
        R20 = R20 & 0xfd;
        R18 = 2;
        R16 = PIND;
        R17 = bVar2;
      }
      if (R19 == '\0') {
        EIFR = 1;
        goto LAB_code_02f2;
      }
      R17 = R17 ^ R16;
      bVar2 = PIND;
      R18 = R18 & 0xe7 | (R17 >> 3 & 1) << 2;
      R17 = bVar2;
      if (R18 == 0) {
        R20 = R20 & 0xfb;
        R18 = 4;
        R17 = PIND;
        R16 = bVar2;
      }
      R16 = R16 ^ R17;
      R18 = R18 | (R16 >> 3 & 1) << 3;
      while (R18 = R18 & 0xcf, R18 == 0) {
        R17 = PIND;
        R20 = R20 & 0xf7;
        R18 = 8;
      }
      R16 = PIND;
      R17 = R17 ^ R16;
      R18 = R18 | (R17 >> 3 & 1) << 4;
      while (R18 = R18 & 0x9f, R18 == 0) {
        R20 = R20 & 0xef;
        R16 = PIND;
        R18 = 0x10;
      }
      R17 = PIND;
      R16 = R16 ^ R17;
      R18 = R18 | (R16 >> 3 & 1) << 5;
      while (R18 = R18 & 0x3f, R18 == 0) {
        R20 = R20 & 0xdf;
        R17 = PIND;
        R18 = 0x20;
      }
      R16 = PIND;
      R17 = R17 ^ R16;
      for (R18 = R18 | (R17 >> 3 & 1) << 6; R18 < 2; R18 = R18 | 0x40) {
        R20 = R20 & 0xbf;
        R16 = PIND;
      }
      R17 = PIND;
      R16 = R16 ^ R17;
      R18 = R18 | (R16 >> 3) << 7;
      while (R18 < 4) {
        R20 = R20 & 0x7f;
        R18 = R18 | 0x80;
        R17 = PIND;
      }
      R20 = R20 ^ R18;
      R16 = PIND;
      Y = Y + 1;
      R19 = R19 + -1;
      *pbVar12 = R20;
      uVar9 = R21;
      R20 = 0xff;
      R17 = R17 ^ R16;
      bVar2 = R17 >> 3;
      R17 = PIND;
      R17 = R17 & 0xc;
      if (R17 == 0) break;
      R18 = R18 & 0xf8 | bVar2 & 1;
      while (R18 == 0) {
        R20 = R20 & 0xfe;
        R16 = R17;
        R17 = PIND;
        R18 = 1;
      }
      R16 = R16 ^ R17;
      R18 = R18 | (R16 >> 3 & 1) << 1;
    }
    cVar1 = R19 + -0xb;
    R19 = -cVar1;
    Y = (byte *)CONCAT11(Y._1_1_ - ((byte)Y < R19),(byte)Y + cVar1);
    EIFR = 1;
    R16 = *Y;
    bVar13 = R16 < 0xc3;
    if ((R16 == 0xc3) || (bVar13 = R16 < 0x4b, R16 == 0x4b)) {
      R21 = uVar9;
      if (DAT_mem_04ad != 0) {
        if ((DAT_mem_04ab == 0) && (bVar13 = R19 < 4, -1 < (char)(R19 - 4))) {
          DAT_mem_04ab = R19;
          DAT_mem_04a7 = DAT_mem_04ad;
          bVar13 = 0xb < DAT_mem_04a8;
          DAT_mem_04a8 = 0xb - DAT_mem_04a8;
        }
LAB_code_0349:
        Y = (byte *)0x14;
        R19 = 2;
LAB_code_034c:
        R17 = DDRD;
        R17 = R17 | 0xc;
        bVar2 = PORTD;
        PORTD = bVar2 | 8;
        DDRD = R17;
        R16 = PORTD;
        R18 = 0x40;
LAB_code_0354:
        R16 = R16 ^ 0xc;
        R21 = '\x06';
LAB_code_0356:
        while( true ) {
          pbVar12 = Y;
          PORTD = R16;
          bVar14 = (bool)(R18 & 1);
          bVar2 = R18 >> 1;
          R18 = bVar13 << 7 | bVar2;
          if (!bVar14) break;
          R21 = R21 + -1;
          if (R21 != '\0') goto code_c0x0360;
          bVar13 = CARRY1(R18,R18);
          R18 = bVar2 * '\x02';
          R21 = '\0';
        }
        R16 = R16 ^ 0xc;
        R21 = '\x06';
code_c0x0360:
        bVar2 = R19 + 0x55;
        bVar14 = R19 < 0xab;
        PORTD = R16;
        if (!bVar14) {
          for (; bVar13 = (bool)(R18 & 1), R18 = R18 >> 1, bVar13; R18 = R18 * '\x02') {
            R21 = R21 + -1;
            if (R21 != '\0') goto LAB_code_036c;
            R21 = '\0';
          }
          R16 = R16 ^ 0xc;
          R21 = '\x06';
LAB_code_036c:
          do {
            bVar14 = (bool)(R18 & 1);
            PORTD = R16;
            if (!bVar14) goto LAB_code_0373;
            cVar1 = R21 + -1;
            bVar14 = R21 == '\0';
            R21 = cVar1;
            if (cVar1 != '\0') goto LAB_code_0375;
            R18 = 0;
            R21 = '\0';
          } while( true );
        }
        goto LAB_code_033d;
      }
    }
    else {
      R17 = Y[1];
      if ((byte)(R17 * '\x02') == DAT_mem_04a6) {
        if (R16 == 0x69) {
          bVar13 = DAT_mem_04ab == 0;
          if (((char)DAT_mem_04ab < '\x01') && (R19 = DAT_mem_0101, (DAT_mem_0101 & 0x10) == 0)) {
            DAT_mem_0101 = 0x5a;
            Y = &DAT_mem_049b;
            goto LAB_code_034c;
          }
          goto LAB_code_0349;
        }
        if ((R16 != 0x2d) && (R16 != 0xe1)) goto LAB_code_02f2;
      }
      else {
LAB_code_02f2:
        R16 = 0;
      }
      DAT_mem_04ad = R16;
    }
LAB_code_030d:
    Y._0_1_ = EIFR;
    if (((byte)Y & 1) == 0) {
LAB_code_0316:
      SREG = bVar10;
      Y = (byte *)uVar11;
      R16 = uVar4;
      R17 = uVar5;
      R18 = uVar6;
      R19 = uVar7;
      R20 = uVar8;
      return;
    }
  } while( true );
LAB_code_0373:
  R16 = R16 ^ 0xc;
  R21 = '\x06';
LAB_code_0375:
  Y = Y + 1;
  R18 = *pbVar12;
  PORTD = R16;
  if (bVar2 == 0) {
    R16 = R16 & 0xf3;
    bVar2 = R16;
    PORTD = R16;
    if ((byte)Y != 0x16 || (bool)(char)((uint)Y >> 8) != (byte)Y < 0x16) {
      DAT_mem_04a6 = DAT_mem_04ac * '\x02';
    }
    EIFR = 1;
    R16 = R16 | 8;
    R17 = DDRD;
    R17 = R17 & 0xf3;
    PORTD = R16;
    DDRD = R17;
    PORTD = bVar2;
    R21 = uVar9;
    goto LAB_code_030d;
  }
LAB_code_033d:
  while( true ) {
    bVar13 = (bool)(R18 & 1);
    bVar3 = R18 >> 1;
    R18 = bVar14 << 7 | bVar3;
    R19 = bVar2;
    if (!bVar13) goto LAB_code_0354;
    cVar1 = R21 + -1;
    bVar13 = R21 == '\0';
    R21 = cVar1;
    if (cVar1 != '\0') break;
    bVar14 = CARRY1(R18,R18);
    R21 = '\0';
    R18 = bVar3 * '\x02';
  }
  goto LAB_code_0356;
}


/* BYTE0x0722; WORDcode:0391; usb_poll */

void usb_poll(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined2 uVar5;
  undefined1 *puVar6;
  
  uVar5 = Y;
  R1 = 0;
  if ((DAT_mem_04ab - 3U & 0x80) != 0) goto LAB_code_0422;
  if ((DAT_mem_04a7 == '-') && ((byte)(DAT_mem_04ab - 3U) == 8)) {
    Y = (UsbSetupPacket *)
        CONCAT11(-(((byte)(-DAT_mem_04a8 + 0xc) < 0x51) + -5) - (0xc < DAT_mem_04a8),
                 -DAT_mem_04a8 + -0x45);
    DAT_mem_049b = 0xc3;
    DAT_mem_0101 = 0x5a;
    DAT_mem_0350 = 0;
    R25R24._0_1_ = Y->bmRequestType;
    R25R24._0_1_ = (byte)R25R24 & 0x60;
    if ((byte)R25R24 == 0) {
      R25R24._0_1_ = (byte)Y->wValue;
      DAT_mem_04a4 = 0;
      R25R24._1_1_ = Y->bRequest;
      if (R25R24._1_1_ == 0) {
        DAT_mem_04a5 = 0;
        R18 = 0xa4;
        R25R24._0_1_ = 2;
      }
      else if (R25R24._1_1_ == 5) {
        DAT_mem_04ac = (byte)R25R24;
LAB_code_0405:
        R18 = 0xa4;
        R25R24._0_1_ = 0;
      }
      else {
        if (R25R24._1_1_ == 6) {
          R25R24._1_1_ = *(char *)((int)&Y->wValue + 1);
          if (R25R24._1_1_ == '\x01') {
            R25R24 = (UsbSetupPacket *)0x13e;
LAB_code_03d4:
            usb_reply_pointer._1_1_ = R25R24._1_1_;
            usb_reply_pointer._0_1_ = (byte)R25R24;
            R25R24._0_1_ = 0x12;
          }
          else {
            if (R25R24._1_1_ == '\x02') {
              R25R24 = (UsbSetupPacket *)0x12c;
              goto LAB_code_03d4;
            }
            if (R25R24._1_1_ == '\x03') {
              if ((byte)R25R24 == '\0') {
                usb_reply_pointer._1_1_ = '\x01';
                usb_reply_pointer._0_1_ = 0x94;
                R25R24._0_1_ = 4;
              }
              else if ((byte)R25R24 == '\x01') {
                usb_reply_pointer._1_1_ = '\x01';
                usb_reply_pointer._0_1_ = 0x6e;
                R25R24._0_1_ = 0x26;
              }
              else {
                if ((byte)R25R24 != '\x02') goto LAB_code_03fa;
                usb_reply_pointer._1_1_ = '\x01';
                usb_reply_pointer._0_1_ = 0x50;
                R25R24._0_1_ = 0x1e;
              }
            }
            else {
LAB_code_03fa:
              R25R24._0_1_ = 0;
            }
          }
          DAT_mem_0350 = 0x40;
          goto LAB_code_0417;
        }
        if (R25R24._1_1_ == 8) {
          R18 = 0xae;
          R25R24._0_1_ = 1;
        }
        else {
          if (R25R24._1_1_ == 9) {
            DAT_mem_04ae = (byte)R25R24;
            goto LAB_code_0405;
          }
          R25R24._0_1_ = R25R24._1_1_ == 10;
          R18 = 0xa4;
        }
      }
      R19 = 4;
      usb_reply_pointer._1_1_ = '\x04';
      usb_reply_pointer._0_1_ = R18;
    }
    else {
      R25R24 = Y;
      R25R24._0_1_ = usb_setup_dispatch(Y);
    }
LAB_code_0417:
    R25R24._1_1_ = *(char *)((int)&Y->wLength + 1);
    if ((R25R24._1_1_ == '\0') && (R25R24._1_1_ = (byte)Y->wLength, R25R24._1_1_ < (byte)R25R24)) {
      R25R24._0_1_ = R25R24._1_1_;
    }
    DAT_mem_0100 = (byte)R25R24;
  }
  DAT_mem_04ab = '\0';
LAB_code_0422:
  if (((DAT_mem_0101 & 0x10) != 0) && (DAT_mem_0100 != 0xff)) {
    R18 = DAT_mem_0100;
    if (8 < DAT_mem_0100) {
      R18 = 8;
    }
    DAT_mem_0100 = DAT_mem_0100 - R18;
    R25R24._0_1_ = DAT_mem_049b ^ 0x88;
    DAT_mem_049b = (byte)R25R24;
    Y = (UsbSetupPacket *)(uint)R18;
    bVar2 = R18;
    if (R18 != 0) {
      R25R24 = (UsbSetupPacket *)CONCAT11(usb_reply_pointer._1_1_,(byte)usb_reply_pointer);
      if ((DAT_mem_0350 & 0x40) == 0) {
        Z = &DAT_mem_049c;
        X = (undefined1 *)R25R24;
        do {
          puVar6 = Z;
          puVar4 = X;
          X = X + 1;
          R19 = *puVar4;
          Z = Z + 1;
          *puVar6 = R19;
          R18 = R18 - 1;
        } while (R18 != 0);
      }
      else {
        X = &DAT_mem_049b;
        R21R20._0_1_ = (byte)usb_reply_pointer + 0x65;
        R21R20._1_1_ = usb_reply_pointer._1_1_ - (((byte)usb_reply_pointer < 0x9b) + '\x04');
        do {
          cVar1 = R21R20._1_1_ + X._1_1_ + CARRY1((byte)R21R20,(byte)X);
          Z = (undefined1 *)CONCAT11(cVar1,(byte)R21R20 + (byte)X);
          Z._0_1_ = *Z;
          Z = (undefined1 *)CONCAT11(cVar1,Z._0_1_);
          X = X + 1;
          *X = Z._0_1_;
          R18 = R18 - 1;
        } while (R18 != R1);
      }
      R25R24 = (UsbSetupPacket *)((int)R25R24 + 1);
      usb_reply_pointer._0_1_ = (byte)R25R24 + ((byte)Y - 1);
      usb_reply_pointer._1_1_ = R25R24._1_1_ + R1 + CARRY1((byte)R25R24,(byte)Y - 1);
      bVar2 = (byte)Y;
    }
    Y._0_1_ = bVar2;
    FUN_code_0260();
    DAT_mem_0101 = (byte)Y + 4;
    if (DAT_mem_0101 != 0xc) {
      DAT_mem_0100 = 0xff;
    }
  }
  R25R24 = (UsbSetupPacket *)0x14;
  do {
    bVar2 = PIND;
    R25R24._1_1_ = bVar2 & 0xc;
    bVar3 = R25R24._1_1_;
    R25R24 = (UsbSetupPacket *)(CONCAT11(bVar2,(byte)R25R24) & 0xcff);
    if (bVar3 != 0) {
      Y = (UsbSetupPacket *)uVar5;
      return;
    }
    cVar1 = (byte)R25R24 + -1;
    R25R24 = (UsbSetupPacket *)(CONCAT11(bVar2,cVar1) & 0xcff);
  } while (cVar1 != '\0');
  DAT_mem_04ac = R1;
  DAT_mem_04a6 = R1;
  Y = (UsbSetupPacket *)uVar5;
  return;
}


/* BYTE0x08fe; WORDcode:047f; FUN_code_047f */

void FUN_code_047f(void)

{
  byte bVar1;
  
  R1 = 0;
  Z = 0x69;
  R24 = EICRA;
  R24 = R24 | 2;
  EICRA = R24;
  bVar1 = EIMSK;
  EIMSK = bVar1 | 1;
  return;
}


/* BYTE0x090c; WORDcode:0486; twi_init */

void twi_init(void)

{
  R1 = 0;
  TWSR0 = 0;
  TWBR0 = 0x48;
  R24 = 4;
  TWCR0 = 4;
  return;
}


/* BYTE0x091e; WORDcode:048f; twi_start_address_bounded */

void twi_start_address_bounded(void)

{
  byte bVar1;
  byte bVar2;
  
  R1 = 0;
  TWCR0 = 0xa4;
  R18 = 0x40;
  R19 = '\x01';
  do {
    bVar2 = TWCR0;
    if ((bVar2 & 0x80) != 0) {
      TWDR0 = (byte)R25R24;
      TWCR0 = 0x84;
      R25R24 = 0x140;
      do {
        R18 = TWCR0;
        if ((R18 & 0x80) != 0) {
          return;
        }
        R25R24 = R25R24 + -1;
      } while (R25R24 != 0);
      R25R24 = DAT_mem_04c5 | 2;
      goto LAB_code_04af;
    }
    bVar1 = R18 - 1;
    R19 = R19 - (R18 == 0);
    R18 = bVar1;
  } while (bVar1 != 0 || R19 != '\0');
  R25R24 = CONCAT11(bVar2,DAT_mem_04c5) | 1;
LAB_code_04af:
  DAT_mem_04c5 = (byte)R25R24;
  return;
}


/* BYTE0x0966; WORDcode:04b3; twi_stop */

void twi_stop(void)

{
  R1 = 0;
  R24 = 0x94;
  TWCR0 = 0x94;
  return;
}


/* BYTE0x096e; WORDcode:04b7; twi_send_byte_bounded */

void twi_send_byte_bounded(void)

{
  R1 = 0;
  TWDR0 = (byte)R25R24;
  TWCR0 = 0x84;
  R25R24 = 0x140;
  do {
    R18 = TWCR0;
    if ((R18 & 0x80) != 0) {
      return;
    }
    R25R24 = R25R24 + -1;
  } while (R25R24 != 0);
  R25R24 = DAT_mem_04c5 | 4;
  DAT_mem_04c5 = (byte)R25R24;
  return;
}


/* BYTE0x09ea; WORDcode:04f5; oled_send_commands */

void oled_send_commands(void)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  uVar3 = Y;
  uVar2 = R17R16;
  R1 = 0;
  R17R16._0_1_ = R25R24._1_1_;
  R17R16._1_1_ = R22;
  twi_start_address_bounded();
  twi_send_byte_bounded();
  bVar1 = (byte)R25R24;
  Y = CONCAT11((byte)R17R16,bVar1);
  R25R24 = CONCAT11((byte)R17R16 + CARRY1(bVar1,R17R16._1_1_),bVar1 + R17R16._1_1_);
  R17R16 = R25R24;
  while ((byte)Y != (byte)R17R16 || Y._1_1_ != (byte)(R17R16._1_1_ + ((byte)Y < (byte)R17R16))) {
    Y = Y + 1;
    twi_send_byte_bounded();
  }
  Y = uVar3;
  R17R16 = uVar2;
  twi_stop();
  return;
}


/* BYTE0x0a2e; WORDcode:0517; oled_send_pixel_data */

void oled_send_pixel_data(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  uVar3 = Y;
  uVar2 = R17R16;
  uVar1 = R15R14;
  R1 = 0;
  R15R14 = R25R24;
  R17R16 = R23R22;
  twi_start_address_bounded();
  twi_send_byte_bounded();
  Y = R15R14;
  R17R16._1_1_ = R17R16._1_1_ + R15R14._1_1_ + CARRY1((byte)R17R16,(byte)R15R14);
  R17R16._0_1_ = (byte)R17R16 + (byte)R15R14;
  while ((byte)Y != (byte)R17R16 || Y._1_1_ != (char)(R17R16._1_1_ + ((byte)Y < (byte)R17R16))) {
    Y = Y + 1;
    twi_send_byte_bounded();
  }
  Y = uVar3;
  R15R14 = uVar1;
  R17R16 = uVar2;
  twi_stop();
  return;
}


/* BYTE0x0a6e; WORDcode:0537; oled_set_text_cursor */

void oled_set_text_cursor(void)

{
  undefined1 uVar1;
  undefined2 uStack_7;
  undefined2 uStack_5;
  undefined2 uStack_3;
  undefined1 uStack_1;
  
  R1 = 0;
  uVar1 = (undefined1)Y;
  uStack_1 = Y._1_1_;
  uStack_3 = 0x53a;
  uStack_5 = 0x53b;
  Y = CONCAT11((char)((uint)((int)&uStack_7 + 1) >> 8),(char)&uStack_7 + '\x01');
  if (((byte)R25R24 < 0x16) && (R22 < 8)) {
    DAT_mem_0351 = (byte)R25R24 * '\x06';
    DAT_mem_0352 = R22;
    R25R24._0_1_ = DAT_mem_0351;
    *(byte *)(Y + 1) = R22 + 0xb0;
    *(undefined1 *)(Y + 2) = 0x21;
    *(byte *)(Y + 3) = (byte)R25R24;
    *(undefined1 *)(Y + 4) = 0x7f;
    uStack_7 = 0x555;
    oled_send_commands();
  }
  R0 = uStack_3._1_1_;
  Y = CONCAT11(uStack_1,uVar1);
  return;
}


/* BYTE0x0ab8; WORDcode:055c; oled_reset_cursor */

void oled_reset_cursor(void)

{
  undefined1 uVar1;
  undefined2 uStack_7;
  undefined1 *puStack_5;
  undefined2 uStack_3;
  undefined1 uStack_1;
  
  R1 = 0;
  uVar1 = (undefined1)Y;
  uStack_1 = Y._1_1_;
  uStack_3 = 0x55f;
  puStack_5 = &DAT_mem_0560;
  Y = CONCAT11((char)((uint)((int)&uStack_7 + 1) >> 8),(char)&uStack_7 + '\x01');
  Z = &DAT_mem_0351;
  DAT_mem_0351 = 0;
  DAT_mem_0352 = 0;
  *(undefined1 *)(Y + 1) = 0xb0;
  *(undefined1 *)(Y + 2) = 0x21;
  *(undefined1 *)(Y + 3) = R1;
  *(undefined1 *)(Y + 4) = 0x7f;
  uStack_7 = 0x572;
  oled_send_commands();
  R0 = uStack_3._1_1_;
  Y = CONCAT11(uStack_1,uVar1);
  return;
}


/* BYTE0x0af2; WORDcode:0579; oled_clear */

void oled_clear(void)

{
  char cVar1;
  char cVar2;
  undefined1 *puVar3;
  byte bVar6;
  int iVar4;
  int iVar5;
  bool bVar7;
  bool bVar8;
  char in_Hflg;
  char cVar9;
  char in_Tflg;
  char cVar10;
  char in_Iflg;
  char cVar11;
  undefined1 uStack_5;
  undefined1 uStack_4;
  undefined1 uStack_3;
  
  R1 = 0;
  uStack_3 = (byte)Y;
  uStack_4 = Y._1_1_;
  bVar6 = (byte)((uint)&uStack_5 >> 8);
  cVar1 = (byte)&uStack_5 + 0x80;
  bVar7 = (byte)&uStack_5 < 0x80;
  cVar2 = bVar6 - bVar7;
  Y = CONCAT11(cVar2,cVar1);
  cVar9 = in_Hflg == '\x01';
  cVar10 = in_Tflg == '\x01';
  cVar11 = in_Iflg == '\x01';
  R0 = bVar6 < bVar7 | (cVar1 == '\0' && cVar2 == '\0') << 1 | (cVar2 < '\0') << 2 |
       SBORROW1(bVar6,bVar7) << 3 | ((char)bVar6 < bVar7) << 4 | cVar9 << 5 | cVar10 << 6 |
       cVar11 << 7;
  SREG = R0;
  SREG = R0;
  iVar4 = CONCAT11(cVar2,cVar1);
  R25R24 = (undefined1 *)(Y + 1);
  R15R14 = R25R24;
  Z = R25R24;
  R25R24._0_1_ = -0x80;
  do {
    puVar3 = Z;
    Z = Z + 1;
    *puVar3 = R1;
    R25R24._0_1_ = (char)R25R24 + -1;
  } while ((char)R25R24 != '\0');
  R17 = '\0';
  do {
    *(undefined2 *)(iVar4 + -1) = 0x594;
    oled_set_text_cursor();
    *(undefined2 *)(iVar4 + -1) = 0x599;
    oled_send_pixel_data();
    bVar7 = R17 != '\a';
    R17 = R17 + '\x01';
  } while (bVar7);
  *(undefined2 *)(iVar4 + -1) = 0x59e;
  oled_reset_cursor();
  bVar7 = (byte)Y < 0x80;
  cVar1 = Y._1_1_ - (bVar7 + -1);
  bVar8 = SBORROW1(Y._1_1_,-1) != SBORROW1(Y._1_1_ + 1U,bVar7);
  R0 = (Y._1_1_ != -1 || (byte)(Y._1_1_ + 1U) < bVar7) |
       ((byte)((byte)Y + 0x80) == '\0' && cVar1 == '\0') << 1 | (cVar1 < '\0') << 2 | bVar8 << 3 |
       (cVar1 < '\0' != bVar8) << 4 | (cVar9 == '\x01') << 5 | (cVar10 == '\x01') << 6 |
       (cVar11 == '\x01') << 7;
  SREG = R0;
  SREG = R0;
  iVar5 = CONCAT11(cVar1,(byte)Y + 0x80);
  Y._1_1_ = *(undefined1 *)(iVar5 + 1);
  Y._0_1_ = *(undefined1 *)(iVar5 + 2);
  R17 = *(undefined1 *)(iVar5 + 3);
  R15R14._1_1_ = *(undefined1 *)(iVar5 + 4);
  R15R14._0_1_ = *(undefined1 *)(iVar5 + 5);
  return;
}


/* BYTE0x0b56; WORDcode:05ab; oled_init_ssd1306_family */

void oled_init_ssd1306_family(void)

{
  uint uVar1;
  undefined1 *puVar2;
  char in_Hflg;
  char cVar3;
  char in_Tflg;
  char cVar4;
  char in_Iflg;
  char cVar5;
  undefined1 uStack_3;
  undefined1 uStack_2;
  undefined1 uStack_1;
  
  R1 = 0;
  uStack_1 = (undefined1)Y;
  uStack_2 = Y._1_1_;
  uVar1 = CONCAT11((char)((uint)&uStack_3 >> 8),(char)&uStack_3);
  Y = uVar1 - 0x1c;
  cVar3 = in_Hflg == '\x01';
  cVar4 = in_Tflg == '\x01';
  cVar5 = in_Iflg == '\x01';
  R0 = uVar1 < 0x1c | (Y == 0) << 1 | ((int)Y < 0) << 2 | SBORROW2(uVar1,0x1c) << 3 |
       ((int)uVar1 < 0x1c) << 4 | cVar3 << 5 | cVar4 << 6 | cVar5 << 7;
  SREG = R0;
  SREG = R0;
  R17 = (undefined1)R25R24;
  *(undefined2 *)(uVar1 - 0x1d) = 0x5b9;
  twi_init();
  Z = &DAT_codebyte_041c;
  X = (undefined1 *)(Y + 1);
  R19R18._0_1_ = (byte)Y;
  R19R18._1_1_ = (char)(Y >> 8);
  R19R18._1_1_ = R19R18._1_1_ - (((byte)R19R18 < 0xe4) + -1);
  R19R18._0_1_ = (byte)R19R18 + 0x1c;
  do {
    puVar2 = X;
    R20 = *Z;
    X = X + 1;
    *puVar2 = R20;
    Z = Z + 1;
  } while ((byte)X != (byte)R19R18 || X._1_1_ != (char)(R19R18._1_1_ + ((byte)X < (byte)R19R18)));
  *(undefined1 *)(Y + 0x1c) = R17;
  *(undefined2 *)(uVar1 - 0x1d) = 0x5cb;
  oled_send_commands();
  *(undefined2 *)(uVar1 - 0x1d) = 0x5cd;
  uVar1 = Y;
  oled_clear();
  Y = Y + 0x1c;
  R0 = 0xffe3 < uVar1 | (uVar1 == 0xffe4) << 1 | ((int)Y < 0) << 2 | SCARRY2(Y,0x1c) << 3 |
       ((int)Y < 0 != SCARRY2(Y,0x1c)) << 4 | (cVar3 == '\x01') << 5 | (cVar4 == '\x01') << 6 |
       (cVar5 == '\x01') << 7;
  SREG = R0;
  SREG = R0;
  Y._1_1_ = *(undefined1 *)(uVar1 + 0x1d);
  Y._0_1_ = *(undefined1 *)(uVar1 + 0x1e);
  R17 = *(undefined1 *)(uVar1 + 0x1f);
  return;
}


/* BYTE0x0bae; WORDcode:05d7; oled_set_inverse */

void oled_set_inverse(void)

{
  undefined2 uStack_5;
  undefined1 uStack_3;
  undefined1 uStack_2;
  undefined1 uStack_1;
  
  R1 = 0;
  uStack_1 = (undefined1)Y;
  uStack_2 = Y._1_1_;
  uStack_3 = 0;
  uStack_5 = 0x5e1;
  twi_start_address_bounded();
  if ((char)R25R24 == '\x01') {
    R25R24._0_1_ = 0xa7;
  }
  else {
    R25R24._0_1_ = 0xa6;
  }
  *(char *)(CONCAT11((char)((uint)((int)&uStack_5 + 1) >> 8),(char)&uStack_5 + '\x01') + 1) =
       (char)R25R24;
  uStack_5 = 0x5ec;
  oled_send_commands();
  R0 = uStack_3;
  Y = CONCAT11(uStack_2,uStack_1);
  return;
}


/* BYTE0x0be2; WORDcode:05f1; oled_set_enabled */

void oled_set_enabled(void)

{
  undefined2 uStack_5;
  undefined1 uStack_3;
  undefined1 uStack_2;
  undefined1 uStack_1;
  
  R1 = 0;
  uStack_1 = (undefined1)Y;
  uStack_2 = Y._1_1_;
  uStack_3 = 0;
  uStack_5 = 0x5fb;
  twi_start_address_bounded();
  if ((char)R25R24 == '\x01') {
    R25R24._0_1_ = 0xae;
  }
  else {
    R25R24._0_1_ = 0xaf;
  }
  *(char *)(CONCAT11((char)((uint)((int)&uStack_5 + 1) >> 8),(char)&uStack_5 + '\x01') + 1) =
       (char)R25R24;
  uStack_5 = 0x606;
  oled_send_commands();
  R0 = uStack_3;
  Y = CONCAT11(uStack_2,uStack_1);
  return;
}


/* BYTE0x0c16; WORDcode:060b; oled_set_contrast */

void oled_set_contrast(void)

{
  undefined1 uVar1;
  undefined2 uStack_5;
  undefined2 uStack_3;
  undefined1 uStack_1;
  
  R1 = 0;
  uVar1 = (undefined1)Y;
  uStack_1 = Y._1_1_;
  uStack_3 = 0x60e;
  Y = CONCAT11((char)((uint)((int)&uStack_5 + 1) >> 8),(char)&uStack_5 + '\x01');
  *(undefined1 *)(Y + 1) = 0x81;
  *(undefined1 *)(Y + 2) = (undefined1)R25R24;
  uStack_5 = 0x618;
  oled_send_commands();
  R0 = uStack_3._1_1_;
  Y = CONCAT11(uStack_1,uVar1);
  return;
}


/* BYTE0x0c3a; WORDcode:061d; oled_render_character */

void oled_render_character(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  byte bVar5;
  byte *pbVar6;
  bool bVar7;
  char in_Hflg;
  char cVar8;
  char in_Tflg;
  char cVar9;
  char in_Iflg;
  char cVar10;
  undefined1 uStack_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  undefined1 uStack_4;
  undefined1 uStack_3;
  undefined1 uStack_2;
  undefined1 uStack_1;
  
  uStack_1 = R9R8._1_1_;
  uStack_2 = (byte)R11R10;
  uStack_3 = R11R10._1_1_;
  uStack_4 = (byte)R13R12;
  uStack_5 = R13R12._1_1_;
  uStack_6 = (byte)R15R14;
  uStack_7 = R15R14._1_1_;
  uStack_8 = (byte)R17R16;
  uStack_9 = R17R16._1_1_;
  uStack_a = (undefined1)Y;
  uStack_b = Y._1_1_;
  uVar4 = CONCAT11((char)((uint)&uStack_c >> 8),(char)&uStack_c);
  Y = uVar4 - 0x10;
  cVar8 = in_Hflg == '\x01';
  cVar9 = in_Tflg == '\x01';
  cVar10 = in_Iflg == '\x01';
  R1R0._0_1_ = uVar4 < 0x10 | (Y == 0) << 1 | ((int)Y < 0) << 2 | SBORROW2(uVar4,0x10) << 3 |
               ((int)uVar4 < 0x10) << 4 | cVar8 << 5 | cVar9 << 6 | cVar10 << 7;
  bVar1 = (byte)R1R0;
  R1R0 = (uint)(byte)R1R0;
  SREG = bVar1;
  SREG = bVar1;
  if ((byte)R25R24 == 9) {
    R1R0 = (uint)DAT_mem_0102 * 4;
    R1R0 = R1R0 & 0xff;
  }
  else if ((byte)R25R24 < 9) {
    if ((byte)R25R24 != 8) {
LAB_code_067c:
      R25R24 = (byte *)CONCAT11(DAT_mem_0351,(byte)R25R24);
      if ((DAT_mem_0351 < 0x7a) && (0x1f < (byte)R25R24)) {
        bVar1 = (byte)R25R24 - 0x20;
        R25R24 = (byte *)(uint)bVar1;
        Z = (byte *)(uint)DAT_codebyte_0199;
        if (bVar1 < DAT_codebyte_0199) {
LAB_code_06a9:
          Z = (byte *)CONCAT11(6,(byte)Z);
          R1R0 = ((uint)R25R24 & 0xff) * 6;
          R17R16 = R1R0;
          R1R0 = R1R0 & 0xff;
          if (DAT_mem_0102 == 2) {
            R25R24 = (byte *)(uVar4 - 0xf);
            R15R14 = R25R24;
            X = R25R24;
            R19R18._0_1_ = 0;
            R19R18._1_1_ = '\0';
            R13R12 = (byte *)0x1;
            do {
              X = X + 1;
              *X = R1R0._1_1_;
              X = X + -1;
              *X = R1R0._1_1_;
              Z._0_1_ = (byte)R17R16;
              Z._1_1_ = (byte)(R17R16 >> 8);
              cVar3 = (Z._1_1_ + R19R18._1_1_ + CARRY1((byte)Z,(byte)R19R18)) -
                      (((byte)((byte)Z + (byte)R19R18) < 0x54) + -2);
              Z = (byte *)CONCAT11(cVar3,(byte)Z + (byte)R19R18 + 0xac);
              Z._0_1_ = *Z;
              Z = (byte *)CONCAT11(cVar3,(byte)Z);
              R21R20._0_1_ = '\x01';
              R25R24 = (byte *)0x0;
              R11R10._0_1_ = (byte)Z;
              R11R10._1_1_ = R1R0._1_1_;
              do {
                pbVar6 = X;
                R23R22._0_1_ = (byte)R11R10;
                R23R22._1_1_ = R11R10._1_1_;
                R1R0 = CONCAT11(R1R0._1_1_,(byte)R25R24);
                while( true ) {
                  cVar3 = R23R22._1_1_;
                  R1R0._0_1_ = (byte)R1R0 + -1;
                  if ((char)(byte)R1R0 < '\0') break;
                  R23R22._1_1_ = (char)R23R22._1_1_ >> 1;
                  R23R22._0_1_ = cVar3 << 7 | (byte)R23R22 >> 1;
                }
                if (((byte)R23R22 & 1) != 0) {
                  X = X + 1;
                  Z._0_1_ = *pbVar6;
                  Z._1_1_ = *X;
                  R23R22 = R13R12;
                  R1R0 = CONCAT11(R1R0._1_1_,(char)R21R20);
                  while( true ) {
                    R1R0._0_1_ = (byte)R1R0 + -1;
                    if ((char)(byte)R1R0 < '\0') break;
                    R23R22 = CONCAT11(R23R22._1_1_ * '\x02' + CARRY1((byte)R23R22,(byte)R23R22),
                                      (byte)R23R22 * '\x02');
                  }
                  Z._0_1_ = (byte)Z | (byte)R23R22;
                  Z._1_1_ = Z._1_1_ | R23R22._1_1_;
                  R23R22._0_1_ = (byte)R25R24 * '\x02';
                  R9R8 = R13R12;
                  while( true ) {
                    R23R22._0_1_ = (byte)R23R22 + -1;
                    if ((char)(byte)R23R22 < '\0') break;
                    R9R8 = CONCAT11(R9R8._1_1_ * '\x02' + CARRY1((byte)R9R8,(byte)R9R8),
                                    (byte)R9R8 * '\x02');
                  }
                  R23R22._0_1_ = (byte)R9R8 | (byte)Z;
                  R23R22._1_1_ = R9R8._1_1_ | Z._1_1_;
                  X = pbVar6 + 1;
                  *X = R23R22._1_1_;
                  X = X + -1;
                  *X = (byte)R23R22;
                }
                R25R24 = (byte *)((int)R25R24 + 1);
                R21R20._0_1_ = (char)R21R20 + '\x02';
              } while ((byte)R25R24 != 8 || R25R24._1_1_ != (byte)(R1R0._1_1_ + ((byte)R25R24 < 8)))
              ;
              bVar1 = (byte)R19R18 + 1;
              R19R18._1_1_ = R19R18._1_1_ - (((byte)R19R18 != 0xff) + -1);
              X = X + 2;
              R19R18._0_1_ = bVar1;
            } while (bVar1 != 6 || R19R18._1_1_ != (byte)(R1R0._1_1_ + (bVar1 < 6)));
            *(undefined2 *)(uVar4 - 0x11) = 0x6fe;
            twi_start_address_bounded();
            *(undefined2 *)(uVar4 - 0x11) = 0x701;
            twi_send_byte_bounded();
            R17R16._0_1_ = (byte)Y;
            R17R16._1_1_ = (char)(Y >> 8);
            R17R16._1_1_ = R17R16._1_1_ - (((byte)R17R16 < 0xf3) + -1);
            R13R12 = R15R14;
            R17R16._0_1_ = (byte)R17R16 + 0xd;
            do {
              R11R10._1_1_ = *R13R12;
              Z._0_1_ = (byte)R13R12;
              Z = (byte *)CONCAT11(2,(byte)Z);
              R13R12 = (byte *)CONCAT11(R13R12._1_1_ + R1R0._1_1_ + (0xfd < (byte)Z),(byte)Z + 2);
              *(undefined2 *)(uVar4 - 0x11) = 0x70d;
              twi_send_byte_bounded();
              *(undefined2 *)(uVar4 - 0x11) = 0x710;
              twi_send_byte_bounded();
            } while ((byte)R17R16 != (byte)R13R12 ||
                     R17R16._1_1_ != (byte)(R13R12._1_1_ + ((byte)R17R16 < (byte)R13R12)));
            *(undefined2 *)(uVar4 - 0x11) = 0x715;
            twi_stop();
            *(byte *)(Y + 0xd) = DAT_mem_0352 + 0xb1;
            *(undefined1 *)(Y + 0xe) = 0x21;
            *(byte *)(Y + 0xf) = DAT_mem_0351;
            *(undefined1 *)(Y + 0x10) = 0x7f;
            *(undefined2 *)(uVar4 - 0x11) = 0x724;
            oled_send_commands();
            *(undefined2 *)(uVar4 - 0x11) = 0x727;
            twi_start_address_bounded();
            *(undefined2 *)(uVar4 - 0x11) = 0x72a;
            twi_send_byte_bounded();
            do {
              R13R12._1_1_ = R15R14[1];
              Z._0_1_ = (byte)R15R14;
              Z = (byte *)CONCAT11(2,(byte)Z);
              R15R14 = (byte *)CONCAT11(R15R14._1_1_ + R1R0._1_1_ + (0xfd < (byte)Z),(byte)Z + 2);
              *(undefined2 *)(uVar4 - 0x11) = 0x732;
              twi_send_byte_bounded();
              *(undefined2 *)(uVar4 - 0x11) = 0x735;
              twi_send_byte_bounded();
            } while ((byte)R17R16 != (byte)R15R14 ||
                     R17R16._1_1_ != (byte)(R15R14._1_1_ + ((byte)R17R16 < (byte)R15R14)));
            *(undefined2 *)(uVar4 - 0x11) = 0x73a;
            twi_stop();
            *(byte *)(Y + 0xd) = DAT_mem_0352 + 0xb0;
            *(byte *)(Y + 0xf) = DAT_mem_0351 + 0xc;
            *(undefined2 *)(uVar4 - 0x11) = 0x746;
            oled_send_commands();
            R25R24 = (byte *)CONCAT11(R25R24._1_1_,DAT_mem_0351 + 0xc);
          }
          else {
            *(undefined2 *)(uVar4 - 0x11) = 0x74d;
            twi_start_address_bounded();
            *(undefined2 *)(uVar4 - 0x11) = 0x750;
            twi_send_byte_bounded();
            R15R14._0_1_ = R1R0._1_1_;
            R15R14._1_1_ = R1R0._1_1_;
            do {
              Z._0_1_ = (byte)R17R16;
              Z._1_1_ = (byte)(R17R16 >> 8);
              Z = (byte *)CONCAT11((Z._1_1_ + R15R14._1_1_ + CARRY1((byte)Z,(byte)R15R14)) -
                                   (((byte)((byte)Z + (byte)R15R14) < 0x54) + -2),
                                   (byte)Z + (byte)R15R14 + 0xac);
              *(undefined2 *)(uVar4 - 0x11) = 0x75a;
              twi_send_byte_bounded();
              bVar1 = (byte)R15R14 + 1;
              R15R14._1_1_ = R15R14._1_1_ - (((byte)R15R14 != 0xff) + -1);
              R15R14._0_1_ = bVar1;
            } while (bVar1 != 6 || R15R14._1_1_ != (byte)(R1R0._1_1_ + (bVar1 < 6)));
            *(undefined2 *)(uVar4 - 0x11) = 0x763;
            twi_stop();
            R25R24 = (byte *)CONCAT11(R25R24._1_1_,DAT_mem_0351 + 6);
          }
          DAT_mem_0351 = (byte)R25R24;
        }
        else {
          bVar2 = 0;
          while( true ) {
            bVar5 = bVar2 * '\x02';
            bVar7 = CARRY1(bVar2,bVar2);
            R19R18 = CONCAT11(bVar7,bVar5);
            cVar3 = bVar7 - ((bVar5 < 0x67) + -2);
            R25R24 = (byte *)CONCAT11(cVar3,bVar5 + 0x99);
            Z = R25R24;
            R21R20._1_1_ = *R25R24;
            R21R20 = CONCAT11(R21R20._1_1_,bVar2);
            if (R21R20._1_1_ == -1) break;
            Z = (byte *)CONCAT11(bVar7 - ((bVar5 < 0x68) + -2),bVar5 + 0x98);
            Z._0_1_ = *Z;
            Z = (byte *)(uint)(byte)Z;
            Z = (byte *)((int)Z - 0x20);
            if (Z == (byte *)CONCAT11((byte)Z < bVar1,bVar1)) {
              Z = R25R24;
              R25R24._0_1_ = *R25R24;
              R25R24 = (byte *)CONCAT11(cVar3,(byte)R25R24);
              if ((byte)R25R24 != -1) goto LAB_code_06a9;
              break;
            }
            bVar2 = bVar2 + 1;
          }
        }
      }
      goto LAB_code_0768;
    }
    *(undefined2 *)(uVar4 - 0x11) = 0x640;
    oled_set_text_cursor();
    *(undefined2 *)(uVar4 - 0x11) = 0x643;
    oled_render_character();
  }
  else if ((byte)R25R24 == 10) {
    R23R22 = CONCAT11(R23R22._1_1_,DAT_mem_0352);
    if (6 < DAT_mem_0352) goto LAB_code_0768;
  }
  else if ((byte)R25R24 != 0xd) goto LAB_code_067c;
  *(undefined2 *)(uVar4 - 0x11) = 0x66c;
  oled_set_text_cursor();
LAB_code_0768:
  uVar4 = Y;
  Y = Y + 0x10;
  R1R0._0_1_ = 0xffef < uVar4 | (uVar4 == 0xfff0) << 1 | ((int)Y < 0) << 2 | SCARRY2(Y,0x10) << 3 |
               ((int)Y < 0 != SCARRY2(Y,0x10)) << 4 | (cVar8 == '\x01') << 5 |
               (cVar9 == '\x01') << 6 | (cVar10 == '\x01') << 7;
  SREG = (byte)R1R0;
  SREG = (byte)R1R0;
  Y._1_1_ = *(undefined1 *)(uVar4 + 0x11);
  Y._0_1_ = *(undefined1 *)(uVar4 + 0x12);
  R17R16._1_1_ = *(undefined1 *)(uVar4 + 0x13);
  R17R16._0_1_ = *(undefined1 *)(uVar4 + 0x14);
  R15R14._1_1_ = *(undefined1 *)(uVar4 + 0x15);
  R15R14._0_1_ = *(undefined1 *)(uVar4 + 0x16);
  R13R12._1_1_ = *(undefined1 *)(uVar4 + 0x17);
  R13R12._0_1_ = *(undefined1 *)(uVar4 + 0x18);
  R11R10._1_1_ = *(undefined1 *)(uVar4 + 0x19);
  R11R10._0_1_ = *(undefined1 *)(uVar4 + 0x1a);
  R9R8._1_1_ = *(undefined1 *)(uVar4 + 0x1b);
  R9R8._0_1_ = *(undefined1 *)(uVar4 + 0x1c);
  return;
}


/* BYTE0x0ef6; WORDcode:077b; oled_set_scale */

void oled_set_scale(undefined1 param_1,undefined1 R24)

{
  R1 = 0;
  DAT_mem_0102 = R24;
  return;
}


/* BYTE0x0efc; WORDcode:077e; oled_print_ram_string */

void oled_print_ram_string(void)

{
  undefined2 uVar1;
  char *pcVar2;
  
  uVar1 = Y;
  R1 = 0;
  Y = R25R24;
  while( true ) {
    pcVar2 = Y;
    Y = Y + 1;
    R25R24._0_1_ = *pcVar2;
    if ((char)R25R24 == '\0') break;
    oled_render_character();
    R25R24 = (char *)((uint)R25R24._1_1_ << 8);
  }
  Y = (char *)uVar1;
  return;
}


/* BYTE0x0f14; WORDcode:078a; oled_print_flash_string */

void oled_print_flash_string(void)

{
  undefined2 uVar1;
  
  uVar1 = Y;
  R1 = 0;
  Z = R25R24;
  while( true ) {
    R25R24._0_1_ = *Z;
    Y = Z + 1;
    if ((char)R25R24 == '\0') break;
    oled_render_character();
    R25R24 = (char *)((uint)R25R24._1_1_ << 8);
    Z = Y;
  }
  Y = (char *)uVar1;
  return;
}


/* BYTE0x0f32; WORDcode:0799; isr_PCINT0 */

void isr_PCINT0(void)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  char in_Cflg;
  char in_Zflg;
  char in_Nflg;
  char in_Vflg;
  char in_Sflg;
  char in_Hflg;
  char in_Tflg;
  
  uVar3 = R25R24;
  uVar2 = R0;
  R0 = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
       (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | (in_Hflg == '\x01') << 5 |
       (in_Tflg == '\x01') << 6 | 0x80;
  SREG = R0;
  R25R24._0_1_ = PINA;
  R25R24._0_1_ = DAT_mem_0482 ^ (byte)R25R24;
  DAT_mem_0482 = PINA;
  if (((byte)R25R24 & 1) != 0) {
    tach_edge_counts[2]._1_1_ = tach_edge_counts[2]._1_1_ - (((char)tach_edge_counts[2] != -1) + -1)
    ;
    tach_edge_counts[2]._0_1_ = (char)tach_edge_counts[2] + '\x01';
  }
  if (((byte)R25R24 & 2) != 0) {
    tach_edge_counts[3]._1_1_ = tach_edge_counts[3]._1_1_ - (((char)tach_edge_counts[3] != -1) + -1)
    ;
    tach_edge_counts[3]._0_1_ = (char)tach_edge_counts[3] + '\x01';
  }
  if (((byte)R25R24 & 4) != 0) {
    tach_edge_counts[0]._1_1_ = tach_edge_counts[0]._1_1_ - (((char)tach_edge_counts[0] != -1) + -1)
    ;
    tach_edge_counts[0]._0_1_ = (char)tach_edge_counts[0] + '\x01';
  }
  bVar1 = (byte)R25R24 & 8;
  R25R24 = tach_edge_counts[1];
  if (bVar1 != 0) {
    R25R24 = tach_edge_counts[1] + 1;
  }
  tach_edge_counts[1]._1_1_ = (undefined1)(R25R24 >> 8);
  tach_edge_counts[1]._0_1_ = (undefined1)R25R24;
  R25R24 = uVar3;
  SREG = R0;
  R0 = uVar2;
  R1 = 0;
  return;
}


/* BYTE0x0fc4; WORDcode:07e2; isr_PCINT1 */

void isr_PCINT1(void)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  char in_Cflg;
  char in_Zflg;
  char in_Nflg;
  char in_Vflg;
  char in_Sflg;
  char in_Hflg;
  char in_Tflg;
  
  uVar3 = R25R24;
  uVar2 = R0;
  R0 = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
       (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | (in_Hflg == '\x01') << 5 |
       (in_Tflg == '\x01') << 6 | 0x80;
  SREG = R0;
  R25R24._0_1_ = PINB;
  R25R24._0_1_ = DAT_mem_0481 ^ (byte)R25R24;
  DAT_mem_0481 = PINB;
  if (((byte)R25R24 & 1) != 0) {
    tach_edge_counts[7]._1_1_ = tach_edge_counts[7]._1_1_ - (((char)tach_edge_counts[7] != -1) + -1)
    ;
    tach_edge_counts[7]._0_1_ = (char)tach_edge_counts[7] + '\x01';
  }
  if (((byte)R25R24 & 2) != 0) {
    tach_edge_counts[6]._1_1_ = tach_edge_counts[6]._1_1_ - (((char)tach_edge_counts[6] != -1) + -1)
    ;
    tach_edge_counts[6]._0_1_ = (char)tach_edge_counts[6] + '\x01';
  }
  if (((byte)R25R24 & 4) != 0) {
    tach_edge_counts[9]._1_1_ = tach_edge_counts[9]._1_1_ - (((char)tach_edge_counts[9] != -1) + -1)
    ;
    tach_edge_counts[9]._0_1_ = (char)tach_edge_counts[9] + '\x01';
  }
  if (((byte)R25R24 & 0x20) != 0) {
    tach_edge_counts[10]._1_1_ =
         tach_edge_counts[10]._1_1_ - (((char)tach_edge_counts[10] != -1) + -1);
    tach_edge_counts[10]._0_1_ = (char)tach_edge_counts[10] + '\x01';
  }
  bVar1 = (byte)R25R24 & 0x40;
  R25R24 = tach_edge_counts[0xb];
  if (bVar1 != 0) {
    R25R24 = tach_edge_counts[0xb] + 1;
  }
  tach_edge_counts[0xb]._1_1_ = (undefined1)(R25R24 >> 8);
  tach_edge_counts[0xb]._0_1_ = (undefined1)R25R24;
  R25R24 = uVar3;
  SREG = R0;
  R0 = uVar2;
  R1 = 0;
  return;
}


/* BYTE0x106e; WORDcode:0837; isr_PCINT3 */

void isr_PCINT3(void)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  char in_Cflg;
  char in_Zflg;
  char in_Nflg;
  char in_Vflg;
  char in_Sflg;
  char in_Hflg;
  char in_Tflg;
  
  uVar3 = R25R24;
  uVar2 = R0;
  R0 = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
       (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | (in_Hflg == '\x01') << 5 |
       (in_Tflg == '\x01') << 6 | 0x80;
  SREG = R0;
  R25R24._0_1_ = PIND;
  R25R24._0_1_ = DAT_mem_0480 ^ (byte)R25R24;
  DAT_mem_0480 = PIND;
  bVar1 = (byte)R25R24 & 1;
  R25R24 = tach_edge_counts[8];
  if (bVar1 != 0) {
    R25R24 = tach_edge_counts[8] + 1;
  }
  tach_edge_counts[8]._1_1_ = (undefined1)(R25R24 >> 8);
  tach_edge_counts[8]._0_1_ = (undefined1)R25R24;
  R25R24 = uVar3;
  SREG = R0;
  R0 = uVar2;
  R1 = 0;
  return;
}


/* BYTE0x10b0; WORDcode:0858; isr_PCINT4 */

void isr_PCINT4(void)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  char in_Cflg;
  char in_Zflg;
  char in_Nflg;
  char in_Vflg;
  char in_Sflg;
  char in_Hflg;
  char in_Tflg;
  
  uVar3 = R25R24;
  uVar2 = R0;
  R0 = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
       (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | (in_Hflg == '\x01') << 5 |
       (in_Tflg == '\x01') << 6 | 0x80;
  SREG = R0;
  R25R24._0_1_ = PINE;
  R25R24._0_1_ = DAT_mem_047f ^ (byte)R25R24;
  DAT_mem_047f = PINE;
  if (((byte)R25R24 & 0x20) != 0) {
    tach_edge_counts[5]._1_1_ = tach_edge_counts[5]._1_1_ - (((char)tach_edge_counts[5] != -1) + -1)
    ;
    tach_edge_counts[5]._0_1_ = (char)tach_edge_counts[5] + '\x01';
  }
  bVar1 = (byte)R25R24 & 0x40;
  R25R24 = tach_edge_counts[4];
  if (bVar1 != 0) {
    R25R24 = tach_edge_counts[4] + 1;
  }
  tach_edge_counts[4]._1_1_ = (undefined1)(R25R24 >> 8);
  tach_edge_counts[4]._0_1_ = (undefined1)R25R24;
  R25R24 = uVar3;
  SREG = R0;
  R0 = uVar2;
  R1 = 0;
  return;
}


/* BYTE0x1112; WORDcode:0889; isr_TIMER3_CAPT */

/* WARNING: Restarted to delay deadcode elimination for space: mem */

void isr_TIMER3_CAPT(char R23,byte R22)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined2 uVar5;
  byte bVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  ushort *puVar11;
  ushort *puVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  undefined2 uVar17;
  ushort *puVar18;
  ushort *puVar19;
  char *pcVar20;
  undefined2 uVar21;
  ushort *puVar22;
  undefined1 *puVar23;
  char in_Cflg;
  char in_Zflg;
  char in_Nflg;
  char in_Vflg;
  char in_Sflg;
  char in_Hflg;
  char in_Tflg;
  
  puVar22 = Z;
  uVar21 = Y;
  puVar18 = X;
  uVar17 = R25R24;
  uVar16 = R23;
  uVar15 = R22;
  uVar14 = R21R20;
  uVar13 = R19R18;
  puVar12 = R17R16;
  puVar11 = R15R14;
  uVar10 = R13R12;
  uVar9 = R11R10;
  uVar8 = R9R8;
  uVar7 = R7R6;
  uVar5 = R5R4;
  bVar3 = (byte)R1R0;
  R1R0._0_1_ = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
               (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | (in_Hflg == '\x01') << 5 |
               (in_Tflg == '\x01') << 6 | 0x80;
  bVar4 = (byte)R1R0;
  SREG = (byte)R1R0;
  R1R0 = (uint)(byte)R1R0;
  OCR3A._1_1_ = 0x2d;
  OCR3A._0_1_ = 199;
  OCR3B._1_1_ = 4;
  OCR3B._0_1_ = 0x4b;
  if ((byte)(calibration_ticks_remaining - 1) < 5) {
    if (calibration_ticks_remaining == 1) {
      R15R14 = tach_results;
      R17R16 = tach_edge_counts;
      Y = 0x14;
      do {
        R22 = (byte)*R17R16;
        R23 = *(undefined1 *)((int)R17R16 + 1);
        Z = (ushort *)((int)R15R14 + 1);
        *(byte *)R15R14 = R22;
        puVar23 = (undefined1 *)Z;
        Z = (ushort *)((int)Z + 1);
        *puVar23 = R23;
        R15R14 = Z;
        eeprom_update_word();
        Z = (ushort *)((int)R17R16 + 1);
        *(byte *)R17R16 = R1R0._1_1_;
        puVar23 = (undefined1 *)Z;
        Z = (ushort *)((int)Z + 1);
        *puVar23 = R1R0._1_1_;
        R17R16 = Z;
        Y = Y + 2;
      } while ((byte)Y != 0x38 || Y._1_1_ != (byte)(R1R0._1_1_ + ((byte)Y < 0x38)));
    }
  }
  else {
    X = tach_results;
    Z = tach_edge_counts;
    R22 = 5;
    do {
      puVar19 = X;
      R21R20._0_1_ = (byte)*Z;
      R21R20._1_1_ = *(char *)((int)Z + 1);
      R1R0 = (uint)R22 * (uint)(byte)R21R20;
      R19R18._1_1_ = (byte)(R1R0 >> 8);
      R19R18._1_1_ = R19R18._1_1_ + R22 * R21R20._1_1_;
      R19R18._0_1_ = (byte)R1R0;
      R1R0 = (uint)(byte)(R22 * R21R20._1_1_);
      X = (ushort *)((int)X + 1);
      *(byte *)puVar19 = (byte)R19R18;
      pcVar20 = (char *)X;
      X = (ushort *)((int)X + 1);
      *pcVar20 = R19R18._1_1_;
      puVar19 = Z;
      Z = (ushort *)((int)Z + 1);
      *(byte *)puVar19 = R1R0._1_1_;
      puVar23 = (undefined1 *)Z;
      Z = (ushort *)((int)Z + 1);
      *puVar23 = R1R0._1_1_;
    } while ((byte)Z != 5 || (char)(Z._1_1_ + (5 < (byte)Z)) != '\x05');
  }
  if (calibration_ticks_remaining != 0) {
    calibration_ticks_remaining = calibration_ticks_remaining - 1;
  }
  avr_unsigned_divide_32bit(DAT_mem_0522,DAT_mem_0521,DAT_mem_0520,DAT_mem_051f);
  R5R4._0_1_ = (byte)R19R18;
  R5R4._1_1_ = R19R18._1_1_;
  R7R6._0_1_ = (byte)R21R20;
  R7R6._1_1_ = R21R20._1_1_;
  avr_unsigned_divide_32bit(DAT_mem_0526,DAT_mem_0525,DAT_mem_0524,DAT_mem_0523);
  R9R8._0_1_ = (byte)R19R18;
  R9R8._1_1_ = R19R18._1_1_;
  R11R10._0_1_ = (byte)R21R20;
  R11R10._1_1_ = R21R20._1_1_;
  avr_unsigned_divide_32bit(DAT_mem_052a,DAT_mem_0529,DAT_mem_0528,DAT_mem_0527);
  R13R12._0_1_ = (byte)R19R18;
  R13R12._1_1_ = R19R18._1_1_;
  R15R14._0_1_ = (byte)R21R20;
  R15R14._1_1_ = R21R20._1_1_;
  avr_unsigned_divide_32bit(DAT_mem_052e,DAT_mem_052d,DAT_mem_052c,DAT_mem_052b);
  voltage_samples[0]._1_1_ = R5R4._1_1_;
  voltage_samples[0]._0_1_ = (byte)R5R4;
  voltage_samples[1]._1_1_ = R9R8._1_1_;
  voltage_samples[1]._0_1_ = (byte)R9R8;
  voltage_samples[2]._1_1_ = R13R12._1_1_;
  voltage_samples[2]._0_1_ = (byte)R13R12;
  voltage_samples[3]._1_1_ = R19R18._1_1_;
  voltage_samples[3]._0_1_ = (byte)R19R18;
  R25R24._0_1_ = '\x02';
  do {
    bVar1 = R7R6._1_1_;
    bVar2 = (byte)R7R6;
    bVar6 = R5R4._1_1_;
    R7R6._1_1_ = R7R6._1_1_ >> 1;
    R7R6._0_1_ = bVar1 << 7 | (byte)R7R6 >> 1;
    bVar1 = R5R4._1_1_ >> 1;
    R5R4._1_1_ = bVar2 << 7 | bVar1;
    bVar2 = (byte)R5R4 >> 1;
    R5R4._0_1_ = bVar6 << 7 | bVar2;
    R25R24._0_1_ = (byte)R25R24 + -1;
  } while ((byte)R25R24 != '\0');
  bVar2 = bVar2 * '\x02';
  Z = (ushort *)
      CONCAT11((bVar1 * '\x02' + CARRY1((byte)R5R4,(byte)R5R4)) - ((bVar2 < 0xfd) + -2),bVar2 + 3);
  R25R24._0_1_ = *(byte *)Z;
  R25R24._1_1_ = *(undefined1 *)((int)Z + 1);
  temperature_samples[0]._1_1_ = R25R24._1_1_;
  temperature_samples[0]._0_1_ = (byte)R25R24;
  R23 = '\x02';
  do {
    bVar1 = R11R10._1_1_;
    bVar2 = (byte)R11R10;
    bVar6 = R9R8._1_1_;
    R11R10._1_1_ = R11R10._1_1_ >> 1;
    R11R10._0_1_ = bVar1 << 7 | (byte)R11R10 >> 1;
    bVar1 = R9R8._1_1_ >> 1;
    R9R8._1_1_ = bVar2 << 7 | bVar1;
    bVar2 = (byte)R9R8 >> 1;
    R9R8._0_1_ = bVar6 << 7 | bVar2;
    R23 = R23 + -1;
  } while (R23 != '\0');
  bVar2 = bVar2 * '\x02';
  Z = (ushort *)
      CONCAT11((bVar1 * '\x02' + CARRY1((byte)R9R8,(byte)R9R8)) - ((bVar2 < 0xfd) + -2),bVar2 + 3);
  R25R24._0_1_ = *(byte *)Z;
  R25R24._1_1_ = *(undefined1 *)((int)Z + 1);
  temperature_samples[1]._1_1_ = R25R24._1_1_;
  temperature_samples[1]._0_1_ = (byte)R25R24;
  Z._1_1_ = '\x02';
  do {
    bVar1 = R15R14._1_1_;
    bVar2 = (byte)R15R14;
    bVar6 = R13R12._1_1_;
    R15R14._1_1_ = R15R14._1_1_ >> 1;
    R15R14._0_1_ = bVar1 << 7 | (byte)R15R14 >> 1;
    bVar1 = R13R12._1_1_ >> 1;
    R13R12._1_1_ = bVar2 << 7 | bVar1;
    bVar2 = (byte)R13R12 >> 1;
    R13R12._0_1_ = bVar6 << 7 | bVar2;
    Z._1_1_ = Z._1_1_ + -1;
  } while (Z._1_1_ != '\0');
  bVar2 = bVar2 * '\x02';
  Z = (ushort *)
      CONCAT11((bVar1 * '\x02' + CARRY1((byte)R13R12,(byte)R13R12)) - ((bVar2 < 0xfd) + -2),
               bVar2 + 3);
  R25R24._0_1_ = *(byte *)Z;
  R25R24._1_1_ = *(undefined1 *)((int)Z + 1);
  temperature_samples[2]._1_1_ = R25R24._1_1_;
  temperature_samples[2]._0_1_ = (byte)R25R24;
  X._0_1_ = (byte)R21R20;
  X._1_1_ = R21R20._1_1_;
  R25R24._0_1_ = (byte)R19R18;
  R25R24._1_1_ = R19R18._1_1_;
  Y._0_1_ = '\x02';
  do {
    bVar1 = X._1_1_;
    bVar2 = (byte)X;
    bVar6 = R25R24._1_1_;
    X._1_1_ = X._1_1_ >> 1;
    X._0_1_ = bVar1 << 7 | (byte)X >> 1;
    bVar1 = R25R24._1_1_ >> 1;
    R25R24._1_1_ = bVar2 << 7 | bVar1;
    bVar2 = (byte)R25R24 >> 1;
    R25R24._0_1_ = bVar6 << 7 | bVar2;
    Y._0_1_ = (byte)Y + -1;
  } while ((byte)Y != '\0');
  bVar2 = bVar2 * '\x02';
  Z = (ushort *)
      CONCAT11((bVar1 * '\x02' + CARRY1((byte)R25R24,(byte)R25R24)) - ((bVar2 < 0xfd) + -2),
               bVar2 + 3);
  R25R24._0_1_ = *(byte *)Z;
  R25R24._1_1_ = *(undefined1 *)((int)Z + 1);
  temperature_samples[3]._1_1_ = R25R24._1_1_;
  temperature_samples[3]._0_1_ = (byte)R25R24;
  DAT_mem_051f = R1R0._1_1_;
  DAT_mem_0520 = R1R0._1_1_;
  DAT_mem_0521 = R1R0._1_1_;
  DAT_mem_0522 = R1R0._1_1_;
  DAT_mem_0523 = R1R0._1_1_;
  DAT_mem_0524 = R1R0._1_1_;
  DAT_mem_0525 = R1R0._1_1_;
  DAT_mem_0526 = R1R0._1_1_;
  DAT_mem_0527 = R1R0._1_1_;
  DAT_mem_0528 = R1R0._1_1_;
  DAT_mem_0529 = R1R0._1_1_;
  DAT_mem_052a = R1R0._1_1_;
  DAT_mem_052b = R1R0._1_1_;
  DAT_mem_052c = R1R0._1_1_;
  DAT_mem_052d = R1R0._1_1_;
  DAT_mem_052e = R1R0._1_1_;
  DAT_mem_048b = R1R0._1_1_;
  DAT_mem_048c = R1R0._1_1_;
  DAT_mem_048d = R1R0._1_1_;
  DAT_mem_048e = R1R0._1_1_;
  DAT_mem_048f = R1R0._1_1_;
  DAT_mem_0490 = R1R0._1_1_;
  DAT_mem_0491 = R1R0._1_1_;
  DAT_mem_0492 = R1R0._1_1_;
  DAT_mem_0493 = R1R0._1_1_;
  DAT_mem_0494 = R1R0._1_1_;
  DAT_mem_0495 = R1R0._1_1_;
  DAT_mem_0496 = R1R0._1_1_;
  DAT_mem_0497 = R1R0._1_1_;
  DAT_mem_0498 = R1R0._1_1_;
  DAT_mem_0499 = R1R0._1_1_;
  DAT_mem_049a = R1R0._1_1_;
  dangerous_command_counter = R1R0._1_1_;
  R25R24 = CONCAT11(host_elapsed_ticks._1_1_,(undefined1)host_elapsed_ticks);
  R25R24 = R25R24 + 1;
  host_elapsed_ticks = R25R24;
  if (1 < led_modes[0]) {
    R25R24._0_1_ = PORTC;
    R25R24._0_1_ = (byte)R25R24 ^ 0x20;
    PORTC = (byte)R25R24;
  }
  if (1 < led_modes[1]) {
    R25R24._0_1_ = PORTC;
    R25R24._0_1_ = (byte)R25R24 ^ 0x40;
    PORTC = (byte)R25R24;
  }
  if (1 < led_modes[2]) {
    bVar1 = PORTC;
    PORTC = bVar1 + 0x80;
  }
  if (1 < led_modes[3]) {
    R25R24._0_1_ = PORTE;
    R25R24._0_1_ = (byte)R25R24 ^ 8;
    PORTE = (byte)R25R24;
  }
  Z = puVar22;
  Y = uVar21;
  X = puVar18;
  R25R24 = uVar17;
  R23 = uVar16;
  R22 = uVar15;
  R21R20 = uVar14;
  R19R18 = uVar13;
  R17R16 = puVar12;
  R15R14 = puVar11;
  R13R12 = uVar10;
  R11R10 = uVar9;
  R9R8 = uVar8;
  R7R6 = uVar7;
  R5R4 = uVar5;
  SREG = bVar4;
  R1R0 = (uint)bVar3;
  return;
}


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


/* BYTE0x154e; WORDcode:0aa7; isr_ADC */

void isr_ADC(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  uint uVar9;
  char in_Cflg;
  bool bVar10;
  bool bVar11;
  char in_Zflg;
  char in_Nflg;
  char in_Vflg;
  char in_Sflg;
  char in_Hflg;
  char in_Tflg;
  
  uVar8 = R25R24;
  uVar7 = R0;
  iVar6 = CONCAT11(DAT_mem_0494,DAT_mem_0493);
  iVar5 = CONCAT11(DAT_mem_0490,DAT_mem_048f);
  iVar4 = CONCAT11(DAT_mem_0498,DAT_mem_0497);
  iVar3 = CONCAT11(DAT_mem_048c,DAT_mem_048b);
  R0 = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
       (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | (in_Hflg == '\x01') << 5 |
       (in_Tflg == '\x01') << 6 | 0x80;
  SREG = R0;
  R25R24._0_1_ = ADMUX;
  R25R24._0_1_ = (byte)R25R24 & 0xf;
  if ((byte)R25R24 == 5) {
    bVar1 = ADC._0_1_;
    bVar2 = ADC._1_1_;
    bVar10 = CARRY1(DAT_mem_0523,bVar1);
    bVar11 = CARRY1(DAT_mem_0524,bVar2) || CARRY1(DAT_mem_0524 + bVar2,bVar10);
    DAT_mem_0526 = DAT_mem_0526 + CARRY1(DAT_mem_0525,bVar11);
    R25R24 = CONCAT11(DAT_mem_0490,DAT_mem_048f);
    uVar9 = R25R24;
    R25R24 = R25R24 + 1;
    iVar5 = R25R24;
    DAT_mem_0492 = DAT_mem_0492 + CARRY1(DAT_mem_0491,0xfffe < uVar9);
    R25R24._0_1_ = 0x46;
    DAT_mem_0491 = DAT_mem_0491 + (0xfffe < uVar9);
    DAT_mem_0523 = DAT_mem_0523 + bVar1;
    DAT_mem_0524 = DAT_mem_0524 + bVar2 + bVar10;
    DAT_mem_0525 = DAT_mem_0525 + bVar11;
    iVar3 = CONCAT11(DAT_mem_048c,DAT_mem_048b);
    iVar4 = CONCAT11(DAT_mem_0498,DAT_mem_0497);
    iVar6 = CONCAT11(DAT_mem_0494,DAT_mem_0493);
  }
  else if ((byte)R25R24 < 5) {
    if ((byte)R25R24 != 4) goto LAB_code_0b78;
    bVar1 = ADC._0_1_;
    bVar2 = ADC._1_1_;
    bVar10 = CARRY1(DAT_mem_051f,bVar1);
    bVar11 = CARRY1(DAT_mem_0520,bVar2) || CARRY1(DAT_mem_0520 + bVar2,bVar10);
    DAT_mem_0522 = DAT_mem_0522 + CARRY1(DAT_mem_0521,bVar11);
    R25R24 = CONCAT11(DAT_mem_048c,DAT_mem_048b);
    uVar9 = R25R24;
    R25R24 = R25R24 + 1;
    iVar3 = R25R24;
    DAT_mem_048e = DAT_mem_048e + CARRY1(DAT_mem_048d,0xfffe < uVar9);
    R25R24._0_1_ = 0x45;
    DAT_mem_048d = DAT_mem_048d + (0xfffe < uVar9);
    DAT_mem_051f = DAT_mem_051f + bVar1;
    DAT_mem_0520 = DAT_mem_0520 + bVar2 + bVar10;
    DAT_mem_0521 = DAT_mem_0521 + bVar11;
    iVar4 = CONCAT11(DAT_mem_0498,DAT_mem_0497);
    iVar5 = CONCAT11(DAT_mem_0490,DAT_mem_048f);
    iVar6 = CONCAT11(DAT_mem_0494,DAT_mem_0493);
  }
  else if ((byte)R25R24 == 6) {
    bVar1 = ADC._0_1_;
    bVar2 = ADC._1_1_;
    bVar10 = CARRY1(DAT_mem_0527,bVar1);
    bVar11 = CARRY1(DAT_mem_0528,bVar2) || CARRY1(DAT_mem_0528 + bVar2,bVar10);
    DAT_mem_052a = DAT_mem_052a + CARRY1(DAT_mem_0529,bVar11);
    R25R24 = CONCAT11(DAT_mem_0494,DAT_mem_0493);
    uVar9 = R25R24;
    R25R24 = R25R24 + 1;
    iVar6 = R25R24;
    DAT_mem_0496 = DAT_mem_0496 + CARRY1(DAT_mem_0495,0xfffe < uVar9);
    R25R24._0_1_ = 0x47;
    DAT_mem_0495 = DAT_mem_0495 + (0xfffe < uVar9);
    DAT_mem_0527 = DAT_mem_0527 + bVar1;
    DAT_mem_0528 = DAT_mem_0528 + bVar2 + bVar10;
    DAT_mem_0529 = DAT_mem_0529 + bVar11;
    iVar3 = CONCAT11(DAT_mem_048c,DAT_mem_048b);
    iVar5 = CONCAT11(DAT_mem_0490,DAT_mem_048f);
  }
  else {
    if ((byte)R25R24 != 7) goto LAB_code_0b78;
    bVar1 = ADC._0_1_;
    bVar2 = ADC._1_1_;
    bVar10 = CARRY1(DAT_mem_052b,bVar1);
    bVar11 = CARRY1(DAT_mem_052c,bVar2) || CARRY1(DAT_mem_052c + bVar2,bVar10);
    DAT_mem_052e = DAT_mem_052e + CARRY1(DAT_mem_052d,bVar11);
    R25R24 = CONCAT11(DAT_mem_0498,DAT_mem_0497);
    uVar9 = R25R24;
    R25R24 = R25R24 + 1;
    iVar4 = R25R24;
    DAT_mem_049a = DAT_mem_049a + CARRY1(DAT_mem_0499,0xfffe < uVar9);
    R25R24._0_1_ = 0x44;
    DAT_mem_0499 = DAT_mem_0499 + (0xfffe < uVar9);
    DAT_mem_052b = DAT_mem_052b + bVar1;
    DAT_mem_052c = DAT_mem_052c + bVar2 + bVar10;
    DAT_mem_052d = DAT_mem_052d + bVar11;
  }
  ADMUX = (byte)R25R24;
LAB_code_0b78:
  DAT_mem_0498 = (undefined1)((uint)iVar4 >> 8);
  DAT_mem_0497 = (undefined1)iVar4;
  DAT_mem_0494 = (undefined1)((uint)iVar6 >> 8);
  DAT_mem_0493 = (undefined1)iVar6;
  DAT_mem_0490 = (undefined1)((uint)iVar5 >> 8);
  DAT_mem_048f = (undefined1)iVar5;
  DAT_mem_048c = (undefined1)((uint)iVar3 >> 8);
  DAT_mem_048b = (undefined1)iVar3;
  R25R24._0_1_ = ADCSRA;
  R25R24._0_1_ = (byte)R25R24 | 0x40;
  ADCSRA = (byte)R25R24;
  R25R24 = uVar8;
  SREG = R0;
  R0 = uVar7;
  R1 = 0;
  return;
}


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


/* BYTE0x183e; WORDcode:0c1f; twi_read_length_prefixed_block */

byte twi_read_length_prefixed_block(undefined1 R25,byte R24,undefined1 R23,byte R22)

{
  byte bVar1;
  undefined2 uVar2;
  
  uVar2 = Y;
  R1 = 0;
  TWCR0 = 0xa4;
  do {
    bVar1 = TWCR0;
  } while ((bVar1 & 0x80) == 0);
  R25 = TWSR0;
  R25 = R25 & 0xf8;
  if ((R25 == 8) || (R25 == 0x10)) {
    TWDR0 = R24 * '\x02';
    TWCR0 = 0x84;
    do {
      bVar1 = TWCR0;
    } while ((bVar1 & 0x80) == 0);
    R25 = TWSR0;
    R25 = R25 & 0xf8;
    if (R25 == 0x18) {
      TWDR0 = R22;
      TWCR0 = 0x84;
      do {
        bVar1 = TWCR0;
      } while ((bVar1 & 0x80) == 0);
      R25 = TWSR0;
      R25 = R25 & 0xf8;
      if (R25 == 0x28) {
        TWCR0 = 0xa4;
        do {
          bVar1 = TWCR0;
        } while ((bVar1 & 0x80) == 0);
        R25 = TWSR0;
        R25 = R25 & 0xf8;
        if ((R25 == 8) || (R25 == 0x10)) {
          TWDR0 = R24 * '\x02' + 1;
          TWCR0 = 0x84;
          do {
            bVar1 = TWCR0;
          } while ((bVar1 & 0x80) == 0);
          R24 = TWSR0;
          R24 = R24 & 0xf8;
          if (R24 == 0x40) {
            TWCR0 = 0xc4;
            do {
              bVar1 = TWCR0;
            } while ((bVar1 & 0x80) == 0);
            R24 = TWSR0;
            R24 = R24 & 0xf0;
            if (R24 == 0x50) {
              R24 = TWDR0;
              R25 = 0;
              R19R18 = (uint)R24;
              X = R19R18 - 1;
              Z = (byte *)CONCAT11(0xc4,(char)Z);
              while( true ) {
                R22 = R25;
                R23 = 0;
                if ((char)-(X._1_1_ + (R25 < (byte)X)) < '\0' ==
                    (SBORROW1('\0',X._1_1_) != SBORROW1(-X._1_1_,R25 < (byte)X))) break;
                TWCR0 = Z._1_1_;
                do {
                  bVar1 = TWCR0;
                  Z = (byte *)CONCAT11(Z._1_1_,bVar1);
                } while ((bVar1 & 0x80) == 0);
                bVar1 = TWSR0;
                Z = (byte *)(CONCAT11(Z._1_1_,bVar1) & 0xfff0);
                if ((char)Z != 'P') goto LAB_code_0cb4;
                bVar1 = TWDR0;
                Z = (byte *)CONCAT11(Z._1_1_,bVar1);
                Y = (byte *)CONCAT11(R21R20._1_1_ + CARRY1((byte)R21R20,R25),(byte)R21R20 + R25);
                *Y = bVar1;
                R25 = R25 + 1;
              }
              TWCR0 = 0x84;
              do {
                bVar1 = TWCR0;
              } while ((bVar1 & 0x80) == 0);
              R25 = TWSR0;
              R25 = R25 & 0xf0;
              if (R25 == 0x50) {
                bVar1 = TWDR0;
                R19R18 = CONCAT11(R19R18._1_1_ + R21R20._1_1_ + CARRY1((byte)R19R18,(byte)R21R20),
                                  (byte)R19R18 + (byte)R21R20);
                Z = (byte *)(R19R18 + -1);
                *Z = bVar1;
                TWCR0 = 0x94;
                R25 = '(';
                do {
                  R25 = R25 + -1;
                } while (R25 != '\0');
                R25 = 0;
                Y = (byte *)uVar2;
                return R25;
              }
            }
          }
        }
      }
    }
  }
LAB_code_0cb4:
  TWCR0 = 0x94;
  R24 = '(';
  do {
    R24 = R24 + -1;
  } while (R24 != '\0');
  R24 = 0;
  Y = (byte *)uVar2;
  return R25;
}


/* BYTE0x197c; WORDcode:0cbe; twi_write_read_transaction */

byte twi_write_read_transaction(undefined1 R25,byte R24,undefined1 R21,char R20)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  
  cVar2 = R16;
  R1 = '\0';
  if (R20 != '\0') {
    TWCR0 = 0xa4;
    do {
      bVar1 = TWCR0;
    } while ((bVar1 & 0x80) == 0);
    R25 = TWSR0;
    R25 = R25 & 0xf8;
    if ((R25 != 8) && (R25 != 0x10)) goto LAB_code_0d37;
    TWDR0 = R24 * '\x02';
    TWCR0 = 0x84;
    do {
      bVar1 = TWCR0;
    } while ((bVar1 & 0x80) == 0);
    R25 = TWSR0;
    R25 = R25 & 0xf8;
    if (R25 != 0x18) goto LAB_code_0d37;
    Z = R23R22;
    R21 = 0x84;
    do {
      pbVar3 = Z;
      Z = Z + 1;
      R25 = *pbVar3;
      TWDR0 = R25;
      TWCR0 = 0x84;
      do {
        bVar1 = TWCR0;
      } while ((bVar1 & 0x80) == 0);
      R25 = TWSR0;
      R25 = R25 & 0xf8;
      if (R25 != 0x28) goto LAB_code_0d37;
      R20 = R20 + -1;
    } while (R20 != '\0');
  }
  if (R16 == '\0') {
    R24 = '\0';
LAB_code_0d30:
    TWCR0 = 0x94;
    R25 = '(';
    do {
      R25 = R25 + -1;
    } while (R25 != '\0');
    R16 = cVar2;
    R25 = 0;
    return R25;
  }
  TWCR0 = 0xa4;
  do {
    bVar1 = TWCR0;
  } while ((bVar1 & 0x80) == 0);
  R25 = TWSR0;
  R25 = R25 & 0xf8;
  if ((R25 == 8) || (R25 == 0x10)) {
    TWDR0 = R24 * '\x02' + 1;
    TWCR0 = 0x84;
    do {
      bVar1 = TWCR0;
    } while ((bVar1 & 0x80) == 0);
    R24 = TWSR0;
    R24 = R24 & 0xf8;
    if (R24 == 0x40) {
      Z = R19R18;
      R25 = 0xc4;
      R19R18 = (byte *)CONCAT11(0x84,(char)R19R18);
      do {
        pbVar3 = Z;
        if (R16 == '\x01') {
          TWCR0 = R19R18._1_1_;
        }
        else {
          TWCR0 = R25;
        }
        do {
          bVar1 = TWCR0;
        } while ((bVar1 & 0x80) == 0);
        R24 = TWSR0;
        R24 = R24 & 0xf0;
        if (R24 != 0x50) goto LAB_code_0d37;
        bVar1 = TWDR0;
        Z = Z + 1;
        *pbVar3 = bVar1;
        R16 = R16 + -1;
        R24 = (char)Z - (char)R19R18;
      } while (R16 != R1);
      goto LAB_code_0d30;
    }
  }
LAB_code_0d37:
  TWCR0 = 0x94;
  R24 = '(';
  do {
    R24 = R24 + -1;
  } while (R24 != '\0');
  R24 = 0;
  R16 = cVar2;
  return R25;
}


/* BYTE0x1a80; WORDcode:0d40; startup_display_and_eeprom_text */

void startup_display_and_eeprom_text(void)

{
  byte bVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  undefined2 uStack_d;
  undefined2 uStack_b;
  undefined2 uStack_9;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  undefined1 uStack_4;
  
  uVar3 = R15;
  uVar2 = R13R12;
  R1 = '\0';
  uStack_4 = (byte)R17R16;
  uStack_5 = R17R16._1_1_;
  uStack_6 = (undefined1)Y;
  uStack_7 = Y._1_1_;
  uStack_9 = 0xd49;
  uStack_b = 0xd4a;
  Y = CONCAT11((char)((uint)((int)&uStack_d + 1) >> 8),(char)&uStack_d + '\x01');
  watchdog_reset();
  uStack_d = 0xd50;
  oled_init_ssd1306_family();
  uStack_d = 0xd52;
  oled_clear();
  uStack_d = 0xd55;
  oled_set_contrast();
  watchdog_reset();
  uStack_d = 0xd59;
  oled_set_scale();
  R17R16._0_1_ = 0;
  R17R16._1_1_ = '\0';
  R15 = '\x01';
  R13R12 = 0x14;
  do {
    R25R24 = CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0x38) + -1),(byte)R17R16 - 0x38);
    uStack_d = 0xd65;
    R25R24._0_1_ = eeprom_read_byte(R25R24);
    if ((byte)((byte)R25R24 - 1) < 0xfe) {
      uStack_d = 0xd6e;
      avr_signed_divide_16bit();
      uStack_d = 0xd70;
      oled_set_text_cursor();
      uStack_d = 0xd73;
      oled_render_character();
      R15 = '\0';
    }
    bVar1 = (byte)R17R16 + 1;
    R17R16._1_1_ = R17R16._1_1_ - (((byte)R17R16 != 0xff) + -1);
    R17R16._0_1_ = bVar1;
  } while (bVar1 != 0xa0 || (bool)R17R16._1_1_ != bVar1 < 0xa0);
  watchdog_reset();
  uStack_d = 0xd7d;
  oled_set_scale();
  R17R16._0_1_ = 0;
  R17R16._1_1_ = '\0';
  R13R12 = 0x14;
  do {
    R25R24 = CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0x98) + -2),(byte)R17R16 + 0x68);
    uStack_d = 0xd87;
    R25R24._0_1_ = eeprom_read_byte(R25R24);
    bVar1 = (byte)R25R24;
    R25R24._0_1_ = (byte)R25R24 - 1;
    R25R24 = CONCAT11(R25R24._1_1_,(byte)R25R24);
    if ((byte)R25R24 < 0xfe) {
      uStack_d = 0xd90;
      avr_signed_divide_16bit();
      uStack_d = 0xd92;
      oled_set_text_cursor();
      *(byte *)(Y + 1) = bVar1;
      *(char *)(Y + 2) = R1;
      uStack_d = 0xd98;
      oled_print_ram_string();
      R15 = R1;
    }
    bVar1 = (byte)R17R16 + 1;
    R17R16._1_1_ = R17R16._1_1_ - (((byte)R17R16 != 0xff) + -1);
    R17R16._0_1_ = bVar1;
  } while (bVar1 != 0xa0 || R17R16._1_1_ != (char)(R1 + (bVar1 < 0xa0)));
  watchdog_reset();
  if (R15 != '\0') {
    uStack_d = 0xda5;
    oled_set_scale();
    uStack_d = 0xda9;
    oled_set_text_cursor();
    uStack_d = 0xdad;
    oled_print_ram_string();
    uStack_d = 0xdb1;
    oled_set_text_cursor();
    uStack_d = 0xdb5;
    oled_print_ram_string();
    uStack_d = 0xdb8;
    oled_set_scale();
    uStack_d = 0xdbc;
    oled_set_text_cursor();
    uStack_d = 0xdc0;
    oled_print_ram_string();
    R25R24 = 0x90;
    uStack_d = 0xdc4;
    eeprom_read_byte(0x90);
    uStack_d = 0xdcb;
    integer_to_string();
    uStack_d = 0xdcf;
    oled_print_ram_string();
    uStack_d = 0xdd3;
    oled_set_text_cursor();
    uStack_d = 0xdd7;
    oled_print_ram_string();
    R25R24 = 0x8d;
    uStack_d = 0xddb;
    eeprom_read_byte(0x8d);
    uStack_d = 0xde2;
    integer_to_string();
    uStack_d = 0xde6;
    oled_print_ram_string();
    uStack_d = 0xdea;
    oled_set_text_cursor();
    uStack_d = 0xdee;
    oled_print_ram_string();
    uStack_d = 0xdf6;
    integer_to_string();
    uStack_d = 0xdfa;
    oled_print_ram_string();
  }
  watchdog_reset();
  R0 = uStack_9._1_1_;
  Y = CONCAT11(uStack_7,uStack_6);
  R17R16 = CONCAT11(uStack_5,uStack_4);
  R15 = uVar3;
  R13R12 = uVar2;
  return;
}


/* BYTE0x1c10; WORDcode:0e08; bme280_discovery_and_calibration */

void bme280_discovery_and_calibration(void)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  char in_Hflg;
  char cVar5;
  char in_Tflg;
  char cVar6;
  char in_Iflg;
  char cVar7;
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined1 uStack_10;
  
  uStack_10 = (undefined1)Y;
  uStack_11 = Y._1_1_;
  uVar2 = CONCAT11((char)((uint)&uStack_12 >> 8),(char)&uStack_12);
  Y = uVar2 - 0x10;
  cVar5 = in_Hflg == '\x01';
  cVar6 = in_Tflg == '\x01';
  cVar7 = in_Iflg == '\x01';
  R1R0._0_1_ = uVar2 < 0x10 | (Y == 0) << 1 | ((int)Y < 0) << 2 | SBORROW2(uVar2,0x10) << 3 |
               ((int)uVar2 < 0x10) << 4 | cVar5 << 5 | cVar6 << 6 | cVar7 << 7;
  bVar3 = (byte)R1R0;
  R1R0 = (uint)(byte)R1R0;
  SREG = bVar3;
  SREG = bVar3;
  R25R24._0_1_ = 0x68;
  *(undefined1 *)(uVar2 - 0xe) = 5;
  *(byte *)(Y + 1) = (byte)R25R24;
  Z._0_1_ = 0x76;
  *(undefined1 *)(Y + 4) = 5;
  *(byte *)(Y + 3) = (byte)Z;
  R25R24._0_1_ = 0xc6;
  *(undefined1 *)(Y + 6) = 4;
  *(byte *)(Y + 5) = (byte)R25R24;
  Z._0_1_ = 100;
  *(undefined1 *)(Y + 8) = 5;
  *(byte *)(Y + 7) = (byte)Z;
  R25R24._0_1_ = 0x60;
  *(undefined1 *)(Y + 10) = 5;
  *(byte *)(Y + 9) = (byte)R25R24;
  Z._0_1_ = 0xd;
  *(undefined1 *)(Y + 0xc) = 5;
  *(byte *)(Y + 0xb) = (byte)Z;
  R25R24._0_1_ = 0x1b;
  *(undefined1 *)(Y + 0xe) = 5;
  *(byte *)(Y + 0xd) = (byte)R25R24;
  R3R2 = &DAT_mem_0557;
  R5R4 = &DAT_mem_04d5;
  R7R6 = &DAT_mem_0517;
  R9R8 = &DAT_mem_055b;
  R11R10 = &DAT_mem_0515;
  Z._1_1_ = 4;
  R13R12 = &DAT_mem_04cf;
  R15R14 = CONCAT11(R1R0._1_1_,R1R0._1_1_);
  *(byte *)(Y + 0x10) = R1R0._1_1_;
  R17 = 0x8a;
  do {
    DAT_mem_057a = -0x30;
    Z._0_1_ = *(char *)(Y + 0x10);
    cVar1 = (byte)Z + 'v';
    Z = (byte *)CONCAT11(Z._1_1_,cVar1);
    *(char *)(Y + 0xf) = cVar1;
    *(undefined2 *)(uVar2 - 0x11) = 0xe68;
    twi_write_read_transaction();
    if (((byte)R25R24 != '\0') && (DAT_mem_057a == '`')) {
      DAT_mem_057a = 0xf2;
      DAT_mem_057b = 5;
      DAT_mem_057c = -0xb;
      DAT_mem_057d = 0x5c;
      DAT_mem_057e = 0xf4;
      Z = (byte *)0xb7f4;
      DAT_mem_057f = 0xb7;
      *(undefined2 *)(uVar2 - 0x11) = 0xe8a;
      twi_write_read_transaction();
      DAT_mem_057a = 0x88;
      *(undefined2 *)(uVar2 - 0x11) = 0xe95;
      twi_write_read_transaction();
      Z._0_1_ = (byte)R15R14;
      Z._1_1_ = (char)((uint)R15R14 >> 8);
      Z = (byte *)CONCAT11(Z._1_1_ - (((byte)Z < 0x36) + -5),(byte)Z - 0x36);
      R25R24._0_1_ = DAT_mem_057a;
      Z[1] = DAT_mem_057b;
      *Z = (byte)R25R24;
      DAT_mem_057a = R17;
      *(undefined2 *)(uVar2 - 0x11) = 0xeab;
      twi_write_read_transaction();
      R25R24._0_1_ = DAT_mem_057a;
      Z._0_1_ = (byte)R15R14;
      Z._1_1_ = (char)((uint)R15R14 >> 8);
      Z = (byte *)CONCAT11(Z._1_1_ - (((byte)Z < 0xad) + -6),(byte)Z + 0x53);
      Z[1] = DAT_mem_057b;
      *Z = (byte)R25R24;
      DAT_mem_057a = 0x8c;
      *(undefined2 *)(uVar2 - 0x11) = 0xebe;
      twi_write_read_transaction();
      R25R24._0_1_ = DAT_mem_057a;
      Z = *(byte **)(Y + 1);
      Z[1] = DAT_mem_057b;
      *Z = (byte)R25R24;
      Z = (byte *)CONCAT11(0x8e,(byte)Z);
      DAT_mem_057a = 0x8e;
      *(undefined2 *)(uVar2 - 0x11) = 0xed0;
      twi_write_read_transaction();
      R25R24._0_1_ = DAT_mem_057a;
      Z = *(byte **)(Y + 3);
      Z[1] = DAT_mem_057b;
      *Z = (byte)R25R24;
      Z = (byte *)CONCAT11(0x90,(byte)Z);
      DAT_mem_057a = 0x90;
      *(undefined2 *)(uVar2 - 0x11) = 0xee6;
      twi_write_read_transaction();
      R25R24._0_1_ = DAT_mem_057a;
      Z = *(byte **)(Y + 5);
      Z[1] = DAT_mem_057b;
      *Z = (byte)R25R24;
      Z = (byte *)CONCAT11(0x92,(byte)Z);
      DAT_mem_057a = 0x92;
      *(undefined2 *)(uVar2 - 0x11) = 0xef8;
      twi_write_read_transaction();
      R25R24._0_1_ = DAT_mem_057a;
      Z = *(byte **)(Y + 7);
      Z[1] = DAT_mem_057b;
      *Z = (byte)R25R24;
      DAT_mem_057a = 0x94;
      *(undefined2 *)(uVar2 - 0x11) = 0xf0a;
      twi_write_read_transaction();
      R25R24._0_1_ = DAT_mem_057a;
      Z = *(byte **)(Y + 9);
      Z[1] = DAT_mem_057b;
      *Z = (byte)R25R24;
      DAT_mem_057a = 0x96;
      *(undefined2 *)(uVar2 - 0x11) = 0xf1c;
      twi_write_read_transaction();
      R25R24._0_1_ = DAT_mem_057a;
      Z = *(byte **)(Y + 0xb);
      Z[1] = DAT_mem_057b;
      *Z = (byte)R25R24;
      DAT_mem_057a = 0x98;
      *(undefined2 *)(uVar2 - 0x11) = 0xf2e;
      twi_write_read_transaction();
      R25R24._0_1_ = DAT_mem_057a;
      Z = *(byte **)(Y + 0xd);
      Z[1] = DAT_mem_057b;
      *Z = (byte)R25R24;
      DAT_mem_057a = 0x9a;
      *(undefined2 *)(uVar2 - 0x11) = 0xf40;
      twi_write_read_transaction();
      R25R24._0_1_ = DAT_mem_057a;
      Z = R3R2;
      R3R2[1] = DAT_mem_057b;
      *Z = (byte)R25R24;
      DAT_mem_057a = 0x9c;
      *(undefined2 *)(uVar2 - 0x11) = 0xf51;
      twi_write_read_transaction();
      R25R24._0_1_ = DAT_mem_057a;
      Z = R5R4;
      R5R4[1] = DAT_mem_057b;
      *Z = (byte)R25R24;
      DAT_mem_057a = 0x9e;
      *(undefined2 *)(uVar2 - 0x11) = 0xf62;
      twi_write_read_transaction();
      R25R24._0_1_ = DAT_mem_057a;
      Z = R7R6;
      R7R6[1] = DAT_mem_057b;
      *Z = (byte)R25R24;
      DAT_mem_057a = 0xa1;
      *(undefined2 *)(uVar2 - 0x11) = 0xf74;
      twi_write_read_transaction();
      Z = R9R8;
      *R9R8 = DAT_mem_057a;
      DAT_mem_057a = 0xe1;
      *(undefined2 *)(uVar2 - 0x11) = 0xf83;
      twi_write_read_transaction();
      R25R24._0_1_ = DAT_mem_057a;
      Z._0_1_ = (byte)R15R14;
      Z._1_1_ = (char)((uint)R15R14 >> 8);
      Z = (byte *)CONCAT11(Z._1_1_ - (((byte)Z < 0x2f) + -5),(byte)Z - 0x2f);
      Z[1] = DAT_mem_057b;
      *Z = (byte)R25R24;
      DAT_mem_057a = 0xe3;
      *(undefined2 *)(uVar2 - 0x11) = 0xf97;
      twi_write_read_transaction();
      Z = R11R10;
      *R11R10 = DAT_mem_057a;
      DAT_mem_057a = -0x1c;
      *(undefined2 *)(uVar2 - 0x11) = 0xfa6;
      twi_write_read_transaction();
      Z._0_1_ = (byte)R15R14;
      Z._1_1_ = (char)((uint)R15R14 >> 8);
      Z = (byte *)CONCAT11(Z._1_1_ - (((byte)Z < 0xef) + -6),(byte)Z + 0x11);
      R1R0 = DAT_mem_057a * 0x10;
      R19R18 = CONCAT11(DAT_mem_057b,DAT_mem_057b) & 0xfff;
      R25R24._0_1_ = (byte)R1R0;
      R25R24._1_1_ = (byte)(R1R0 >> 8);
      R25R24._0_1_ = (byte)R25R24 | R19R18._1_1_;
      Z[1] = R25R24._1_1_;
      *Z = (byte)R25R24;
      Z._0_1_ = (byte)R15R14;
      Z._1_1_ = (char)((uint)R15R14 >> 8);
      Z = (byte *)CONCAT11(Z._1_1_ - (((byte)Z < 0x65) + -6),(byte)Z + 0x9b);
      R1R0 = DAT_mem_057c * 0x10;
      bVar3 = R1R0._1_1_;
      R25R24._0_1_ = (byte)R1R0;
      R1R0 = R1R0 & 0xff;
      R25R24._0_1_ = (byte)R25R24 | (byte)R19R18 >> 4;
      Z[1] = bVar3;
      *Z = (byte)R25R24;
      DAT_mem_057a = -0x19;
      *(undefined2 *)(uVar2 - 0x11) = 0xfcf;
      twi_write_read_transaction();
      *R13R12 = DAT_mem_057a;
    }
    Z._1_1_ = *(char *)(Y + 0x10);
    *(char *)(Y + 0x10) = Z._1_1_ + '\x01';
    R15R14 = CONCAT11(R15R14._1_1_ + R1R0._1_1_ + (0xfd < (byte)R15R14),(byte)R15R14 + 2);
    R25R24 = *(int *)(Y + 1) + 2;
    *(byte *)(Y + 2) = R25R24._1_1_;
    *(byte *)(Y + 1) = (byte)R25R24;
    Z = (byte *)(*(int *)(Y + 3) + 2);
    *(char *)(Y + 4) = Z._1_1_;
    *(byte *)(Y + 3) = (byte)Z;
    R25R24 = *(int *)(Y + 5) + 2;
    *(byte *)(Y + 6) = R25R24._1_1_;
    *(byte *)(Y + 5) = (byte)R25R24;
    Z = (byte *)(*(int *)(Y + 7) + 2);
    *(char *)(Y + 8) = Z._1_1_;
    *(byte *)(Y + 7) = (byte)Z;
    R25R24 = *(int *)(Y + 9) + 2;
    *(byte *)(Y + 10) = R25R24._1_1_;
    *(byte *)(Y + 9) = (byte)R25R24;
    Z = (byte *)(*(int *)(Y + 0xb) + 2);
    *(char *)(Y + 0xc) = Z._1_1_;
    *(byte *)(Y + 0xb) = (byte)Z;
    R25R24 = *(int *)(Y + 0xd) + 2;
    *(byte *)(Y + 0xe) = R25R24._1_1_;
    *(byte *)(Y + 0xd) = (byte)R25R24;
    uVar4 = Y;
    R3R2 = (undefined1 *)CONCAT11(R3R2._1_1_ + R1R0._1_1_ + (0xfd < (byte)R3R2),(byte)R3R2 + 2);
    R5R4 = (undefined1 *)CONCAT11(R5R4._1_1_ + R1R0._1_1_ + (0xfd < (byte)R5R4),(byte)R5R4 + 2);
    R7R6 = (undefined1 *)CONCAT11(R7R6._1_1_ + R1R0._1_1_ + (0xfd < (byte)R7R6),(byte)R7R6 + 2);
    R19R18 = CONCAT11(0xff,(byte)R19R18);
    R9R8 = (undefined1 *)CONCAT11(R9R8._1_1_ - (((char)R9R8 != -1) + -1),(char)R9R8 + '\x01');
    R11R10 = (undefined1 *)
             CONCAT11(R11R10._1_1_ - (((char)R11R10 != -1) + -1),(char)R11R10 + '\x01');
    R25R24 = 0xffff;
    R13R12 = (char *)CONCAT11(R13R12._1_1_ - (((char)R13R12 != -1) + -1),(char)R13R12 + '\x01');
    Z._0_1_ = *(char *)(Y + 0x10);
    Z._1_1_ = 2;
  } while ((byte)Z != '\x02');
  Y = Y + 0x10;
  R1R0._0_1_ = 0xffef < uVar4 | (uVar4 == 0xfff0) << 1 | ((int)Y < 0) << 2 | SCARRY2(Y,0x10) << 3 |
               ((int)Y < 0 != SCARRY2(Y,0x10)) << 4 | (cVar5 == '\x01') << 5 |
               (cVar6 == '\x01') << 6 | (cVar7 == '\x01') << 7;
  SREG = (byte)R1R0;
  SREG = (byte)R1R0;
  Y._1_1_ = *(undefined1 *)(uVar4 + 0x11);
  Y._0_1_ = *(undefined1 *)(uVar4 + 0x12);
  R17 = *(undefined1 *)(uVar4 + 0x13);
  R16 = *(undefined1 *)(uVar4 + 0x14);
  R15R14._1_1_ = *(undefined1 *)(uVar4 + 0x15);
  R15R14._0_1_ = *(undefined1 *)(uVar4 + 0x16);
  R13R12._1_1_ = *(undefined1 *)(uVar4 + 0x17);
  R13R12._0_1_ = *(undefined1 *)(uVar4 + 0x18);
  R11R10._1_1_ = *(undefined1 *)(uVar4 + 0x19);
  R11R10._0_1_ = *(undefined1 *)(uVar4 + 0x1a);
  R9R8._1_1_ = *(undefined1 *)(uVar4 + 0x1b);
  R9R8._0_1_ = *(undefined1 *)(uVar4 + 0x1c);
  R7R6._1_1_ = *(undefined1 *)(uVar4 + 0x1d);
  R7R6._0_1_ = *(undefined1 *)(uVar4 + 0x1e);
  R5R4._1_1_ = *(undefined1 *)(uVar4 + 0x1f);
  R5R4._0_1_ = *(undefined1 *)(uVar4 + 0x20);
  R3R2._1_1_ = *(undefined1 *)(uVar4 + 0x21);
  R3R2._0_1_ = *(undefined1 *)(uVar4 + 0x22);
  Z._1_1_ = 2;
  return;
}


/* BYTE0x2056; WORDcode:102b; application_main */

void application_main(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  byte *pbVar6;
  char in_Cflg;
  char cVar7;
  char in_Zflg;
  char cVar8;
  char in_Nflg;
  char cVar9;
  char in_Vflg;
  char cVar10;
  char in_Sflg;
  bool bVar11;
  char cVar12;
  char in_Hflg;
  char cVar13;
  char in_Tflg;
  char cVar14;
  char in_Iflg;
  char cVar15;
  
  R1 = 0;
  cVar13 = in_Hflg == '\x01';
  cVar14 = in_Tflg == '\x01';
  R0 = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
       (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | cVar13 << 5 | cVar14 << 6 |
       (in_Iflg == '\x01') << 7;
  SREG = R0;
  watchdog_reset();
  WDTCSR = 0x18;
  SREG = R0;
  WDTCSR = 0xf;
  watchdog_reset();
  gpio_input_init();
  pwm_timer_init_from_eeprom();
  X = signature_serial_bytes;
  Z = &DAT_codebyte_000e;
  R25R24 = 0x2100;
  do {
    pbVar6 = X;
    SPMCSR = R25R24._1_1_;
    R25R24._0_1_ = *Z;
    X = X + 1;
    *pbVar6 = (byte)R25R24;
    Z = Z + 1;
  } while ((byte)Z != 0x18 || Z._1_1_ != (byte)(R1 + ((byte)Z < 0x18)));
  startup_display_and_eeprom_text();
  bme280_discovery_and_calibration();
  FUN_code_047f();
  bVar1 = DDRD;
  DDRD = bVar1 | 2;
  bVar1 = PORTD;
  PORTD = bVar1 | 2;
  cVar15 = '\x01';
  watchdog_reset();
  host_watchdog_threshold._1_1_ = R1;
  host_watchdog_threshold._0_1_ = R1;
  R25R24 = 100;
  R25R24._0_1_ = eeprom_read_byte(100);
  host_watchdog_mode = (byte)R25R24;
  if (2 < (byte)R25R24) {
    eeprom_update_byte();
    host_watchdog_mode = R1;
    eeprom_update_byte();
    eeprom_update_byte();
    eeprom_update_word();
    eeprom_update_word();
    eeprom_update_word();
  }
  R25R24 = 0x65;
  R25R24._0_1_ = eeprom_read_byte(0x65);
  host_watchdog_retry_stage = (byte)R25R24;
  R25R24 = 0x66;
  R25R24._0_1_ = eeprom_read_byte(0x66);
  extra_recovery_attempts = (byte)R25R24;
  if (host_watchdog_mode == 2) {
    R25R24 = 0x67;
  }
  else {
    if (host_watchdog_mode != 1) goto LAB_code_109e;
    R25R24 = 0x69;
  }
  R25R24 = eeprom_read_word(R25R24);
  host_watchdog_threshold._1_1_ = R25R24._1_1_;
  host_watchdog_threshold._0_1_ = (byte)R25R24;
LAB_code_109e:
  do {
    usb_poll();
    watchdog_reset();
    if (host_watchdog_threshold._1_1_ <= host_elapsed_ticks._1_1_ &&
        ((byte)host_elapsed_ticks < (byte)host_watchdog_threshold) <=
        (byte)(host_elapsed_ticks._1_1_ - host_watchdog_threshold._1_1_)) {
      if (host_watchdog_mode == 2) {
        if (host_watchdog_retry_stage != R1) {
          cVar10 = SBORROW1(host_watchdog_retry_stage,'\x01');
          cVar7 = host_watchdog_retry_stage == 0;
          cVar9 = (char)(host_watchdog_retry_stage - 1) < '\0';
          cVar8 = host_watchdog_retry_stage == 1;
          cVar12 = (char)host_watchdog_retry_stage < '\x01';
          eeprom_update_byte();
          R0 = cVar7 == '\x01' | (cVar8 == '\x01') << 1 | (cVar9 == '\x01') << 2 |
               (cVar10 == '\x01') << 3 | (cVar12 == '\x01') << 4 | (cVar13 == '\x01') << 5 |
               (cVar14 == '\x01') << 6 | (cVar15 == '\x01') << 7;
          SREG = R0;
          watchdog_reset();
          WDTCSR = 0x18;
          SREG = R0;
          WDTCSR = 0xc;
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        eeprom_update_byte();
        eeprom_update_byte();
        eeprom_read_word(0x6b);
        eeprom_write_word();
        R18 = '\x7f';
        R25R24._0_1_ = 0xa9;
        R25R24._1_1_ = '\x03';
        do {
          cVar7 = R18 + -1;
          bVar1 = (byte)R25R24 - (R18 == '\0');
          R25R24._1_1_ = R25R24._1_1_ - ((byte)R25R24 < (R18 == '\0'));
          R18 = cVar7;
          R25R24._0_1_ = bVar1;
        } while ((cVar7 != '\0' || bVar1 != 0) || R25R24._1_1_ != '\0');
        bVar1 = PORTC;
        PORTC = bVar1 | 8;
        R18 = '\x7f';
        R25R24._0_1_ = 0x4f;
        R25R24._1_1_ = 0x12;
        do {
          cVar7 = R18 + -1;
          bVar1 = (byte)R25R24 - (R18 == '\0');
          bVar11 = (byte)R25R24 < (R18 == '\0');
          bVar2 = R25R24._1_1_ - bVar11;
          bVar3 = SBORROW1(R25R24._1_1_,bVar11);
          bVar4 = R25R24._1_1_ < bVar11;
          bVar11 = (char)R25R24._1_1_ < bVar11;
          R18 = cVar7;
          R25R24._0_1_ = bVar1;
          R25R24._1_1_ = bVar2;
        } while ((cVar7 != '\0' || bVar1 != 0) || bVar2 != 0);
        bVar5 = PORTC;
        PORTC = bVar5 & 0xf7;
        R0 = bVar4 | ((cVar7 == '\0' && bVar1 == 0) && bVar2 == 0) << 1 | ((char)bVar2 < '\0') << 2
             | bVar3 << 3 | bVar11 << 4 | (cVar13 == '\x01') << 5 | (cVar14 == '\x01') << 6 |
             (cVar15 == '\x01') << 7;
        SREG = R0;
        watchdog_reset();
        WDTCSR = 0x18;
        SREG = R0;
        WDTCSR = 0xc;
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      if (host_watchdog_mode == 1) {
        if (host_watchdog_retry_stage != R1) {
          cVar10 = SBORROW1(host_watchdog_retry_stage,'\x01');
          cVar7 = host_watchdog_retry_stage == 0;
          cVar9 = (char)(host_watchdog_retry_stage - 1) < '\0';
          cVar8 = host_watchdog_retry_stage == 1;
          cVar12 = (char)host_watchdog_retry_stage < '\x01';
          eeprom_update_byte();
          R0 = cVar7 == '\x01' | (cVar8 == '\x01') << 1 | (cVar9 == '\x01') << 2 |
               (cVar10 == '\x01') << 3 | (cVar12 == '\x01') << 4 | (cVar13 == '\x01') << 5 |
               (cVar14 == '\x01') << 6 | (cVar15 == '\x01') << 7;
          SREG = R0;
          watchdog_reset();
          WDTCSR = 0x18;
          SREG = R0;
          WDTCSR = 0xc;
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        if (extra_recovery_attempts != R1) {
          eeprom_update_byte();
          eeprom_update_byte();
          eeprom_read_word(0x6b);
          eeprom_write_word();
          R18 = '\x7f';
          R25R24._0_1_ = 0xa9;
          R25R24._1_1_ = '\x03';
          do {
            cVar7 = R18 + -1;
            bVar1 = (byte)R25R24 - (R18 == '\0');
            R25R24._1_1_ = R25R24._1_1_ - ((byte)R25R24 < (R18 == '\0'));
            R18 = cVar7;
            R25R24._0_1_ = bVar1;
          } while ((cVar7 != '\0' || bVar1 != 0) || R25R24._1_1_ != '\0');
          bVar1 = PORTC;
          PORTC = bVar1 | 8;
          R18 = '\x7f';
          R25R24._0_1_ = 0x4f;
          R25R24._1_1_ = 0x12;
          do {
            cVar7 = R18 + -1;
            bVar1 = (byte)R25R24 - (R18 == '\0');
            bVar11 = (byte)R25R24 < (R18 == '\0');
            bVar2 = R25R24._1_1_ - bVar11;
            bVar3 = SBORROW1(R25R24._1_1_,bVar11);
            bVar4 = R25R24._1_1_ < bVar11;
            bVar11 = (char)R25R24._1_1_ < bVar11;
            R18 = cVar7;
            R25R24._0_1_ = bVar1;
            R25R24._1_1_ = bVar2;
          } while ((cVar7 != '\0' || bVar1 != 0) || bVar2 != 0);
          bVar5 = PORTC;
          PORTC = bVar5 & 0xf7;
          R0 = bVar4 | ((cVar7 == '\0' && bVar1 == 0) && bVar2 == 0) << 1 |
               ((char)bVar2 < '\0') << 2 | bVar3 << 3 | bVar11 << 4 | (cVar13 == '\x01') << 5 |
               (cVar14 == '\x01') << 6 | (cVar15 == '\x01') << 7;
          SREG = R0;
          watchdog_reset();
          WDTCSR = 0x18;
          SREG = R0;
          WDTCSR = 0xc;
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        eeprom_update_byte();
        host_watchdog_mode = R1;
        eeprom_update_byte();
        host_watchdog_retry_stage = 2;
        eeprom_read_word(0x6b);
        eeprom_write_word();
        R18 = '\x7f';
        R25R24._0_1_ = 0xa9;
        R25R24._1_1_ = '\x03';
        do {
          cVar7 = R18 + -1;
          bVar1 = (byte)R25R24 - (R18 == '\0');
          R25R24._1_1_ = R25R24._1_1_ - ((byte)R25R24 < (R18 == '\0'));
          R18 = cVar7;
          R25R24._0_1_ = bVar1;
        } while ((cVar7 != '\0' || bVar1 != 0) || R25R24._1_1_ != '\0');
        bVar1 = PORTC;
        PORTC = bVar1 | 0x10;
      }
    }
    if (host_watchdog_mode != 0) {
      if (host_watchdog_retry_stage == 1) {
        led_modes[1] = 3;
      }
      else if (host_watchdog_retry_stage == R1) {
        led_modes[1] = 2;
      }
      else {
        led_modes[1] = R1;
      }
    }
    if (led_modes[0] == R1) {
      bVar1 = PORTC;
      PORTC = bVar1 & 0xdf;
    }
    if (led_modes[0] == 1) {
      bVar1 = PORTC;
      PORTC = bVar1 | 0x20;
    }
    if (led_modes[1] == R1) {
      bVar1 = PORTC;
      PORTC = bVar1 & 0xbf;
    }
    else if (led_modes[1] == 1) {
      bVar1 = PORTC;
      PORTC = bVar1 | 0x40;
    }
    if (led_modes[2] == R1) {
      bVar1 = PORTC;
      PORTC = bVar1 & 0x7f;
    }
    else if (led_modes[2] == 1) {
      bVar1 = PORTC;
      PORTC = bVar1 | 0x80;
    }
    if (led_modes[3] == R1) {
      bVar1 = PORTE;
      PORTE = bVar1 & 0xf7;
    }
    else if (led_modes[3] == 1) {
      bVar1 = PORTE;
      PORTE = bVar1 | 8;
    }
  } while( true );
}


/* BYTE0x2352; WORDcode:11a9; usb_setup_dispatch */

byte usb_setup_dispatch(UsbSetupPacket *setup)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  ushort uVar9;
  byte bVar10;
  UsbSetupPacket *pUVar11;
  uint uVar12;
  byte bVar13;
  undefined1 *puVar14;
  undefined2 *puVar15;
  UsbSetupPacket *pUVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  char cVar20;
  char cVar21;
  char cVar22;
  char cVar23;
  char cVar24;
  char in_Hflg;
  char cVar25;
  char in_Tflg;
  char cVar26;
  char in_Iflg;
  char cVar27;
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined1 uStack_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined1 uStack_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  undefined1 uStack_4;
  undefined1 uStack_3;
  undefined1 uStack_2;
  undefined1 uStack_1;
  
  pUVar11 = setup;
  uStack_1 = R3R2._1_1_;
  uStack_2 = (byte)R5R4;
  uStack_3 = R5R4._1_1_;
  uStack_4 = (byte)R7R6;
  uStack_5 = R7R6._1_1_;
  uStack_6 = (byte)R9R8;
  uStack_7 = R9R8._1_1_;
  uStack_8 = (byte)R11R10;
  uStack_9 = R11R10._1_1_;
  uStack_a = (byte)R13R12;
  uStack_b = R13R12._1_1_;
  uStack_c = (byte)R15R14;
  uStack_d = R15R14._1_1_;
  uStack_e = (byte)R17R16;
  uStack_f = R17R16._1_1_;
  uStack_10 = (undefined1)Y;
  uStack_11 = Y._1_1_;
  uVar8 = CONCAT11((char)((uint)&uStack_12 >> 8),(char)&uStack_12);
  Y = uVar8 - 0x10;
  cVar25 = in_Hflg == '\x01';
  cVar26 = in_Tflg == '\x01';
  R1R0._0_1_ = uVar8 < 0x10 | (Y == 0) << 1 | ((int)Y < 0) << 2 | SBORROW2(uVar8,0x10) << 3 |
               ((int)uVar8 < 0x10) << 4 | cVar25 << 5 | cVar26 << 6 | (in_Iflg == '\x01') << 7;
  bVar1 = (byte)R1R0;
  R1R0 = (uint)(byte)R1R0;
  SREG = bVar1;
  cVar27 = -((char)bVar1 >> 7);
  SREG = bVar1;
  R19R18 = &usb_reply_buffer;
  usb_reply_pointer._1_1_ = 3;
  usb_reply_pointer._0_1_ = 0x53;
  X = (UsbSetupPacket *)&setup->bRequest;
  R17R16._1_1_ = *(byte *)X;
  if (R17R16._1_1_ == 0xb) {
    Z = signature_serial_bytes;
    X = (UsbSetupPacket *)&usb_reply_buffer;
    do {
      pUVar16 = (UsbSetupPacket *)Z;
      pUVar11 = X;
      Z = &((UsbSetupPacket *)Z)->bRequest;
      setup._0_1_ = pUVar16->bmRequestType;
      X = (UsbSetupPacket *)&X->bRequest;
      pUVar11->bmRequestType = (byte)setup;
    } while ((byte)Z != 0x76 || Z._1_1_ != (char)(((byte)Z < 0x76) + '\x05'));
    R17R16._1_1_ = 10;
    uVar9 = host_watchdog_threshold;
    goto LAB_code_1b6f;
  }
  R15R14 = setup;
  if (R17R16._1_1_ < 0xc) {
    if (R17R16._1_1_ == 5) {
      X = (UsbSetupPacket *)&setup->wIndex;
      Z._0_1_ = (byte)*(ushort *)X;
      X = setup;
      if ((byte)Z < 4) {
        Z = (byte *)CONCAT11(-(((byte)Z < 0x79) + -5),(byte)Z + 0x87);
        X = (UsbSetupPacket *)&setup->wValue;
        setup._0_1_ = (byte)*(ushort *)X;
        ((UsbSetupPacket *)Z)->bmRequestType = (byte)setup;
      }
    }
    else if (R17R16._1_1_ < 5) {
      if (R17R16._1_1_ == 2) {
        X = (UsbSetupPacket *)&setup->wIndex;
        Z._0_1_ = (byte)*(ushort *)X;
        setup = (UsbSetupPacket *)0x0;
        if ((byte)Z < 0xc) {
          Z = (byte *)CONCAT11(-(((byte)Z < 0x8e) + -1),(byte)Z + 0x72);
                    /* WARNING: Return address prevents inlining here */
          gcc_tablejump_helper();
          pUVar11 = setup;
          bVar1 = (byte)setup;
          setup = pUVar11;
          return bVar1;
        }
LAB_code_12ba:
        R17R16._1_1_ = calibration_ticks_remaining;
        if (calibration_ticks_remaining == 0) {
          X = (UsbSetupPacket *)&pUVar11->wIndex;
          Z._0_1_ = (byte)*(ushort *)X;
          setup = (UsbSetupPacket *)0x0;
          uVar9 = host_watchdog_threshold;
          if ((byte)Z < 0xc) {
            Z = (byte *)CONCAT11(-(((byte)Z < 0x82) + -1),(byte)Z + 0x7e);
            X = (UsbSetupPacket *)&pUVar11->wValue;
                    /* WARNING: Return address prevents inlining here */
            gcc_tablejump_helper();
            pUVar11 = setup;
            bVar1 = (byte)setup;
            setup = pUVar11;
            return bVar1;
          }
          goto LAB_code_1b6f;
        }
      }
      else if (R17R16._1_1_ < 2) {
        if (R17R16._1_1_ == 0) {
          bVar1 = PORTC;
          PORTC = bVar1 | 0x40;
          host_elapsed_ticks._1_1_ = 0;
          host_elapsed_ticks._0_1_ = 0;
          *(undefined2 *)(uVar8 - 0x11) = 0x1374;
          eeprom_update_byte();
          setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,2);
          host_watchdog_retry_stage = 2;
          X = (UsbSetupPacket *)CONCAT11(0x7f,(byte)X);
          Z = (byte *)0x3a9;
          do {
            cVar20 = X._1_1_ + -1;
            bVar17 = X._1_1_ == '\0';
            X = (UsbSetupPacket *)CONCAT11(cVar20,(byte)X);
            cVar21 = (byte)Z - bVar17;
            Z._1_1_ = Z._1_1_ - ((byte)Z < bVar17);
            Z = (byte *)CONCAT11(Z._1_1_,cVar21);
          } while ((cVar20 != '\0' || cVar21 != '\0') || Z._1_1_ != '\0');
          bVar1 = PORTC;
          PORTC = bVar1 & 0xbf;
          uVar9 = host_watchdog_threshold;
          goto LAB_code_1b6f;
        }
        if (R17R16._1_1_ == 1) {
          X = (UsbSetupPacket *)&setup->wIndex;
          Z._0_1_ = (byte)*(ushort *)X;
          setup = (UsbSetupPacket *)0x0;
          if ((byte)Z < 0xc) {
            Z = (byte *)CONCAT11(-(((byte)Z < 0x9a) + -1),(byte)Z + 0x66);
                    /* WARNING: Return address prevents inlining here */
            gcc_tablejump_helper();
            pUVar11 = setup;
            bVar1 = (byte)setup;
            setup = pUVar11;
            return bVar1;
          }
        }
      }
      else {
        if (R17R16._1_1_ == 3) {
          setup._0_1_ = (byte)setup->wIndex;
          bVar1 = (byte)setup * '\x02';
          setup._1_1_ = CARRY1((byte)setup,(byte)setup);
          Z = (byte *)CONCAT11(setup._1_1_ - ((bVar1 < 0xd1) + -6),bVar1 + 0x2f);
          R19R18._0_1_ = *Z;
          R19R18 = (byte *)CONCAT11(3,(byte)R19R18);
          usb_reply_buffer = (byte)R19R18;
          Z = (byte *)CONCAT11(setup._1_1_ - ((bVar1 < 0xd0) + -6),bVar1 + 0x30);
          goto LAB_code_1354;
        }
        if (R17R16._1_1_ == 4) goto LAB_code_12ba;
      }
    }
    else {
      if (R17R16._1_1_ == 8) {
        X = (UsbSetupPacket *)&setup->wIndex;
        setup._0_1_ = (byte)*(ushort *)X;
        bVar1 = (byte)setup * '\x02';
        setup._1_1_ = CARRY1((byte)setup,(byte)setup);
        Z = (byte *)CONCAT11(setup._1_1_ - ((bVar1 < 0x27) + -5),bVar1 - 0x27);
        R19R18._0_1_ = *Z;
        R19R18 = (byte *)CONCAT11(3,(byte)R19R18);
        usb_reply_buffer = (byte)R19R18;
        Z = (byte *)CONCAT11(setup._1_1_ - ((bVar1 < 0x26) + -5),bVar1 - 0x26);
LAB_code_1354:
        setup._0_1_ = ((UsbSetupPacket *)Z)->bmRequestType;
LAB_code_1355:
        DAT_mem_0354 = (byte)setup;
        R17R16._1_1_ = 2;
        uVar9 = host_watchdog_threshold;
        goto LAB_code_1b6f;
      }
      if (R17R16._1_1_ < 8) {
        if (R17R16._1_1_ == 6) {
          Z = (byte *)CONCAT11(Z._1_1_,3);
          R15R14 = (UsbSetupPacket *)&usb_reply_buffer;
          R17R16 = &PRR0;
          do {
            setup = (UsbSetupPacket *)R17R16;
            *(undefined2 *)(uVar8 - 0x11) = 0x138b;
            setup._0_1_ = eeprom_read_byte((ushort)setup);
            setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,(byte)setup);
            X = (UsbSetupPacket *)&R15R14->bRequest;
            R15R14->bmRequestType = (byte)setup;
            R15R14 = X;
            bVar1 = (byte)R17R16 + 1;
            cVar20 = R17R16._1_1_ - (((byte)R17R16 != -1) + -1);
            R17R16 = (byte *)CONCAT11(cVar20,bVar1);
          } while (bVar1 != 0x6d || cVar20 != (byte)(R1R0._1_1_ + (bVar1 < 0x6d)));
          R17R16._1_1_ = 9;
          uVar9 = host_watchdog_threshold;
          goto LAB_code_1b6f;
        }
        if (R17R16._1_1_ == 7) {
          host_elapsed_ticks._1_1_ = 0;
          host_elapsed_ticks._0_1_ = 0;
          *(undefined2 *)(uVar8 - 0x11) = 0x139e;
          eeprom_update_byte();
          host_watchdog_mode = R1R0._1_1_;
          *(undefined2 *)(uVar8 - 0x11) = 0x13a5;
          eeprom_update_byte();
          host_watchdog_retry_stage = 2;
          Z = &R15R14->bmRequestType;
          *(undefined2 *)(uVar8 - 0x11) = 0x13ae;
          eeprom_update_byte();
          X = (UsbSetupPacket *)((int)&R15R14->wIndex + 1);
          setup._0_1_ = *(byte *)X;
          extra_recovery_attempts = (byte)setup;
          led_modes[1] = R1R0._1_1_;
          X = (UsbSetupPacket *)&R15R14->wIndex;
          R23R22._0_1_ = (byte)*(ushort *)X;
          if ((byte)R23R22 != 0) {
            X = (UsbSetupPacket *)CONCAT11(0x14,(byte)X);
            R1R0 = (uint)(byte)R23R22 * 0x14;
            R1R0 = R1R0 & 0xff;
            *(undefined2 *)(uVar8 - 0x11) = 0x13c3;
            eeprom_update_word();
            setup._0_1_ = (byte)R15R14->wIndex;
            setup = (UsbSetupPacket *)(uint)(byte)setup;
            Z._0_1_ = (byte)R15R14;
            Z = (byte *)CONCAT11(0x14,(byte)Z);
            R1R0 = (int)setup * 0x14;
            host_watchdog_threshold = R1R0;
            R1R0 = R1R0 & 0xff;
            *(undefined2 *)(uVar8 - 0x11) = 0x13d2;
            eeprom_update_byte();
            host_watchdog_mode = 1;
            X = (UsbSetupPacket *)&R15R14->wValue;
            uVar9 = *(ushort *)X;
            X = R15R14;
            if (uVar9 == 0) {
              setup = (UsbSetupPacket *)0x0;
            }
            else {
              R17R16 = (byte *)0x3;
              *(undefined2 *)(uVar8 - 0x11) = 0x13e2;
              avr_unsigned_divide_16bit();
              *(undefined2 *)(uVar8 - 0x11) = 0x13e6;
              eeprom_update_word();
              Z = &R15R14->bmRequestType;
              *(undefined2 *)(uVar8 - 0x11) = 0x13ec;
              avr_unsigned_divide_16bit();
              host_watchdog_threshold._1_1_ = R23R22._1_1_;
              host_watchdog_threshold._0_1_ = (byte)R23R22;
              *(undefined2 *)(uVar8 - 0x11) = 0x13f5;
              eeprom_update_byte();
              setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,2);
              host_watchdog_mode = 2;
            }
          }
        }
      }
      else if (R17R16._1_1_ == 9) {
        X = (UsbSetupPacket *)&setup->wIndex;
        Z._0_1_ = (byte)*(ushort *)X;
        setup = (UsbSetupPacket *)0x0;
        if ((byte)Z < 0xc) {
          Z = (byte *)CONCAT11(-(((byte)Z < 0x76) + -1),(byte)Z + 0x8a);
                    /* WARNING: Return address prevents inlining here */
          gcc_tablejump_helper();
          pUVar11 = setup;
          bVar1 = (byte)setup;
          setup = pUVar11;
          return bVar1;
        }
      }
      else if (R17R16._1_1_ == 10) {
        usb_reply_buffer = 0x1e;
        setup = (UsbSetupPacket *)&TCCR3A;
        *(undefined2 *)(uVar8 - 0x11) = 0x1205;
        setup._0_1_ = eeprom_read_byte((ushort)setup);
        DAT_mem_0354 = (byte)setup;
        setup = (UsbSetupPacket *)&UNK_mem_008d;
        *(undefined2 *)(uVar8 - 0x11) = 0x120b;
        setup._0_1_ = eeprom_read_byte((ushort)setup);
        DAT_mem_0355 = (byte)setup;
        setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,0xc);
        DAT_mem_0356 = '\f';
        R17R16._1_1_ = 4;
        uVar9 = host_watchdog_threshold;
        goto LAB_code_1b6f;
      }
    }
  }
  else if (R17R16._1_1_ == 0x12) {
    X = (UsbSetupPacket *)&setup->wIndex;
    setup._0_1_ = (byte)*(ushort *)X;
    if ((byte)setup < 8) {
      DAT_mem_057a = 8;
      setup._1_1_ = -(((byte)setup + 0x58) * '\x02' + '\b');
      DAT_mem_057b = setup._1_1_;
      R17R16._0_1_ = 3;
      *(undefined2 *)(uVar8 - 0x11) = 0x14c3;
      twi_write_read_transaction();
      if (((byte)setup != '\0') &&
         (setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,DAT_mem_057a), DAT_mem_057a != 0xff)) {
        usb_reply_buffer = DAT_mem_057a;
        DAT_mem_0354 = DAT_mem_057b;
        DAT_mem_057a = 10;
        Z = &R15R14->bmRequestType;
        setup._0_1_ = (byte)R15R14->wIndex;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '\n');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x14e3;
        twi_write_read_transaction();
        DAT_mem_0355 = DAT_mem_057a;
        DAT_mem_0356 = DAT_mem_057b;
        DAT_mem_057a = 0xc;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        setup._0_1_ = (byte)*(ushort *)X;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '\f');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x14fe;
        twi_write_read_transaction();
        DAT_mem_0357 = DAT_mem_057a;
        DAT_mem_0358 = DAT_mem_057b;
        DAT_mem_057a = 0xe;
        Z = &R15R14->bmRequestType;
        setup._0_1_ = (byte)R15R14->wIndex;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '\x0e');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x1518;
        twi_write_read_transaction();
        DAT_mem_0359 = DAT_mem_057a;
        DAT_mem_035a = DAT_mem_057b;
        DAT_mem_057a = 0x10;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        setup._0_1_ = (byte)*(ushort *)X;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '\x10');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x1533;
        twi_write_read_transaction();
        DAT_mem_035b = DAT_mem_057a;
        DAT_mem_035c = DAT_mem_057b;
        DAT_mem_057a = R17R16._1_1_;
        Z = &R15R14->bmRequestType;
        setup._0_1_ = (byte)R15R14->wIndex;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '\x12');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x154c;
        twi_write_read_transaction();
        DAT_mem_035d = DAT_mem_057a;
        DAT_mem_035e = DAT_mem_057b;
        DAT_mem_057a = 0x1a;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        setup._0_1_ = (byte)*(ushort *)X;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '\x1a');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x1567;
        twi_write_read_transaction();
        DAT_mem_035f = DAT_mem_057a;
        DAT_mem_0360 = DAT_mem_057b;
        DAT_mem_057a = 0x1c;
        Z = &R15R14->bmRequestType;
        setup._0_1_ = (byte)R15R14->wIndex;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '\x1c');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x1581;
        twi_write_read_transaction();
        DAT_mem_0361 = DAT_mem_057a;
        DAT_mem_0362 = DAT_mem_057b;
        DAT_mem_057a = 0x1e;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        setup._0_1_ = (byte)*(ushort *)X;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '\x1e');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x159c;
        twi_write_read_transaction();
        DAT_mem_0363 = DAT_mem_057a;
        DAT_mem_0364 = DAT_mem_057b;
        DAT_mem_057a = 0x32;
        Z = &R15R14->bmRequestType;
        setup._0_1_ = (byte)R15R14->wIndex;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '2');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x15b6;
        twi_write_read_transaction();
        DAT_mem_0365 = DAT_mem_057a;
        DAT_mem_0366 = DAT_mem_057b;
        DAT_mem_057a = 0x36;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        setup._0_1_ = (byte)*(ushort *)X;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '6');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x15d1;
        twi_write_read_transaction();
        DAT_mem_0367 = DAT_mem_057a;
        DAT_mem_0368 = DAT_mem_057b;
        DAT_mem_057a = 0x2c;
        Z = &R15R14->bmRequestType;
        setup._0_1_ = (byte)R15R14->wIndex;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + ',');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x15eb;
        twi_write_read_transaction();
        DAT_mem_0369 = DAT_mem_057a;
        DAT_mem_036a = DAT_mem_057b;
        DAT_mem_057a = 0x2e;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        setup._0_1_ = (byte)*(ushort *)X;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '.');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x1606;
        twi_write_read_transaction();
        DAT_mem_036b = DAT_mem_057a;
        setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,DAT_mem_057b);
        DAT_mem_036c = DAT_mem_057b;
        R17R16._1_1_ = 0x1a;
        uVar9 = host_watchdog_threshold;
        goto LAB_code_1b6f;
      }
    }
  }
  else if (R17R16._1_1_ < 0x12) {
    if (R17R16._1_1_ == 0xf) {
      Z = &setup->bmRequestType;
      *(undefined2 *)(uVar8 - 0x11) = 0x132d;
      eeprom_update_word();
      setup = (UsbSetupPacket *)((uint)setup._1_1_ << 8);
    }
    else if (R17R16._1_1_ < 0xf) {
      if (R17R16._1_1_ == 0xd) {
        OCR0A = 0xff;
        OCR0B = 0xff;
        R19R18 = (undefined1 *)0xff;
        OCR1A._1_1_ = 0;
        OCR1A._0_1_ = 0xff;
        OCR1B._1_1_ = 0;
        OCR1B._0_1_ = 0xff;
        OCR2A = 0xff;
        OCR2B = 0xff;
        setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,10);
        calibration_ticks_remaining = 10;
      }
      else if (R17R16._1_1_ == 0xe) {
        X = (UsbSetupPacket *)&setup->wIndex;
        R17R16._0_1_ = (byte)*(ushort *)X;
        bVar1 = (byte)R17R16 + 10;
        R17R16 = (byte *)CONCAT11((((byte)R17R16 < 0xf6) + -1) * -2 + CARRY1(bVar1,bVar1),
                                  bVar1 * '\x02');
        setup = (UsbSetupPacket *)R17R16;
        *(undefined2 *)(uVar8 - 0x11) = 0x122d;
        setup._0_1_ = eeprom_read_byte((ushort)setup);
        usb_reply_buffer = (byte)setup;
        setup = (UsbSetupPacket *)&((UsbSetupPacket *)R17R16)->bRequest;
        *(undefined2 *)(uVar8 - 0x11) = 0x1233;
        setup._0_1_ = eeprom_read_byte((ushort)setup);
        setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,(byte)setup);
        goto LAB_code_1355;
      }
    }
    else if (R17R16._1_1_ == 0x10) {
      DAT_mem_057a = 0x82;
      R17R16 = (byte *)0x1002;
      *(undefined2 *)(uVar8 - 0x11) = 0x1410;
      twi_write_read_transaction();
      if ((byte)setup != '\0') {
        usb_reply_buffer = DAT_mem_057b;
        DAT_mem_0354 = DAT_mem_057a;
        DAT_mem_057a = -0x7d;
        *(undefined2 *)(uVar8 - 0x11) = 0x1425;
        twi_write_read_transaction();
        DAT_mem_0355 = DAT_mem_057b;
        DAT_mem_0356 = DAT_mem_057a;
        DAT_mem_057a = -0x7a;
        *(undefined2 *)(uVar8 - 0x11) = 0x1437;
        twi_write_read_transaction();
        DAT_mem_0357 = DAT_mem_057b;
        DAT_mem_0358 = DAT_mem_057a;
        DAT_mem_057a = -0x7f;
        *(undefined2 *)(uVar8 - 0x11) = 0x1449;
        twi_write_read_transaction();
        DAT_mem_0359 = DAT_mem_057b;
        DAT_mem_035a = DAT_mem_057a;
        DAT_mem_057a = -0x78;
        *(undefined2 *)(uVar8 - 0x11) = 0x145b;
        twi_write_read_transaction();
        DAT_mem_035b = DAT_mem_057b;
        DAT_mem_035c = DAT_mem_057a;
        R17R16._1_1_ = -0x7b;
        DAT_mem_057a = -0x7b;
        *(undefined2 *)(uVar8 - 0x11) = 0x146d;
        twi_write_read_transaction();
        DAT_mem_035d = DAT_mem_057b;
        DAT_mem_035e = DAT_mem_057a;
        DAT_mem_057a = -0x7c;
        *(undefined2 *)(uVar8 - 0x11) = 0x147f;
        twi_write_read_transaction();
        DAT_mem_035f = DAT_mem_057b;
        DAT_mem_0360 = DAT_mem_057a;
        DAT_mem_057a = R17R16._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x1490;
        twi_write_read_transaction();
        DAT_mem_0361 = DAT_mem_057b;
        DAT_mem_0362 = DAT_mem_057a;
        DAT_mem_057a = 0x87;
        *(undefined2 *)(uVar8 - 0x11) = 0x14a2;
        twi_write_read_transaction();
        DAT_mem_0363 = DAT_mem_057b;
        setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,DAT_mem_057a);
        DAT_mem_0364 = DAT_mem_057a;
        R17R16._1_1_ = 0x12;
        uVar9 = host_watchdog_threshold;
        goto LAB_code_1b6f;
      }
    }
    else if (R17R16._1_1_ == 0x11) {
      X = (UsbSetupPacket *)&setup->wIndex;
      *(undefined2 *)(uVar8 - 0x11) = 0x1a4d;
      oled_set_text_cursor();
      Z = &R15R14->bmRequestType;
      setup._0_1_ = (byte)(R15R14->wValue & 0xfd00);
      if ((ushort)(byte)setup == 0) {
        *(undefined2 *)(uVar8 - 0x11) = 0x1a54;
        oled_set_scale();
      }
      X = (UsbSetupPacket *)((int)&R15R14->wValue + 1);
      setup._0_1_ = *(byte *)X;
      setup._0_1_ = (byte)setup & 0xfd;
      if ((byte)setup == 1) {
        *(undefined2 *)(uVar8 - 0x11) = 0x1a5d;
        oled_set_scale();
      }
      Z = &R15R14->bmRequestType;
      *(undefined2 *)(uVar8 - 0x11) = 0x1a61;
      oled_render_character();
      X = (UsbSetupPacket *)((int)&R15R14->wValue + 1);
      setup._0_1_ = *(byte *)X;
      if ((byte)setup == '\x02') {
        X = (UsbSetupPacket *)((int)&R15R14->wIndex + 1);
        setup._0_1_ = *(byte *)X;
        setup = (UsbSetupPacket *)(uint)(byte)setup;
        X._0_1_ = (char)R15R14 + '\x04';
        X = (UsbSetupPacket *)CONCAT11(0x14,(byte)X);
        R1R0 = (int)setup * 0x14;
        R1R0 = R1R0 & 0xff;
        Z = &R15R14->bmRequestType;
        *(undefined2 *)(uVar8 - 0x11) = 0x1a78;
        eeprom_update_byte();
      }
      X = (UsbSetupPacket *)((int)&R15R14->wValue + 1);
      setup._0_1_ = *(byte *)X;
      X = R15R14;
      if ((byte)setup == '\x03') {
        X = (UsbSetupPacket *)((int)&R15R14->wIndex + 1);
        setup._0_1_ = *(byte *)X;
        setup = (UsbSetupPacket *)(uint)(byte)setup;
        X._0_1_ = (char)R15R14 + '\x04';
        X = (UsbSetupPacket *)CONCAT11(0x14,(byte)X);
        R1R0 = (int)setup * 0x14;
        R1R0 = R1R0 & 0xff;
        Z = &R15R14->bmRequestType;
        *(undefined2 *)(uVar8 - 0x11) = 0x1a90;
        eeprom_update_byte();
        X = (UsbSetupPacket *)((int)&R15R14->wIndex + 1);
        R19R18._0_1_ = *(byte *)X;
        X._0_1_ = (char)R15R14 + '\x04';
        X = (UsbSetupPacket *)CONCAT11(0x14,(byte)X);
        R1R0 = (uint)(byte)R19R18 * 0x14;
        R1R0 = R1R0 & 0xff;
        *(undefined2 *)(uVar8 - 0x11) = 0x1aa1;
        eeprom_update_byte();
        R19R18._0_1_ = *(byte *)((int)&R15R14->wIndex + 1);
        Z._0_1_ = (byte)R15R14;
        Z = (byte *)CONCAT11(0x14,(byte)Z);
        R1R0 = (uint)(byte)R19R18 * 0x14;
        R1R0 = R1R0 & 0xff;
        *(undefined2 *)(uVar8 - 0x11) = 0x1aaf;
        eeprom_update_byte();
        X = (UsbSetupPacket *)((int)&R15R14->wIndex + 1);
        R19R18._0_1_ = *(byte *)X;
        X._0_1_ = (char)R15R14 + '\x04';
        X = (UsbSetupPacket *)CONCAT11(0x14,(byte)X);
        R1R0 = (uint)(byte)R19R18 * 0x14;
        R1R0 = R1R0 & 0xff;
        *(undefined2 *)(uVar8 - 0x11) = 0x1ac0;
        eeprom_update_byte();
      }
      Z = &R15R14->bmRequestType;
      setup._0_1_ = *(char *)((int)&R15R14->wValue + 1);
      if ((byte)setup == '\x04') {
        *(undefined2 *)(uVar8 - 0x11) = 0x1ac7;
        oled_clear();
        R17R16._0_1_ = 200;
        R17R16._1_1_ = '\0';
        do {
          *(undefined2 *)(uVar8 - 0x11) = 0x1acd;
          eeprom_update_byte();
          setup = (UsbSetupPacket *)((uint)setup._1_1_ << 8);
          bVar1 = (byte)R17R16 + 1;
          R17R16._1_1_ = R17R16._1_1_ - (((byte)R17R16 != 0xff) + -1);
          Z = (byte *)CONCAT11(2,(byte)Z);
          R17R16._0_1_ = bVar1;
        } while (bVar1 != 8 || R17R16._1_1_ != (byte)((bVar1 < 8) + '\x02'));
      }
    }
  }
  else if (R17R16._1_1_ == 0x15) {
    Z = &setup->bmRequestType;
    setup._0_1_ = (byte)setup->wIndex;
    if ((byte)setup < 8) {
      *(undefined2 *)(uVar8 - 0x11) = 0x161b;
      twi_read_length_prefixed_block();
      usb_reply_buffer = (byte)setup;
      bVar1 = (byte)setup - 1;
      setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,bVar1);
      if (bVar1 < 0x20) {
        setup = (UsbSetupPacket *)0x0;
        while( true ) {
          if (usb_reply_buffer <= (byte)setup) break;
          Z = (byte *)CONCAT11(-(((byte)setup < 0xad) + -4),(byte)setup + 0x53);
          X = (UsbSetupPacket *)CONCAT11(-(((byte)setup < 0x86) + -6),(byte)setup + 0x7a);
          setup._1_1_ = *(byte *)X;
          *(byte *)((int)Z + 1) = setup._1_1_;
          setup = (UsbSetupPacket *)(uint)(byte)((byte)setup + 1);
        }
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 1) = R1R0._1_1_;
        DAT_mem_057a = 0x88;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        R17R16 = (byte *)CONCAT11(R17R16._1_1_,2);
        *(undefined2 *)(uVar8 - 0x11) = 0x1644;
        twi_write_read_transaction();
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 2) = DAT_mem_057a;
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 3) = DAT_mem_057b;
        DAT_mem_057a = 0x89;
        Z = &R15R14->bmRequestType;
        *(undefined2 *)(uVar8 - 0x11) = 0x1660;
        twi_write_read_transaction();
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 4) = DAT_mem_057a;
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 5) = DAT_mem_057b;
        DAT_mem_057a = 0x97;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        *(undefined2 *)(uVar8 - 0x11) = 0x167d;
        twi_write_read_transaction();
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 6) = DAT_mem_057a;
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 7) = DAT_mem_057b;
        DAT_mem_057a = 0x8b;
        Z = &R15R14->bmRequestType;
        *(undefined2 *)(uVar8 - 0x11) = 0x1699;
        twi_write_read_transaction();
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 8) = DAT_mem_057a;
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 9) = DAT_mem_057b;
        DAT_mem_057a = 0x8c;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        *(undefined2 *)(uVar8 - 0x11) = 0x16b6;
        twi_write_read_transaction();
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 10) = DAT_mem_057a;
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 0xb) = DAT_mem_057b;
        DAT_mem_057a = 0x96;
        Z = &R15R14->bmRequestType;
        *(undefined2 *)(uVar8 - 0x11) = 0x16d2;
        twi_write_read_transaction();
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 0xc) = DAT_mem_057a;
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 0xd) = DAT_mem_057b;
        DAT_mem_057a = 0x8d;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        *(undefined2 *)(uVar8 - 0x11) = 0x16ef;
        twi_write_read_transaction();
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 0xe) = DAT_mem_057a;
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 0xf) = DAT_mem_057b;
        DAT_mem_057a = 0x8e;
        Z = &R15R14->bmRequestType;
        *(undefined2 *)(uVar8 - 0x11) = 0x170b;
        twi_write_read_transaction();
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 0x10) = DAT_mem_057a;
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 0x11) = DAT_mem_057b;
        DAT_mem_057a = 0xd5;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        *(undefined2 *)(uVar8 - 0x11) = 0x1728;
        twi_write_read_transaction();
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 0x12) = DAT_mem_057a;
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,DAT_mem_057b);
        *(byte *)((int)&((UsbSetupPacket *)((int)Z + 0x10))->wValue + 1) = DAT_mem_057b;
        R17R16._1_1_ = usb_reply_buffer + 0x14;
        uVar9 = host_watchdog_threshold;
        goto LAB_code_1b6f;
      }
    }
  }
  else if (R17R16._1_1_ < 0x15) {
    if (R17R16._1_1_ == 0x13) {
      Z = &setup->bmRequestType;
      setup._0_1_ = (byte)setup->wIndex;
      if ((byte)setup < 2) {
        DAT_mem_057a = 0xf7;
        R17R16 = (byte *)0x1308;
        *(undefined2 *)(uVar8 - 0x11) = 0x174c;
        twi_write_read_transaction();
        if ((byte)setup != '\0') {
          setup = (UsbSetupPacket *)(uint)DAT_mem_057a;
          R21R20 = setup;
          R23R22._0_1_ = 0;
          R23R22._1_1_ = 0;
          R17R16._1_1_ = '\f';
          do {
            bVar7 = (byte)R21R20 * '\x02';
            bVar1 = R21R20._1_1_ * '\x02' + CARRY1((byte)R21R20,(byte)R21R20);
            bVar17 = CARRY1(R21R20._1_1_,R21R20._1_1_) ||
                     CARRY1(R21R20._1_1_ * '\x02',CARRY1((byte)R21R20,(byte)R21R20));
            R21R20 = (UsbSetupPacket *)CONCAT11(bVar1,bVar7);
            bVar2 = (byte)R23R22 * '\x02' + bVar17;
            R23R22._1_1_ = R23R22._1_1_ * '\x02' +
                           (CARRY1((byte)R23R22,(byte)R23R22) ||
                           CARRY1((byte)R23R22 * '\x02',bVar17));
            R17R16._1_1_ = R17R16._1_1_ + -1;
            R23R22._0_1_ = bVar2;
          } while (R17R16._1_1_ != '\0');
          setup = (UsbSetupPacket *)(uint)DAT_mem_057b;
          X._0_1_ = 0;
          X._1_1_ = 0;
          R17R16._0_1_ = '\x04';
          do {
            R21R20._0_1_ = (byte)setup * '\x02';
            R21R20._1_1_ = setup._1_1_ * '\x02' + CARRY1((byte)setup,(byte)setup);
            bVar17 = CARRY1(setup._1_1_,setup._1_1_) ||
                     CARRY1(setup._1_1_ * '\x02',CARRY1((byte)setup,(byte)setup));
            setup = (UsbSetupPacket *)CONCAT11(R21R20._1_1_,(byte)R21R20);
            R23R22._0_1_ = (byte)X * '\x02' + bVar17;
            X._1_1_ = X._1_1_ * '\x02' +
                      (CARRY1((byte)X,(byte)X) || CARRY1((byte)X * '\x02',bVar17));
            R17R16._0_1_ = (byte)R17R16 + -1;
            X._0_1_ = (byte)R23R22;
          } while ((byte)R17R16 != '\0');
          R21R20._0_1_ = bVar7 | (byte)R21R20;
          R21R20._1_1_ = bVar1 | R21R20._1_1_;
          R23R22._0_1_ = bVar2 | (byte)R23R22;
          R23R22._1_1_ = R23R22._1_1_ | X._1_1_;
          R11R10 = R23R22;
          R9R8._0_1_ = (byte)R21R20 | DAT_mem_057c >> 4;
          R9R8._1_1_ = R21R20._1_1_;
          *(byte *)(Y + 0xd) = (byte)R9R8;
          *(byte *)(Y + 0xe) = R9R8._1_1_;
          *(byte *)(Y + 0xf) = (byte)R11R10;
          *(byte *)(Y + 0x10) = R11R10._1_1_;
          setup = (UsbSetupPacket *)(uint)DAT_mem_057d;
          R21R20 = setup;
          R23R22._0_1_ = 0;
          R23R22._1_1_ = 0;
          setup = (UsbSetupPacket *)0xc;
          do {
            bVar7 = (byte)R21R20 * '\x02';
            bVar1 = R21R20._1_1_ * '\x02' + CARRY1((byte)R21R20,(byte)R21R20);
            bVar17 = CARRY1(R21R20._1_1_,R21R20._1_1_) ||
                     CARRY1(R21R20._1_1_ * '\x02',CARRY1((byte)R21R20,(byte)R21R20));
            R21R20 = (UsbSetupPacket *)CONCAT11(bVar1,bVar7);
            bVar2 = (byte)R23R22 * '\x02' + bVar17;
            R23R22._1_1_ = R23R22._1_1_ * '\x02' +
                           (CARRY1((byte)R23R22,(byte)R23R22) ||
                           CARRY1((byte)R23R22 * '\x02',bVar17));
            setup._0_1_ = (byte)setup - 1;
            bVar3 = (byte)setup;
            setup = (UsbSetupPacket *)(uint)(byte)setup;
            R23R22._0_1_ = bVar2;
          } while (bVar3 != 0);
          setup = (UsbSetupPacket *)(uint)DAT_mem_057e;
          X._0_1_ = 0;
          X._1_1_ = 0;
          R19R18._0_1_ = '\x04';
          do {
            bVar5 = (byte)setup * '\x02';
            bVar3 = setup._1_1_ * '\x02' + CARRY1((byte)setup,(byte)setup);
            bVar17 = CARRY1(setup._1_1_,setup._1_1_) ||
                     CARRY1(setup._1_1_ * '\x02',CARRY1((byte)setup,(byte)setup));
            setup = (UsbSetupPacket *)CONCAT11(bVar3,bVar5);
            bVar4 = (byte)X * '\x02' + bVar17;
            X._1_1_ = X._1_1_ * '\x02' +
                      (CARRY1((byte)X,(byte)X) || CARRY1((byte)X * '\x02',bVar17));
            R19R18._0_1_ = (byte)R19R18 + -1;
            X._0_1_ = bVar4;
          } while ((byte)R19R18 != '\0');
          setup._0_1_ = bVar5 | bVar7;
          setup._1_1_ = bVar3 | bVar1;
          X._0_1_ = bVar4 | bVar2;
          X._1_1_ = X._1_1_ | R23R22._1_1_;
          setup._0_1_ = (byte)setup | DAT_mem_057f >> 4;
          R3R2._0_1_ = (byte)R15R14->wIndex;
          R3R2._1_1_ = R1R0._1_1_;
          R17R16._0_1_ = (byte)R3R2 * '\x02';
          R17R16._1_1_ = R1R0._1_1_ * '\x02' + CARRY1((byte)R3R2,(byte)R3R2);
          Z._1_1_ = R17R16._1_1_ - (((byte)R17R16 < 0x36) + -5);
          R19R18 = (byte *)CONCAT11(Z._1_1_,(byte)R17R16 - 0x36);
          R21R20._0_1_ = *R19R18;
          R21R20._1_1_ = R19R18[1];
          R13R12 = setup;
          R15R14._0_1_ = (byte)X;
          R15R14._1_1_ = X._1_1_;
          R23R22._0_1_ = '\x04';
          do {
            bVar1 = R15R14._1_1_;
            bVar2 = (byte)R15R14;
            R15R14._1_1_ = R15R14._1_1_ >> 1;
            R15R14._0_1_ = bVar1 << 7 | (byte)R15R14 >> 1;
            bVar1 = R13R12._1_1_;
            R13R12._1_1_ = bVar2 << 7 | R13R12._1_1_ >> 1;
            R13R12._0_1_ = bVar1 << 7 | (byte)R13R12 >> 1;
            R23R22._0_1_ = (byte)R23R22 + -1;
          } while ((byte)R23R22 != '\0');
          bVar17 = R13R12._1_1_ < R21R20._1_1_ ||
                   (byte)(R13R12._1_1_ - R21R20._1_1_) < ((byte)R13R12 < (byte)R21R20);
          R13R12 = (UsbSetupPacket *)
                   CONCAT11(R13R12._1_1_ - (R21R20._1_1_ + ((byte)R13R12 < (byte)R21R20)),
                            (byte)R13R12 - (byte)R21R20);
          R15R14 = (UsbSetupPacket *)
                   CONCAT11(R15R14._1_1_ - ((byte)R15R14 < bVar17),(byte)R15R14 - bVar17);
          Z._0_1_ = '\x03';
          do {
            bVar1 = X._1_1_;
            bVar2 = (byte)X;
            X._1_1_ = X._1_1_ >> 1;
            X._0_1_ = bVar1 << 7 | (byte)X >> 1;
            bVar1 = setup._1_1_;
            setup._1_1_ = bVar2 << 7 | setup._1_1_ >> 1;
            setup._0_1_ = bVar1 << 7 | (byte)setup >> 1;
            Z._0_1_ = (byte)Z + -1;
          } while ((byte)Z != '\0');
          bVar1 = R21R20._1_1_ * '\x02' + CARRY1((byte)R21R20,(byte)R21R20);
          bVar17 = CARRY1(R21R20._1_1_,R21R20._1_1_) ||
                   CARRY1(R21R20._1_1_ * '\x02',CARRY1((byte)R21R20,(byte)R21R20));
          bVar18 = (byte)setup < (byte)((byte)R21R20 * '\x02');
          bVar19 = setup._1_1_ < bVar1 || (byte)(setup._1_1_ - bVar1) < bVar18;
          R9R8 = (UsbSetupPacket *)
                 CONCAT11(setup._1_1_ - (bVar1 + bVar18),(byte)setup + (byte)R21R20 * -2);
          R11R10 = (UsbSetupPacket *)
                   CONCAT11(X._1_1_ - ((byte)X < bVar17 || (byte)((byte)X - bVar17) < bVar19),
                            (byte)X - (bVar17 + bVar19));
          X = (UsbSetupPacket *)
              CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0xad) + -6),(byte)R17R16 + 0x53);
          puVar14 = (undefined1 *)X;
          X = (UsbSetupPacket *)((int)X + 1);
          R1R0._0_1_ = *puVar14;
          X._1_1_ = *(byte *)X;
          X._0_1_ = (byte)R1R0;
          *(undefined2 *)(uVar8 - 0x11) = 0x17d3;
          FUN_code_1bf4();
          R5R4._0_1_ = (byte)R23R22;
          R5R4._1_1_ = R23R22._1_1_;
          R7R6 = setup;
          X._0_1_ = '\v';
          do {
            bVar1 = R5R4._1_1_;
            bVar7 = R7R6._1_1_;
            bVar2 = (byte)R7R6;
            R7R6._1_1_ = R7R6._1_1_ >> 1;
            R7R6._0_1_ = bVar7 << 7 | (byte)R7R6 >> 1;
            R5R4._1_1_ = bVar2 << 7 | R5R4._1_1_ >> 1;
            R5R4._0_1_ = bVar1 << 7 | (byte)R5R4 >> 1;
            X._0_1_ = (byte)X + -1;
          } while ((byte)X != '\0');
          *(undefined2 *)(uVar8 - 0x11) = 0x17e2;
          avr_multiply_32bit();
          X._1_1_ = '\f';
          do {
            X._1_1_ = X._1_1_ + -1;
          } while (X._1_1_ != '\0');
          X = (UsbSetupPacket *)
              CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0x98) + -6),(byte)R17R16 + 0x68);
          R1R0._0_1_ = *(byte *)X;
          X = *(UsbSetupPacket **)X;
          *(undefined2 *)(uVar8 - 0x11) = 0x17f3;
          FUN_code_1bf4();
          R9R8._0_1_ = (byte)R23R22;
          R9R8._1_1_ = R23R22._1_1_;
          R11R10 = setup;
          setup = (UsbSetupPacket *)0xe;
          do {
            bVar1 = R9R8._1_1_;
            bVar7 = R11R10._1_1_;
            bVar2 = (byte)R11R10;
            R11R10._1_1_ = R11R10._1_1_ >> 1;
            R11R10._0_1_ = bVar7 << 7 | (byte)R11R10 >> 1;
            R9R8._1_1_ = bVar2 << 7 | R9R8._1_1_ >> 1;
            R9R8._0_1_ = bVar1 << 7 | (byte)R9R8 >> 1;
            setup._0_1_ = (byte)setup - 1;
            bVar1 = (byte)setup;
            setup = (UsbSetupPacket *)(uint)(byte)setup;
          } while (bVar1 != 0);
          bVar17 = CARRY1((byte)R9R8,(byte)R5R4);
          bVar18 = CARRY1(R9R8._1_1_,R5R4._1_1_) || CARRY1(R9R8._1_1_ + R5R4._1_1_,bVar17);
          R11R10._1_1_ = R11R10._1_1_ + R7R6._1_1_ +
                         (CARRY1((byte)R11R10,(byte)R7R6) ||
                         CARRY1((byte)R11R10 + (byte)R7R6,bVar18));
          X = (UsbSetupPacket *)0x5;
          R11R10._0_1_ = (byte)R11R10 + (byte)R7R6 + bVar18;
          R9R8._0_1_ = (byte)R9R8 + (byte)R5R4;
          R9R8._1_1_ = R9R8._1_1_ + R5R4._1_1_ + bVar17;
          *(undefined2 *)(uVar8 - 0x11) = 0x1806;
          FUN_code_1be9();
          bVar17 = R23R22._1_1_ != -1 || (byte)(R23R22._1_1_ + 1) < ((byte)R23R22 < 0x80);
          R19R18._1_1_ = (byte)setup - (bVar17 + -1);
          R21R20._0_1_ = setup._1_1_ -
                         (((byte)setup != -1 || (byte)((byte)setup + 1) < bVar17) + -1);
          R21R20._1_1_ = 0;
          if (((byte)R21R20 & 0x80) != 0) {
            R21R20._1_1_ = 0xff;
          }
          *(byte *)(Y + 9) = R23R22._1_1_ - (((byte)R23R22 < 0x80) + -1);
          *(byte *)(Y + 10) = R19R18._1_1_;
          *(byte *)(Y + 0xb) = (byte)R21R20;
          *(byte *)(Y + 0xc) = R21R20._1_1_;
          setup._1_1_ = R9R8._1_1_ - 0x2c;
          X._0_1_ = (byte)R11R10 - ((R9R8._1_1_ < 0x2c) + '\x01');
          X._1_1_ = R11R10._1_1_ -
                    (R1R0._1_1_ +
                    ((byte)R11R10 == 0 || (byte)((byte)R11R10 - 1) < (R9R8._1_1_ < 0x2c)));
          *(byte *)(Y + 5) = (byte)R9R8;
          *(byte *)(Y + 6) = setup._1_1_;
          *(byte *)(Y + 7) = (byte)X;
          *(byte *)(Y + 8) = X._1_1_;
          X = (UsbSetupPacket *)CONCAT11(R3R2._1_1_ - (((byte)R3R2 < 0xeb) + -6),(byte)R3R2 + 0x15);
          X._0_1_ = *(byte *)X;
          X = (UsbSetupPacket *)(uint)(byte)X;
          *(undefined2 *)(uVar8 - 0x11) = 0x182a;
          FUN_code_1be9();
          R13R12._0_1_ = (byte)R23R22;
          R13R12._1_1_ = R23R22._1_1_;
          R15R14 = setup;
          R23R22._0_1_ = '\v';
          do {
            bVar1 = R13R12._1_1_;
            cVar20 = R15R14._1_1_;
            bVar2 = (byte)R15R14;
            R15R14._1_1_ = (char)R15R14._1_1_ >> 1;
            R15R14._0_1_ = cVar20 << 7 | (byte)R15R14 >> 1;
            R13R12._1_1_ = bVar2 << 7 | R13R12._1_1_ >> 1;
            R13R12._0_1_ = bVar1 << 7 | (byte)R13R12 >> 1;
            R23R22._0_1_ = (byte)R23R22 + -1;
          } while ((byte)R23R22 != '\0');
          bVar17 = 0x7f < R13R12._1_1_;
          R13R12 = (UsbSetupPacket *)CONCAT11(R13R12._1_1_ + 0x80,(byte)R13R12);
          R15R14 = (UsbSetupPacket *)
                   CONCAT11(R15R14._1_1_ + R1R0._1_1_ +
                            (CARRY1((byte)R15R14,R1R0._1_1_) ||
                            CARRY1((byte)R15R14 + R1R0._1_1_,bVar17)),
                            (byte)R15R14 + R1R0._1_1_ + bVar17);
          X = (UsbSetupPacket *)CONCAT11(R3R2._1_1_ - (((byte)R3R2 < 0x31) + -5),(byte)R3R2 - 0x31);
          X._0_1_ = *(byte *)X;
          R1R0._0_1_ = (byte)X * '\x02';
          X = (UsbSetupPacket *)CONCAT11(-CARRY1((byte)X,(byte)X),(byte)X);
          *(undefined2 *)(uVar8 - 0x11) = 0x1840;
          FUN_code_1bf4();
          Z._0_1_ = '\n';
          do {
            Z._0_1_ = (byte)Z + -1;
          } while ((byte)Z != '\0');
          *(undefined2 *)(uVar8 - 0x11) = 0x184b;
          avr_multiply_32bit();
          Z._1_1_ = '\n';
          do {
            Z._1_1_ = Z._1_1_ + -1;
          } while (Z._1_1_ != '\0');
          X = (UsbSetupPacket *)
              CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0x2f) + -5),(byte)R17R16 - 0x2f);
          R1R0._0_1_ = *(byte *)X;
          X = *(UsbSetupPacket **)X;
          *(undefined2 *)(uVar8 - 0x11) = 0x1860;
          FUN_code_1bf4();
          R5R4._1_1_ = R23R22._1_1_ + 0x20;
          R5R4._0_1_ = (byte)R23R22;
          R7R6._0_1_ = (byte)setup + R1R0._1_1_ + (0xdf < R23R22._1_1_);
          R7R6._1_1_ = setup._1_1_ + R1R0._1_1_ +
                       (CARRY1((byte)setup,R1R0._1_1_) ||
                       CARRY1((byte)setup + R1R0._1_1_,0xdf < R23R22._1_1_));
          X._0_1_ = '\x0e';
          do {
            cVar20 = R7R6._1_1_;
            bVar2 = (byte)R7R6;
            bVar1 = R5R4._1_1_;
            R7R6._1_1_ = (char)R7R6._1_1_ >> 1;
            R7R6._0_1_ = cVar20 << 7 | (byte)R7R6 >> 1;
            R5R4._1_1_ = bVar2 << 7 | R5R4._1_1_ >> 1;
            R5R4._0_1_ = bVar1 << 7 | (byte)R5R4 >> 1;
            X._0_1_ = (byte)X + -1;
          } while ((byte)X != '\0');
          R13R12._0_1_ = DAT_mem_0581;
          R13R12._1_1_ = DAT_mem_0580;
          R15R14._0_1_ = R1R0._1_1_;
          R15R14._1_1_ = R1R0._1_1_;
          X._1_1_ = '\x0e';
          do {
            bVar7 = (byte)R13R12 * '\x02';
            bVar1 = R13R12._1_1_ * '\x02' + CARRY1((byte)R13R12,(byte)R13R12);
            bVar17 = CARRY1(R13R12._1_1_,R13R12._1_1_) ||
                     CARRY1(R13R12._1_1_ * '\x02',CARRY1((byte)R13R12,(byte)R13R12));
            bVar2 = (byte)R15R14 * '\x02' + bVar17;
            R15R14._1_1_ = R15R14._1_1_ * '\x02' +
                           (CARRY1((byte)R15R14,(byte)R15R14) ||
                           CARRY1((byte)R15R14 * '\x02',bVar17));
            X._1_1_ = X._1_1_ + -1;
            R13R12._0_1_ = bVar7;
            R13R12._1_1_ = bVar1;
            R15R14._0_1_ = bVar2;
          } while (X._1_1_ != '\0');
          bVar4 = bVar1 + 0x40;
          bVar3 = bVar2 + R1R0._1_1_ + (0xbf < bVar1);
          X = (UsbSetupPacket *)
              CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0xef) + -6),(byte)R17R16 + 0x11);
          puVar15 = (undefined2 *)X;
          X = (UsbSetupPacket *)((int)X + 1);
          setup._1_1_ = *(byte *)X;
          bVar17 = CARRY1(setup._1_1_,setup._1_1_);
          X._1_1_ = -bVar17;
          R19R18._0_1_ = '\x14';
          setup = (UsbSetupPacket *)*puVar15;
          X._0_1_ = -bVar17;
          do {
            bVar13 = (byte)setup;
            bVar10 = (byte)setup * '\x02';
            bVar5 = setup._1_1_ * '\x02' + CARRY1((byte)setup,(byte)setup);
            bVar17 = CARRY1(setup._1_1_,setup._1_1_) ||
                     CARRY1(setup._1_1_ * '\x02',CARRY1((byte)setup,(byte)setup));
            setup = (UsbSetupPacket *)CONCAT11(bVar5,bVar10);
            bVar6 = (byte)X * '\x02' + bVar17;
            X._1_1_ = X._1_1_ * '\x02' +
                      (CARRY1((byte)X,(byte)X) || CARRY1((byte)X * '\x02',bVar17));
            R19R18._0_1_ = (byte)R19R18 + -1;
            X._0_1_ = bVar6;
          } while ((byte)R19R18 != '\0');
          bVar17 = bVar4 < bVar5 || (byte)(bVar4 - bVar5) < (bVar7 < bVar10);
          R13R12 = (UsbSetupPacket *)
                   CONCAT11(bVar4 - (bVar5 + (bVar7 < bVar10)),bVar7 + bVar13 * -2);
          R15R14 = (UsbSetupPacket *)
                   CONCAT11((R15R14._1_1_ + R1R0._1_1_ +
                            (CARRY1(bVar2,R1R0._1_1_) || CARRY1(bVar2 + R1R0._1_1_,0xbf < bVar1))) -
                            (X._1_1_ + (bVar3 < bVar6 || (byte)(bVar3 - bVar6) < bVar17)),
                            bVar3 - (bVar6 + bVar17));
          X = (UsbSetupPacket *)
              CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0x65) + -6),(byte)R17R16 + 0x9b);
          R1R0._0_1_ = *(byte *)X;
          X = *(UsbSetupPacket **)X;
          *(undefined2 *)(uVar8 - 0x11) = 0x18a1;
          FUN_code_1bf4();
          R19R18._1_1_ = '\x0f';
          do {
            R19R18._1_1_ = R19R18._1_1_ + -1;
          } while (R19R18._1_1_ != '\0');
          *(undefined2 *)(uVar8 - 0x11) = 0x18b4;
          avr_multiply_32bit();
          R13R12 = R23R22;
          R15R14 = setup;
          R21R20._0_1_ = '\x0f';
          do {
            R21R20._0_1_ = (byte)R21R20 + -1;
          } while ((byte)R21R20 != '\0');
          *(undefined2 *)(uVar8 - 0x11) = 0x18c1;
          avr_multiply_32bit();
          R23R22._0_1_ = '\a';
          do {
            R23R22._0_1_ = (byte)R23R22 + -1;
          } while ((byte)R23R22 != '\0');
          Z = (byte *)CONCAT11(R3R2._1_1_ - (((byte)R3R2 < 0xa5) + -6),(byte)R3R2 + 0x5b);
          X._0_1_ = *Z;
          X = (UsbSetupPacket *)(uint)(byte)X;
          *(undefined2 *)(uVar8 - 0x11) = 0x18d1;
          FUN_code_1be9();
          X = setup;
          setup = R23R22;
          R23R22._1_1_ = '\x04';
          do {
            cVar20 = X._1_1_;
            bVar2 = (byte)X;
            X._1_1_ = (char)X._1_1_ >> 1;
            X._0_1_ = cVar20 << 7 | (byte)X >> 1;
            bVar1 = setup._1_1_;
            setup._1_1_ = bVar2 << 7 | setup._1_1_ >> 1;
            setup._0_1_ = bVar1 << 7 | (byte)setup >> 1;
            R23R22._1_1_ = R23R22._1_1_ + -1;
          } while (R23R22._1_1_ != '\0');
          bVar17 = R13R12._1_1_ < setup._1_1_ ||
                   (byte)(R13R12._1_1_ - setup._1_1_) < ((byte)R13R12 < (byte)setup);
          R13R12 = (UsbSetupPacket *)
                   CONCAT11(R13R12._1_1_ - (setup._1_1_ + ((byte)R13R12 < (byte)setup)),
                            (byte)R13R12 - (byte)setup);
          R15R14._1_1_ = R15R14._1_1_ -
                         (X._1_1_ +
                         ((byte)R15R14 < (byte)X || (byte)((byte)R15R14 - (byte)X) < bVar17));
          R15R14 = (UsbSetupPacket *)CONCAT11(R15R14._1_1_,(byte)R15R14 - ((byte)X + bVar17));
          if ((R15R14._1_1_ & 0x80) != 0) {
            R13R12 = (UsbSetupPacket *)CONCAT11(R1R0._1_1_,R1R0._1_1_);
            R15R14 = R13R12;
          }
          bVar17 = (byte)R15R14 < R1R0._1_1_ ||
                   (byte)((byte)R15R14 - R1R0._1_1_) <
                   (R13R12._1_1_ < R1R0._1_1_ ||
                   (byte)(R13R12._1_1_ - R1R0._1_1_) < ((byte)R13R12 == '\0'));
          if ((char)(R15R14._1_1_ - (bVar17 + '\x19')) < '\0' ==
              (SBORROW1(R15R14._1_1_,'\x19') != SBORROW1(R15R14._1_1_ + -0x19,bVar17))) {
            R13R12 = (UsbSetupPacket *)CONCAT11(R1R0._1_1_,R1R0._1_1_);
            R15R14 = (UsbSetupPacket *)CONCAT11(0x19,R1R0._1_1_);
          }
          X = R15R14;
          setup = R13R12;
          R21R20._0_1_ = '\f';
          do {
            cVar20 = X._1_1_;
            bVar2 = (byte)X;
            X._1_1_ = (char)X._1_1_ >> 1;
            X._0_1_ = cVar20 << 7 | (byte)X >> 1;
            bVar1 = setup._1_1_;
            setup._1_1_ = bVar2 << 7 | setup._1_1_ >> 1;
            setup._0_1_ = bVar1 << 7 | (byte)setup >> 1;
            R21R20._0_1_ = (byte)R21R20 + -1;
          } while ((byte)R21R20 != '\0');
          *(byte *)(Y + 5) = (byte)setup;
          *(byte *)(Y + 6) = setup._1_1_;
          *(byte *)(Y + 7) = (byte)X;
          *(byte *)(Y + 8) = X._1_1_;
          cVar20 = R11R10._1_1_;
          bVar2 = (byte)R11R10;
          bVar1 = R9R8._1_1_;
          R11R10._1_1_ = (char)R11R10._1_1_ >> 1;
          R11R10._0_1_ = cVar20 << 7 | (byte)R11R10 >> 1;
          R9R8._1_1_ = bVar2 << 7 | R9R8._1_1_ >> 1;
          R9R8._0_1_ = bVar1 << 7 | (byte)R9R8 >> 1;
          bVar17 = R9R8._1_1_ < 0xfa;
          R9R8 = (UsbSetupPacket *)CONCAT11(R9R8._1_1_ + 6,(byte)R9R8);
          R11R10 = (UsbSetupPacket *)
                   CONCAT11(R11R10._1_1_ -
                            (R1R0._1_1_ +
                            ((byte)R11R10 < R1R0._1_1_ || (byte)((byte)R11R10 - R1R0._1_1_) < bVar17
                            )),(byte)R11R10 - (R1R0._1_1_ + bVar17));
          Z._0_1_ = '\x02';
          do {
            Z._0_1_ = (byte)Z + -1;
          } while ((byte)Z != '\0');
          *(undefined2 *)(uVar8 - 0x11) = 0x1911;
          avr_multiply_32bit();
          R5R4 = R23R22;
          R7R6 = setup;
          Z._1_1_ = '\v';
          do {
            Z._1_1_ = Z._1_1_ + -1;
          } while (Z._1_1_ != '\0');
          Z = (byte *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0xe5) + -6),(byte)R17R16 + 0x1b);
          X = *(UsbSetupPacket **)Z;
          *(undefined2 *)(uVar8 - 0x11) = 0x1923;
          FUN_code_1bf4();
          R13R12 = R23R22;
          R15R14 = setup;
          Z = (byte *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0xf3) + -6),(byte)R17R16 + 0xd);
          X = *(UsbSetupPacket **)Z;
          *(undefined2 *)(uVar8 - 0x11) = 0x192e;
          FUN_code_1bf4();
          bVar7 = (byte)R23R22 * '\x02';
          bVar1 = R23R22._1_1_ * '\x02' + CARRY1((byte)R23R22,(byte)R23R22);
          bVar17 = CARRY1(R23R22._1_1_,R23R22._1_1_) ||
                   CARRY1(R23R22._1_1_ * '\x02',CARRY1((byte)R23R22,(byte)R23R22));
          bVar2 = (byte)setup * '\x02' + bVar17;
          bVar18 = CARRY1(R13R12._1_1_,bVar1) ||
                   CARRY1(R13R12._1_1_ + bVar1,CARRY1((byte)R13R12,bVar7));
          R13R12 = (UsbSetupPacket *)
                   CONCAT11(R13R12._1_1_ + bVar1 + CARRY1((byte)R13R12,bVar7),(byte)R13R12 + bVar7);
          X._0_1_ = (byte)R15R14 + bVar2 + bVar18;
          X._1_1_ = R15R14._1_1_ +
                    setup._1_1_ * '\x02' +
                    (CARRY1((byte)setup,(byte)setup) || CARRY1((byte)setup * '\x02',bVar17)) +
                    (CARRY1((byte)R15R14,bVar2) || CARRY1((byte)R15R14 + bVar2,bVar18));
          setup = R13R12;
          R19R18._1_1_ = '\x02';
          do {
            cVar20 = X._1_1_;
            bVar2 = (byte)X;
            X._1_1_ = (char)X._1_1_ >> 1;
            X._0_1_ = cVar20 << 7 | (byte)X >> 1;
            bVar1 = setup._1_1_;
            setup._1_1_ = bVar2 << 7 | setup._1_1_ >> 1;
            setup._0_1_ = bVar1 << 7 | (byte)setup >> 1;
            R19R18._1_1_ = R19R18._1_1_ + -1;
          } while (R19R18._1_1_ != '\0');
          Z = (byte *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0xa0) + -6),(byte)R17R16 + 0x60);
          R13R12._0_1_ = *Z;
          R13R12._1_1_ = Z[1];
          R1R0 = CONCAT11(R1R0._1_1_,R13R12._1_1_ * '\x02');
          R15R14._0_1_ = (byte)R13R12 + (byte)X;
          R15R14._1_1_ = R13R12._1_1_ + X._1_1_ + CARRY1((byte)R13R12,(byte)X);
          Z = (byte *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0x9c) + -6),(byte)R17R16 + 100);
          X = *(UsbSetupPacket **)Z;
          R23R22._0_1_ = '\r';
          do {
            R23R22._0_1_ = (byte)R23R22 + -1;
          } while ((byte)R23R22 != '\0');
          R13R12._0_1_ = (byte)setup;
          R13R12._1_1_ = setup._1_1_;
          *(undefined2 *)(uVar8 - 0x11) = 0x1961;
          FUN_code_1bf4();
          R5R4._0_1_ = (byte)R23R22;
          R5R4._1_1_ = R23R22._1_1_;
          R7R6 = setup;
          R23R22._1_1_ = '\x03';
          do {
            bVar1 = R5R4._1_1_;
            cVar20 = R7R6._1_1_;
            bVar2 = (byte)R7R6;
            R7R6._1_1_ = (char)R7R6._1_1_ >> 1;
            R7R6._0_1_ = cVar20 << 7 | (byte)R7R6 >> 1;
            R5R4._1_1_ = bVar2 << 7 | R5R4._1_1_ >> 1;
            R5R4._0_1_ = bVar1 << 7 | (byte)R5R4 >> 1;
            R23R22._1_1_ = R23R22._1_1_ + -1;
          } while (R23R22._1_1_ != '\0');
          Z = (byte *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0x3a) + -5),(byte)R17R16 - 0x3a);
          X = *(UsbSetupPacket **)Z;
          *(undefined2 *)(uVar8 - 0x11) = 0x1973;
          FUN_code_1bf4();
          Z._1_1_ = '\x12';
          do {
            Z._1_1_ = Z._1_1_ + -1;
          } while (Z._1_1_ != '\0');
          Z = (byte *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0x8a) + -6),(byte)R17R16 + 0x76);
          X._0_1_ = ((UsbSetupPacket *)Z)->bmRequestType;
          X._1_1_ = ((UsbSetupPacket *)Z)->bRequest;
          *(undefined2 *)(uVar8 - 0x11) = 0x1990;
          FUN_code_1be9();
          R9R8 = R23R22;
          R11R10 = setup;
          X = (UsbSetupPacket *)CONCAT11(X._1_1_,0xf);
          do {
            cVar20 = R11R10._1_1_;
            bVar2 = (byte)R11R10;
            R11R10._1_1_ = (char)R11R10._1_1_ >> 1;
            R11R10._0_1_ = cVar20 << 7 | (byte)R11R10 >> 1;
            bVar1 = R9R8._1_1_;
            R9R8._1_1_ = bVar2 << 7 | R9R8._1_1_ >> 1;
            R9R8._0_1_ = bVar1 << 7 | (byte)R9R8 >> 1;
            X._0_1_ = (byte)X + -1;
          } while ((byte)X != '\0');
          bVar17 = R9R8._1_1_ < R1R0._1_1_ ||
                   (byte)(R9R8._1_1_ - R1R0._1_1_) < ((byte)R9R8 < R1R0._1_1_);
          if ((((byte)R9R8 != R1R0._1_1_ ||
               R9R8._1_1_ != (byte)(R1R0._1_1_ + ((byte)R9R8 < R1R0._1_1_))) ||
              (byte)R11R10 != (byte)(R1R0._1_1_ + bVar17)) ||
              R11R10._1_1_ !=
              (byte)(R1R0._1_1_ +
                    ((byte)R11R10 < R1R0._1_1_ || (byte)((byte)R11R10 - R1R0._1_1_) < bVar17))) {
            R19R18._1_1_ = '\f';
            do {
              cVar20 = R15R14._1_1_;
              bVar2 = (byte)R15R14;
              bVar1 = R13R12._1_1_;
              R15R14._1_1_ = (char)R15R14._1_1_ >> 1;
              R15R14._0_1_ = cVar20 << 7 | (byte)R15R14 >> 1;
              R13R12._1_1_ = bVar2 << 7 | R13R12._1_1_ >> 1;
              R13R12._0_1_ = bVar1 << 7 | (byte)R13R12 >> 1;
              R19R18._1_1_ = R19R18._1_1_ + -1;
            } while (R19R18._1_1_ != '\0');
            X = (UsbSetupPacket *)0xf3cb;
            *(undefined2 *)(uVar8 - 0x11) = 0x19b2;
            FUN_code_1bf7();
            if ((setup._1_1_ - (((byte)setup < 0xb0) + '<') & 0x80) == 0) {
              *(undefined2 *)(uVar8 - 0x11) = 0x19be;
              avr_unsigned_divide_32bit();
              R13R12._0_1_ = (byte)R19R18;
              R13R12._1_1_ = R19R18._1_1_;
              R15R14._0_1_ = (byte)R21R20;
              R15R14._1_1_ = R21R20._1_1_;
            }
            else {
              *(undefined2 *)(uVar8 - 0x11) = 0x19c5;
              avr_unsigned_divide_32bit();
              R13R12._0_1_ = (byte)R19R18 * '\x02';
              R13R12._1_1_ = R19R18._1_1_ * '\x02' + CARRY1((byte)R19R18,(byte)R19R18);
              bVar17 = CARRY1(R19R18._1_1_,R19R18._1_1_) ||
                       CARRY1(R19R18._1_1_ * '\x02',CARRY1((byte)R19R18,(byte)R19R18));
              R15R14._0_1_ = (byte)R21R20 * '\x02' + bVar17;
              R15R14._1_1_ = R21R20._1_1_ * '\x02' +
                             (CARRY1((byte)R21R20,(byte)R21R20) ||
                             CARRY1((byte)R21R20 * '\x02',bVar17));
            }
            R19R18._0_1_ = '\x03';
            do {
              R19R18._0_1_ = (byte)R19R18 + -1;
            } while ((byte)R19R18 != '\0');
            *(undefined2 *)(uVar8 - 0x11) = 0x19d8;
            avr_multiply_32bit();
            R23R22._0_1_ = '\r';
            do {
              R23R22._0_1_ = (byte)R23R22 + -1;
            } while ((byte)R23R22 != '\0');
            Z = (byte *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0xe9) + -6),(byte)R17R16 + 0x17);
            X = *(UsbSetupPacket **)Z;
            *(undefined2 *)(uVar8 - 0x11) = 0x19e8;
            FUN_code_1bf4();
            R9R8._0_1_ = (byte)R23R22;
            R9R8._1_1_ = R23R22._1_1_;
            R11R10 = setup;
            R23R22._1_1_ = '\f';
            do {
              bVar1 = R9R8._1_1_;
              cVar20 = R11R10._1_1_;
              bVar2 = (byte)R11R10;
              R11R10._1_1_ = (char)R11R10._1_1_ >> 1;
              R11R10._0_1_ = cVar20 << 7 | (byte)R11R10 >> 1;
              R9R8._1_1_ = bVar2 << 7 | R9R8._1_1_ >> 1;
              R9R8._0_1_ = bVar1 << 7 | (byte)R9R8 >> 1;
              R23R22._1_1_ = R23R22._1_1_ + -1;
            } while (R23R22._1_1_ != '\0');
            Z._0_1_ = '\x02';
            do {
              Z._0_1_ = (byte)Z + -1;
            } while ((byte)Z != '\0');
            Z = (byte *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0x2b) + -5),(byte)R17R16 - 0x2b);
            X = *(UsbSetupPacket **)Z;
            *(undefined2 *)(uVar8 - 0x11) = 0x1a01;
            FUN_code_1bf4();
            uVar8 = R1R0;
            X = setup;
            setup = R23R22;
            Z._1_1_ = '\r';
            do {
              cVar20 = X._1_1_;
              bVar2 = (byte)X;
              X._1_1_ = (char)X._1_1_ >> 1;
              X._0_1_ = cVar20 << 7 | (byte)X >> 1;
              bVar1 = setup._1_1_;
              setup._1_1_ = bVar2 << 7 | setup._1_1_ >> 1;
              setup._0_1_ = bVar1 << 7 | (byte)setup >> 1;
              Z._1_1_ = Z._1_1_ + -1;
            } while (Z._1_1_ != '\0');
            bVar7 = (byte)R9R8 + (byte)setup;
            bVar1 = R9R8._1_1_ + setup._1_1_ + CARRY1((byte)R9R8,(byte)setup);
            bVar18 = CARRY1(R9R8._1_1_,setup._1_1_) ||
                     CARRY1(R9R8._1_1_ + setup._1_1_,CARRY1((byte)R9R8,(byte)setup));
            bVar2 = (byte)R11R10 + (byte)X + bVar18;
            bVar17 = CARRY1((byte)R11R10,(byte)X);
            X._0_1_ = (byte)R11R10 + (byte)X;
            Z = (byte *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0xa9) + -6),(byte)R17R16 + 0x57);
            setup._0_1_ = *Z;
            setup._1_1_ = Z[1];
            pUVar11 = *(UsbSetupPacket **)Z;
            R1R0 = R1R0 & 0xff00;
            uVar12 = R1R0;
            bVar3 = -CARRY1(setup._1_1_,setup._1_1_);
            R9R8._0_1_ = bVar7 + (byte)setup;
            R9R8._1_1_ = bVar1 + setup._1_1_ + CARRY1(bVar7,(byte)setup);
            bVar19 = CARRY1(bVar1,setup._1_1_) ||
                     CARRY1(bVar1 + setup._1_1_,CARRY1(bVar7,(byte)setup));
            R11R10._0_1_ = bVar2 + bVar3 + bVar19;
            R11R10._1_1_ = ((R11R10._1_1_ + X._1_1_ + (bVar17 || CARRY1((byte)X,bVar18))) -
                           CARRY1(setup._1_1_,setup._1_1_)) +
                           (CARRY1(bVar2,bVar3) || CARRY1(bVar2 + bVar3,bVar19));
            X._0_1_ = '\x04';
            do {
              cVar20 = R11R10._1_1_;
              bVar2 = (byte)R11R10;
              bVar1 = R9R8._1_1_;
              R11R10._1_1_ = (char)R11R10._1_1_ >> 1;
              R11R10._0_1_ = cVar20 << 7 | (byte)R11R10 >> 1;
              R9R8._1_1_ = bVar2 << 7 | R9R8._1_1_ >> 1;
              R9R8._0_1_ = bVar1 << 7 | (byte)R9R8 >> 1;
              X._0_1_ = (byte)X + -1;
            } while ((byte)X != '\0');
            DAT_mem_035e = (byte)R13R12 + (byte)R9R8;
            DAT_mem_035d = R13R12._1_1_ + R9R8._1_1_ + CARRY1((byte)R13R12,(byte)R9R8);
            bVar17 = CARRY1(R13R12._1_1_,R9R8._1_1_) ||
                     CARRY1(R13R12._1_1_ + R9R8._1_1_,CARRY1((byte)R13R12,(byte)R9R8));
            DAT_mem_035c = (byte)R15R14 + (byte)R11R10 + bVar17;
            DAT_mem_035b = R15R14._1_1_ + R11R10._1_1_ +
                           (CARRY1((byte)R15R14,(byte)R11R10) ||
                           CARRY1((byte)R15R14 + (byte)R11R10,bVar17));
            X._0_1_ = *(char *)(Y + 5);
            DAT_mem_035a = (byte)X;
            X._1_1_ = *(byte *)(Y + 6);
            DAT_mem_0359 = X._1_1_;
            Z._0_1_ = *(char *)(Y + 7);
            DAT_mem_0358 = (byte)Z;
            R1R0._1_1_ = SUB21(uVar8,1);
            DAT_mem_0357 = R1R0._1_1_;
            Z._1_1_ = *(char *)(Y + 9);
            DAT_mem_0356 = Z._1_1_;
            R9R8._0_1_ = *(byte *)(Y + 10);
            DAT_mem_0355 = (byte)R9R8;
            DAT_mem_0354 = R1R0._1_1_;
            usb_reply_buffer = R1R0._1_1_;
            R17R16._1_1_ = 0xc;
            R1R0 = uVar12;
            setup = pUVar11;
            uVar9 = host_watchdog_threshold;
            goto LAB_code_1b6f;
          }
        }
      }
    }
    else if (R17R16._1_1_ == 0x14) {
      setup._0_1_ = (byte)setup->wIndex;
      bVar1 = (byte)setup * '\x02';
      setup._1_1_ = CARRY1((byte)setup,(byte)setup);
      Z = (byte *)CONCAT11(setup._1_1_ - ((bVar1 < 0xfb) + -6),bVar1 + 5);
      R19R18._0_1_ = *Z;
      R19R18 = (byte *)CONCAT11(3,(byte)R19R18);
      usb_reply_buffer = (byte)R19R18;
      Z = (byte *)CONCAT11(setup._1_1_ - ((bVar1 < 0xfa) + -6),bVar1 + 6);
      goto LAB_code_1354;
    }
  }
  else if (R17R16._1_1_ == 0x92) {
    dangerous_command_counter = dangerous_command_counter + 1;
    setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,dangerous_command_counter);
    if (4 < dangerous_command_counter) {
      bVar1 = PORTC;
      PORTC = bVar1 | 0x10;
    }
  }
  else if (R17R16._1_1_ == 0x93) {
    bVar1 = dangerous_command_counter + 1;
    setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,bVar1);
    cVar23 = SBORROW1(bVar1,'\x05');
    cVar20 = bVar1 < 5;
    cVar22 = (char)(dangerous_command_counter - 4) < '\0';
    cVar21 = dangerous_command_counter == 4;
    cVar24 = (char)bVar1 < '\x05';
    dangerous_command_counter = bVar1;
    if (!(bool)cVar20) {
      *(undefined2 *)(uVar8 - 0x11) = 0x1b09;
      eeprom_update_byte();
      R1R0._0_1_ = cVar20 == '\x01' | (cVar21 == '\x01') << 1 | (cVar22 == '\x01') << 2 |
                   (cVar23 == '\x01') << 3 | (cVar24 == '\x01') << 4 | (cVar25 == '\x01') << 5 |
                   (cVar26 == '\x01') << 6 | (cVar27 == '\x01') << 7;
      SREG = (byte)R1R0;
      watchdog_reset();
      WDTCSR = 0x18;
      SREG = (byte)R1R0;
      WDTCSR = 0xc;
      *(undefined2 *)(uVar8 - 0x11) = 0x1b15;
      oled_clear();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b18;
      oled_set_scale();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b1c;
      oled_set_text_cursor();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b20;
      oled_print_ram_string();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b24;
      oled_set_text_cursor();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b28;
      oled_print_ram_string();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b2b;
      oled_set_scale();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b2f;
      oled_set_text_cursor();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b33;
      oled_print_ram_string();
      setup = (UsbSetupPacket *)&TCCR3A;
      *(undefined2 *)(uVar8 - 0x11) = 0x1b37;
      eeprom_read_byte((ushort)setup);
      *(undefined2 *)(uVar8 - 0x11) = 0x1b3e;
      integer_to_string();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b42;
      oled_print_ram_string();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b46;
      oled_set_text_cursor();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b4a;
      oled_print_ram_string();
      setup = (UsbSetupPacket *)&UNK_mem_008d;
      *(undefined2 *)(uVar8 - 0x11) = 0x1b4e;
      eeprom_read_byte((ushort)setup);
      *(undefined2 *)(uVar8 - 0x11) = 0x1b55;
      integer_to_string();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b59;
      oled_print_ram_string();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b5d;
      oled_set_text_cursor();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b61;
      oled_print_ram_string();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b69;
      integer_to_string();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b6d;
      oled_print_ram_string();
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  else if (R17R16._1_1_ == 0x91) {
    dangerous_command_counter = dangerous_command_counter + 1;
    setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,dangerous_command_counter);
    if (4 < dangerous_command_counter) {
      bVar1 = PORTC;
      PORTC = bVar1 | 8;
      R17R16._0_1_ = '\x7f';
      R17R16._1_1_ = 0x4f;
      bVar1 = 0x12;
      do {
        cVar20 = (byte)R17R16 + -1;
        bVar2 = R17R16._1_1_ - ((byte)R17R16 == '\0');
        bVar18 = R17R16._1_1_ < ((byte)R17R16 == '\0');
        bVar7 = bVar1 - bVar18;
        bVar17 = SBORROW1(bVar1,bVar18);
        bVar19 = bVar1 < bVar18;
        bVar18 = (char)bVar1 < bVar18;
        R17R16._0_1_ = cVar20;
        R17R16._1_1_ = bVar2;
        bVar1 = bVar7;
      } while ((cVar20 != '\0' || bVar2 != 0) || bVar7 != 0);
      bVar1 = PORTC;
      PORTC = bVar1 & 0xf7;
      R1R0._0_1_ = bVar19 | ((cVar20 == '\0' && bVar2 == 0) && bVar7 == 0) << 1 |
                   ((char)bVar7 < '\0') << 2 | bVar17 << 3 | bVar18 << 4 | cVar25 << 5 | cVar26 << 6
                   | (cVar27 == '\x01') << 7;
      SREG = (byte)R1R0;
      watchdog_reset();
      WDTCSR = 0x18;
      SREG = (byte)R1R0;
      WDTCSR = 0xc;
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  R17R16._1_1_ = 0;
  uVar9 = host_watchdog_threshold;
LAB_code_1b6f:
  uVar8 = Y;
  bVar1 = R17R16._1_1_;
  host_watchdog_threshold._1_1_ = (undefined1)(uVar9 >> 8);
  host_watchdog_threshold._0_1_ = (undefined1)uVar9;
  setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,R17R16._1_1_);
  pUVar11 = setup;
  Y = Y + 0x10;
  R1R0._0_1_ = 0xffef < uVar8 | (uVar8 == 0xfff0) << 1 | ((int)Y < 0) << 2 | SCARRY2(Y,0x10) << 3 |
               ((int)Y < 0 != SCARRY2(Y,0x10)) << 4 | (cVar25 == '\x01') << 5 |
               (cVar26 == '\x01') << 6 | (cVar27 == '\x01') << 7;
  SREG = (byte)R1R0;
  SREG = (byte)R1R0;
  Y._1_1_ = *(undefined1 *)(uVar8 + 0x11);
  Y._0_1_ = *(undefined1 *)(uVar8 + 0x12);
  R17R16._1_1_ = *(undefined1 *)(uVar8 + 0x13);
  R17R16._0_1_ = *(undefined1 *)(uVar8 + 0x14);
  R15R14._1_1_ = *(undefined1 *)(uVar8 + 0x15);
  R15R14._0_1_ = *(undefined1 *)(uVar8 + 0x16);
  R13R12._1_1_ = *(undefined1 *)(uVar8 + 0x17);
  R13R12._0_1_ = *(undefined1 *)(uVar8 + 0x18);
  R11R10._1_1_ = *(undefined1 *)(uVar8 + 0x19);
  R11R10._0_1_ = *(undefined1 *)(uVar8 + 0x1a);
  R9R8._1_1_ = *(undefined1 *)(uVar8 + 0x1b);
  R9R8._0_1_ = *(undefined1 *)(uVar8 + 0x1c);
  R7R6._1_1_ = *(undefined1 *)(uVar8 + 0x1d);
  R7R6._0_1_ = *(undefined1 *)(uVar8 + 0x1e);
  R5R4._1_1_ = *(undefined1 *)(uVar8 + 0x1f);
  R5R4._0_1_ = *(undefined1 *)(uVar8 + 0x20);
  R3R2._1_1_ = *(undefined1 *)(uVar8 + 0x21);
  R3R2._0_1_ = *(undefined1 *)(uVar8 + 0x22);
  setup._0_1_ = bVar1;
  bVar1 = (byte)setup;
  setup = pUVar11;
  return bVar1;
}


/* BYTE0x3712; WORDcode:1b89; avr_multiply_32bit */

undefined2 avr_multiply_32bit(char R25,byte R24)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  bool bVar4;
  
  cVar3 = R25;
  bVar2 = R24;
  R1R0 = (uint)(byte)R1R0;
  X = R23R22;
  FUN_code_1be9();
  X = CONCAT11(cVar3,bVar2);
  R1R0 = (uint)bVar2 * (uint)R18;
  cVar1 = R24 + (byte)R1R0;
  bVar4 = CARRY1(R24,(byte)R1R0);
  R24 = cVar1;
  R1R0._0_1_ = bVar2 * R19;
  bVar2 = cVar3 * R18;
  R25 = R25 + R1R0._1_1_ + bVar4 + (byte)R1R0 + bVar2;
  R1R0 = (uint)bVar2;
  return CONCAT11(cVar1,R25);
}


/* BYTE0x3732; WORDcode:1b99; avr_unsigned_divide_16bit */

void avr_unsigned_divide_16bit(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  
  R1 = 0;
  bVar4 = false;
  Xlo = 0;
  Xhi = 0;
  R21 = '\x11';
  while( true ) {
    bVar2 = (byte)R25R24 * '\x02' + bVar4;
    bVar4 = CARRY1((byte)R25R24,(byte)R25R24) || CARRY1((byte)R25R24 * '\x02',bVar4);
    bVar3 = R25R24._1_1_ * '\x02' + bVar4;
    bVar4 = CARRY1(R25R24._1_1_,R25R24._1_1_) || CARRY1(R25R24._1_1_ * '\x02',bVar4);
    R25R24 = CONCAT11(bVar3,bVar2);
    R21 = R21 + -1;
    if (R21 == '\0') break;
    bVar2 = Xlo * '\x02' + bVar4;
    bVar3 = Xhi * '\x02' + (CARRY1(Xlo,Xlo) || CARRY1(Xlo * '\x02',bVar4));
    bVar1 = (byte)(bVar3 - R23R22._1_1_) < (bVar2 < (byte)R23R22);
    bVar4 = bVar3 < R23R22._1_1_ || bVar1;
    Xlo = bVar2;
    Xhi = bVar3;
    if (bVar3 >= R23R22._1_1_ && !bVar1) {
      Xlo = bVar2 - (byte)R23R22;
      Xhi = bVar3 - (R23R22._1_1_ + (bVar2 < (byte)R23R22));
      bVar4 = bVar3 < R23R22._1_1_ || (byte)(bVar3 - R23R22._1_1_) < (bVar2 < (byte)R23R22);
    }
  }
  R25R24._0_1_ = ~bVar2;
  R25R24._1_1_ = ~bVar3;
  R23R22 = R25R24;
  R21 = 0;
  R25R24._0_1_ = Xlo;
  R25R24._1_1_ = Xhi;
  return;
}


/* BYTE0x375a; WORDcode:1bad; avr_signed_divide_16bit */

undefined2 avr_signed_divide_16bit(byte R25,undefined1 R24,byte R23)

{
  undefined1 uVar1;
  
  R1 = 0;
  uVar1 = R25 >> 7;
  if ((bool)uVar1) {
    FUN_code_1bb9();
  }
  if ((R23 & 0x80) != 0) {
    FUN_code_1bbd();
  }
  avr_unsigned_divide_16bit();
  if ((R0 & 0x80) != 0) {
    FUN_code_1bbd();
  }
  if ((bool)uVar1) {
    R25 = ~R25;
    R24 = -R24;
    R25 = R25 - ((R24 != '\0') + -1);
    return CONCAT11(R24,R25);
  }
  return CONCAT11(R24,R25);
}


/* BYTE0x3772; WORDcode:1bb9; FUN_code_1bb9 */

undefined2 FUN_code_1bb9(byte R25,char R24)

{
  R1 = 0;
  R25 = ~R25;
  R24 = -R24;
  R25 = R25 - ((R24 != '\0') + -1);
  return CONCAT11(R24,R25);
}


/* BYTE0x377a; WORDcode:1bbd; FUN_code_1bbd */

void FUN_code_1bbd(undefined1 param_1,undefined1 param_2,byte R23,char R22)

{
  R1 = 0;
  R23 = ~R23;
  R22 = -R22;
  R23 = R23 - ((R22 != '\0') + -1);
  return;
}


/* BYTE0x3782; WORDcode:1bc1; avr_unsigned_divide_32bit */

void avr_unsigned_divide_32bit(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  bool bVar6;
  
  R1 = '!';
  bVar6 = false;
  Xlo = 0;
  Xhi = 0;
  Zlo = 0;
  Zhi = 0;
  while( true ) {
    bVar2 = (byte)R23R22 * '\x02' + bVar6;
    bVar6 = CARRY1((byte)R23R22,(byte)R23R22) || CARRY1((byte)R23R22 * '\x02',bVar6);
    bVar3 = R23R22._1_1_ * '\x02' + bVar6;
    bVar6 = CARRY1(R23R22._1_1_,R23R22._1_1_) || CARRY1(R23R22._1_1_ * '\x02',bVar6);
    R23R22 = CONCAT11(bVar3,bVar2);
    bVar4 = (byte)R25R24 * '\x02' + bVar6;
    bVar6 = CARRY1((byte)R25R24,(byte)R25R24) || CARRY1((byte)R25R24 * '\x02',bVar6);
    bVar5 = R25R24._1_1_ * '\x02' + bVar6;
    bVar6 = CARRY1(R25R24._1_1_,R25R24._1_1_) || CARRY1(R25R24._1_1_ * '\x02',bVar6);
    R25R24 = CONCAT11(bVar5,bVar4);
    R1 = R1 + -1;
    if (R1 == '\0') break;
    bVar2 = Xlo * '\x02' + bVar6;
    bVar6 = CARRY1(Xlo,Xlo) || CARRY1(Xlo * '\x02',bVar6);
    bVar3 = Xhi * '\x02' + bVar6;
    bVar6 = CARRY1(Xhi,Xhi) || CARRY1(Xhi * '\x02',bVar6);
    bVar4 = Zlo * '\x02' + bVar6;
    bVar5 = Zhi * '\x02' + (CARRY1(Zlo,Zlo) || CARRY1(Zlo * '\x02',bVar6));
    bVar1 = (byte)(bVar5 - R21R20._1_1_) <
            (bVar4 < (byte)R21R20 ||
            (byte)(bVar4 - (byte)R21R20) <
            (bVar3 < R19R18._1_1_ || (byte)(bVar3 - R19R18._1_1_) < (bVar2 < (byte)R19R18)));
    bVar6 = bVar5 < R21R20._1_1_ || bVar1;
    Xlo = bVar2;
    Xhi = bVar3;
    Zlo = bVar4;
    Zhi = bVar5;
    if (bVar5 >= R21R20._1_1_ && !bVar1) {
      Xlo = bVar2 - (byte)R19R18;
      Xhi = bVar3 - (R19R18._1_1_ + (bVar2 < (byte)R19R18));
      bVar6 = bVar3 < R19R18._1_1_ || (byte)(bVar3 - R19R18._1_1_) < (bVar2 < (byte)R19R18);
      Zlo = bVar4 - ((byte)R21R20 + bVar6);
      bVar6 = bVar4 < (byte)R21R20 || (byte)(bVar4 - (byte)R21R20) < bVar6;
      Zhi = bVar5 - (R21R20._1_1_ + bVar6);
      bVar6 = bVar5 < R21R20._1_1_ || (byte)(bVar5 - R21R20._1_1_) < bVar6;
    }
  }
  R23R22._0_1_ = ~bVar2;
  R23R22._1_1_ = ~bVar3;
  R25R24._0_1_ = ~bVar4;
  R25R24._1_1_ = ~bVar5;
  R19R18 = R23R22;
  R21R20 = R25R24;
  R23R22._0_1_ = Xlo;
  R23R22._1_1_ = Xhi;
  R25R24._0_1_ = Zlo;
  R25R24._1_1_ = Zhi;
  return;
}


/* BYTE0x37c6; WORDcode:1be3; gcc_tablejump_helper */

/* WARNING: This is an inlined function */
/* GCC tablejump helper. Marked inline so each caller's flash-table base is visible. Actual12entry
   tables at BYTEcc/e4/fc/114; targets WORD-addressed. Verify generated switch output against source
   bytes. */

void gcc_tablejump_helper(void)

{
  R1 = 0;
  Z = (undefined2 *)CONCAT11(Z._1_1_ * '\x02' + CARRY1((byte)Z,(byte)Z),(byte)Z * '\x02');
  Z = (undefined2 *)*Z;
                    /* WARNING: Could not recover jumptable at 0x1be8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)Z)();
  return;
}


/* BYTE0x37d2; WORDcode:1be9; FUN_code_1be9 */

undefined2 FUN_code_1be9(void)

{
  char cVar1;
  bool bVar2;
  
  R1R0 = (uint)(byte)R1R0;
  FUN_code_1bfc();
  R1R0 = (uint)Xlo * (uint)R20;
  cVar1 = R24 + (byte)R1R0;
  bVar2 = CARRY1(R24,(byte)R1R0);
  R24 = cVar1;
  R25 = R25 + Xlo * R21 + Xhi * R20 + R1R0._1_1_ + bVar2;
  R1R0 = R1R0 & 0xff;
  return CONCAT11(cVar1,R25);
}


/* BYTE0x37e8; WORDcode:1bf4; FUN_code_1bf4 */

undefined2 FUN_code_1bf4(void)

{
  char cVar1;
  bool bVar2;
  
  R1R0 = (uint)(byte)R1R0;
  if ((Xhi & 0x80) == 0) {
    FUN_code_1bfc();
    R1R0 = (uint)Xlo * (uint)R20;
    cVar1 = R24 + (byte)R1R0;
    bVar2 = CARRY1(R24,(byte)R1R0);
    R24 = cVar1;
    R25 = R25 + Xlo * R21 + Xhi * R20 + R1R0._1_1_ + bVar2;
    R1R0 = R1R0 & 0xff;
    return CONCAT11(cVar1,R25);
  }
  FUN_code_1be9();
  cVar1 = R24 - R18;
  bVar2 = R24 < R18;
  R24 = cVar1;
  R25 = R25 - (R19 + bVar2);
  return CONCAT11(cVar1,R25);
}


/* BYTE0x37ee; WORDcode:1bf7; FUN_code_1bf7 */

undefined2 FUN_code_1bf7(void)

{
  char cVar1;
  bool bVar2;
  
  R1 = 0;
  FUN_code_1be9();
  cVar1 = R24 - R18;
  bVar2 = R24 < R18;
  R24 = cVar1;
  R25 = R25 - (R19 + bVar2);
  return CONCAT11(cVar1,R25);
}


/* BYTE0x37f8; WORDcode:1bfc; FUN_code_1bfc */

void FUN_code_1bfc(void)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  
  R1R0 = (uint)Xlo * (uint)R18;
  iVar6 = R1R0;
  R1R0 = (uint)Xhi * (uint)R19;
  iVar7 = R1R0;
  R1R0 = (uint)Xlo * (uint)R19;
  R23R22._1_1_ = (byte)((uint)iVar6 >> 8);
  bVar5 = R23R22._1_1_ + (byte)R1R0;
  bVar8 = CARRY1(R23R22._1_1_,(byte)R1R0);
  R25R24._0_1_ = (byte)iVar7;
  bVar2 = (byte)R25R24 + R1R0._1_1_ + bVar8;
  bVar3 = CARRY1((byte)R25R24,R1R0._1_1_);
  R25R24._0_1_ = (byte)R25R24 + R1R0._1_1_;
  R25R24._1_1_ = (char)((uint)iVar7 >> 8);
  R1R0 = (uint)Xhi * (uint)R18;
  bVar9 = CARRY1(bVar5,(byte)R1R0);
  R23R22 = CONCAT11(bVar5 + (byte)R1R0,(char)iVar6);
  cVar1 = bVar2 + R1R0._1_1_;
  bVar4 = CARRY1(bVar2,R1R0._1_1_);
  bVar2 = bVar2 + R1R0._1_1_;
  R1R0 = R1R0 & 0xff;
  R25R24 = CONCAT11(R25R24._1_1_ + (bVar3 || CARRY1((byte)R25R24,bVar8)) +
                    (bVar4 || CARRY1(bVar2,bVar9)),cVar1 + bVar9);
  return;
}


/* BYTE0x3816; WORDcode:1c0b; integer_to_string */

void integer_to_string(void)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  byte *pbVar4;
  bool bVar5;
  
  R1 = 0;
  X._1_1_ = 0;
  if ((R20 == 10) && ((int)R25R24 < 0)) {
    X._1_1_ = 0x2d;
    R25R24._1_1_ = ~R25R24._1_1_;
    R25R24._0_1_ = -(byte)R25R24;
    R25R24 = (byte *)CONCAT11(R25R24._1_1_ - (((byte)R25R24 != '\0') + -1),(byte)R25R24);
  }
  Z = R23R22;
  R21 = '\0';
  do {
    pbVar4 = Z;
    X._0_1_ = 0;
    do {
      cVar2 = (byte)R25R24 * '\x02';
      bVar5 = CARRY1((byte)R25R24,(byte)R25R24);
      X._0_1_ = (byte)X * '\x02' +
                (CARRY1(R25R24._1_1_,R25R24._1_1_) || CARRY1(R25R24._1_1_ * '\x02',bVar5));
      R25R24._0_1_ = cVar2;
      if (R20 <= (byte)X) {
        X._0_1_ = (byte)X - R20;
        R25R24._0_1_ = cVar2 + '\x01';
      }
      R25R24 = (byte *)CONCAT11(R25R24._1_1_ * '\x02' + bVar5,(byte)R25R24);
      R21 = R21 + -0x10;
    } while (R21 != '\0');
    bVar1 = (byte)X + 0x30;
    if (0x39 < bVar1) {
      bVar1 = (byte)X + 0x57;
    }
    Z = Z + 1;
    *pbVar4 = bVar1;
    pbVar4 = Z;
  } while (R25R24 != (byte *)0x0);
  if (X._1_1_ != R1) {
    Z = Z + 1;
    *pbVar4 = X._1_1_;
  }
  *Z = R1;
  R25R24 = R23R22;
  X = R23R22;
  Z = R23R22;
  do {
    pbVar4 = Z;
    uVar3 = R23R22._1_1_;
    Z = Z + 1;
    R23R22._1_1_ = *pbVar4;
    R23R22 = (byte *)CONCAT11(R23R22._1_1_,uVar3);
  } while (R23R22._1_1_ != 0);
  Z = pbVar4 + -1;
  while (pbVar4 = X, X._1_1_ < Z._1_1_ || (byte)(X._1_1_ - Z._1_1_) < ((byte)X < (byte)Z)) {
    R23R22._1_1_ = *X;
    X = X + 1;
    *pbVar4 = (byte)R23R22;
    *Z = R23R22._1_1_;
    Z = Z + -1;
    R23R22._0_1_ = *Z;
  }
  return;
}


/* BYTE0x3880; WORDcode:1c40; eeprom_read_byte */

byte eeprom_read_byte(ushort eeprom_address)

{
  byte bVar1;
  ushort uVar2;
  
  R1 = 0;
  do {
    bVar1 = EECR;
  } while ((bVar1 & 2) != 0);
  EEAR._1_1_ = eeprom_address._1_1_;
  EEAR._0_1_ = (byte)eeprom_address;
  bVar1 = EECR;
  EECR = bVar1 | 1;
  bVar1 = EEDR;
  eeprom_address = (ushort)bVar1;
  uVar2 = eeprom_address;
  eeprom_address._0_1_ = bVar1;
  bVar1 = (byte)eeprom_address;
  eeprom_address = uVar2;
  return bVar1;
}


/* BYTE0x3890; WORDcode:1c48; eeprom_read_word */

ushort eeprom_read_word(ushort eeprom_address)

{
  R1 = 0;
  FUN_code_1c6d();
  return eeprom_address;
}


/* BYTE0x389c; WORDcode:1c4e; eeprom_update_byte */

void eeprom_update_byte(void)

{
  byte bVar1;
  char in_Hflg;
  char in_Tflg;
  char in_Iflg;
  
  R1 = 0;
  R18 = R22;
  do {
    bVar1 = EECR;
  } while ((bVar1 & 2) != 0);
  EEAR._1_1_ = R25R24._1_1_;
  EEAR._0_1_ = (undefined1)R25R24;
  bVar1 = EECR;
  EECR = bVar1 | 1;
  R25R24 = R25R24 + -1;
  R0 = EEDR;
  if (R0 != R22) {
    EECR = 0;
    EEDR = R22;
    R0 = R0 < R22 | ((char)(R0 - R22) < '\0') << 2 | SBORROW1(R0,R22) << 3 |
         ((char)R0 < (char)R22) << 4 | (in_Hflg == '\x01') << 5 | (in_Tflg == '\x01') << 6 |
         (in_Iflg == '\x01') << 7;
    SREG = R0;
    bVar1 = EECR;
    EECR = bVar1 | 4;
    bVar1 = EECR;
    EECR = bVar1 | 2;
    SREG = R0;
  }
  return;
}


/* BYTE0x389e; WORDcode:1c4f; FUN_code_1c4f */

void FUN_code_1c4f(void)

{
  byte bVar1;
  char in_Hflg;
  char in_Tflg;
  char in_Iflg;
  
  R1 = 0;
  do {
    bVar1 = EECR;
  } while ((bVar1 & 2) != 0);
  EEAR._1_1_ = R25R24._1_1_;
  EEAR._0_1_ = (undefined1)R25R24;
  bVar1 = EECR;
  EECR = bVar1 | 1;
  R25R24 = R25R24 + -1;
  R0 = EEDR;
  if (R0 != R18) {
    EECR = 0;
    EEDR = R18;
    R0 = R0 < R18 | ((char)(R0 - R18) < '\0') << 2 | SBORROW1(R0,R18) << 3 |
         ((char)R0 < (char)R18) << 4 | (in_Hflg == '\x01') << 5 | (in_Tflg == '\x01') << 6 |
         (in_Iflg == '\x01') << 7;
    SREG = R0;
    bVar1 = EECR;
    EECR = bVar1 | 4;
    bVar1 = EECR;
    EECR = bVar1 | 2;
    SREG = R0;
  }
  return;
}


/* BYTE0x38c0; WORDcode:1c60; eeprom_update_word */

void eeprom_update_word(void)

{
  R1 = 0;
  FUN_code_1c4f();
  eeprom_update_byte();
  return;
}


/* BYTE0x38cc; WORDcode:1c66; eeprom_write_word */

void eeprom_write_word(void)

{
  byte bVar1;
  char in_Cflg;
  char in_Zflg;
  char in_Nflg;
  char in_Vflg;
  char in_Sflg;
  char in_Hflg;
  char in_Tflg;
  char in_Iflg;
  
  R1 = 0;
  eeprom_write_byte();
  R18 = R23;
  do {
    bVar1 = EECR;
  } while ((bVar1 & 2) != 0);
  EECR = 0;
  EEAR._1_1_ = R25R24._1_1_;
  EEAR._0_1_ = (undefined1)R25R24;
  EEDR = R23;
  R0 = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
       (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | (in_Hflg == '\x01') << 5 |
       (in_Tflg == '\x01') << 6 | (in_Iflg == '\x01') << 7;
  SREG = R0;
  bVar1 = EECR;
  EECR = bVar1 | 4;
  bVar1 = EECR;
  EECR = bVar1 | 2;
  SREG = R0;
  R25R24 = R25R24 + 1;
  return;
}


/* BYTE0x38da; WORDcode:1c6d; FUN_code_1c6d */

void FUN_code_1c6d(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  bool bVar5;
  
  R1 = 0;
  Z = R25R24;
  do {
    bVar2 = EECR;
  } while ((bVar2 & 2) != 0);
  while( true ) {
    pbVar4 = X;
    cVar1 = R20 + -1;
    bVar5 = R20 == '\0';
    R20 = cVar1;
    bVar2 = R21 - bVar5;
    bVar5 = R21 < bVar5;
    R21 = bVar2;
    if (bVar5) break;
    EEAR._1_1_ = Z._1_1_;
    EEAR._0_1_ = (undefined1)Z;
    bVar3 = EECR;
    EECR = bVar3 | 1;
    Z = Z + 1;
    R0 = EEDR;
    X = X + 1;
    *pbVar4 = R0;
  }
  return;
}


/* BYTE0x38f6; WORDcode:1c7b; eeprom_write_byte */

void eeprom_write_byte(void)

{
  byte bVar1;
  char in_Cflg;
  char in_Zflg;
  char in_Nflg;
  char in_Vflg;
  char in_Sflg;
  char in_Hflg;
  char in_Tflg;
  char in_Iflg;
  
  R1 = 0;
  R18 = R22;
  do {
    bVar1 = EECR;
  } while ((bVar1 & 2) != 0);
  EECR = 0;
  EEAR._1_1_ = R25R24._1_1_;
  EEAR._0_1_ = (undefined1)R25R24;
  EEDR = R22;
  R0 = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
       (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | (in_Hflg == '\x01') << 5 |
       (in_Tflg == '\x01') << 6 | (in_Iflg == '\x01') << 7;
  SREG = R0;
  bVar1 = EECR;
  EECR = bVar1 | 4;
  bVar1 = EECR;
  EECR = bVar1 | 2;
  SREG = R0;
  R25R24 = R25R24 + 1;
  return;
}


/* BYTE0x3912; WORDcode:1c89; terminal_exit_loop */

void terminal_exit_loop(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* BYTE0x7000; WORDcode:3800; bootloader_entry */

void bootloader_entry(void)

{
  R1 = 0;
  bootloader_runtime_startup();
  return;
}


/* BYTE0x713e; WORDcode:389f; bootloader_runtime_startup */

void bootloader_runtime_startup(void)

{
  undefined1 *puVar1;
  
  R1 = 0;
  SREG = 0;
  DAT_mem_013b = MCUSR;
  Y = 0x900;
  R19 = DAT_mem_08fe._1_1_;
  if ((char)DAT_mem_08fe != '8') {
    R19 = 0xff;
  }
  DAT_mem_013c = R19;
  R17 = '\x01';
  X = &DAT_mem_0100;
  Z = &DAT_codebyte_799e;
  while (puVar1 = X, (byte)X != 6 || X._1_1_ != (char)(R17 + ((byte)X < 6))) {
    R0 = *Z;
    Z = Z + 1;
    X = X + 1;
    *puVar1 = R0;
  }
  R18 = '\x01';
  X = &DAT_mem_0106;
  while (puVar1 = X, (byte)X != 0x3b || X._1_1_ != (char)(R18 + ((byte)X < 0x3b))) {
    X = X + 1;
    *puVar1 = R1;
  }
  DAT_mem_08fe = 0x38c5;
  bootloader_usb_main();
  FUN_code_3ccd();
  return;
}


/* BYTE0x718e; WORDcode:38c7; FUN_code_38c7 */

byte FUN_code_38c7(byte R25,byte R24,undefined1 param_3,byte R22)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  
  R1 = 0;
  X = (byte *)CONCAT11(R25,R24);
  R24 = 0;
  R25 = 0;
  R20 = 1;
  R21 = 0xa0;
  R22 = ~R22;
  R19 = 0;
  while( true ) {
    pbVar3 = X;
    bVar2 = R22 + 1;
    bVar5 = R22 != 0xff;
    R22 = bVar2;
    if (!bVar5) break;
    X = X + 1;
    R18 = *pbVar3;
    R24 = R24 ^ R18;
    do {
      bVar1 = R25;
      R25 = bVar5 << 7 | R25 >> 1;
      bVar5 = (bool)(R24 & 1);
      R24 = bVar1 << 7 | R24 >> 1;
      if (!bVar5) {
        R24 = R24 ^ 1;
        R25 = R25 ^ 0xa0;
      }
      bVar1 = R19 + 0x20;
      bVar4 = R19 < 0xe0;
      bVar5 = true;
      R19 = bVar1;
    } while (bVar4);
  }
  return R25;
}


/* BYTE0x71b8; WORDcode:38dc; FUN_code_38dc */

undefined1 FUN_code_38dc(void)

{
  undefined1 *puVar1;
  
  R1 = 0;
  FUN_code_38c7();
  puVar1 = X;
  X = X + 1;
  *puVar1 = R24;
  puVar1 = X;
  X = X + 1;
  *puVar1 = R25;
  return R25;
}


/* BYTE0x741a; WORDcode:3a0d; bootloader_isp_command */

void bootloader_isp_command(void)

{
  int iVar1;
  
  iVar1 = R25R24;
  R1 = 0;
  X = (byte *)(R25R24 + 3);
  R19 = *X;
  X = (byte *)(R25R24 + 4);
  Z._0_1_ = *X;
  R25R24._1_1_ = R19;
  X = (byte *)(iVar1 + 2);
  R18 = *X;
  X = (byte *)iVar1;
  if (R18 == '0') {
    Z._0_1_ = (byte)Z & 3;
    Z = (undefined1 *)CONCAT11(-(((byte)Z < 0xfe) + -2),(byte)Z + 2);
    R25R24._0_1_ = *Z;
    R25R24 = CONCAT11(R19,(undefined1)R25R24);
    R18 = 0x30;
    return;
  }
  if (R18 == 'X') {
    if (R19 == 0) {
      Z = (undefined1 *)0x1;
    }
    else {
      if (R19 != 8) goto LAB_code_3a59;
      Z = (undefined1 *)0x3;
    }
  }
  else {
    if (R18 != 'P') {
      if (R18 == ' ') {
        Z = (undefined1 *)CONCAT11(R19 * '\x02' + CARRY1((byte)Z,(byte)Z),(byte)Z * '\x02');
      }
      else {
        if (R18 != '(') {
          if (R18 == -0x60) {
            FUN_code_3ca5();
            return;
          }
          if (R18 == -0x40) {
            X = (byte *)(iVar1 + 5);
            FUN_code_3cbf();
          }
          else if (R18 == -1) {
            DAT_mem_010f = 0xf1;
          }
          goto LAB_code_3a59;
        }
        Z = (undefined1 *)CONCAT11(R19 * '\x02' + CARRY1((byte)Z,(byte)Z),(byte)Z * '\x02');
        Z = (undefined1 *)((int)Z + 1);
      }
      R25R24._0_1_ = *Z;
      R25R24 = CONCAT11(R19,(undefined1)R25R24);
      return;
    }
    if (R19 == 0) {
      Z = (undefined1 *)0x0;
    }
    else {
      if (R19 != 8) {
LAB_code_3a59:
        R25R24 = (uint)R25R24._1_1_ << 8;
        return;
      }
      Z = (undefined1 *)0x2;
    }
  }
  SPMCSR = 9;
  R25R24._0_1_ = *Z;
  R25R24 = CONCAT11(R19,(undefined1)R25R24);
  return;
}


/* BYTE0x74b6; WORDcode:3a5b; bootloader_usb_main */

void bootloader_usb_main(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  uint *puVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char in_Hflg;
  char in_Tflg;
  char in_Iflg;
  
  R1R0 = (uint)(byte)R1R0;
  bVar1 = DDRC;
  DDRC = bVar1 | 0x40;
  bVar1 = PORTC;
  PORTC = bVar1 | 0x40;
  bVar1 = DDRE;
  DDRE = bVar1 & 0xfb;
  bVar1 = PORTE;
  PORTE = bVar1 | 4;
  FUN_code_3ca5();
  if ((byte)R25R24 != -0x6d) {
    R25R24 = (byte *)0x900;
    X = &EIMSK;
    do {
      iVar3 = (int)R25R24;
      watchdog_reset();
      R25R24 = (byte *)((int)R25R24 + -1);
      cVar8 = (byte)X - (R1R0._1_1_ + (iVar3 == 0));
      X._1_1_ = X._1_1_ - (R1R0._1_1_ +
                          ((byte)X < R1R0._1_1_ || (byte)((byte)X - R1R0._1_1_) < (iVar3 == 0)));
      X = (byte *)CONCAT11(X._1_1_,cVar8);
    } while ((R25R24 != (byte *)0x0 || cVar8 != '\0') || X._1_1_ != '\0');
  }
  bVar1 = DDRC;
  DDRC = bVar1 | 0x20;
  bVar1 = PORTC;
  PORTC = bVar1 | 0x20;
  bVar1 = DDRC;
  DDRC = bVar1 | 0x80;
  bVar1 = PORTC;
  PORTC = bVar1 | 0x80;
  bVar1 = DDRE;
  DDRE = bVar1 | 8;
  bVar1 = PORTE;
  PORTE = bVar1 | 8;
  FUN_code_3cad();
  FUN_code_3cad();
  MCUCR = 1;
  cVar8 = '\x01';
  MCUCR = 2;
  Z = (byte *)0xd4c0;
  do {
    iVar3 = (int)Z;
    watchdog_reset();
    Z = (byte *)((int)Z + -1);
    cVar8 = cVar8 - (iVar3 == 0);
  } while (Z != (byte *)0x0 || cVar8 != '\0');
  FUN_code_3ca5();
  pbVar2 = (byte *)CONCAT11(DAT_mem_010e,DAT_mem_010d);
  cVar11 = SBORROW1((byte)R25R24,-0x6d);
  cVar8 = (byte)R25R24 < 0x93;
  cVar10 = (char)((byte)R25R24 + 0x6d) < '\0';
  cVar9 = (byte)R25R24 == 0x93;
  cVar12 = (char)(byte)R25R24 < -0x6d;
  if ((bool)cVar9) {
    FUN_code_3cad();
  }
  else {
    bVar1 = PINE;
    if (((bVar1 & 4) != 0) && (bVar1 = PINC, (bVar1 & 8) == 0)) goto LAB_code_3a93;
  }
  do {
    pbVar2 = (byte *)CONCAT11(DAT_mem_010e,DAT_mem_010d);
    DAT_mem_010f = 0xfe;
    MCUSR = R1R0._1_1_;
    in_Hflg = in_Hflg == '\x01';
    in_Tflg = in_Tflg == '\x01';
    R1R0._0_1_ = cVar8 == '\x01' | (cVar9 == '\x01') << 1 | (cVar10 == '\x01') << 2 |
                 (cVar11 == '\x01') << 3 | (cVar12 == '\x01') << 4 | in_Hflg << 5 | in_Tflg << 6 |
                 (in_Iflg == '\x01') << 7;
    SREG = (byte)R1R0;
    watchdog_reset();
    R25R24._0_1_ = WDTCSR;
    R25R24._0_1_ = (byte)R25R24 | 0x18;
    WDTCSR = (byte)R25R24;
    WDTCSR = R1R0._1_1_;
    SREG = (byte)R1R0;
    R25R24._0_1_ = EICRA;
    R25R24._0_1_ = (byte)R25R24 | 2;
    EICRA = (byte)R25R24;
    bVar1 = EIMSK;
    EIMSK = bVar1 | 1;
    bVar1 = DDRD;
    DDRD = bVar1 & 0xfd;
    bVar1 = PORTD;
    PORTD = bVar1 & 0xfd;
    cVar8 = '\t';
    Z = (byte *)0x27c0;
    do {
      pbVar4 = Z;
      watchdog_reset();
      Z = Z + -1;
      cVar8 = cVar8 - (pbVar4 == (byte *)0x0);
    } while (Z != (byte *)0x0 || cVar8 != '\0');
    bVar1 = DDRD;
    DDRD = bVar1 | 2;
    bVar1 = PORTD;
    PORTD = bVar1 | 2;
    do {
      DAT_mem_010e = (byte)((uint)pbVar2 >> 8);
      DAT_mem_010d = (byte)pbVar2;
      R17R16._1_1_ = DAT_mem_0121 - 3;
      if ((R17R16._1_1_ & 0x80) == 0) {
        Y = (uint *)CONCAT11(-(((byte)(-DAT_mem_011e + 0xc) < 0xdb) + -2) -
                             (R1R0._1_1_ + (0xc < DAT_mem_011e)),-DAT_mem_011e + '1');
        if (DAT_mem_011d == '-') {
          if (DAT_mem_0121 == '\v') {
            DAT_mem_0111 = 0xc3;
            DAT_mem_0101 = 0x5a;
            DAT_mem_0110 = R1R0._1_1_;
            R25R24 = (byte *)(*Y & 0xff60);
            if ((byte)R25R24 == '\0') {
              R25R24._0_1_ = (byte)Y[1];
              DAT_mem_011a = R1R0._1_1_;
              if (R25R24._1_1_ == R1R0._1_1_) {
                DAT_mem_011b = R1R0._1_1_;
                R19R18 = &DAT_mem_011a;
                R25R24._0_1_ = 2;
              }
              else if (R25R24._1_1_ == 5) {
                DAT_mem_0122 = (byte)R25R24;
LAB_code_3b70:
                R19R18 = &DAT_mem_011a;
                R25R24._0_1_ = 0;
              }
              else {
                if (R25R24._1_1_ == 6) {
                  R25R24._1_1_ = *(char *)((int)Y + 3);
                  if (R25R24._1_1_ == '\x01') {
                    R25R24 = (byte *)0x70fe;
LAB_code_3b3f:
                    DAT_mem_0120 = R25R24._1_1_;
                    DAT_mem_011f = (byte)R25R24;
                    R25R24._0_1_ = 0x12;
                  }
                  else {
                    if (R25R24._1_1_ == '\x02') {
                      R25R24 = (byte *)0x70ec;
                      goto LAB_code_3b3f;
                    }
                    if (R25R24._1_1_ == '\x03') {
                      if ((byte)R25R24 == R1R0._1_1_) {
                        DAT_mem_0120 = 0x71;
                        DAT_mem_011f = 0x3a;
                        R25R24._0_1_ = 4;
                      }
                      else if ((byte)R25R24 == 1) {
                        DAT_mem_0120 = 0x71;
                        DAT_mem_011f = 0x1e;
                        R25R24._0_1_ = 0x1c;
                      }
                      else {
                        if ((byte)R25R24 != 2) goto LAB_code_3b65;
                        DAT_mem_0120 = 0x71;
                        DAT_mem_011f = 0x10;
                        R25R24._0_1_ = 0xe;
                      }
                    }
                    else {
LAB_code_3b65:
                      R25R24._0_1_ = 0;
                    }
                  }
                  DAT_mem_0110 = 0x40;
                  goto LAB_code_3b88;
                }
                if (R25R24._1_1_ == 8) {
                  R19R18 = &DAT_mem_0124;
                  R25R24._0_1_ = 1;
                }
                else {
                  if (R25R24._1_1_ == 9) {
                    DAT_mem_0124 = (byte)R25R24;
                    goto LAB_code_3b70;
                  }
                  R25R24._0_1_ = R25R24._1_1_ == 10;
                  R19R18 = &DAT_mem_011a;
                }
              }
              DAT_mem_0120 = R19R18._1_1_;
              DAT_mem_011f = (byte)R19R18;
LAB_code_3b88:
              R25R24._1_1_ = *(char *)((int)Y + 7);
              if ((R25R24._1_1_ == R1R0._1_1_) &&
                 (R25R24._1_1_ = (byte)Y[3], R25R24._1_1_ < (byte)R25R24)) {
                R25R24._0_1_ = R25R24._1_1_;
              }
            }
            else {
              DAT_mem_0120 = 1;
              DAT_mem_011f = 6;
              if (R25R24._1_1_ == 3) {
                bootloader_isp_command();
                pbVar2 = (byte *)CONCAT11(DAT_mem_010e,DAT_mem_010d);
                DAT_mem_0109 = (byte)R25R24;
                R25R24._0_1_ = 4;
                goto LAB_code_3b88;
              }
              if ((R25R24._1_1_ == 5) || (R25R24._1_1_ == 10)) {
                R25R24._0_1_ = 1;
                goto LAB_code_3b88;
              }
              if (5 < (byte)(R25R24._1_1_ - 4)) {
                if (R25R24._1_1_ == 2) {
                  R25R24._0_1_ = DAT_mem_010f & 0xfe;
                  DAT_mem_010f = (byte)R25R24;
                }
                else {
                  R25R24._0_1_ = DAT_mem_010f | 1;
                  DAT_mem_010f = (byte)R25R24;
                }
LAB_code_3c9d:
                R25R24._0_1_ = 0;
                goto LAB_code_3b88;
              }
              pbVar2 = (byte *)Y[1];
              if (R25R24._1_1_ == 9) goto LAB_code_3c9d;
              R25R24._0_1_ = (byte)Y[3];
              DAT_mem_010c = (byte)R25R24;
              R19R18._0_1_ = *(byte *)((int)Y + 5);
              R19R18._0_1_ = (byte)R19R18 & 2;
              DAT_mem_010b = (byte)R19R18;
              DAT_mem_010a = R25R24._1_1_;
              if ((*Y & 0x80) == 0) {
                R25R24._0_1_ = 0xff;
              }
              DAT_mem_0110 = 0x80;
            }
            DAT_mem_0100 = (byte)R25R24;
          }
        }
        else if ((DAT_mem_0110 & 0x80) != 0) {
          if (DAT_mem_010c < R17R16._1_1_) {
            R17R16._1_1_ = DAT_mem_010c;
          }
          DAT_mem_010c = DAT_mem_010c - R17R16._1_1_;
          R17R16 = (byte *)CONCAT11(R17R16._1_1_,DAT_mem_010c);
          R15R14 = (byte *)CONCAT11(R1R0._1_1_,(char)R15R14);
          R25R24 = pbVar2;
          while( true ) {
            pbVar2 = R25R24;
            puVar5 = Y;
            DAT_mem_010e = (byte)((uint)pbVar2 >> 8);
            DAT_mem_010d = (byte)pbVar2;
            if (R17R16._1_1_ <= R15R14._1_1_) break;
            if (DAT_mem_010a < 7) {
              if (0x6f < DAT_mem_010e && (DAT_mem_010d < R1R0._1_1_) <= (byte)(DAT_mem_010e + 0x90))
              goto LAB_code_3c0a;
              R15R14._1_1_ = R15R14._1_1_ + 2;
              Y = (uint *)((int)Y + 1);
              puVar6 = (undefined1 *)Y;
              R19R18._0_1_ = (byte)*puVar5;
              Y = puVar5 + 1;
              R19R18._1_1_ = *puVar6;
              SPMCSR = 1;
              *(undefined **)((int)pbVar2 << 1) = R19R18;
              store_program_mem();
              R1R0 = (uint)(byte)R19R18;
              R25R24 = pbVar2 + 2;
              Z = pbVar2;
              if ((((uint)R25R24 & 0x7f) == 0) ||
                 ((((byte)R17R16 == 0 && (R17R16._1_1_ <= R15R14._1_1_)) && (DAT_mem_010b != 0)))) {
                SPMCSR = 3;
                *(uint *)((int)pbVar2 * 2) = R1R0;
                store_program_mem();
                do {
                  bVar1 = SPMCSR;
                  R1R0 = (uint)bVar1;
                } while ((bVar1 & 1) != 0);
                SPMCSR = 5;
                *(uint *)((int)pbVar2 * 2) = R1R0;
                store_program_mem();
                do {
                  bVar1 = SPMCSR;
                  R1R0 = (uint)bVar1;
                } while ((bVar1 & 1) != 0);
                SPMCSR = 0x11;
                *(uint *)((int)pbVar2 * 2) = R1R0;
                store_program_mem();
              }
            }
            else {
              Z = (byte *)CONCAT11(0xff,Z._0_1_);
              R13R12._0_1_ = (char)Y;
              R13R12._1_1_ = (byte)((uint)Y >> 8);
              R13R12 = (uint *)CONCAT11(R13R12._1_1_ - (((char)R13R12 != -1) + -1),
                                        (char)R13R12 + '\x01');
              DAT_mem_010e = DAT_mem_010e - ((DAT_mem_010d != 0xff) + -1);
              DAT_mem_010d = DAT_mem_010d + 1;
              FUN_code_3cbf();
              R15R14._1_1_ = R15R14._1_1_ + '\x01';
              Y = R13R12;
              R25R24 = (byte *)CONCAT11(DAT_mem_010e,DAT_mem_010d);
            }
          }
          if ((byte)R17R16 == R1R0._1_1_) {
LAB_code_3c0a:
            DAT_mem_0100 = R1R0._1_1_;
          }
        }
        DAT_mem_0121 = R1R0._1_1_;
      }
      DAT_mem_010e = (byte)((uint)pbVar2 >> 8);
      DAT_mem_010d = (byte)pbVar2;
      if (((DAT_mem_0101 & 0x10) != 0) && (DAT_mem_0100 != 0xff)) {
        Y._0_1_ = DAT_mem_0100;
        if (8 < DAT_mem_0100) {
          Y._0_1_ = 8;
        }
        DAT_mem_0100 = DAT_mem_0100 - (byte)Y;
        R25R24._0_1_ = DAT_mem_0111 ^ 0x88;
        DAT_mem_0111 = (byte)R25R24;
        if ((byte)Y == 0) {
          FUN_code_38dc();
          DAT_mem_0101 = 4;
LAB_code_3c74:
          DAT_mem_0100 = 0xff;
        }
        else {
          if ((DAT_mem_0110 & 0x80) == 0) {
            Z = (byte *)CONCAT11(DAT_mem_0120,DAT_mem_011f);
            X = &DAT_mem_0112;
            R25R24._0_1_ = (byte)Y;
            if ((DAT_mem_0110 & 0x40) == 0) {
              do {
                pbVar7 = Z;
                pbVar4 = X;
                DAT_mem_010e = (byte)((uint)pbVar2 >> 8);
                DAT_mem_010d = (byte)pbVar2;
                Z = Z + 1;
                R25R24._1_1_ = *pbVar7;
                X = X + 1;
                *pbVar4 = R25R24._1_1_;
                pbVar2 = (byte *)CONCAT11(DAT_mem_010e,DAT_mem_010d);
                R25R24._0_1_ = (byte)R25R24 - 1;
              } while ((byte)R25R24 != 0);
            }
            else {
              do {
                pbVar4 = X;
                DAT_mem_010e = (byte)((uint)pbVar2 >> 8);
                DAT_mem_010d = (byte)pbVar2;
                R25R24._1_1_ = *Z;
                X = X + 1;
                *pbVar4 = R25R24._1_1_;
                pbVar2 = (byte *)CONCAT11(DAT_mem_010e,DAT_mem_010d);
                Z = Z + 1;
                R25R24._0_1_ = (byte)R25R24 - 1;
              } while ((byte)R25R24 != 0);
            }
            pbVar2 = (byte *)CONCAT11(DAT_mem_010e,DAT_mem_010d);
            DAT_mem_0120 = Z._1_1_;
            DAT_mem_011f = Z._0_1_;
          }
          else {
            if (DAT_mem_010c < (byte)Y) {
              Y._0_1_ = DAT_mem_010c;
            }
            DAT_mem_010c = DAT_mem_010c - (byte)Y;
            R13R12 = (uint *)CONCAT11(DAT_mem_010a,(char)R13R12);
            Y._1_1_ = 0;
            R15R14 = &DAT_mem_0112;
            while( true ) {
              DAT_mem_010e = (byte)((uint)pbVar2 >> 8);
              DAT_mem_010d = (byte)pbVar2;
              if (Y._1_1_ == (byte)Y) break;
              if (R13R12._1_1_ < 7) {
                R25R24._0_1_ = *pbVar2;
                R17R16 = pbVar2;
              }
              else {
                R17R16 = pbVar2;
                FUN_code_3ca5();
              }
              Z._0_1_ = SUB21(R15R14,0);
              *R15R14 = (byte)R25R24;
              Z = (byte *)CONCAT11(0xff,Z._0_1_);
              R15R14 = (byte *)CONCAT11(R15R14._1_1_ - (((char)R15R14 != -1) + -1),
                                        (char)R15R14 + '\x01');
              cVar8 = (byte)R17R16 + '\x01';
              cVar9 = R17R16._1_1_ - (((byte)R17R16 != -1) + -1);
              R17R16 = (byte *)CONCAT11(cVar9,cVar8);
              pbVar2 = (byte *)CONCAT11(cVar9,cVar8);
              Y._1_1_ = Y._1_1_ + 1;
            }
          }
          DAT_mem_010e = (byte)((uint)pbVar2 >> 8);
          DAT_mem_010d = (byte)pbVar2;
          FUN_code_38dc();
          DAT_mem_0101 = (byte)Y + 4;
          if (DAT_mem_0101 != 0xc) goto LAB_code_3c74;
        }
        pbVar2 = (byte *)CONCAT11(DAT_mem_010e,DAT_mem_010d);
      }
      cVar8 = '\x14';
      do {
        R25R24._1_1_ = PIND;
        R25R24._1_1_ = R25R24._1_1_ & 0xc;
        if (R25R24._1_1_ != 0) goto LAB_code_3c83;
        cVar8 = cVar8 + -1;
      } while (cVar8 != '\0');
      DAT_mem_0122 = R1R0._1_1_;
      DAT_mem_011c = R1R0._1_1_;
LAB_code_3c83:
      cVar11 = SBORROW1(DAT_mem_010f,'\x10');
      cVar8 = DAT_mem_010f < 0x10;
      cVar10 = (char)(DAT_mem_010f - 0x10) < '\0';
      cVar9 = DAT_mem_010f == 0x10;
      cVar12 = (char)DAT_mem_010f < '\x10';
      if ((bool)cVar8) {
        bVar1 = PINC;
        if ((bVar1 & 8) != 0) {
          cVar11 = SBORROW1(DAT_mem_010f,'\x02');
          cVar10 = (char)(DAT_mem_010f - 2) < '\0';
          cVar9 = DAT_mem_010f == 2;
          cVar12 = (char)DAT_mem_010f < '\x02';
          cVar8 = true;
          if (1 < DAT_mem_010f) {
            cVar11 = SBORROW1(DAT_mem_010f,'\x02');
            cVar8 = DAT_mem_010f < 2;
            cVar12 = (char)DAT_mem_010f < '\x02';
            DAT_mem_010f = DAT_mem_010f - 2;
            goto LAB_code_3c96;
          }
        }
      }
      else {
        bVar1 = PINC;
        if ((bVar1 & 8) == 0) {
          cVar11 = SBORROW1(DAT_mem_010f,'\x10');
          cVar8 = DAT_mem_010f < 0x10;
          cVar12 = (char)DAT_mem_010f < '\x10';
          DAT_mem_010f = DAT_mem_010f - 0x10;
LAB_code_3c96:
          cVar10 = (char)DAT_mem_010f < '\0';
          cVar9 = DAT_mem_010f == 0;
        }
      }
    } while (DAT_mem_010f != R1R0._1_1_);
LAB_code_3a93:
    DAT_mem_010e = (byte)((uint)pbVar2 >> 8);
    DAT_mem_010d = (byte)pbVar2;
    in_Iflg = '\0';
    bVar1 = DDRD;
    DDRD = bVar1 & 0xfd;
    bVar1 = PORTD;
    PORTD = bVar1 & 0xfd;
    bVar1 = DDRC;
    DDRC = bVar1 & 0xdf;
    bVar1 = PORTC;
    PORTC = bVar1 & 0xdf;
    bVar1 = DDRC;
    DDRC = bVar1 & 0xbf;
    bVar1 = PORTC;
    PORTC = bVar1 & 0xbf;
    bVar1 = DDRC;
    DDRC = bVar1 & 0x7f;
    bVar1 = PORTC;
    PORTC = bVar1 & 0x7f;
    bVar1 = DDRE;
    DDRE = bVar1 & 0xf7;
    bVar1 = PORTE;
    PORTE = bVar1 & 0xf7;
    EIMSK = R1R0._1_1_;
    EICRA = R1R0._1_1_;
    MCUCR = 1;
    MCUCR = R1R0._1_1_;
    Z = (byte *)0x0;
    vector_RESET();
  } while( true );
}


/* BYTE0x794a; WORDcode:3ca5; FUN_code_3ca5 */

int FUN_code_3ca5(undefined1 R25,byte R24)

{
  byte bVar1;
  
  R1 = 0;
  do {
    bVar1 = EECR;
  } while ((bVar1 & 2) != 0);
  EEAR._1_1_ = R25;
  EEAR._0_1_ = R24;
  bVar1 = EECR;
  EECR = bVar1 | 1;
  R25 = 0;
  R24 = EEDR;
  return (uint)R24 << 8;
}


/* BYTE0x795a; WORDcode:3cad; FUN_code_3cad */

void FUN_code_3cad(void)

{
  byte bVar1;
  char in_Hflg;
  char in_Tflg;
  char in_Iflg;
  
  R1 = 0;
  R18 = R22;
  do {
    bVar1 = EECR;
  } while ((bVar1 & 2) != 0);
  EEAR._1_1_ = R25R24._1_1_;
  EEAR._0_1_ = (undefined1)R25R24;
  bVar1 = EECR;
  EECR = bVar1 | 1;
  R25R24 = R25R24 + -1;
  R0 = EEDR;
  if (R0 != R22) {
    EECR = 0;
    EEDR = R22;
    R0 = R0 < R22 | ((char)(R0 - R22) < '\0') << 2 | SBORROW1(R0,R22) << 3 |
         ((char)R0 < (char)R22) << 4 | (in_Hflg == '\x01') << 5 | (in_Tflg == '\x01') << 6 |
         (in_Iflg == '\x01') << 7;
    SREG = R0;
    bVar1 = EECR;
    EECR = bVar1 | 4;
    bVar1 = EECR;
    EECR = bVar1 | 2;
    SREG = R0;
  }
  return;
}


/* BYTE0x797e; WORDcode:3cbf; FUN_code_3cbf */

void FUN_code_3cbf(void)

{
  byte bVar1;
  char in_Cflg;
  char in_Zflg;
  char in_Nflg;
  char in_Vflg;
  char in_Sflg;
  char in_Hflg;
  char in_Tflg;
  char in_Iflg;
  
  R1 = 0;
  R18 = R22;
  do {
    bVar1 = EECR;
  } while ((bVar1 & 2) != 0);
  EECR = 0;
  EEAR._1_1_ = R25R24._1_1_;
  EEAR._0_1_ = (undefined1)R25R24;
  EEDR = R22;
  R0 = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
       (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | (in_Hflg == '\x01') << 5 |
       (in_Tflg == '\x01') << 6 | (in_Iflg == '\x01') << 7;
  SREG = R0;
  bVar1 = EECR;
  EECR = bVar1 | 4;
  bVar1 = EECR;
  EECR = bVar1 | 2;
  SREG = R0;
  R25R24 = R25R24 + 1;
  return;
}


/* BYTE0x799a; WORDcode:3ccd; FUN_code_3ccd */

void FUN_code_3ccd(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


