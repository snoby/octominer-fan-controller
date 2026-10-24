/* BYTE0x09ea; WORDcode:04f5; oled_send_commands */

void oled_send_commands(void)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  uVar3 = Y;
  uVar2 = R17R16;
  R1 = 0;
  R17R16._0_1_ = R25R24._1_1_;
  R17R16._1_1_ = R22;
  twi_start_address_bounded();
  twi_send_byte_bounded();
  bVar1 = (byte)R25R24;
  Y = CONCAT11((byte)R17R16,bVar1);
  R25R24 = CONCAT11((byte)R17R16 + CARRY1(bVar1,R17R16._1_1_),bVar1 + R17R16._1_1_);
  R17R16 = R25R24;
  while ((byte)Y != (byte)R17R16 || Y._1_1_ != (byte)(R17R16._1_1_ + ((byte)Y < (byte)R17R16))) {
    Y = Y + 1;
    twi_send_byte_bounded();
  }
  Y = uVar3;
  R17R16 = uVar2;
  twi_stop();
  return;
}

