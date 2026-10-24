/* BYTE0x37ee; WORDcode:1bf7; FUN_code_1bf7 */

undefined2 FUN_code_1bf7(void)

{
  char cVar1;
  bool bVar2;
  
  R1 = 0;
  FUN_code_1be9();
  cVar1 = R24 - R18;
  bVar2 = R24 < R18;
  R24 = cVar1;
  R25 = R25 - (R19 + bVar2);
  return CONCAT11(cVar1,R25);
}

