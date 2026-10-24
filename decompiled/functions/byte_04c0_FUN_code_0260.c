/* BYTE0x04c0; WORDcode:0260; FUN_code_0260 */

undefined1 FUN_code_0260(void)

{
  undefined1 *puVar1;
  
  R1 = 0;
  FUN_code_023b();
  puVar1 = X;
  X = X + 1;
  *puVar1 = R24;
  puVar1 = X;
  X = X + 1;
  *puVar1 = R25;
  return R25;
}

