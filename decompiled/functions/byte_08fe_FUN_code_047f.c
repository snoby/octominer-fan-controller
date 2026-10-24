/* BYTE0x08fe; WORDcode:047f; FUN_code_047f */

void FUN_code_047f(void)

{
  byte bVar1;
  
  R1 = 0;
  Z = 0x69;
  R24 = EICRA;
  R24 = R24 | 2;
  EICRA = R24;
  bVar1 = EIMSK;
  EIMSK = bVar1 | 1;
  return;
}

