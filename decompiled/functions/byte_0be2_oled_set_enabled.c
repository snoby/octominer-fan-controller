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

