/* BYTE0x377a; WORDcode:1bbd; FUN_code_1bbd */

void FUN_code_1bbd(undefined1 param_1,undefined1 param_2,byte R23,char R22)

{
  R1 = 0;
  R23 = ~R23;
  R22 = -R22;
  R23 = R23 - ((R22 != '\0') + -1);
  return;
}

