/* BYTE0x3782; WORDcode:1bc1; avr_unsigned_divide_32bit */

void avr_unsigned_divide_32bit(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  bool bVar6;
  
  R1 = '!';
  bVar6 = false;
  Xlo = 0;
  Xhi = 0;
  Zlo = 0;
  Zhi = 0;
  while( true ) {
    bVar2 = (byte)R23R22 * '\x02' + bVar6;
    bVar6 = CARRY1((byte)R23R22,(byte)R23R22) || CARRY1((byte)R23R22 * '\x02',bVar6);
    bVar3 = R23R22._1_1_ * '\x02' + bVar6;
    bVar6 = CARRY1(R23R22._1_1_,R23R22._1_1_) || CARRY1(R23R22._1_1_ * '\x02',bVar6);
    R23R22 = CONCAT11(bVar3,bVar2);
    bVar4 = (byte)R25R24 * '\x02' + bVar6;
    bVar6 = CARRY1((byte)R25R24,(byte)R25R24) || CARRY1((byte)R25R24 * '\x02',bVar6);
    bVar5 = R25R24._1_1_ * '\x02' + bVar6;
    bVar6 = CARRY1(R25R24._1_1_,R25R24._1_1_) || CARRY1(R25R24._1_1_ * '\x02',bVar6);
    R25R24 = CONCAT11(bVar5,bVar4);
    R1 = R1 + -1;
    if (R1 == '\0') break;
    bVar2 = Xlo * '\x02' + bVar6;
    bVar6 = CARRY1(Xlo,Xlo) || CARRY1(Xlo * '\x02',bVar6);
    bVar3 = Xhi * '\x02' + bVar6;
    bVar6 = CARRY1(Xhi,Xhi) || CARRY1(Xhi * '\x02',bVar6);
    bVar4 = Zlo * '\x02' + bVar6;
    bVar5 = Zhi * '\x02' + (CARRY1(Zlo,Zlo) || CARRY1(Zlo * '\x02',bVar6));
    bVar1 = (byte)(bVar5 - R21R20._1_1_) <
            (bVar4 < (byte)R21R20 ||
            (byte)(bVar4 - (byte)R21R20) <
            (bVar3 < R19R18._1_1_ || (byte)(bVar3 - R19R18._1_1_) < (bVar2 < (byte)R19R18)));
    bVar6 = bVar5 < R21R20._1_1_ || bVar1;
    Xlo = bVar2;
    Xhi = bVar3;
    Zlo = bVar4;
    Zhi = bVar5;
    if (bVar5 >= R21R20._1_1_ && !bVar1) {
      Xlo = bVar2 - (byte)R19R18;
      Xhi = bVar3 - (R19R18._1_1_ + (bVar2 < (byte)R19R18));
      bVar6 = bVar3 < R19R18._1_1_ || (byte)(bVar3 - R19R18._1_1_) < (bVar2 < (byte)R19R18);
      Zlo = bVar4 - ((byte)R21R20 + bVar6);
      bVar6 = bVar4 < (byte)R21R20 || (byte)(bVar4 - (byte)R21R20) < bVar6;
      Zhi = bVar5 - (R21R20._1_1_ + bVar6);
      bVar6 = bVar5 < R21R20._1_1_ || (byte)(bVar5 - R21R20._1_1_) < bVar6;
    }
  }
  R23R22._0_1_ = ~bVar2;
  R23R22._1_1_ = ~bVar3;
  R25R24._0_1_ = ~bVar4;
  R25R24._1_1_ = ~bVar5;
  R19R18 = R23R22;
  R21R20 = R25R24;
  R23R22._0_1_ = Xlo;
  R23R22._1_1_ = Xhi;
  R25R24._0_1_ = Zlo;
  R25R24._1_1_ = Zhi;
  return;
}

