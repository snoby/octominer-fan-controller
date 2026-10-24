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

