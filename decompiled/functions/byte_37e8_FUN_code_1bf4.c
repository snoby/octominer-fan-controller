/* BYTE0x37e8; WORDcode:1bf4; FUN_code_1bf4 */

undefined2 FUN_code_1bf4(void)

{
  char cVar1;
  bool bVar2;
  
  R1R0 = (uint)(byte)R1R0;
  if ((Xhi & 0x80) == 0) {
    FUN_code_1bfc();
    R1R0 = (uint)Xlo * (uint)R20;
    cVar1 = R24 + (byte)R1R0;
    bVar2 = CARRY1(R24,(byte)R1R0);
    R24 = cVar1;
    R25 = R25 + Xlo * R21 + Xhi * R20 + R1R0._1_1_ + bVar2;
    R1R0 = R1R0 & 0xff;
    return CONCAT11(cVar1,R25);
  }
  FUN_code_1be9();
  cVar1 = R24 - R18;
  bVar2 = R24 < R18;
  R24 = cVar1;
  R25 = R25 - (R19 + bVar2);
  return CONCAT11(cVar1,R25);
}

