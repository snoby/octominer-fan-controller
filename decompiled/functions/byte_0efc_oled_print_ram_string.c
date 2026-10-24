/* BYTE0x0efc; WORDcode:077e; oled_print_ram_string */

void oled_print_ram_string(void)

{
  undefined2 uVar1;
  char *pcVar2;
  
  uVar1 = Y;
  R1 = 0;
  Y = R25R24;
  while( true ) {
    pcVar2 = Y;
    Y = Y + 1;
    R25R24._0_1_ = *pcVar2;
    if ((char)R25R24 == '\0') break;
    oled_render_character();
    R25R24 = (char *)((uint)R25R24._1_1_ << 8);
  }
  Y = (char *)uVar1;
  return;
}

