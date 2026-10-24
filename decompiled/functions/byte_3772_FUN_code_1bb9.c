/* BYTE0x3772; WORDcode:1bb9; FUN_code_1bb9 */

undefined2 FUN_code_1bb9(byte R25,char R24)

{
  R1 = 0;
  R25 = ~R25;
  R24 = -R24;
  R25 = R25 - ((R24 != '\0') + -1);
  return CONCAT11(R24,R25);
}

