/* BYTE0x0476; WORDcode:023b; FUN_code_023b */

byte FUN_code_023b(byte R25,byte R24,byte R23,char R22)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  bool bVar5;
  
  R1 = 0;
  X = (byte *)CONCAT11(R25,R24);
  R24 = 0xff;
  R25 = 0xff;
  while (pbVar4 = X, cVar1 = R22 + -1, bVar5 = R22 != '\0', R22 = cVar1, bVar5) {
    X = X + 1;
    R18 = *pbVar4;
    R24 = R24 ^ R18;
    bVar3 = R24;
    R18 = R24 >> 4 ^ R24;
    bVar2 = R18;
    R18 = R18 >> 2;
    R18 = R18 ^ bVar2;
    R18 = R18 + 1;
    R18 = R18 >> 1;
    R18 = R18 & 1;
    R24 = R25 ^ R18;
    R18 = -R18;
    R18 = R18 & 0xc0;
    R23 = bVar3 >> 1;
    bVar2 = R23;
    R25 = R18 ^ R23;
    R24 = R24 ^ bVar3 << 7;
    R23 = bVar3 >> 2;
    R18 = bVar2 << 7 | (bVar3 & 1) << 6;
    R25 = R25 ^ R23;
    R24 = R24 ^ R18;
  }
  R24 = ~R24;
  R25 = ~R25;
  return R25;
}

