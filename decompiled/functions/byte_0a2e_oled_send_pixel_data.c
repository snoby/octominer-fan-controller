/* BYTE0x0a2e; WORDcode:0517; oled_send_pixel_data */

void oled_send_pixel_data(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  uVar3 = Y;
  uVar2 = R17R16;
  uVar1 = R15R14;
  R1 = 0;
  R15R14 = R25R24;
  R17R16 = R23R22;
  twi_start_address_bounded();
  twi_send_byte_bounded();
  Y = R15R14;
  R17R16._1_1_ = R17R16._1_1_ + R15R14._1_1_ + CARRY1((byte)R17R16,(byte)R15R14);
  R17R16._0_1_ = (byte)R17R16 + (byte)R15R14;
  while ((byte)Y != (byte)R17R16 || Y._1_1_ != (char)(R17R16._1_1_ + ((byte)Y < (byte)R17R16))) {
    Y = Y + 1;
    twi_send_byte_bounded();
  }
  Y = uVar3;
  R15R14 = uVar1;
  R17R16 = uVar2;
  twi_stop();
  return;
}

