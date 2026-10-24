/* BYTE0x3816; WORDcode:1c0b; integer_to_string */

void integer_to_string(void)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  byte *pbVar4;
  bool bVar5;
  
  R1 = 0;
  X._1_1_ = 0;
  if ((R20 == 10) && ((int)R25R24 < 0)) {
    X._1_1_ = 0x2d;
    R25R24._1_1_ = ~R25R24._1_1_;
    R25R24._0_1_ = -(byte)R25R24;
    R25R24 = (byte *)CONCAT11(R25R24._1_1_ - (((byte)R25R24 != '\0') + -1),(byte)R25R24);
  }
  Z = R23R22;
  R21 = '\0';
  do {
    pbVar4 = Z;
    X._0_1_ = 0;
    do {
      cVar2 = (byte)R25R24 * '\x02';
      bVar5 = CARRY1((byte)R25R24,(byte)R25R24);
      X._0_1_ = (byte)X * '\x02' +
                (CARRY1(R25R24._1_1_,R25R24._1_1_) || CARRY1(R25R24._1_1_ * '\x02',bVar5));
      R25R24._0_1_ = cVar2;
      if (R20 <= (byte)X) {
        X._0_1_ = (byte)X - R20;
        R25R24._0_1_ = cVar2 + '\x01';
      }
      R25R24 = (byte *)CONCAT11(R25R24._1_1_ * '\x02' + bVar5,(byte)R25R24);
      R21 = R21 + -0x10;
    } while (R21 != '\0');
    bVar1 = (byte)X + 0x30;
    if (0x39 < bVar1) {
      bVar1 = (byte)X + 0x57;
    }
    Z = Z + 1;
    *pbVar4 = bVar1;
    pbVar4 = Z;
  } while (R25R24 != (byte *)0x0);
  if (X._1_1_ != R1) {
    Z = Z + 1;
    *pbVar4 = X._1_1_;
  }
  *Z = R1;
  R25R24 = R23R22;
  X = R23R22;
  Z = R23R22;
  do {
    pbVar4 = Z;
    uVar3 = R23R22._1_1_;
    Z = Z + 1;
    R23R22._1_1_ = *pbVar4;
    R23R22 = (byte *)CONCAT11(R23R22._1_1_,uVar3);
  } while (R23R22._1_1_ != 0);
  Z = pbVar4 + -1;
  while (pbVar4 = X, X._1_1_ < Z._1_1_ || (byte)(X._1_1_ - Z._1_1_) < ((byte)X < (byte)Z)) {
    R23R22._1_1_ = *X;
    X = X + 1;
    *pbVar4 = (byte)R23R22;
    *Z = R23R22._1_1_;
    Z = Z + -1;
    R23R22._0_1_ = *Z;
  }
  return;
}

