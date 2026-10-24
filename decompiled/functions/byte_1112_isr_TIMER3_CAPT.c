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

