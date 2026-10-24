/* BYTE0x197c; WORDcode:0cbe; twi_write_read_transaction */

byte twi_write_read_transaction(undefined1 R25,byte R24,undefined1 R21,char R20)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  
  cVar2 = R16;
  R1 = '\0';
  if (R20 != '\0') {
    TWCR0 = 0xa4;
    do {
      bVar1 = TWCR0;
    } while ((bVar1 & 0x80) == 0);
    R25 = TWSR0;
    R25 = R25 & 0xf8;
    if ((R25 != 8) && (R25 != 0x10)) goto LAB_code_0d37;
    TWDR0 = R24 * '\x02';
    TWCR0 = 0x84;
    do {
      bVar1 = TWCR0;
    } while ((bVar1 & 0x80) == 0);
    R25 = TWSR0;
    R25 = R25 & 0xf8;
    if (R25 != 0x18) goto LAB_code_0d37;
    Z = R23R22;
    R21 = 0x84;
    do {
      pbVar3 = Z;
      Z = Z + 1;
      R25 = *pbVar3;
      TWDR0 = R25;
      TWCR0 = 0x84;
      do {
        bVar1 = TWCR0;
      } while ((bVar1 & 0x80) == 0);
      R25 = TWSR0;
      R25 = R25 & 0xf8;
      if (R25 != 0x28) goto LAB_code_0d37;
      R20 = R20 + -1;
    } while (R20 != '\0');
  }
  if (R16 == '\0') {
    R24 = '\0';
LAB_code_0d30:
    TWCR0 = 0x94;
    R25 = '(';
    do {
      R25 = R25 + -1;
    } while (R25 != '\0');
    R16 = cVar2;
    R25 = 0;
    return R25;
  }
  TWCR0 = 0xa4;
  do {
    bVar1 = TWCR0;
  } while ((bVar1 & 0x80) == 0);
  R25 = TWSR0;
  R25 = R25 & 0xf8;
  if ((R25 == 8) || (R25 == 0x10)) {
    TWDR0 = R24 * '\x02' + 1;
    TWCR0 = 0x84;
    do {
      bVar1 = TWCR0;
    } while ((bVar1 & 0x80) == 0);
    R24 = TWSR0;
    R24 = R24 & 0xf8;
    if (R24 == 0x40) {
      Z = R19R18;
      R25 = 0xc4;
      R19R18 = (byte *)CONCAT11(0x84,(char)R19R18);
      do {
        pbVar3 = Z;
        if (R16 == '\x01') {
          TWCR0 = R19R18._1_1_;
        }
        else {
          TWCR0 = R25;
        }
        do {
          bVar1 = TWCR0;
        } while ((bVar1 & 0x80) == 0);
        R24 = TWSR0;
        R24 = R24 & 0xf0;
        if (R24 != 0x50) goto LAB_code_0d37;
        bVar1 = TWDR0;
        Z = Z + 1;
        *pbVar3 = bVar1;
        R16 = R16 + -1;
        R24 = (char)Z - (char)R19R18;
      } while (R16 != R1);
      goto LAB_code_0d30;
    }
  }
LAB_code_0d37:
  TWCR0 = 0x94;
  R24 = '(';
  do {
    R24 = R24 + -1;
  } while (R24 != '\0');
  R24 = 0;
  R16 = cVar2;
  return R25;
}

