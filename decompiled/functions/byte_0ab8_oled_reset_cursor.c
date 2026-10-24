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

