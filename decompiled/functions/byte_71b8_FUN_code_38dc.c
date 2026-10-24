/* BYTE0x71b8; WORDcode:38dc; FUN_code_38dc */

undefined1 FUN_code_38dc(void)

{
  undefined1 *puVar1;
  
  R1 = 0;
  FUN_code_38c7();
  puVar1 = X;
  X = X + 1;
  *puVar1 = R24;
  puVar1 = X;
  X = X + 1;
  *puVar1 = R25;
  return R25;
}

