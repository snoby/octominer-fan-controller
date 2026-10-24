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

