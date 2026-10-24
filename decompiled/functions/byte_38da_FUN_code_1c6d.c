/* BYTE0x38da; WORDcode:1c6d; FUN_code_1c6d */

void FUN_code_1c6d(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  bool bVar5;
  
  R1 = 0;
  Z = R25R24;
  do {
    bVar2 = EECR;
  } while ((bVar2 & 2) != 0);
  while( true ) {
    pbVar4 = X;
    cVar1 = R20 + -1;
    bVar5 = R20 == '\0';
    R20 = cVar1;
    bVar2 = R21 - bVar5;
    bVar5 = R21 < bVar5;
    R21 = bVar2;
    if (bVar5) break;
    EEAR._1_1_ = Z._1_1_;
    EEAR._0_1_ = (undefined1)Z;
    bVar3 = EECR;
    EECR = bVar3 | 1;
    Z = Z + 1;
    R0 = EEDR;
    X = X + 1;
    *pbVar4 = R0;
  }
  return;
}

