/* BYTE0x3732; WORDcode:1b99; avr_unsigned_divide_16bit */

void avr_unsigned_divide_16bit(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  
  R1 = 0;
  bVar4 = false;
  Xlo = 0;
  Xhi = 0;
  R21 = '\x11';
  while( true ) {
    bVar2 = (byte)R25R24 * '\x02' + bVar4;
    bVar4 = CARRY1((byte)R25R24,(byte)R25R24) || CARRY1((byte)R25R24 * '\x02',bVar4);
    bVar3 = R25R24._1_1_ * '\x02' + bVar4;
    bVar4 = CARRY1(R25R24._1_1_,R25R24._1_1_) || CARRY1(R25R24._1_1_ * '\x02',bVar4);
    R25R24 = CONCAT11(bVar3,bVar2);
    R21 = R21 + -1;
    if (R21 == '\0') break;
    bVar2 = Xlo * '\x02' + bVar4;
    bVar3 = Xhi * '\x02' + (CARRY1(Xlo,Xlo) || CARRY1(Xlo * '\x02',bVar4));
    bVar1 = (byte)(bVar3 - R23R22._1_1_) < (bVar2 < (byte)R23R22);
    bVar4 = bVar3 < R23R22._1_1_ || bVar1;
    Xlo = bVar2;
    Xhi = bVar3;
    if (bVar3 >= R23R22._1_1_ && !bVar1) {
      Xlo = bVar2 - (byte)R23R22;
      Xhi = bVar3 - (R23R22._1_1_ + (bVar2 < (byte)R23R22));
      bVar4 = bVar3 < R23R22._1_1_ || (byte)(bVar3 - R23R22._1_1_) < (bVar2 < (byte)R23R22);
    }
  }
  R25R24._0_1_ = ~bVar2;
  R25R24._1_1_ = ~bVar3;
  R23R22 = R25R24;
  R21 = 0;
  R25R24._0_1_ = Xlo;
  R25R24._1_1_ = Xhi;
  return;
}

