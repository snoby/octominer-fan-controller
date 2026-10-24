/* BYTE0x375a; WORDcode:1bad; avr_signed_divide_16bit */

undefined2 avr_signed_divide_16bit(byte R25,undefined1 R24,byte R23)

{
  undefined1 uVar1;
  
  R1 = 0;
  uVar1 = R25 >> 7;
  if ((bool)uVar1) {
    FUN_code_1bb9();
  }
  if ((R23 & 0x80) != 0) {
    FUN_code_1bbd();
  }
  avr_unsigned_divide_16bit();
  if ((R0 & 0x80) != 0) {
    FUN_code_1bbd();
  }
  if ((bool)uVar1) {
    R25 = ~R25;
    R24 = -R24;
    R25 = R25 - ((R24 != '\0') + -1);
    return CONCAT11(R24,R25);
  }
  return CONCAT11(R24,R25);
}

