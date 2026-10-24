/* BYTE0x1a80; WORDcode:0d40; startup_display_and_eeprom_text */

void startup_display_and_eeprom_text(void)

{
  byte bVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  undefined2 uStack_d;
  undefined2 uStack_b;
  undefined2 uStack_9;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  undefined1 uStack_4;
  
  uVar3 = R15;
  uVar2 = R13R12;
  R1 = '\0';
  uStack_4 = (byte)R17R16;
  uStack_5 = R17R16._1_1_;
  uStack_6 = (undefined1)Y;
  uStack_7 = Y._1_1_;
  uStack_9 = 0xd49;
  uStack_b = 0xd4a;
  Y = CONCAT11((char)((uint)((int)&uStack_d + 1) >> 8),(char)&uStack_d + '\x01');
  watchdog_reset();
  uStack_d = 0xd50;
  oled_init_ssd1306_family();
  uStack_d = 0xd52;
  oled_clear();
  uStack_d = 0xd55;
  oled_set_contrast();
  watchdog_reset();
  uStack_d = 0xd59;
  oled_set_scale();
  R17R16._0_1_ = 0;
  R17R16._1_1_ = '\0';
  R15 = '\x01';
  R13R12 = 0x14;
  do {
    R25R24 = CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0x38) + -1),(byte)R17R16 - 0x38);
    uStack_d = 0xd65;
    R25R24._0_1_ = eeprom_read_byte(R25R24);
    if ((byte)((byte)R25R24 - 1) < 0xfe) {
      uStack_d = 0xd6e;
      avr_signed_divide_16bit();
      uStack_d = 0xd70;
      oled_set_text_cursor();
      uStack_d = 0xd73;
      oled_render_character();
      R15 = '\0';
    }
    bVar1 = (byte)R17R16 + 1;
    R17R16._1_1_ = R17R16._1_1_ - (((byte)R17R16 != 0xff) + -1);
    R17R16._0_1_ = bVar1;
  } while (bVar1 != 0xa0 || (bool)R17R16._1_1_ != bVar1 < 0xa0);
  watchdog_reset();
  uStack_d = 0xd7d;
  oled_set_scale();
  R17R16._0_1_ = 0;
  R17R16._1_1_ = '\0';
  R13R12 = 0x14;
  do {
    R25R24 = CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0x98) + -2),(byte)R17R16 + 0x68);
    uStack_d = 0xd87;
    R25R24._0_1_ = eeprom_read_byte(R25R24);
    bVar1 = (byte)R25R24;
    R25R24._0_1_ = (byte)R25R24 - 1;
    R25R24 = CONCAT11(R25R24._1_1_,(byte)R25R24);
    if ((byte)R25R24 < 0xfe) {
      uStack_d = 0xd90;
      avr_signed_divide_16bit();
      uStack_d = 0xd92;
      oled_set_text_cursor();
      *(byte *)(Y + 1) = bVar1;
      *(char *)(Y + 2) = R1;
      uStack_d = 0xd98;
      oled_print_ram_string();
      R15 = R1;
    }
    bVar1 = (byte)R17R16 + 1;
    R17R16._1_1_ = R17R16._1_1_ - (((byte)R17R16 != 0xff) + -1);
    R17R16._0_1_ = bVar1;
  } while (bVar1 != 0xa0 || R17R16._1_1_ != (char)(R1 + (bVar1 < 0xa0)));
  watchdog_reset();
  if (R15 != '\0') {
    uStack_d = 0xda5;
    oled_set_scale();
    uStack_d = 0xda9;
    oled_set_text_cursor();
    uStack_d = 0xdad;
    oled_print_ram_string();
    uStack_d = 0xdb1;
    oled_set_text_cursor();
    uStack_d = 0xdb5;
    oled_print_ram_string();
    uStack_d = 0xdb8;
    oled_set_scale();
    uStack_d = 0xdbc;
    oled_set_text_cursor();
    uStack_d = 0xdc0;
    oled_print_ram_string();
    R25R24 = 0x90;
    uStack_d = 0xdc4;
    eeprom_read_byte(0x90);
    uStack_d = 0xdcb;
    integer_to_string();
    uStack_d = 0xdcf;
    oled_print_ram_string();
    uStack_d = 0xdd3;
    oled_set_text_cursor();
    uStack_d = 0xdd7;
    oled_print_ram_string();
    R25R24 = 0x8d;
    uStack_d = 0xddb;
    eeprom_read_byte(0x8d);
    uStack_d = 0xde2;
    integer_to_string();
    uStack_d = 0xde6;
    oled_print_ram_string();
    uStack_d = 0xdea;
    oled_set_text_cursor();
    uStack_d = 0xdee;
    oled_print_ram_string();
    uStack_d = 0xdf6;
    integer_to_string();
    uStack_d = 0xdfa;
    oled_print_ram_string();
  }
  watchdog_reset();
  R0 = uStack_9._1_1_;
  Y = CONCAT11(uStack_7,uStack_6);
  R17R16 = CONCAT11(uStack_5,uStack_4);
  R15 = uVar3;
  R13R12 = uVar2;
  return;
}

