/* BYTE0x74b6; WORDcode:3a5b; bootloader_usb_main */

void bootloader_usb_main(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  uint *puVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char in_Hflg;
  char in_Tflg;
  char in_Iflg;
  
  R1R0 = (uint)(byte)R1R0;
  bVar1 = DDRC;
  DDRC = bVar1 | 0x40;
  bVar1 = PORTC;
  PORTC = bVar1 | 0x40;
  bVar1 = DDRE;
  DDRE = bVar1 & 0xfb;
  bVar1 = PORTE;
  PORTE = bVar1 | 4;
  FUN_code_3ca5();
  if ((byte)R25R24 != -0x6d) {
    R25R24 = (byte *)0x900;
    X = &EIMSK;
    do {
      iVar3 = (int)R25R24;
      watchdog_reset();
      R25R24 = (byte *)((int)R25R24 + -1);
      cVar8 = (byte)X - (R1R0._1_1_ + (iVar3 == 0));
      X._1_1_ = X._1_1_ - (R1R0._1_1_ +
                          ((byte)X < R1R0._1_1_ || (byte)((byte)X - R1R0._1_1_) < (iVar3 == 0)));
      X = (byte *)CONCAT11(X._1_1_,cVar8);
    } while ((R25R24 != (byte *)0x0 || cVar8 != '\0') || X._1_1_ != '\0');
  }
  bVar1 = DDRC;
  DDRC = bVar1 | 0x20;
  bVar1 = PORTC;
  PORTC = bVar1 | 0x20;
  bVar1 = DDRC;
  DDRC = bVar1 | 0x80;
  bVar1 = PORTC;
  PORTC = bVar1 | 0x80;
  bVar1 = DDRE;
  DDRE = bVar1 | 8;
  bVar1 = PORTE;
  PORTE = bVar1 | 8;
  FUN_code_3cad();
  FUN_code_3cad();
  MCUCR = 1;
  cVar8 = '\x01';
  MCUCR = 2;
  Z = (byte *)0xd4c0;
  do {
    iVar3 = (int)Z;
    watchdog_reset();
    Z = (byte *)((int)Z + -1);
    cVar8 = cVar8 - (iVar3 == 0);
  } while (Z != (byte *)0x0 || cVar8 != '\0');
  FUN_code_3ca5();
  pbVar2 = (byte *)CONCAT11(DAT_mem_010e,DAT_mem_010d);
  cVar11 = SBORROW1((byte)R25R24,-0x6d);
  cVar8 = (byte)R25R24 < 0x93;
  cVar10 = (char)((byte)R25R24 + 0x6d) < '\0';
  cVar9 = (byte)R25R24 == 0x93;
  cVar12 = (char)(byte)R25R24 < -0x6d;
  if ((bool)cVar9) {
    FUN_code_3cad();
  }
  else {
    bVar1 = PINE;
    if (((bVar1 & 4) != 0) && (bVar1 = PINC, (bVar1 & 8) == 0)) goto LAB_code_3a93;
  }
  do {
    pbVar2 = (byte *)CONCAT11(DAT_mem_010e,DAT_mem_010d);
    DAT_mem_010f = 0xfe;
    MCUSR = R1R0._1_1_;
    in_Hflg = in_Hflg == '\x01';
    in_Tflg = in_Tflg == '\x01';
    R1R0._0_1_ = cVar8 == '\x01' | (cVar9 == '\x01') << 1 | (cVar10 == '\x01') << 2 |
                 (cVar11 == '\x01') << 3 | (cVar12 == '\x01') << 4 | in_Hflg << 5 | in_Tflg << 6 |
                 (in_Iflg == '\x01') << 7;
    SREG = (byte)R1R0;
    watchdog_reset();
    R25R24._0_1_ = WDTCSR;
    R25R24._0_1_ = (byte)R25R24 | 0x18;
    WDTCSR = (byte)R25R24;
    WDTCSR = R1R0._1_1_;
    SREG = (byte)R1R0;
    R25R24._0_1_ = EICRA;
    R25R24._0_1_ = (byte)R25R24 | 2;
    EICRA = (byte)R25R24;
    bVar1 = EIMSK;
    EIMSK = bVar1 | 1;
    bVar1 = DDRD;
    DDRD = bVar1 & 0xfd;
    bVar1 = PORTD;
    PORTD = bVar1 & 0xfd;
    cVar8 = '\t';
    Z = (byte *)0x27c0;
    do {
      pbVar4 = Z;
      watchdog_reset();
      Z = Z + -1;
      cVar8 = cVar8 - (pbVar4 == (byte *)0x0);
    } while (Z != (byte *)0x0 || cVar8 != '\0');
    bVar1 = DDRD;
    DDRD = bVar1 | 2;
    bVar1 = PORTD;
    PORTD = bVar1 | 2;
    do {
      DAT_mem_010e = (byte)((uint)pbVar2 >> 8);
      DAT_mem_010d = (byte)pbVar2;
      R17R16._1_1_ = DAT_mem_0121 - 3;
      if ((R17R16._1_1_ & 0x80) == 0) {
        Y = (uint *)CONCAT11(-(((byte)(-DAT_mem_011e + 0xc) < 0xdb) + -2) -
                             (R1R0._1_1_ + (0xc < DAT_mem_011e)),-DAT_mem_011e + '1');
        if (DAT_mem_011d == '-') {
          if (DAT_mem_0121 == '\v') {
            DAT_mem_0111 = 0xc3;
            DAT_mem_0101 = 0x5a;
            DAT_mem_0110 = R1R0._1_1_;
            R25R24 = (byte *)(*Y & 0xff60);
            if ((byte)R25R24 == '\0') {
              R25R24._0_1_ = (byte)Y[1];
              DAT_mem_011a = R1R0._1_1_;
              if (R25R24._1_1_ == R1R0._1_1_) {
                DAT_mem_011b = R1R0._1_1_;
                R19R18 = &DAT_mem_011a;
                R25R24._0_1_ = 2;
              }
              else if (R25R24._1_1_ == 5) {
                DAT_mem_0122 = (byte)R25R24;
LAB_code_3b70:
                R19R18 = &DAT_mem_011a;
                R25R24._0_1_ = 0;
              }
              else {
                if (R25R24._1_1_ == 6) {
                  R25R24._1_1_ = *(char *)((int)Y + 3);
                  if (R25R24._1_1_ == '\x01') {
                    R25R24 = (byte *)0x70fe;
LAB_code_3b3f:
                    DAT_mem_0120 = R25R24._1_1_;
                    DAT_mem_011f = (byte)R25R24;
                    R25R24._0_1_ = 0x12;
                  }
                  else {
                    if (R25R24._1_1_ == '\x02') {
                      R25R24 = (byte *)0x70ec;
                      goto LAB_code_3b3f;
                    }
                    if (R25R24._1_1_ == '\x03') {
                      if ((byte)R25R24 == R1R0._1_1_) {
                        DAT_mem_0120 = 0x71;
                        DAT_mem_011f = 0x3a;
                        R25R24._0_1_ = 4;
                      }
                      else if ((byte)R25R24 == 1) {
                        DAT_mem_0120 = 0x71;
                        DAT_mem_011f = 0x1e;
                        R25R24._0_1_ = 0x1c;
                      }
                      else {
                        if ((byte)R25R24 != 2) goto LAB_code_3b65;
                        DAT_mem_0120 = 0x71;
                        DAT_mem_011f = 0x10;
                        R25R24._0_1_ = 0xe;
                      }
                    }
                    else {
LAB_code_3b65:
                      R25R24._0_1_ = 0;
                    }
                  }
                  DAT_mem_0110 = 0x40;
                  goto LAB_code_3b88;
                }
                if (R25R24._1_1_ == 8) {
                  R19R18 = &DAT_mem_0124;
                  R25R24._0_1_ = 1;
                }
                else {
                  if (R25R24._1_1_ == 9) {
                    DAT_mem_0124 = (byte)R25R24;
                    goto LAB_code_3b70;
                  }
                  R25R24._0_1_ = R25R24._1_1_ == 10;
                  R19R18 = &DAT_mem_011a;
                }
              }
              DAT_mem_0120 = R19R18._1_1_;
              DAT_mem_011f = (byte)R19R18;
LAB_code_3b88:
              R25R24._1_1_ = *(char *)((int)Y + 7);
              if ((R25R24._1_1_ == R1R0._1_1_) &&
                 (R25R24._1_1_ = (byte)Y[3], R25R24._1_1_ < (byte)R25R24)) {
                R25R24._0_1_ = R25R24._1_1_;
              }
            }
            else {
              DAT_mem_0120 = 1;
              DAT_mem_011f = 6;
              if (R25R24._1_1_ == 3) {
                bootloader_isp_command();
                pbVar2 = (byte *)CONCAT11(DAT_mem_010e,DAT_mem_010d);
                DAT_mem_0109 = (byte)R25R24;
                R25R24._0_1_ = 4;
                goto LAB_code_3b88;
              }
              if ((R25R24._1_1_ == 5) || (R25R24._1_1_ == 10)) {
                R25R24._0_1_ = 1;
                goto LAB_code_3b88;
              }
              if (5 < (byte)(R25R24._1_1_ - 4)) {
                if (R25R24._1_1_ == 2) {
                  R25R24._0_1_ = DAT_mem_010f & 0xfe;
                  DAT_mem_010f = (byte)R25R24;
                }
                else {
                  R25R24._0_1_ = DAT_mem_010f | 1;
                  DAT_mem_010f = (byte)R25R24;
                }
LAB_code_3c9d:
                R25R24._0_1_ = 0;
                goto LAB_code_3b88;
              }
              pbVar2 = (byte *)Y[1];
              if (R25R24._1_1_ == 9) goto LAB_code_3c9d;
              R25R24._0_1_ = (byte)Y[3];
              DAT_mem_010c = (byte)R25R24;
              R19R18._0_1_ = *(byte *)((int)Y + 5);
              R19R18._0_1_ = (byte)R19R18 & 2;
              DAT_mem_010b = (byte)R19R18;
              DAT_mem_010a = R25R24._1_1_;
              if ((*Y & 0x80) == 0) {
                R25R24._0_1_ = 0xff;
              }
              DAT_mem_0110 = 0x80;
            }
            DAT_mem_0100 = (byte)R25R24;
          }
        }
        else if ((DAT_mem_0110 & 0x80) != 0) {
          if (DAT_mem_010c < R17R16._1_1_) {
            R17R16._1_1_ = DAT_mem_010c;
          }
          DAT_mem_010c = DAT_mem_010c - R17R16._1_1_;
          R17R16 = (byte *)CONCAT11(R17R16._1_1_,DAT_mem_010c);
          R15R14 = (byte *)CONCAT11(R1R0._1_1_,(char)R15R14);
          R25R24 = pbVar2;
          while( true ) {
            pbVar2 = R25R24;
            puVar5 = Y;
            DAT_mem_010e = (byte)((uint)pbVar2 >> 8);
            DAT_mem_010d = (byte)pbVar2;
            if (R17R16._1_1_ <= R15R14._1_1_) break;
            if (DAT_mem_010a < 7) {
              if (0x6f < DAT_mem_010e && (DAT_mem_010d < R1R0._1_1_) <= (byte)(DAT_mem_010e + 0x90))
              goto LAB_code_3c0a;
              R15R14._1_1_ = R15R14._1_1_ + 2;
              Y = (uint *)((int)Y + 1);
              puVar6 = (undefined1 *)Y;
              R19R18._0_1_ = (byte)*puVar5;
              Y = puVar5 + 1;
              R19R18._1_1_ = *puVar6;
              SPMCSR = 1;
              *(undefined **)((int)pbVar2 << 1) = R19R18;
              store_program_mem();
              R1R0 = (uint)(byte)R19R18;
              R25R24 = pbVar2 + 2;
              Z = pbVar2;
              if ((((uint)R25R24 & 0x7f) == 0) ||
                 ((((byte)R17R16 == 0 && (R17R16._1_1_ <= R15R14._1_1_)) && (DAT_mem_010b != 0)))) {
                SPMCSR = 3;
                *(uint *)((int)pbVar2 * 2) = R1R0;
                store_program_mem();
                do {
                  bVar1 = SPMCSR;
                  R1R0 = (uint)bVar1;
                } while ((bVar1 & 1) != 0);
                SPMCSR = 5;
                *(uint *)((int)pbVar2 * 2) = R1R0;
                store_program_mem();
                do {
                  bVar1 = SPMCSR;
                  R1R0 = (uint)bVar1;
                } while ((bVar1 & 1) != 0);
                SPMCSR = 0x11;
                *(uint *)((int)pbVar2 * 2) = R1R0;
                store_program_mem();
              }
            }
            else {
              Z = (byte *)CONCAT11(0xff,Z._0_1_);
              R13R12._0_1_ = (char)Y;
              R13R12._1_1_ = (byte)((uint)Y >> 8);
              R13R12 = (uint *)CONCAT11(R13R12._1_1_ - (((char)R13R12 != -1) + -1),
                                        (char)R13R12 + '\x01');
              DAT_mem_010e = DAT_mem_010e - ((DAT_mem_010d != 0xff) + -1);
              DAT_mem_010d = DAT_mem_010d + 1;
              FUN_code_3cbf();
              R15R14._1_1_ = R15R14._1_1_ + '\x01';
              Y = R13R12;
              R25R24 = (byte *)CONCAT11(DAT_mem_010e,DAT_mem_010d);
            }
          }
          if ((byte)R17R16 == R1R0._1_1_) {
LAB_code_3c0a:
            DAT_mem_0100 = R1R0._1_1_;
          }
        }
        DAT_mem_0121 = R1R0._1_1_;
      }
      DAT_mem_010e = (byte)((uint)pbVar2 >> 8);
      DAT_mem_010d = (byte)pbVar2;
      if (((DAT_mem_0101 & 0x10) != 0) && (DAT_mem_0100 != 0xff)) {
        Y._0_1_ = DAT_mem_0100;
        if (8 < DAT_mem_0100) {
          Y._0_1_ = 8;
        }
        DAT_mem_0100 = DAT_mem_0100 - (byte)Y;
        R25R24._0_1_ = DAT_mem_0111 ^ 0x88;
        DAT_mem_0111 = (byte)R25R24;
        if ((byte)Y == 0) {
          FUN_code_38dc();
          DAT_mem_0101 = 4;
LAB_code_3c74:
          DAT_mem_0100 = 0xff;
        }
        else {
          if ((DAT_mem_0110 & 0x80) == 0) {
            Z = (byte *)CONCAT11(DAT_mem_0120,DAT_mem_011f);
            X = &DAT_mem_0112;
            R25R24._0_1_ = (byte)Y;
            if ((DAT_mem_0110 & 0x40) == 0) {
              do {
                pbVar7 = Z;
                pbVar4 = X;
                DAT_mem_010e = (byte)((uint)pbVar2 >> 8);
                DAT_mem_010d = (byte)pbVar2;
                Z = Z + 1;
                R25R24._1_1_ = *pbVar7;
                X = X + 1;
                *pbVar4 = R25R24._1_1_;
                pbVar2 = (byte *)CONCAT11(DAT_mem_010e,DAT_mem_010d);
                R25R24._0_1_ = (byte)R25R24 - 1;
              } while ((byte)R25R24 != 0);
            }
            else {
              do {
                pbVar4 = X;
                DAT_mem_010e = (byte)((uint)pbVar2 >> 8);
                DAT_mem_010d = (byte)pbVar2;
                R25R24._1_1_ = *Z;
                X = X + 1;
                *pbVar4 = R25R24._1_1_;
                pbVar2 = (byte *)CONCAT11(DAT_mem_010e,DAT_mem_010d);
                Z = Z + 1;
                R25R24._0_1_ = (byte)R25R24 - 1;
              } while ((byte)R25R24 != 0);
            }
            pbVar2 = (byte *)CONCAT11(DAT_mem_010e,DAT_mem_010d);
            DAT_mem_0120 = Z._1_1_;
            DAT_mem_011f = Z._0_1_;
          }
          else {
            if (DAT_mem_010c < (byte)Y) {
              Y._0_1_ = DAT_mem_010c;
            }
            DAT_mem_010c = DAT_mem_010c - (byte)Y;
            R13R12 = (uint *)CONCAT11(DAT_mem_010a,(char)R13R12);
            Y._1_1_ = 0;
            R15R14 = &DAT_mem_0112;
            while( true ) {
              DAT_mem_010e = (byte)((uint)pbVar2 >> 8);
              DAT_mem_010d = (byte)pbVar2;
              if (Y._1_1_ == (byte)Y) break;
              if (R13R12._1_1_ < 7) {
                R25R24._0_1_ = *pbVar2;
                R17R16 = pbVar2;
              }
              else {
                R17R16 = pbVar2;
                FUN_code_3ca5();
              }
              Z._0_1_ = SUB21(R15R14,0);
              *R15R14 = (byte)R25R24;
              Z = (byte *)CONCAT11(0xff,Z._0_1_);
              R15R14 = (byte *)CONCAT11(R15R14._1_1_ - (((char)R15R14 != -1) + -1),
                                        (char)R15R14 + '\x01');
              cVar8 = (byte)R17R16 + '\x01';
              cVar9 = R17R16._1_1_ - (((byte)R17R16 != -1) + -1);
              R17R16 = (byte *)CONCAT11(cVar9,cVar8);
              pbVar2 = (byte *)CONCAT11(cVar9,cVar8);
              Y._1_1_ = Y._1_1_ + 1;
            }
          }
          DAT_mem_010e = (byte)((uint)pbVar2 >> 8);
          DAT_mem_010d = (byte)pbVar2;
          FUN_code_38dc();
          DAT_mem_0101 = (byte)Y + 4;
          if (DAT_mem_0101 != 0xc) goto LAB_code_3c74;
        }
        pbVar2 = (byte *)CONCAT11(DAT_mem_010e,DAT_mem_010d);
      }
      cVar8 = '\x14';
      do {
        R25R24._1_1_ = PIND;
        R25R24._1_1_ = R25R24._1_1_ & 0xc;
        if (R25R24._1_1_ != 0) goto LAB_code_3c83;
        cVar8 = cVar8 + -1;
      } while (cVar8 != '\0');
      DAT_mem_0122 = R1R0._1_1_;
      DAT_mem_011c = R1R0._1_1_;
LAB_code_3c83:
      cVar11 = SBORROW1(DAT_mem_010f,'\x10');
      cVar8 = DAT_mem_010f < 0x10;
      cVar10 = (char)(DAT_mem_010f - 0x10) < '\0';
      cVar9 = DAT_mem_010f == 0x10;
      cVar12 = (char)DAT_mem_010f < '\x10';
      if ((bool)cVar8) {
        bVar1 = PINC;
        if ((bVar1 & 8) != 0) {
          cVar11 = SBORROW1(DAT_mem_010f,'\x02');
          cVar10 = (char)(DAT_mem_010f - 2) < '\0';
          cVar9 = DAT_mem_010f == 2;
          cVar12 = (char)DAT_mem_010f < '\x02';
          cVar8 = true;
          if (1 < DAT_mem_010f) {
            cVar11 = SBORROW1(DAT_mem_010f,'\x02');
            cVar8 = DAT_mem_010f < 2;
            cVar12 = (char)DAT_mem_010f < '\x02';
            DAT_mem_010f = DAT_mem_010f - 2;
            goto LAB_code_3c96;
          }
        }
      }
      else {
        bVar1 = PINC;
        if ((bVar1 & 8) == 0) {
          cVar11 = SBORROW1(DAT_mem_010f,'\x10');
          cVar8 = DAT_mem_010f < 0x10;
          cVar12 = (char)DAT_mem_010f < '\x10';
          DAT_mem_010f = DAT_mem_010f - 0x10;
LAB_code_3c96:
          cVar10 = (char)DAT_mem_010f < '\0';
          cVar9 = DAT_mem_010f == 0;
        }
      }
    } while (DAT_mem_010f != R1R0._1_1_);
LAB_code_3a93:
    DAT_mem_010e = (byte)((uint)pbVar2 >> 8);
    DAT_mem_010d = (byte)pbVar2;
    in_Iflg = '\0';
    bVar1 = DDRD;
    DDRD = bVar1 & 0xfd;
    bVar1 = PORTD;
    PORTD = bVar1 & 0xfd;
    bVar1 = DDRC;
    DDRC = bVar1 & 0xdf;
    bVar1 = PORTC;
    PORTC = bVar1 & 0xdf;
    bVar1 = DDRC;
    DDRC = bVar1 & 0xbf;
    bVar1 = PORTC;
    PORTC = bVar1 & 0xbf;
    bVar1 = DDRC;
    DDRC = bVar1 & 0x7f;
    bVar1 = PORTC;
    PORTC = bVar1 & 0x7f;
    bVar1 = DDRE;
    DDRE = bVar1 & 0xf7;
    bVar1 = PORTE;
    PORTE = bVar1 & 0xf7;
    EIMSK = R1R0._1_1_;
    EICRA = R1R0._1_1_;
    MCUCR = 1;
    MCUCR = R1R0._1_1_;
    Z = (byte *)0x0;
    vector_RESET();
  } while( true );
}

