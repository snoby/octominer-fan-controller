/* BYTE0x0c3a; WORDcode:061d; oled_render_character */

void oled_render_character(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  byte bVar5;
  byte *pbVar6;
  bool bVar7;
  char in_Hflg;
  char cVar8;
  char in_Tflg;
  char cVar9;
  char in_Iflg;
  char cVar10;
  undefined1 uStack_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  undefined1 uStack_4;
  undefined1 uStack_3;
  undefined1 uStack_2;
  undefined1 uStack_1;
  
  uStack_1 = R9R8._1_1_;
  uStack_2 = (byte)R11R10;
  uStack_3 = R11R10._1_1_;
  uStack_4 = (byte)R13R12;
  uStack_5 = R13R12._1_1_;
  uStack_6 = (byte)R15R14;
  uStack_7 = R15R14._1_1_;
  uStack_8 = (byte)R17R16;
  uStack_9 = R17R16._1_1_;
  uStack_a = (undefined1)Y;
  uStack_b = Y._1_1_;
  uVar4 = CONCAT11((char)((uint)&uStack_c >> 8),(char)&uStack_c);
  Y = uVar4 - 0x10;
  cVar8 = in_Hflg == '\x01';
  cVar9 = in_Tflg == '\x01';
  cVar10 = in_Iflg == '\x01';
  R1R0._0_1_ = uVar4 < 0x10 | (Y == 0) << 1 | ((int)Y < 0) << 2 | SBORROW2(uVar4,0x10) << 3 |
               ((int)uVar4 < 0x10) << 4 | cVar8 << 5 | cVar9 << 6 | cVar10 << 7;
  bVar1 = (byte)R1R0;
  R1R0 = (uint)(byte)R1R0;
  SREG = bVar1;
  SREG = bVar1;
  if ((byte)R25R24 == 9) {
    R1R0 = (uint)DAT_mem_0102 * 4;
    R1R0 = R1R0 & 0xff;
  }
  else if ((byte)R25R24 < 9) {
    if ((byte)R25R24 != 8) {
LAB_code_067c:
      R25R24 = (byte *)CONCAT11(DAT_mem_0351,(byte)R25R24);
      if ((DAT_mem_0351 < 0x7a) && (0x1f < (byte)R25R24)) {
        bVar1 = (byte)R25R24 - 0x20;
        R25R24 = (byte *)(uint)bVar1;
        Z = (byte *)(uint)DAT_codebyte_0199;
        if (bVar1 < DAT_codebyte_0199) {
LAB_code_06a9:
          Z = (byte *)CONCAT11(6,(byte)Z);
          R1R0 = ((uint)R25R24 & 0xff) * 6;
          R17R16 = R1R0;
          R1R0 = R1R0 & 0xff;
          if (DAT_mem_0102 == 2) {
            R25R24 = (byte *)(uVar4 - 0xf);
            R15R14 = R25R24;
            X = R25R24;
            R19R18._0_1_ = 0;
            R19R18._1_1_ = '\0';
            R13R12 = (byte *)0x1;
            do {
              X = X + 1;
              *X = R1R0._1_1_;
              X = X + -1;
              *X = R1R0._1_1_;
              Z._0_1_ = (byte)R17R16;
              Z._1_1_ = (byte)(R17R16 >> 8);
              cVar3 = (Z._1_1_ + R19R18._1_1_ + CARRY1((byte)Z,(byte)R19R18)) -
                      (((byte)((byte)Z + (byte)R19R18) < 0x54) + -2);
              Z = (byte *)CONCAT11(cVar3,(byte)Z + (byte)R19R18 + 0xac);
              Z._0_1_ = *Z;
              Z = (byte *)CONCAT11(cVar3,(byte)Z);
              R21R20._0_1_ = '\x01';
              R25R24 = (byte *)0x0;
              R11R10._0_1_ = (byte)Z;
              R11R10._1_1_ = R1R0._1_1_;
              do {
                pbVar6 = X;
                R23R22._0_1_ = (byte)R11R10;
                R23R22._1_1_ = R11R10._1_1_;
                R1R0 = CONCAT11(R1R0._1_1_,(byte)R25R24);
                while( true ) {
                  cVar3 = R23R22._1_1_;
                  R1R0._0_1_ = (byte)R1R0 + -1;
                  if ((char)(byte)R1R0 < '\0') break;
                  R23R22._1_1_ = (char)R23R22._1_1_ >> 1;
                  R23R22._0_1_ = cVar3 << 7 | (byte)R23R22 >> 1;
                }
                if (((byte)R23R22 & 1) != 0) {
                  X = X + 1;
                  Z._0_1_ = *pbVar6;
                  Z._1_1_ = *X;
                  R23R22 = R13R12;
                  R1R0 = CONCAT11(R1R0._1_1_,(char)R21R20);
                  while( true ) {
                    R1R0._0_1_ = (byte)R1R0 + -1;
                    if ((char)(byte)R1R0 < '\0') break;
                    R23R22 = CONCAT11(R23R22._1_1_ * '\x02' + CARRY1((byte)R23R22,(byte)R23R22),
                                      (byte)R23R22 * '\x02');
                  }
                  Z._0_1_ = (byte)Z | (byte)R23R22;
                  Z._1_1_ = Z._1_1_ | R23R22._1_1_;
                  R23R22._0_1_ = (byte)R25R24 * '\x02';
                  R9R8 = R13R12;
                  while( true ) {
                    R23R22._0_1_ = (byte)R23R22 + -1;
                    if ((char)(byte)R23R22 < '\0') break;
                    R9R8 = CONCAT11(R9R8._1_1_ * '\x02' + CARRY1((byte)R9R8,(byte)R9R8),
                                    (byte)R9R8 * '\x02');
                  }
                  R23R22._0_1_ = (byte)R9R8 | (byte)Z;
                  R23R22._1_1_ = R9R8._1_1_ | Z._1_1_;
                  X = pbVar6 + 1;
                  *X = R23R22._1_1_;
                  X = X + -1;
                  *X = (byte)R23R22;
                }
                R25R24 = (byte *)((int)R25R24 + 1);
                R21R20._0_1_ = (char)R21R20 + '\x02';
              } while ((byte)R25R24 != 8 || R25R24._1_1_ != (byte)(R1R0._1_1_ + ((byte)R25R24 < 8)))
              ;
              bVar1 = (byte)R19R18 + 1;
              R19R18._1_1_ = R19R18._1_1_ - (((byte)R19R18 != 0xff) + -1);
              X = X + 2;
              R19R18._0_1_ = bVar1;
            } while (bVar1 != 6 || R19R18._1_1_ != (byte)(R1R0._1_1_ + (bVar1 < 6)));
            *(undefined2 *)(uVar4 - 0x11) = 0x6fe;
            twi_start_address_bounded();
            *(undefined2 *)(uVar4 - 0x11) = 0x701;
            twi_send_byte_bounded();
            R17R16._0_1_ = (byte)Y;
            R17R16._1_1_ = (char)(Y >> 8);
            R17R16._1_1_ = R17R16._1_1_ - (((byte)R17R16 < 0xf3) + -1);
            R13R12 = R15R14;
            R17R16._0_1_ = (byte)R17R16 + 0xd;
            do {
              R11R10._1_1_ = *R13R12;
              Z._0_1_ = (byte)R13R12;
              Z = (byte *)CONCAT11(2,(byte)Z);
              R13R12 = (byte *)CONCAT11(R13R12._1_1_ + R1R0._1_1_ + (0xfd < (byte)Z),(byte)Z + 2);
              *(undefined2 *)(uVar4 - 0x11) = 0x70d;
              twi_send_byte_bounded();
              *(undefined2 *)(uVar4 - 0x11) = 0x710;
              twi_send_byte_bounded();
            } while ((byte)R17R16 != (byte)R13R12 ||
                     R17R16._1_1_ != (byte)(R13R12._1_1_ + ((byte)R17R16 < (byte)R13R12)));
            *(undefined2 *)(uVar4 - 0x11) = 0x715;
            twi_stop();
            *(byte *)(Y + 0xd) = DAT_mem_0352 + 0xb1;
            *(undefined1 *)(Y + 0xe) = 0x21;
            *(byte *)(Y + 0xf) = DAT_mem_0351;
            *(undefined1 *)(Y + 0x10) = 0x7f;
            *(undefined2 *)(uVar4 - 0x11) = 0x724;
            oled_send_commands();
            *(undefined2 *)(uVar4 - 0x11) = 0x727;
            twi_start_address_bounded();
            *(undefined2 *)(uVar4 - 0x11) = 0x72a;
            twi_send_byte_bounded();
            do {
              R13R12._1_1_ = R15R14[1];
              Z._0_1_ = (byte)R15R14;
              Z = (byte *)CONCAT11(2,(byte)Z);
              R15R14 = (byte *)CONCAT11(R15R14._1_1_ + R1R0._1_1_ + (0xfd < (byte)Z),(byte)Z + 2);
              *(undefined2 *)(uVar4 - 0x11) = 0x732;
              twi_send_byte_bounded();
              *(undefined2 *)(uVar4 - 0x11) = 0x735;
              twi_send_byte_bounded();
            } while ((byte)R17R16 != (byte)R15R14 ||
                     R17R16._1_1_ != (byte)(R15R14._1_1_ + ((byte)R17R16 < (byte)R15R14)));
            *(undefined2 *)(uVar4 - 0x11) = 0x73a;
            twi_stop();
            *(byte *)(Y + 0xd) = DAT_mem_0352 + 0xb0;
            *(byte *)(Y + 0xf) = DAT_mem_0351 + 0xc;
            *(undefined2 *)(uVar4 - 0x11) = 0x746;
            oled_send_commands();
            R25R24 = (byte *)CONCAT11(R25R24._1_1_,DAT_mem_0351 + 0xc);
          }
          else {
            *(undefined2 *)(uVar4 - 0x11) = 0x74d;
            twi_start_address_bounded();
            *(undefined2 *)(uVar4 - 0x11) = 0x750;
            twi_send_byte_bounded();
            R15R14._0_1_ = R1R0._1_1_;
            R15R14._1_1_ = R1R0._1_1_;
            do {
              Z._0_1_ = (byte)R17R16;
              Z._1_1_ = (byte)(R17R16 >> 8);
              Z = (byte *)CONCAT11((Z._1_1_ + R15R14._1_1_ + CARRY1((byte)Z,(byte)R15R14)) -
                                   (((byte)((byte)Z + (byte)R15R14) < 0x54) + -2),
                                   (byte)Z + (byte)R15R14 + 0xac);
              *(undefined2 *)(uVar4 - 0x11) = 0x75a;
              twi_send_byte_bounded();
              bVar1 = (byte)R15R14 + 1;
              R15R14._1_1_ = R15R14._1_1_ - (((byte)R15R14 != 0xff) + -1);
              R15R14._0_1_ = bVar1;
            } while (bVar1 != 6 || R15R14._1_1_ != (byte)(R1R0._1_1_ + (bVar1 < 6)));
            *(undefined2 *)(uVar4 - 0x11) = 0x763;
            twi_stop();
            R25R24 = (byte *)CONCAT11(R25R24._1_1_,DAT_mem_0351 + 6);
          }
          DAT_mem_0351 = (byte)R25R24;
        }
        else {
          bVar2 = 0;
          while( true ) {
            bVar5 = bVar2 * '\x02';
            bVar7 = CARRY1(bVar2,bVar2);
            R19R18 = CONCAT11(bVar7,bVar5);
            cVar3 = bVar7 - ((bVar5 < 0x67) + -2);
            R25R24 = (byte *)CONCAT11(cVar3,bVar5 + 0x99);
            Z = R25R24;
            R21R20._1_1_ = *R25R24;
            R21R20 = CONCAT11(R21R20._1_1_,bVar2);
            if (R21R20._1_1_ == -1) break;
            Z = (byte *)CONCAT11(bVar7 - ((bVar5 < 0x68) + -2),bVar5 + 0x98);
            Z._0_1_ = *Z;
            Z = (byte *)(uint)(byte)Z;
            Z = (byte *)((int)Z - 0x20);
            if (Z == (byte *)CONCAT11((byte)Z < bVar1,bVar1)) {
              Z = R25R24;
              R25R24._0_1_ = *R25R24;
              R25R24 = (byte *)CONCAT11(cVar3,(byte)R25R24);
              if ((byte)R25R24 != -1) goto LAB_code_06a9;
              break;
            }
            bVar2 = bVar2 + 1;
          }
        }
      }
      goto LAB_code_0768;
    }
    *(undefined2 *)(uVar4 - 0x11) = 0x640;
    oled_set_text_cursor();
    *(undefined2 *)(uVar4 - 0x11) = 0x643;
    oled_render_character();
  }
  else if ((byte)R25R24 == 10) {
    R23R22 = CONCAT11(R23R22._1_1_,DAT_mem_0352);
    if (6 < DAT_mem_0352) goto LAB_code_0768;
  }
  else if ((byte)R25R24 != 0xd) goto LAB_code_067c;
  *(undefined2 *)(uVar4 - 0x11) = 0x66c;
  oled_set_text_cursor();
LAB_code_0768:
  uVar4 = Y;
  Y = Y + 0x10;
  R1R0._0_1_ = 0xffef < uVar4 | (uVar4 == 0xfff0) << 1 | ((int)Y < 0) << 2 | SCARRY2(Y,0x10) << 3 |
               ((int)Y < 0 != SCARRY2(Y,0x10)) << 4 | (cVar8 == '\x01') << 5 |
               (cVar9 == '\x01') << 6 | (cVar10 == '\x01') << 7;
  SREG = (byte)R1R0;
  SREG = (byte)R1R0;
  Y._1_1_ = *(undefined1 *)(uVar4 + 0x11);
  Y._0_1_ = *(undefined1 *)(uVar4 + 0x12);
  R17R16._1_1_ = *(undefined1 *)(uVar4 + 0x13);
  R17R16._0_1_ = *(undefined1 *)(uVar4 + 0x14);
  R15R14._1_1_ = *(undefined1 *)(uVar4 + 0x15);
  R15R14._0_1_ = *(undefined1 *)(uVar4 + 0x16);
  R13R12._1_1_ = *(undefined1 *)(uVar4 + 0x17);
  R13R12._0_1_ = *(undefined1 *)(uVar4 + 0x18);
  R11R10._1_1_ = *(undefined1 *)(uVar4 + 0x19);
  R11R10._0_1_ = *(undefined1 *)(uVar4 + 0x1a);
  R9R8._1_1_ = *(undefined1 *)(uVar4 + 0x1b);
  R9R8._0_1_ = *(undefined1 *)(uVar4 + 0x1c);
  return;
}

