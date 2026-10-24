/* BYTE0x718e; WORDcode:38c7; FUN_code_38c7 */

byte FUN_code_38c7(byte R25,byte R24,undefined1 param_3,byte R22)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  
  R1 = 0;
  X = (byte *)CONCAT11(R25,R24);
  R24 = 0;
  R25 = 0;
  R20 = 1;
  R21 = 0xa0;
  R22 = ~R22;
  R19 = 0;
  while( true ) {
    pbVar3 = X;
    bVar2 = R22 + 1;
    bVar5 = R22 != 0xff;
    R22 = bVar2;
    if (!bVar5) break;
    X = X + 1;
    R18 = *pbVar3;
    R24 = R24 ^ R18;
    do {
      bVar1 = R25;
      R25 = bVar5 << 7 | R25 >> 1;
      bVar5 = (bool)(R24 & 1);
      R24 = bVar1 << 7 | R24 >> 1;
      if (!bVar5) {
        R24 = R24 ^ 1;
        R25 = R25 ^ 0xa0;
      }
      bVar1 = R19 + 0x20;
      bVar4 = R19 < 0xe0;
      bVar5 = true;
      R19 = bVar1;
    } while (bVar4);
  }
  return R25;
}

