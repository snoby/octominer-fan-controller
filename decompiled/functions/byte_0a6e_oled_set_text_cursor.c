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

