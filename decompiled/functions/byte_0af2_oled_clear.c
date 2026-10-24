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

