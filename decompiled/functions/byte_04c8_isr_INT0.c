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

