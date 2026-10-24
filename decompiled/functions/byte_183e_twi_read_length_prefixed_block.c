/* BYTE0x183e; WORDcode:0c1f; twi_read_length_prefixed_block */

byte twi_read_length_prefixed_block(undefined1 R25,byte R24,undefined1 R23,byte R22)

{
  byte bVar1;
  undefined2 uVar2;
  
  uVar2 = Y;
  R1 = 0;
  TWCR0 = 0xa4;
  do {
    bVar1 = TWCR0;
  } while ((bVar1 & 0x80) == 0);
  R25 = TWSR0;
  R25 = R25 & 0xf8;
  if ((R25 == 8) || (R25 == 0x10)) {
    TWDR0 = R24 * '\x02';
    TWCR0 = 0x84;
    do {
      bVar1 = TWCR0;
    } while ((bVar1 & 0x80) == 0);
    R25 = TWSR0;
    R25 = R25 & 0xf8;
    if (R25 == 0x18) {
      TWDR0 = R22;
      TWCR0 = 0x84;
      do {
        bVar1 = TWCR0;
      } while ((bVar1 & 0x80) == 0);
      R25 = TWSR0;
      R25 = R25 & 0xf8;
      if (R25 == 0x28) {
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
            TWCR0 = 0xc4;
            do {
              bVar1 = TWCR0;
            } while ((bVar1 & 0x80) == 0);
            R24 = TWSR0;
            R24 = R24 & 0xf0;
            if (R24 == 0x50) {
              R24 = TWDR0;
              R25 = 0;
              R19R18 = (uint)R24;
              X = R19R18 - 1;
              Z = (byte *)CONCAT11(0xc4,(char)Z);
              while( true ) {
                R22 = R25;
                R23 = 0;
                if ((char)-(X._1_1_ + (R25 < (byte)X)) < '\0' ==
                    (SBORROW1('\0',X._1_1_) != SBORROW1(-X._1_1_,R25 < (byte)X))) break;
                TWCR0 = Z._1_1_;
                do {
                  bVar1 = TWCR0;
                  Z = (byte *)CONCAT11(Z._1_1_,bVar1);
                } while ((bVar1 & 0x80) == 0);
                bVar1 = TWSR0;
                Z = (byte *)(CONCAT11(Z._1_1_,bVar1) & 0xfff0);
                if ((char)Z != 'P') goto LAB_code_0cb4;
                bVar1 = TWDR0;
                Z = (byte *)CONCAT11(Z._1_1_,bVar1);
                Y = (byte *)CONCAT11(R21R20._1_1_ + CARRY1((byte)R21R20,R25),(byte)R21R20 + R25);
                *Y = bVar1;
                R25 = R25 + 1;
              }
              TWCR0 = 0x84;
              do {
                bVar1 = TWCR0;
              } while ((bVar1 & 0x80) == 0);
              R25 = TWSR0;
              R25 = R25 & 0xf0;
              if (R25 == 0x50) {
                bVar1 = TWDR0;
                R19R18 = CONCAT11(R19R18._1_1_ + R21R20._1_1_ + CARRY1((byte)R19R18,(byte)R21R20),
                                  (byte)R19R18 + (byte)R21R20);
                Z = (byte *)(R19R18 + -1);
                *Z = bVar1;
                TWCR0 = 0x94;
                R25 = '(';
                do {
                  R25 = R25 + -1;
                } while (R25 != '\0');
                R25 = 0;
                Y = (byte *)uVar2;
                return R25;
              }
            }
          }
        }
      }
    }
  }
LAB_code_0cb4:
  TWCR0 = 0x94;
  R24 = '(';
  do {
    R24 = R24 + -1;
  } while (R24 != '\0');
  R24 = 0;
  Y = (byte *)uVar2;
  return R25;
}

