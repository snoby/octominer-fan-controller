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

