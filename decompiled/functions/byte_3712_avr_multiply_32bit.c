/* BYTE0x3712; WORDcode:1b89; avr_multiply_32bit */

undefined2 avr_multiply_32bit(char R25,byte R24)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  bool bVar4;
  
  cVar3 = R25;
  bVar2 = R24;
  R1R0 = (uint)(byte)R1R0;
  X = R23R22;
  FUN_code_1be9();
  X = CONCAT11(cVar3,bVar2);
  R1R0 = (uint)bVar2 * (uint)R18;
  cVar1 = R24 + (byte)R1R0;
  bVar4 = CARRY1(R24,(byte)R1R0);
  R24 = cVar1;
  R1R0._0_1_ = bVar2 * R19;
  bVar2 = cVar3 * R18;
  R25 = R25 + R1R0._1_1_ + bVar4 + (byte)R1R0 + bVar2;
  R1R0 = (uint)bVar2;
  return CONCAT11(cVar1,R25);
}

