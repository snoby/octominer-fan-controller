/* BYTE0x37f8; WORDcode:1bfc; FUN_code_1bfc */

void FUN_code_1bfc(void)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  
  R1R0 = (uint)Xlo * (uint)R18;
  iVar6 = R1R0;
  R1R0 = (uint)Xhi * (uint)R19;
  iVar7 = R1R0;
  R1R0 = (uint)Xlo * (uint)R19;
  R23R22._1_1_ = (byte)((uint)iVar6 >> 8);
  bVar5 = R23R22._1_1_ + (byte)R1R0;
  bVar8 = CARRY1(R23R22._1_1_,(byte)R1R0);
  R25R24._0_1_ = (byte)iVar7;
  bVar2 = (byte)R25R24 + R1R0._1_1_ + bVar8;
  bVar3 = CARRY1((byte)R25R24,R1R0._1_1_);
  R25R24._0_1_ = (byte)R25R24 + R1R0._1_1_;
  R25R24._1_1_ = (char)((uint)iVar7 >> 8);
  R1R0 = (uint)Xhi * (uint)R18;
  bVar9 = CARRY1(bVar5,(byte)R1R0);
  R23R22 = CONCAT11(bVar5 + (byte)R1R0,(char)iVar6);
  cVar1 = bVar2 + R1R0._1_1_;
  bVar4 = CARRY1(bVar2,R1R0._1_1_);
  bVar2 = bVar2 + R1R0._1_1_;
  R1R0 = R1R0 & 0xff;
  R25R24 = CONCAT11(R25R24._1_1_ + (bVar3 || CARRY1((byte)R25R24,bVar8)) +
                    (bVar4 || CARRY1(bVar2,bVar9)),cVar1 + bVar9);
  return;
}

