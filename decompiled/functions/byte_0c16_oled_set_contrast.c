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

