/* BYTE0x37d2; WORDcode:1be9; FUN_code_1be9 */

undefined2 FUN_code_1be9(void)

{
  char cVar1;
  bool bVar2;
  
  R1R0 = (uint)(byte)R1R0;
  FUN_code_1bfc();
  R1R0 = (uint)Xlo * (uint)R20;
  cVar1 = R24 + (byte)R1R0;
  bVar2 = CARRY1(R24,(byte)R1R0);
  R24 = cVar1;
  R25 = R25 + Xlo * R21 + Xhi * R20 + R1R0._1_1_ + bVar2;
  R1R0 = R1R0 & 0xff;
  return CONCAT11(cVar1,R25);
}

