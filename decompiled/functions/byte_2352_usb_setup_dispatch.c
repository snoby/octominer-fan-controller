/* BYTE0x2352; WORDcode:11a9; usb_setup_dispatch */

byte usb_setup_dispatch(UsbSetupPacket *setup)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  ushort uVar9;
  byte bVar10;
  UsbSetupPacket *pUVar11;
  uint uVar12;
  byte bVar13;
  undefined1 *puVar14;
  undefined2 *puVar15;
  UsbSetupPacket *pUVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  char cVar20;
  char cVar21;
  char cVar22;
  char cVar23;
  char cVar24;
  char in_Hflg;
  char cVar25;
  char in_Tflg;
  char cVar26;
  char in_Iflg;
  char cVar27;
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined1 uStack_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined1 uStack_d;
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
  
  pUVar11 = setup;
  uStack_1 = R3R2._1_1_;
  uStack_2 = (byte)R5R4;
  uStack_3 = R5R4._1_1_;
  uStack_4 = (byte)R7R6;
  uStack_5 = R7R6._1_1_;
  uStack_6 = (byte)R9R8;
  uStack_7 = R9R8._1_1_;
  uStack_8 = (byte)R11R10;
  uStack_9 = R11R10._1_1_;
  uStack_a = (byte)R13R12;
  uStack_b = R13R12._1_1_;
  uStack_c = (byte)R15R14;
  uStack_d = R15R14._1_1_;
  uStack_e = (byte)R17R16;
  uStack_f = R17R16._1_1_;
  uStack_10 = (undefined1)Y;
  uStack_11 = Y._1_1_;
  uVar8 = CONCAT11((char)((uint)&uStack_12 >> 8),(char)&uStack_12);
  Y = uVar8 - 0x10;
  cVar25 = in_Hflg == '\x01';
  cVar26 = in_Tflg == '\x01';
  R1R0._0_1_ = uVar8 < 0x10 | (Y == 0) << 1 | ((int)Y < 0) << 2 | SBORROW2(uVar8,0x10) << 3 |
               ((int)uVar8 < 0x10) << 4 | cVar25 << 5 | cVar26 << 6 | (in_Iflg == '\x01') << 7;
  bVar1 = (byte)R1R0;
  R1R0 = (uint)(byte)R1R0;
  SREG = bVar1;
  cVar27 = -((char)bVar1 >> 7);
  SREG = bVar1;
  R19R18 = &usb_reply_buffer;
  usb_reply_pointer._1_1_ = 3;
  usb_reply_pointer._0_1_ = 0x53;
  X = (UsbSetupPacket *)&setup->bRequest;
  R17R16._1_1_ = *(byte *)X;
  if (R17R16._1_1_ == 0xb) {
    Z = signature_serial_bytes;
    X = (UsbSetupPacket *)&usb_reply_buffer;
    do {
      pUVar16 = (UsbSetupPacket *)Z;
      pUVar11 = X;
      Z = &((UsbSetupPacket *)Z)->bRequest;
      setup._0_1_ = pUVar16->bmRequestType;
      X = (UsbSetupPacket *)&X->bRequest;
      pUVar11->bmRequestType = (byte)setup;
    } while ((byte)Z != 0x76 || Z._1_1_ != (char)(((byte)Z < 0x76) + '\x05'));
    R17R16._1_1_ = 10;
    uVar9 = host_watchdog_threshold;
    goto LAB_code_1b6f;
  }
  R15R14 = setup;
  if (R17R16._1_1_ < 0xc) {
    if (R17R16._1_1_ == 5) {
      X = (UsbSetupPacket *)&setup->wIndex;
      Z._0_1_ = (byte)*(ushort *)X;
      X = setup;
      if ((byte)Z < 4) {
        Z = (byte *)CONCAT11(-(((byte)Z < 0x79) + -5),(byte)Z + 0x87);
        X = (UsbSetupPacket *)&setup->wValue;
        setup._0_1_ = (byte)*(ushort *)X;
        ((UsbSetupPacket *)Z)->bmRequestType = (byte)setup;
      }
    }
    else if (R17R16._1_1_ < 5) {
      if (R17R16._1_1_ == 2) {
        X = (UsbSetupPacket *)&setup->wIndex;
        Z._0_1_ = (byte)*(ushort *)X;
        setup = (UsbSetupPacket *)0x0;
        if ((byte)Z < 0xc) {
          Z = (byte *)CONCAT11(-(((byte)Z < 0x8e) + -1),(byte)Z + 0x72);
                    /* WARNING: Return address prevents inlining here */
          gcc_tablejump_helper();
          pUVar11 = setup;
          bVar1 = (byte)setup;
          setup = pUVar11;
          return bVar1;
        }
LAB_code_12ba:
        R17R16._1_1_ = calibration_ticks_remaining;
        if (calibration_ticks_remaining == 0) {
          X = (UsbSetupPacket *)&pUVar11->wIndex;
          Z._0_1_ = (byte)*(ushort *)X;
          setup = (UsbSetupPacket *)0x0;
          uVar9 = host_watchdog_threshold;
          if ((byte)Z < 0xc) {
            Z = (byte *)CONCAT11(-(((byte)Z < 0x82) + -1),(byte)Z + 0x7e);
            X = (UsbSetupPacket *)&pUVar11->wValue;
                    /* WARNING: Return address prevents inlining here */
            gcc_tablejump_helper();
            pUVar11 = setup;
            bVar1 = (byte)setup;
            setup = pUVar11;
            return bVar1;
          }
          goto LAB_code_1b6f;
        }
      }
      else if (R17R16._1_1_ < 2) {
        if (R17R16._1_1_ == 0) {
          bVar1 = PORTC;
          PORTC = bVar1 | 0x40;
          host_elapsed_ticks._1_1_ = 0;
          host_elapsed_ticks._0_1_ = 0;
          *(undefined2 *)(uVar8 - 0x11) = 0x1374;
          eeprom_update_byte();
          setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,2);
          host_watchdog_retry_stage = 2;
          X = (UsbSetupPacket *)CONCAT11(0x7f,(byte)X);
          Z = (byte *)0x3a9;
          do {
            cVar20 = X._1_1_ + -1;
            bVar17 = X._1_1_ == '\0';
            X = (UsbSetupPacket *)CONCAT11(cVar20,(byte)X);
            cVar21 = (byte)Z - bVar17;
            Z._1_1_ = Z._1_1_ - ((byte)Z < bVar17);
            Z = (byte *)CONCAT11(Z._1_1_,cVar21);
          } while ((cVar20 != '\0' || cVar21 != '\0') || Z._1_1_ != '\0');
          bVar1 = PORTC;
          PORTC = bVar1 & 0xbf;
          uVar9 = host_watchdog_threshold;
          goto LAB_code_1b6f;
        }
        if (R17R16._1_1_ == 1) {
          X = (UsbSetupPacket *)&setup->wIndex;
          Z._0_1_ = (byte)*(ushort *)X;
          setup = (UsbSetupPacket *)0x0;
          if ((byte)Z < 0xc) {
            Z = (byte *)CONCAT11(-(((byte)Z < 0x9a) + -1),(byte)Z + 0x66);
                    /* WARNING: Return address prevents inlining here */
            gcc_tablejump_helper();
            pUVar11 = setup;
            bVar1 = (byte)setup;
            setup = pUVar11;
            return bVar1;
          }
        }
      }
      else {
        if (R17R16._1_1_ == 3) {
          setup._0_1_ = (byte)setup->wIndex;
          bVar1 = (byte)setup * '\x02';
          setup._1_1_ = CARRY1((byte)setup,(byte)setup);
          Z = (byte *)CONCAT11(setup._1_1_ - ((bVar1 < 0xd1) + -6),bVar1 + 0x2f);
          R19R18._0_1_ = *Z;
          R19R18 = (byte *)CONCAT11(3,(byte)R19R18);
          usb_reply_buffer = (byte)R19R18;
          Z = (byte *)CONCAT11(setup._1_1_ - ((bVar1 < 0xd0) + -6),bVar1 + 0x30);
          goto LAB_code_1354;
        }
        if (R17R16._1_1_ == 4) goto LAB_code_12ba;
      }
    }
    else {
      if (R17R16._1_1_ == 8) {
        X = (UsbSetupPacket *)&setup->wIndex;
        setup._0_1_ = (byte)*(ushort *)X;
        bVar1 = (byte)setup * '\x02';
        setup._1_1_ = CARRY1((byte)setup,(byte)setup);
        Z = (byte *)CONCAT11(setup._1_1_ - ((bVar1 < 0x27) + -5),bVar1 - 0x27);
        R19R18._0_1_ = *Z;
        R19R18 = (byte *)CONCAT11(3,(byte)R19R18);
        usb_reply_buffer = (byte)R19R18;
        Z = (byte *)CONCAT11(setup._1_1_ - ((bVar1 < 0x26) + -5),bVar1 - 0x26);
LAB_code_1354:
        setup._0_1_ = ((UsbSetupPacket *)Z)->bmRequestType;
LAB_code_1355:
        DAT_mem_0354 = (byte)setup;
        R17R16._1_1_ = 2;
        uVar9 = host_watchdog_threshold;
        goto LAB_code_1b6f;
      }
      if (R17R16._1_1_ < 8) {
        if (R17R16._1_1_ == 6) {
          Z = (byte *)CONCAT11(Z._1_1_,3);
          R15R14 = (UsbSetupPacket *)&usb_reply_buffer;
          R17R16 = &PRR0;
          do {
            setup = (UsbSetupPacket *)R17R16;
            *(undefined2 *)(uVar8 - 0x11) = 0x138b;
            setup._0_1_ = eeprom_read_byte((ushort)setup);
            setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,(byte)setup);
            X = (UsbSetupPacket *)&R15R14->bRequest;
            R15R14->bmRequestType = (byte)setup;
            R15R14 = X;
            bVar1 = (byte)R17R16 + 1;
            cVar20 = R17R16._1_1_ - (((byte)R17R16 != -1) + -1);
            R17R16 = (byte *)CONCAT11(cVar20,bVar1);
          } while (bVar1 != 0x6d || cVar20 != (byte)(R1R0._1_1_ + (bVar1 < 0x6d)));
          R17R16._1_1_ = 9;
          uVar9 = host_watchdog_threshold;
          goto LAB_code_1b6f;
        }
        if (R17R16._1_1_ == 7) {
          host_elapsed_ticks._1_1_ = 0;
          host_elapsed_ticks._0_1_ = 0;
          *(undefined2 *)(uVar8 - 0x11) = 0x139e;
          eeprom_update_byte();
          host_watchdog_mode = R1R0._1_1_;
          *(undefined2 *)(uVar8 - 0x11) = 0x13a5;
          eeprom_update_byte();
          host_watchdog_retry_stage = 2;
          Z = &R15R14->bmRequestType;
          *(undefined2 *)(uVar8 - 0x11) = 0x13ae;
          eeprom_update_byte();
          X = (UsbSetupPacket *)((int)&R15R14->wIndex + 1);
          setup._0_1_ = *(byte *)X;
          extra_recovery_attempts = (byte)setup;
          led_modes[1] = R1R0._1_1_;
          X = (UsbSetupPacket *)&R15R14->wIndex;
          R23R22._0_1_ = (byte)*(ushort *)X;
          if ((byte)R23R22 != 0) {
            X = (UsbSetupPacket *)CONCAT11(0x14,(byte)X);
            R1R0 = (uint)(byte)R23R22 * 0x14;
            R1R0 = R1R0 & 0xff;
            *(undefined2 *)(uVar8 - 0x11) = 0x13c3;
            eeprom_update_word();
            setup._0_1_ = (byte)R15R14->wIndex;
            setup = (UsbSetupPacket *)(uint)(byte)setup;
            Z._0_1_ = (byte)R15R14;
            Z = (byte *)CONCAT11(0x14,(byte)Z);
            R1R0 = (int)setup * 0x14;
            host_watchdog_threshold = R1R0;
            R1R0 = R1R0 & 0xff;
            *(undefined2 *)(uVar8 - 0x11) = 0x13d2;
            eeprom_update_byte();
            host_watchdog_mode = 1;
            X = (UsbSetupPacket *)&R15R14->wValue;
            uVar9 = *(ushort *)X;
            X = R15R14;
            if (uVar9 == 0) {
              setup = (UsbSetupPacket *)0x0;
            }
            else {
              R17R16 = (byte *)0x3;
              *(undefined2 *)(uVar8 - 0x11) = 0x13e2;
              avr_unsigned_divide_16bit();
              *(undefined2 *)(uVar8 - 0x11) = 0x13e6;
              eeprom_update_word();
              Z = &R15R14->bmRequestType;
              *(undefined2 *)(uVar8 - 0x11) = 0x13ec;
              avr_unsigned_divide_16bit();
              host_watchdog_threshold._1_1_ = R23R22._1_1_;
              host_watchdog_threshold._0_1_ = (byte)R23R22;
              *(undefined2 *)(uVar8 - 0x11) = 0x13f5;
              eeprom_update_byte();
              setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,2);
              host_watchdog_mode = 2;
            }
          }
        }
      }
      else if (R17R16._1_1_ == 9) {
        X = (UsbSetupPacket *)&setup->wIndex;
        Z._0_1_ = (byte)*(ushort *)X;
        setup = (UsbSetupPacket *)0x0;
        if ((byte)Z < 0xc) {
          Z = (byte *)CONCAT11(-(((byte)Z < 0x76) + -1),(byte)Z + 0x8a);
                    /* WARNING: Return address prevents inlining here */
          gcc_tablejump_helper();
          pUVar11 = setup;
          bVar1 = (byte)setup;
          setup = pUVar11;
          return bVar1;
        }
      }
      else if (R17R16._1_1_ == 10) {
        usb_reply_buffer = 0x1e;
        setup = (UsbSetupPacket *)&TCCR3A;
        *(undefined2 *)(uVar8 - 0x11) = 0x1205;
        setup._0_1_ = eeprom_read_byte((ushort)setup);
        DAT_mem_0354 = (byte)setup;
        setup = (UsbSetupPacket *)&UNK_mem_008d;
        *(undefined2 *)(uVar8 - 0x11) = 0x120b;
        setup._0_1_ = eeprom_read_byte((ushort)setup);
        DAT_mem_0355 = (byte)setup;
        setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,0xc);
        DAT_mem_0356 = '\f';
        R17R16._1_1_ = 4;
        uVar9 = host_watchdog_threshold;
        goto LAB_code_1b6f;
      }
    }
  }
  else if (R17R16._1_1_ == 0x12) {
    X = (UsbSetupPacket *)&setup->wIndex;
    setup._0_1_ = (byte)*(ushort *)X;
    if ((byte)setup < 8) {
      DAT_mem_057a = 8;
      setup._1_1_ = -(((byte)setup + 0x58) * '\x02' + '\b');
      DAT_mem_057b = setup._1_1_;
      R17R16._0_1_ = 3;
      *(undefined2 *)(uVar8 - 0x11) = 0x14c3;
      twi_write_read_transaction();
      if (((byte)setup != '\0') &&
         (setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,DAT_mem_057a), DAT_mem_057a != 0xff)) {
        usb_reply_buffer = DAT_mem_057a;
        DAT_mem_0354 = DAT_mem_057b;
        DAT_mem_057a = 10;
        Z = &R15R14->bmRequestType;
        setup._0_1_ = (byte)R15R14->wIndex;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '\n');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x14e3;
        twi_write_read_transaction();
        DAT_mem_0355 = DAT_mem_057a;
        DAT_mem_0356 = DAT_mem_057b;
        DAT_mem_057a = 0xc;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        setup._0_1_ = (byte)*(ushort *)X;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '\f');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x14fe;
        twi_write_read_transaction();
        DAT_mem_0357 = DAT_mem_057a;
        DAT_mem_0358 = DAT_mem_057b;
        DAT_mem_057a = 0xe;
        Z = &R15R14->bmRequestType;
        setup._0_1_ = (byte)R15R14->wIndex;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '\x0e');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x1518;
        twi_write_read_transaction();
        DAT_mem_0359 = DAT_mem_057a;
        DAT_mem_035a = DAT_mem_057b;
        DAT_mem_057a = 0x10;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        setup._0_1_ = (byte)*(ushort *)X;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '\x10');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x1533;
        twi_write_read_transaction();
        DAT_mem_035b = DAT_mem_057a;
        DAT_mem_035c = DAT_mem_057b;
        DAT_mem_057a = R17R16._1_1_;
        Z = &R15R14->bmRequestType;
        setup._0_1_ = (byte)R15R14->wIndex;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '\x12');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x154c;
        twi_write_read_transaction();
        DAT_mem_035d = DAT_mem_057a;
        DAT_mem_035e = DAT_mem_057b;
        DAT_mem_057a = 0x1a;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        setup._0_1_ = (byte)*(ushort *)X;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '\x1a');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x1567;
        twi_write_read_transaction();
        DAT_mem_035f = DAT_mem_057a;
        DAT_mem_0360 = DAT_mem_057b;
        DAT_mem_057a = 0x1c;
        Z = &R15R14->bmRequestType;
        setup._0_1_ = (byte)R15R14->wIndex;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '\x1c');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x1581;
        twi_write_read_transaction();
        DAT_mem_0361 = DAT_mem_057a;
        DAT_mem_0362 = DAT_mem_057b;
        DAT_mem_057a = 0x1e;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        setup._0_1_ = (byte)*(ushort *)X;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '\x1e');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x159c;
        twi_write_read_transaction();
        DAT_mem_0363 = DAT_mem_057a;
        DAT_mem_0364 = DAT_mem_057b;
        DAT_mem_057a = 0x32;
        Z = &R15R14->bmRequestType;
        setup._0_1_ = (byte)R15R14->wIndex;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '2');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x15b6;
        twi_write_read_transaction();
        DAT_mem_0365 = DAT_mem_057a;
        DAT_mem_0366 = DAT_mem_057b;
        DAT_mem_057a = 0x36;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        setup._0_1_ = (byte)*(ushort *)X;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '6');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x15d1;
        twi_write_read_transaction();
        DAT_mem_0367 = DAT_mem_057a;
        DAT_mem_0368 = DAT_mem_057b;
        DAT_mem_057a = 0x2c;
        Z = &R15R14->bmRequestType;
        setup._0_1_ = (byte)R15R14->wIndex;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + ',');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x15eb;
        twi_write_read_transaction();
        DAT_mem_0369 = DAT_mem_057a;
        DAT_mem_036a = DAT_mem_057b;
        DAT_mem_057a = 0x2e;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        setup._0_1_ = (byte)*(ushort *)X;
        setup._1_1_ = -(((byte)setup + 'X') * '\x02' + '.');
        DAT_mem_057b = setup._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x1606;
        twi_write_read_transaction();
        DAT_mem_036b = DAT_mem_057a;
        setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,DAT_mem_057b);
        DAT_mem_036c = DAT_mem_057b;
        R17R16._1_1_ = 0x1a;
        uVar9 = host_watchdog_threshold;
        goto LAB_code_1b6f;
      }
    }
  }
  else if (R17R16._1_1_ < 0x12) {
    if (R17R16._1_1_ == 0xf) {
      Z = &setup->bmRequestType;
      *(undefined2 *)(uVar8 - 0x11) = 0x132d;
      eeprom_update_word();
      setup = (UsbSetupPacket *)((uint)setup._1_1_ << 8);
    }
    else if (R17R16._1_1_ < 0xf) {
      if (R17R16._1_1_ == 0xd) {
        OCR0A = 0xff;
        OCR0B = 0xff;
        R19R18 = (undefined1 *)0xff;
        OCR1A._1_1_ = 0;
        OCR1A._0_1_ = 0xff;
        OCR1B._1_1_ = 0;
        OCR1B._0_1_ = 0xff;
        OCR2A = 0xff;
        OCR2B = 0xff;
        setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,10);
        calibration_ticks_remaining = 10;
      }
      else if (R17R16._1_1_ == 0xe) {
        X = (UsbSetupPacket *)&setup->wIndex;
        R17R16._0_1_ = (byte)*(ushort *)X;
        bVar1 = (byte)R17R16 + 10;
        R17R16 = (byte *)CONCAT11((((byte)R17R16 < 0xf6) + -1) * -2 + CARRY1(bVar1,bVar1),
                                  bVar1 * '\x02');
        setup = (UsbSetupPacket *)R17R16;
        *(undefined2 *)(uVar8 - 0x11) = 0x122d;
        setup._0_1_ = eeprom_read_byte((ushort)setup);
        usb_reply_buffer = (byte)setup;
        setup = (UsbSetupPacket *)&((UsbSetupPacket *)R17R16)->bRequest;
        *(undefined2 *)(uVar8 - 0x11) = 0x1233;
        setup._0_1_ = eeprom_read_byte((ushort)setup);
        setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,(byte)setup);
        goto LAB_code_1355;
      }
    }
    else if (R17R16._1_1_ == 0x10) {
      DAT_mem_057a = 0x82;
      R17R16 = (byte *)0x1002;
      *(undefined2 *)(uVar8 - 0x11) = 0x1410;
      twi_write_read_transaction();
      if ((byte)setup != '\0') {
        usb_reply_buffer = DAT_mem_057b;
        DAT_mem_0354 = DAT_mem_057a;
        DAT_mem_057a = -0x7d;
        *(undefined2 *)(uVar8 - 0x11) = 0x1425;
        twi_write_read_transaction();
        DAT_mem_0355 = DAT_mem_057b;
        DAT_mem_0356 = DAT_mem_057a;
        DAT_mem_057a = -0x7a;
        *(undefined2 *)(uVar8 - 0x11) = 0x1437;
        twi_write_read_transaction();
        DAT_mem_0357 = DAT_mem_057b;
        DAT_mem_0358 = DAT_mem_057a;
        DAT_mem_057a = -0x7f;
        *(undefined2 *)(uVar8 - 0x11) = 0x1449;
        twi_write_read_transaction();
        DAT_mem_0359 = DAT_mem_057b;
        DAT_mem_035a = DAT_mem_057a;
        DAT_mem_057a = -0x78;
        *(undefined2 *)(uVar8 - 0x11) = 0x145b;
        twi_write_read_transaction();
        DAT_mem_035b = DAT_mem_057b;
        DAT_mem_035c = DAT_mem_057a;
        R17R16._1_1_ = -0x7b;
        DAT_mem_057a = -0x7b;
        *(undefined2 *)(uVar8 - 0x11) = 0x146d;
        twi_write_read_transaction();
        DAT_mem_035d = DAT_mem_057b;
        DAT_mem_035e = DAT_mem_057a;
        DAT_mem_057a = -0x7c;
        *(undefined2 *)(uVar8 - 0x11) = 0x147f;
        twi_write_read_transaction();
        DAT_mem_035f = DAT_mem_057b;
        DAT_mem_0360 = DAT_mem_057a;
        DAT_mem_057a = R17R16._1_1_;
        *(undefined2 *)(uVar8 - 0x11) = 0x1490;
        twi_write_read_transaction();
        DAT_mem_0361 = DAT_mem_057b;
        DAT_mem_0362 = DAT_mem_057a;
        DAT_mem_057a = 0x87;
        *(undefined2 *)(uVar8 - 0x11) = 0x14a2;
        twi_write_read_transaction();
        DAT_mem_0363 = DAT_mem_057b;
        setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,DAT_mem_057a);
        DAT_mem_0364 = DAT_mem_057a;
        R17R16._1_1_ = 0x12;
        uVar9 = host_watchdog_threshold;
        goto LAB_code_1b6f;
      }
    }
    else if (R17R16._1_1_ == 0x11) {
      X = (UsbSetupPacket *)&setup->wIndex;
      *(undefined2 *)(uVar8 - 0x11) = 0x1a4d;
      oled_set_text_cursor();
      Z = &R15R14->bmRequestType;
      setup._0_1_ = (byte)(R15R14->wValue & 0xfd00);
      if ((ushort)(byte)setup == 0) {
        *(undefined2 *)(uVar8 - 0x11) = 0x1a54;
        oled_set_scale();
      }
      X = (UsbSetupPacket *)((int)&R15R14->wValue + 1);
      setup._0_1_ = *(byte *)X;
      setup._0_1_ = (byte)setup & 0xfd;
      if ((byte)setup == 1) {
        *(undefined2 *)(uVar8 - 0x11) = 0x1a5d;
        oled_set_scale();
      }
      Z = &R15R14->bmRequestType;
      *(undefined2 *)(uVar8 - 0x11) = 0x1a61;
      oled_render_character();
      X = (UsbSetupPacket *)((int)&R15R14->wValue + 1);
      setup._0_1_ = *(byte *)X;
      if ((byte)setup == '\x02') {
        X = (UsbSetupPacket *)((int)&R15R14->wIndex + 1);
        setup._0_1_ = *(byte *)X;
        setup = (UsbSetupPacket *)(uint)(byte)setup;
        X._0_1_ = (char)R15R14 + '\x04';
        X = (UsbSetupPacket *)CONCAT11(0x14,(byte)X);
        R1R0 = (int)setup * 0x14;
        R1R0 = R1R0 & 0xff;
        Z = &R15R14->bmRequestType;
        *(undefined2 *)(uVar8 - 0x11) = 0x1a78;
        eeprom_update_byte();
      }
      X = (UsbSetupPacket *)((int)&R15R14->wValue + 1);
      setup._0_1_ = *(byte *)X;
      X = R15R14;
      if ((byte)setup == '\x03') {
        X = (UsbSetupPacket *)((int)&R15R14->wIndex + 1);
        setup._0_1_ = *(byte *)X;
        setup = (UsbSetupPacket *)(uint)(byte)setup;
        X._0_1_ = (char)R15R14 + '\x04';
        X = (UsbSetupPacket *)CONCAT11(0x14,(byte)X);
        R1R0 = (int)setup * 0x14;
        R1R0 = R1R0 & 0xff;
        Z = &R15R14->bmRequestType;
        *(undefined2 *)(uVar8 - 0x11) = 0x1a90;
        eeprom_update_byte();
        X = (UsbSetupPacket *)((int)&R15R14->wIndex + 1);
        R19R18._0_1_ = *(byte *)X;
        X._0_1_ = (char)R15R14 + '\x04';
        X = (UsbSetupPacket *)CONCAT11(0x14,(byte)X);
        R1R0 = (uint)(byte)R19R18 * 0x14;
        R1R0 = R1R0 & 0xff;
        *(undefined2 *)(uVar8 - 0x11) = 0x1aa1;
        eeprom_update_byte();
        R19R18._0_1_ = *(byte *)((int)&R15R14->wIndex + 1);
        Z._0_1_ = (byte)R15R14;
        Z = (byte *)CONCAT11(0x14,(byte)Z);
        R1R0 = (uint)(byte)R19R18 * 0x14;
        R1R0 = R1R0 & 0xff;
        *(undefined2 *)(uVar8 - 0x11) = 0x1aaf;
        eeprom_update_byte();
        X = (UsbSetupPacket *)((int)&R15R14->wIndex + 1);
        R19R18._0_1_ = *(byte *)X;
        X._0_1_ = (char)R15R14 + '\x04';
        X = (UsbSetupPacket *)CONCAT11(0x14,(byte)X);
        R1R0 = (uint)(byte)R19R18 * 0x14;
        R1R0 = R1R0 & 0xff;
        *(undefined2 *)(uVar8 - 0x11) = 0x1ac0;
        eeprom_update_byte();
      }
      Z = &R15R14->bmRequestType;
      setup._0_1_ = *(char *)((int)&R15R14->wValue + 1);
      if ((byte)setup == '\x04') {
        *(undefined2 *)(uVar8 - 0x11) = 0x1ac7;
        oled_clear();
        R17R16._0_1_ = 200;
        R17R16._1_1_ = '\0';
        do {
          *(undefined2 *)(uVar8 - 0x11) = 0x1acd;
          eeprom_update_byte();
          setup = (UsbSetupPacket *)((uint)setup._1_1_ << 8);
          bVar1 = (byte)R17R16 + 1;
          R17R16._1_1_ = R17R16._1_1_ - (((byte)R17R16 != 0xff) + -1);
          Z = (byte *)CONCAT11(2,(byte)Z);
          R17R16._0_1_ = bVar1;
        } while (bVar1 != 8 || R17R16._1_1_ != (byte)((bVar1 < 8) + '\x02'));
      }
    }
  }
  else if (R17R16._1_1_ == 0x15) {
    Z = &setup->bmRequestType;
    setup._0_1_ = (byte)setup->wIndex;
    if ((byte)setup < 8) {
      *(undefined2 *)(uVar8 - 0x11) = 0x161b;
      twi_read_length_prefixed_block();
      usb_reply_buffer = (byte)setup;
      bVar1 = (byte)setup - 1;
      setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,bVar1);
      if (bVar1 < 0x20) {
        setup = (UsbSetupPacket *)0x0;
        while( true ) {
          if (usb_reply_buffer <= (byte)setup) break;
          Z = (byte *)CONCAT11(-(((byte)setup < 0xad) + -4),(byte)setup + 0x53);
          X = (UsbSetupPacket *)CONCAT11(-(((byte)setup < 0x86) + -6),(byte)setup + 0x7a);
          setup._1_1_ = *(byte *)X;
          *(byte *)((int)Z + 1) = setup._1_1_;
          setup = (UsbSetupPacket *)(uint)(byte)((byte)setup + 1);
        }
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 1) = R1R0._1_1_;
        DAT_mem_057a = 0x88;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        R17R16 = (byte *)CONCAT11(R17R16._1_1_,2);
        *(undefined2 *)(uVar8 - 0x11) = 0x1644;
        twi_write_read_transaction();
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 2) = DAT_mem_057a;
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 3) = DAT_mem_057b;
        DAT_mem_057a = 0x89;
        Z = &R15R14->bmRequestType;
        *(undefined2 *)(uVar8 - 0x11) = 0x1660;
        twi_write_read_transaction();
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 4) = DAT_mem_057a;
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 5) = DAT_mem_057b;
        DAT_mem_057a = 0x97;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        *(undefined2 *)(uVar8 - 0x11) = 0x167d;
        twi_write_read_transaction();
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 6) = DAT_mem_057a;
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 7) = DAT_mem_057b;
        DAT_mem_057a = 0x8b;
        Z = &R15R14->bmRequestType;
        *(undefined2 *)(uVar8 - 0x11) = 0x1699;
        twi_write_read_transaction();
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 8) = DAT_mem_057a;
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 9) = DAT_mem_057b;
        DAT_mem_057a = 0x8c;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        *(undefined2 *)(uVar8 - 0x11) = 0x16b6;
        twi_write_read_transaction();
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 10) = DAT_mem_057a;
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 0xb) = DAT_mem_057b;
        DAT_mem_057a = 0x96;
        Z = &R15R14->bmRequestType;
        *(undefined2 *)(uVar8 - 0x11) = 0x16d2;
        twi_write_read_transaction();
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 0xc) = DAT_mem_057a;
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 0xd) = DAT_mem_057b;
        DAT_mem_057a = 0x8d;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        *(undefined2 *)(uVar8 - 0x11) = 0x16ef;
        twi_write_read_transaction();
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 0xe) = DAT_mem_057a;
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 0xf) = DAT_mem_057b;
        DAT_mem_057a = 0x8e;
        Z = &R15R14->bmRequestType;
        *(undefined2 *)(uVar8 - 0x11) = 0x170b;
        twi_write_read_transaction();
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 0x10) = DAT_mem_057a;
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 0x11) = DAT_mem_057b;
        DAT_mem_057a = 0xd5;
        X = (UsbSetupPacket *)&R15R14->wIndex;
        *(undefined2 *)(uVar8 - 0x11) = 0x1728;
        twi_write_read_transaction();
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        *(byte *)((int)Z + 0x12) = DAT_mem_057a;
        Z = (byte *)CONCAT11(-((usb_reply_buffer < 0xad) + -4),usb_reply_buffer + 0x53);
        setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,DAT_mem_057b);
        *(byte *)((int)&((UsbSetupPacket *)((int)Z + 0x10))->wValue + 1) = DAT_mem_057b;
        R17R16._1_1_ = usb_reply_buffer + 0x14;
        uVar9 = host_watchdog_threshold;
        goto LAB_code_1b6f;
      }
    }
  }
  else if (R17R16._1_1_ < 0x15) {
    if (R17R16._1_1_ == 0x13) {
      Z = &setup->bmRequestType;
      setup._0_1_ = (byte)setup->wIndex;
      if ((byte)setup < 2) {
        DAT_mem_057a = 0xf7;
        R17R16 = (byte *)0x1308;
        *(undefined2 *)(uVar8 - 0x11) = 0x174c;
        twi_write_read_transaction();
        if ((byte)setup != '\0') {
          setup = (UsbSetupPacket *)(uint)DAT_mem_057a;
          R21R20 = setup;
          R23R22._0_1_ = 0;
          R23R22._1_1_ = 0;
          R17R16._1_1_ = '\f';
          do {
            bVar7 = (byte)R21R20 * '\x02';
            bVar1 = R21R20._1_1_ * '\x02' + CARRY1((byte)R21R20,(byte)R21R20);
            bVar17 = CARRY1(R21R20._1_1_,R21R20._1_1_) ||
                     CARRY1(R21R20._1_1_ * '\x02',CARRY1((byte)R21R20,(byte)R21R20));
            R21R20 = (UsbSetupPacket *)CONCAT11(bVar1,bVar7);
            bVar2 = (byte)R23R22 * '\x02' + bVar17;
            R23R22._1_1_ = R23R22._1_1_ * '\x02' +
                           (CARRY1((byte)R23R22,(byte)R23R22) ||
                           CARRY1((byte)R23R22 * '\x02',bVar17));
            R17R16._1_1_ = R17R16._1_1_ + -1;
            R23R22._0_1_ = bVar2;
          } while (R17R16._1_1_ != '\0');
          setup = (UsbSetupPacket *)(uint)DAT_mem_057b;
          X._0_1_ = 0;
          X._1_1_ = 0;
          R17R16._0_1_ = '\x04';
          do {
            R21R20._0_1_ = (byte)setup * '\x02';
            R21R20._1_1_ = setup._1_1_ * '\x02' + CARRY1((byte)setup,(byte)setup);
            bVar17 = CARRY1(setup._1_1_,setup._1_1_) ||
                     CARRY1(setup._1_1_ * '\x02',CARRY1((byte)setup,(byte)setup));
            setup = (UsbSetupPacket *)CONCAT11(R21R20._1_1_,(byte)R21R20);
            R23R22._0_1_ = (byte)X * '\x02' + bVar17;
            X._1_1_ = X._1_1_ * '\x02' +
                      (CARRY1((byte)X,(byte)X) || CARRY1((byte)X * '\x02',bVar17));
            R17R16._0_1_ = (byte)R17R16 + -1;
            X._0_1_ = (byte)R23R22;
          } while ((byte)R17R16 != '\0');
          R21R20._0_1_ = bVar7 | (byte)R21R20;
          R21R20._1_1_ = bVar1 | R21R20._1_1_;
          R23R22._0_1_ = bVar2 | (byte)R23R22;
          R23R22._1_1_ = R23R22._1_1_ | X._1_1_;
          R11R10 = R23R22;
          R9R8._0_1_ = (byte)R21R20 | DAT_mem_057c >> 4;
          R9R8._1_1_ = R21R20._1_1_;
          *(byte *)(Y + 0xd) = (byte)R9R8;
          *(byte *)(Y + 0xe) = R9R8._1_1_;
          *(byte *)(Y + 0xf) = (byte)R11R10;
          *(byte *)(Y + 0x10) = R11R10._1_1_;
          setup = (UsbSetupPacket *)(uint)DAT_mem_057d;
          R21R20 = setup;
          R23R22._0_1_ = 0;
          R23R22._1_1_ = 0;
          setup = (UsbSetupPacket *)0xc;
          do {
            bVar7 = (byte)R21R20 * '\x02';
            bVar1 = R21R20._1_1_ * '\x02' + CARRY1((byte)R21R20,(byte)R21R20);
            bVar17 = CARRY1(R21R20._1_1_,R21R20._1_1_) ||
                     CARRY1(R21R20._1_1_ * '\x02',CARRY1((byte)R21R20,(byte)R21R20));
            R21R20 = (UsbSetupPacket *)CONCAT11(bVar1,bVar7);
            bVar2 = (byte)R23R22 * '\x02' + bVar17;
            R23R22._1_1_ = R23R22._1_1_ * '\x02' +
                           (CARRY1((byte)R23R22,(byte)R23R22) ||
                           CARRY1((byte)R23R22 * '\x02',bVar17));
            setup._0_1_ = (byte)setup - 1;
            bVar3 = (byte)setup;
            setup = (UsbSetupPacket *)(uint)(byte)setup;
            R23R22._0_1_ = bVar2;
          } while (bVar3 != 0);
          setup = (UsbSetupPacket *)(uint)DAT_mem_057e;
          X._0_1_ = 0;
          X._1_1_ = 0;
          R19R18._0_1_ = '\x04';
          do {
            bVar5 = (byte)setup * '\x02';
            bVar3 = setup._1_1_ * '\x02' + CARRY1((byte)setup,(byte)setup);
            bVar17 = CARRY1(setup._1_1_,setup._1_1_) ||
                     CARRY1(setup._1_1_ * '\x02',CARRY1((byte)setup,(byte)setup));
            setup = (UsbSetupPacket *)CONCAT11(bVar3,bVar5);
            bVar4 = (byte)X * '\x02' + bVar17;
            X._1_1_ = X._1_1_ * '\x02' +
                      (CARRY1((byte)X,(byte)X) || CARRY1((byte)X * '\x02',bVar17));
            R19R18._0_1_ = (byte)R19R18 + -1;
            X._0_1_ = bVar4;
          } while ((byte)R19R18 != '\0');
          setup._0_1_ = bVar5 | bVar7;
          setup._1_1_ = bVar3 | bVar1;
          X._0_1_ = bVar4 | bVar2;
          X._1_1_ = X._1_1_ | R23R22._1_1_;
          setup._0_1_ = (byte)setup | DAT_mem_057f >> 4;
          R3R2._0_1_ = (byte)R15R14->wIndex;
          R3R2._1_1_ = R1R0._1_1_;
          R17R16._0_1_ = (byte)R3R2 * '\x02';
          R17R16._1_1_ = R1R0._1_1_ * '\x02' + CARRY1((byte)R3R2,(byte)R3R2);
          Z._1_1_ = R17R16._1_1_ - (((byte)R17R16 < 0x36) + -5);
          R19R18 = (byte *)CONCAT11(Z._1_1_,(byte)R17R16 - 0x36);
          R21R20._0_1_ = *R19R18;
          R21R20._1_1_ = R19R18[1];
          R13R12 = setup;
          R15R14._0_1_ = (byte)X;
          R15R14._1_1_ = X._1_1_;
          R23R22._0_1_ = '\x04';
          do {
            bVar1 = R15R14._1_1_;
            bVar2 = (byte)R15R14;
            R15R14._1_1_ = R15R14._1_1_ >> 1;
            R15R14._0_1_ = bVar1 << 7 | (byte)R15R14 >> 1;
            bVar1 = R13R12._1_1_;
            R13R12._1_1_ = bVar2 << 7 | R13R12._1_1_ >> 1;
            R13R12._0_1_ = bVar1 << 7 | (byte)R13R12 >> 1;
            R23R22._0_1_ = (byte)R23R22 + -1;
          } while ((byte)R23R22 != '\0');
          bVar17 = R13R12._1_1_ < R21R20._1_1_ ||
                   (byte)(R13R12._1_1_ - R21R20._1_1_) < ((byte)R13R12 < (byte)R21R20);
          R13R12 = (UsbSetupPacket *)
                   CONCAT11(R13R12._1_1_ - (R21R20._1_1_ + ((byte)R13R12 < (byte)R21R20)),
                            (byte)R13R12 - (byte)R21R20);
          R15R14 = (UsbSetupPacket *)
                   CONCAT11(R15R14._1_1_ - ((byte)R15R14 < bVar17),(byte)R15R14 - bVar17);
          Z._0_1_ = '\x03';
          do {
            bVar1 = X._1_1_;
            bVar2 = (byte)X;
            X._1_1_ = X._1_1_ >> 1;
            X._0_1_ = bVar1 << 7 | (byte)X >> 1;
            bVar1 = setup._1_1_;
            setup._1_1_ = bVar2 << 7 | setup._1_1_ >> 1;
            setup._0_1_ = bVar1 << 7 | (byte)setup >> 1;
            Z._0_1_ = (byte)Z + -1;
          } while ((byte)Z != '\0');
          bVar1 = R21R20._1_1_ * '\x02' + CARRY1((byte)R21R20,(byte)R21R20);
          bVar17 = CARRY1(R21R20._1_1_,R21R20._1_1_) ||
                   CARRY1(R21R20._1_1_ * '\x02',CARRY1((byte)R21R20,(byte)R21R20));
          bVar18 = (byte)setup < (byte)((byte)R21R20 * '\x02');
          bVar19 = setup._1_1_ < bVar1 || (byte)(setup._1_1_ - bVar1) < bVar18;
          R9R8 = (UsbSetupPacket *)
                 CONCAT11(setup._1_1_ - (bVar1 + bVar18),(byte)setup + (byte)R21R20 * -2);
          R11R10 = (UsbSetupPacket *)
                   CONCAT11(X._1_1_ - ((byte)X < bVar17 || (byte)((byte)X - bVar17) < bVar19),
                            (byte)X - (bVar17 + bVar19));
          X = (UsbSetupPacket *)
              CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0xad) + -6),(byte)R17R16 + 0x53);
          puVar14 = (undefined1 *)X;
          X = (UsbSetupPacket *)((int)X + 1);
          R1R0._0_1_ = *puVar14;
          X._1_1_ = *(byte *)X;
          X._0_1_ = (byte)R1R0;
          *(undefined2 *)(uVar8 - 0x11) = 0x17d3;
          FUN_code_1bf4();
          R5R4._0_1_ = (byte)R23R22;
          R5R4._1_1_ = R23R22._1_1_;
          R7R6 = setup;
          X._0_1_ = '\v';
          do {
            bVar1 = R5R4._1_1_;
            bVar7 = R7R6._1_1_;
            bVar2 = (byte)R7R6;
            R7R6._1_1_ = R7R6._1_1_ >> 1;
            R7R6._0_1_ = bVar7 << 7 | (byte)R7R6 >> 1;
            R5R4._1_1_ = bVar2 << 7 | R5R4._1_1_ >> 1;
            R5R4._0_1_ = bVar1 << 7 | (byte)R5R4 >> 1;
            X._0_1_ = (byte)X + -1;
          } while ((byte)X != '\0');
          *(undefined2 *)(uVar8 - 0x11) = 0x17e2;
          avr_multiply_32bit();
          X._1_1_ = '\f';
          do {
            X._1_1_ = X._1_1_ + -1;
          } while (X._1_1_ != '\0');
          X = (UsbSetupPacket *)
              CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0x98) + -6),(byte)R17R16 + 0x68);
          R1R0._0_1_ = *(byte *)X;
          X = *(UsbSetupPacket **)X;
          *(undefined2 *)(uVar8 - 0x11) = 0x17f3;
          FUN_code_1bf4();
          R9R8._0_1_ = (byte)R23R22;
          R9R8._1_1_ = R23R22._1_1_;
          R11R10 = setup;
          setup = (UsbSetupPacket *)0xe;
          do {
            bVar1 = R9R8._1_1_;
            bVar7 = R11R10._1_1_;
            bVar2 = (byte)R11R10;
            R11R10._1_1_ = R11R10._1_1_ >> 1;
            R11R10._0_1_ = bVar7 << 7 | (byte)R11R10 >> 1;
            R9R8._1_1_ = bVar2 << 7 | R9R8._1_1_ >> 1;
            R9R8._0_1_ = bVar1 << 7 | (byte)R9R8 >> 1;
            setup._0_1_ = (byte)setup - 1;
            bVar1 = (byte)setup;
            setup = (UsbSetupPacket *)(uint)(byte)setup;
          } while (bVar1 != 0);
          bVar17 = CARRY1((byte)R9R8,(byte)R5R4);
          bVar18 = CARRY1(R9R8._1_1_,R5R4._1_1_) || CARRY1(R9R8._1_1_ + R5R4._1_1_,bVar17);
          R11R10._1_1_ = R11R10._1_1_ + R7R6._1_1_ +
                         (CARRY1((byte)R11R10,(byte)R7R6) ||
                         CARRY1((byte)R11R10 + (byte)R7R6,bVar18));
          X = (UsbSetupPacket *)0x5;
          R11R10._0_1_ = (byte)R11R10 + (byte)R7R6 + bVar18;
          R9R8._0_1_ = (byte)R9R8 + (byte)R5R4;
          R9R8._1_1_ = R9R8._1_1_ + R5R4._1_1_ + bVar17;
          *(undefined2 *)(uVar8 - 0x11) = 0x1806;
          FUN_code_1be9();
          bVar17 = R23R22._1_1_ != -1 || (byte)(R23R22._1_1_ + 1) < ((byte)R23R22 < 0x80);
          R19R18._1_1_ = (byte)setup - (bVar17 + -1);
          R21R20._0_1_ = setup._1_1_ -
                         (((byte)setup != -1 || (byte)((byte)setup + 1) < bVar17) + -1);
          R21R20._1_1_ = 0;
          if (((byte)R21R20 & 0x80) != 0) {
            R21R20._1_1_ = 0xff;
          }
          *(byte *)(Y + 9) = R23R22._1_1_ - (((byte)R23R22 < 0x80) + -1);
          *(byte *)(Y + 10) = R19R18._1_1_;
          *(byte *)(Y + 0xb) = (byte)R21R20;
          *(byte *)(Y + 0xc) = R21R20._1_1_;
          setup._1_1_ = R9R8._1_1_ - 0x2c;
          X._0_1_ = (byte)R11R10 - ((R9R8._1_1_ < 0x2c) + '\x01');
          X._1_1_ = R11R10._1_1_ -
                    (R1R0._1_1_ +
                    ((byte)R11R10 == 0 || (byte)((byte)R11R10 - 1) < (R9R8._1_1_ < 0x2c)));
          *(byte *)(Y + 5) = (byte)R9R8;
          *(byte *)(Y + 6) = setup._1_1_;
          *(byte *)(Y + 7) = (byte)X;
          *(byte *)(Y + 8) = X._1_1_;
          X = (UsbSetupPacket *)CONCAT11(R3R2._1_1_ - (((byte)R3R2 < 0xeb) + -6),(byte)R3R2 + 0x15);
          X._0_1_ = *(byte *)X;
          X = (UsbSetupPacket *)(uint)(byte)X;
          *(undefined2 *)(uVar8 - 0x11) = 0x182a;
          FUN_code_1be9();
          R13R12._0_1_ = (byte)R23R22;
          R13R12._1_1_ = R23R22._1_1_;
          R15R14 = setup;
          R23R22._0_1_ = '\v';
          do {
            bVar1 = R13R12._1_1_;
            cVar20 = R15R14._1_1_;
            bVar2 = (byte)R15R14;
            R15R14._1_1_ = (char)R15R14._1_1_ >> 1;
            R15R14._0_1_ = cVar20 << 7 | (byte)R15R14 >> 1;
            R13R12._1_1_ = bVar2 << 7 | R13R12._1_1_ >> 1;
            R13R12._0_1_ = bVar1 << 7 | (byte)R13R12 >> 1;
            R23R22._0_1_ = (byte)R23R22 + -1;
          } while ((byte)R23R22 != '\0');
          bVar17 = 0x7f < R13R12._1_1_;
          R13R12 = (UsbSetupPacket *)CONCAT11(R13R12._1_1_ + 0x80,(byte)R13R12);
          R15R14 = (UsbSetupPacket *)
                   CONCAT11(R15R14._1_1_ + R1R0._1_1_ +
                            (CARRY1((byte)R15R14,R1R0._1_1_) ||
                            CARRY1((byte)R15R14 + R1R0._1_1_,bVar17)),
                            (byte)R15R14 + R1R0._1_1_ + bVar17);
          X = (UsbSetupPacket *)CONCAT11(R3R2._1_1_ - (((byte)R3R2 < 0x31) + -5),(byte)R3R2 - 0x31);
          X._0_1_ = *(byte *)X;
          R1R0._0_1_ = (byte)X * '\x02';
          X = (UsbSetupPacket *)CONCAT11(-CARRY1((byte)X,(byte)X),(byte)X);
          *(undefined2 *)(uVar8 - 0x11) = 0x1840;
          FUN_code_1bf4();
          Z._0_1_ = '\n';
          do {
            Z._0_1_ = (byte)Z + -1;
          } while ((byte)Z != '\0');
          *(undefined2 *)(uVar8 - 0x11) = 0x184b;
          avr_multiply_32bit();
          Z._1_1_ = '\n';
          do {
            Z._1_1_ = Z._1_1_ + -1;
          } while (Z._1_1_ != '\0');
          X = (UsbSetupPacket *)
              CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0x2f) + -5),(byte)R17R16 - 0x2f);
          R1R0._0_1_ = *(byte *)X;
          X = *(UsbSetupPacket **)X;
          *(undefined2 *)(uVar8 - 0x11) = 0x1860;
          FUN_code_1bf4();
          R5R4._1_1_ = R23R22._1_1_ + 0x20;
          R5R4._0_1_ = (byte)R23R22;
          R7R6._0_1_ = (byte)setup + R1R0._1_1_ + (0xdf < R23R22._1_1_);
          R7R6._1_1_ = setup._1_1_ + R1R0._1_1_ +
                       (CARRY1((byte)setup,R1R0._1_1_) ||
                       CARRY1((byte)setup + R1R0._1_1_,0xdf < R23R22._1_1_));
          X._0_1_ = '\x0e';
          do {
            cVar20 = R7R6._1_1_;
            bVar2 = (byte)R7R6;
            bVar1 = R5R4._1_1_;
            R7R6._1_1_ = (char)R7R6._1_1_ >> 1;
            R7R6._0_1_ = cVar20 << 7 | (byte)R7R6 >> 1;
            R5R4._1_1_ = bVar2 << 7 | R5R4._1_1_ >> 1;
            R5R4._0_1_ = bVar1 << 7 | (byte)R5R4 >> 1;
            X._0_1_ = (byte)X + -1;
          } while ((byte)X != '\0');
          R13R12._0_1_ = DAT_mem_0581;
          R13R12._1_1_ = DAT_mem_0580;
          R15R14._0_1_ = R1R0._1_1_;
          R15R14._1_1_ = R1R0._1_1_;
          X._1_1_ = '\x0e';
          do {
            bVar7 = (byte)R13R12 * '\x02';
            bVar1 = R13R12._1_1_ * '\x02' + CARRY1((byte)R13R12,(byte)R13R12);
            bVar17 = CARRY1(R13R12._1_1_,R13R12._1_1_) ||
                     CARRY1(R13R12._1_1_ * '\x02',CARRY1((byte)R13R12,(byte)R13R12));
            bVar2 = (byte)R15R14 * '\x02' + bVar17;
            R15R14._1_1_ = R15R14._1_1_ * '\x02' +
                           (CARRY1((byte)R15R14,(byte)R15R14) ||
                           CARRY1((byte)R15R14 * '\x02',bVar17));
            X._1_1_ = X._1_1_ + -1;
            R13R12._0_1_ = bVar7;
            R13R12._1_1_ = bVar1;
            R15R14._0_1_ = bVar2;
          } while (X._1_1_ != '\0');
          bVar4 = bVar1 + 0x40;
          bVar3 = bVar2 + R1R0._1_1_ + (0xbf < bVar1);
          X = (UsbSetupPacket *)
              CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0xef) + -6),(byte)R17R16 + 0x11);
          puVar15 = (undefined2 *)X;
          X = (UsbSetupPacket *)((int)X + 1);
          setup._1_1_ = *(byte *)X;
          bVar17 = CARRY1(setup._1_1_,setup._1_1_);
          X._1_1_ = -bVar17;
          R19R18._0_1_ = '\x14';
          setup = (UsbSetupPacket *)*puVar15;
          X._0_1_ = -bVar17;
          do {
            bVar13 = (byte)setup;
            bVar10 = (byte)setup * '\x02';
            bVar5 = setup._1_1_ * '\x02' + CARRY1((byte)setup,(byte)setup);
            bVar17 = CARRY1(setup._1_1_,setup._1_1_) ||
                     CARRY1(setup._1_1_ * '\x02',CARRY1((byte)setup,(byte)setup));
            setup = (UsbSetupPacket *)CONCAT11(bVar5,bVar10);
            bVar6 = (byte)X * '\x02' + bVar17;
            X._1_1_ = X._1_1_ * '\x02' +
                      (CARRY1((byte)X,(byte)X) || CARRY1((byte)X * '\x02',bVar17));
            R19R18._0_1_ = (byte)R19R18 + -1;
            X._0_1_ = bVar6;
          } while ((byte)R19R18 != '\0');
          bVar17 = bVar4 < bVar5 || (byte)(bVar4 - bVar5) < (bVar7 < bVar10);
          R13R12 = (UsbSetupPacket *)
                   CONCAT11(bVar4 - (bVar5 + (bVar7 < bVar10)),bVar7 + bVar13 * -2);
          R15R14 = (UsbSetupPacket *)
                   CONCAT11((R15R14._1_1_ + R1R0._1_1_ +
                            (CARRY1(bVar2,R1R0._1_1_) || CARRY1(bVar2 + R1R0._1_1_,0xbf < bVar1))) -
                            (X._1_1_ + (bVar3 < bVar6 || (byte)(bVar3 - bVar6) < bVar17)),
                            bVar3 - (bVar6 + bVar17));
          X = (UsbSetupPacket *)
              CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0x65) + -6),(byte)R17R16 + 0x9b);
          R1R0._0_1_ = *(byte *)X;
          X = *(UsbSetupPacket **)X;
          *(undefined2 *)(uVar8 - 0x11) = 0x18a1;
          FUN_code_1bf4();
          R19R18._1_1_ = '\x0f';
          do {
            R19R18._1_1_ = R19R18._1_1_ + -1;
          } while (R19R18._1_1_ != '\0');
          *(undefined2 *)(uVar8 - 0x11) = 0x18b4;
          avr_multiply_32bit();
          R13R12 = R23R22;
          R15R14 = setup;
          R21R20._0_1_ = '\x0f';
          do {
            R21R20._0_1_ = (byte)R21R20 + -1;
          } while ((byte)R21R20 != '\0');
          *(undefined2 *)(uVar8 - 0x11) = 0x18c1;
          avr_multiply_32bit();
          R23R22._0_1_ = '\a';
          do {
            R23R22._0_1_ = (byte)R23R22 + -1;
          } while ((byte)R23R22 != '\0');
          Z = (byte *)CONCAT11(R3R2._1_1_ - (((byte)R3R2 < 0xa5) + -6),(byte)R3R2 + 0x5b);
          X._0_1_ = *Z;
          X = (UsbSetupPacket *)(uint)(byte)X;
          *(undefined2 *)(uVar8 - 0x11) = 0x18d1;
          FUN_code_1be9();
          X = setup;
          setup = R23R22;
          R23R22._1_1_ = '\x04';
          do {
            cVar20 = X._1_1_;
            bVar2 = (byte)X;
            X._1_1_ = (char)X._1_1_ >> 1;
            X._0_1_ = cVar20 << 7 | (byte)X >> 1;
            bVar1 = setup._1_1_;
            setup._1_1_ = bVar2 << 7 | setup._1_1_ >> 1;
            setup._0_1_ = bVar1 << 7 | (byte)setup >> 1;
            R23R22._1_1_ = R23R22._1_1_ + -1;
          } while (R23R22._1_1_ != '\0');
          bVar17 = R13R12._1_1_ < setup._1_1_ ||
                   (byte)(R13R12._1_1_ - setup._1_1_) < ((byte)R13R12 < (byte)setup);
          R13R12 = (UsbSetupPacket *)
                   CONCAT11(R13R12._1_1_ - (setup._1_1_ + ((byte)R13R12 < (byte)setup)),
                            (byte)R13R12 - (byte)setup);
          R15R14._1_1_ = R15R14._1_1_ -
                         (X._1_1_ +
                         ((byte)R15R14 < (byte)X || (byte)((byte)R15R14 - (byte)X) < bVar17));
          R15R14 = (UsbSetupPacket *)CONCAT11(R15R14._1_1_,(byte)R15R14 - ((byte)X + bVar17));
          if ((R15R14._1_1_ & 0x80) != 0) {
            R13R12 = (UsbSetupPacket *)CONCAT11(R1R0._1_1_,R1R0._1_1_);
            R15R14 = R13R12;
          }
          bVar17 = (byte)R15R14 < R1R0._1_1_ ||
                   (byte)((byte)R15R14 - R1R0._1_1_) <
                   (R13R12._1_1_ < R1R0._1_1_ ||
                   (byte)(R13R12._1_1_ - R1R0._1_1_) < ((byte)R13R12 == '\0'));
          if ((char)(R15R14._1_1_ - (bVar17 + '\x19')) < '\0' ==
              (SBORROW1(R15R14._1_1_,'\x19') != SBORROW1(R15R14._1_1_ + -0x19,bVar17))) {
            R13R12 = (UsbSetupPacket *)CONCAT11(R1R0._1_1_,R1R0._1_1_);
            R15R14 = (UsbSetupPacket *)CONCAT11(0x19,R1R0._1_1_);
          }
          X = R15R14;
          setup = R13R12;
          R21R20._0_1_ = '\f';
          do {
            cVar20 = X._1_1_;
            bVar2 = (byte)X;
            X._1_1_ = (char)X._1_1_ >> 1;
            X._0_1_ = cVar20 << 7 | (byte)X >> 1;
            bVar1 = setup._1_1_;
            setup._1_1_ = bVar2 << 7 | setup._1_1_ >> 1;
            setup._0_1_ = bVar1 << 7 | (byte)setup >> 1;
            R21R20._0_1_ = (byte)R21R20 + -1;
          } while ((byte)R21R20 != '\0');
          *(byte *)(Y + 5) = (byte)setup;
          *(byte *)(Y + 6) = setup._1_1_;
          *(byte *)(Y + 7) = (byte)X;
          *(byte *)(Y + 8) = X._1_1_;
          cVar20 = R11R10._1_1_;
          bVar2 = (byte)R11R10;
          bVar1 = R9R8._1_1_;
          R11R10._1_1_ = (char)R11R10._1_1_ >> 1;
          R11R10._0_1_ = cVar20 << 7 | (byte)R11R10 >> 1;
          R9R8._1_1_ = bVar2 << 7 | R9R8._1_1_ >> 1;
          R9R8._0_1_ = bVar1 << 7 | (byte)R9R8 >> 1;
          bVar17 = R9R8._1_1_ < 0xfa;
          R9R8 = (UsbSetupPacket *)CONCAT11(R9R8._1_1_ + 6,(byte)R9R8);
          R11R10 = (UsbSetupPacket *)
                   CONCAT11(R11R10._1_1_ -
                            (R1R0._1_1_ +
                            ((byte)R11R10 < R1R0._1_1_ || (byte)((byte)R11R10 - R1R0._1_1_) < bVar17
                            )),(byte)R11R10 - (R1R0._1_1_ + bVar17));
          Z._0_1_ = '\x02';
          do {
            Z._0_1_ = (byte)Z + -1;
          } while ((byte)Z != '\0');
          *(undefined2 *)(uVar8 - 0x11) = 0x1911;
          avr_multiply_32bit();
          R5R4 = R23R22;
          R7R6 = setup;
          Z._1_1_ = '\v';
          do {
            Z._1_1_ = Z._1_1_ + -1;
          } while (Z._1_1_ != '\0');
          Z = (byte *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0xe5) + -6),(byte)R17R16 + 0x1b);
          X = *(UsbSetupPacket **)Z;
          *(undefined2 *)(uVar8 - 0x11) = 0x1923;
          FUN_code_1bf4();
          R13R12 = R23R22;
          R15R14 = setup;
          Z = (byte *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0xf3) + -6),(byte)R17R16 + 0xd);
          X = *(UsbSetupPacket **)Z;
          *(undefined2 *)(uVar8 - 0x11) = 0x192e;
          FUN_code_1bf4();
          bVar7 = (byte)R23R22 * '\x02';
          bVar1 = R23R22._1_1_ * '\x02' + CARRY1((byte)R23R22,(byte)R23R22);
          bVar17 = CARRY1(R23R22._1_1_,R23R22._1_1_) ||
                   CARRY1(R23R22._1_1_ * '\x02',CARRY1((byte)R23R22,(byte)R23R22));
          bVar2 = (byte)setup * '\x02' + bVar17;
          bVar18 = CARRY1(R13R12._1_1_,bVar1) ||
                   CARRY1(R13R12._1_1_ + bVar1,CARRY1((byte)R13R12,bVar7));
          R13R12 = (UsbSetupPacket *)
                   CONCAT11(R13R12._1_1_ + bVar1 + CARRY1((byte)R13R12,bVar7),(byte)R13R12 + bVar7);
          X._0_1_ = (byte)R15R14 + bVar2 + bVar18;
          X._1_1_ = R15R14._1_1_ +
                    setup._1_1_ * '\x02' +
                    (CARRY1((byte)setup,(byte)setup) || CARRY1((byte)setup * '\x02',bVar17)) +
                    (CARRY1((byte)R15R14,bVar2) || CARRY1((byte)R15R14 + bVar2,bVar18));
          setup = R13R12;
          R19R18._1_1_ = '\x02';
          do {
            cVar20 = X._1_1_;
            bVar2 = (byte)X;
            X._1_1_ = (char)X._1_1_ >> 1;
            X._0_1_ = cVar20 << 7 | (byte)X >> 1;
            bVar1 = setup._1_1_;
            setup._1_1_ = bVar2 << 7 | setup._1_1_ >> 1;
            setup._0_1_ = bVar1 << 7 | (byte)setup >> 1;
            R19R18._1_1_ = R19R18._1_1_ + -1;
          } while (R19R18._1_1_ != '\0');
          Z = (byte *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0xa0) + -6),(byte)R17R16 + 0x60);
          R13R12._0_1_ = *Z;
          R13R12._1_1_ = Z[1];
          R1R0 = CONCAT11(R1R0._1_1_,R13R12._1_1_ * '\x02');
          R15R14._0_1_ = (byte)R13R12 + (byte)X;
          R15R14._1_1_ = R13R12._1_1_ + X._1_1_ + CARRY1((byte)R13R12,(byte)X);
          Z = (byte *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0x9c) + -6),(byte)R17R16 + 100);
          X = *(UsbSetupPacket **)Z;
          R23R22._0_1_ = '\r';
          do {
            R23R22._0_1_ = (byte)R23R22 + -1;
          } while ((byte)R23R22 != '\0');
          R13R12._0_1_ = (byte)setup;
          R13R12._1_1_ = setup._1_1_;
          *(undefined2 *)(uVar8 - 0x11) = 0x1961;
          FUN_code_1bf4();
          R5R4._0_1_ = (byte)R23R22;
          R5R4._1_1_ = R23R22._1_1_;
          R7R6 = setup;
          R23R22._1_1_ = '\x03';
          do {
            bVar1 = R5R4._1_1_;
            cVar20 = R7R6._1_1_;
            bVar2 = (byte)R7R6;
            R7R6._1_1_ = (char)R7R6._1_1_ >> 1;
            R7R6._0_1_ = cVar20 << 7 | (byte)R7R6 >> 1;
            R5R4._1_1_ = bVar2 << 7 | R5R4._1_1_ >> 1;
            R5R4._0_1_ = bVar1 << 7 | (byte)R5R4 >> 1;
            R23R22._1_1_ = R23R22._1_1_ + -1;
          } while (R23R22._1_1_ != '\0');
          Z = (byte *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0x3a) + -5),(byte)R17R16 - 0x3a);
          X = *(UsbSetupPacket **)Z;
          *(undefined2 *)(uVar8 - 0x11) = 0x1973;
          FUN_code_1bf4();
          Z._1_1_ = '\x12';
          do {
            Z._1_1_ = Z._1_1_ + -1;
          } while (Z._1_1_ != '\0');
          Z = (byte *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0x8a) + -6),(byte)R17R16 + 0x76);
          X._0_1_ = ((UsbSetupPacket *)Z)->bmRequestType;
          X._1_1_ = ((UsbSetupPacket *)Z)->bRequest;
          *(undefined2 *)(uVar8 - 0x11) = 0x1990;
          FUN_code_1be9();
          R9R8 = R23R22;
          R11R10 = setup;
          X = (UsbSetupPacket *)CONCAT11(X._1_1_,0xf);
          do {
            cVar20 = R11R10._1_1_;
            bVar2 = (byte)R11R10;
            R11R10._1_1_ = (char)R11R10._1_1_ >> 1;
            R11R10._0_1_ = cVar20 << 7 | (byte)R11R10 >> 1;
            bVar1 = R9R8._1_1_;
            R9R8._1_1_ = bVar2 << 7 | R9R8._1_1_ >> 1;
            R9R8._0_1_ = bVar1 << 7 | (byte)R9R8 >> 1;
            X._0_1_ = (byte)X + -1;
          } while ((byte)X != '\0');
          bVar17 = R9R8._1_1_ < R1R0._1_1_ ||
                   (byte)(R9R8._1_1_ - R1R0._1_1_) < ((byte)R9R8 < R1R0._1_1_);
          if ((((byte)R9R8 != R1R0._1_1_ ||
               R9R8._1_1_ != (byte)(R1R0._1_1_ + ((byte)R9R8 < R1R0._1_1_))) ||
              (byte)R11R10 != (byte)(R1R0._1_1_ + bVar17)) ||
              R11R10._1_1_ !=
              (byte)(R1R0._1_1_ +
                    ((byte)R11R10 < R1R0._1_1_ || (byte)((byte)R11R10 - R1R0._1_1_) < bVar17))) {
            R19R18._1_1_ = '\f';
            do {
              cVar20 = R15R14._1_1_;
              bVar2 = (byte)R15R14;
              bVar1 = R13R12._1_1_;
              R15R14._1_1_ = (char)R15R14._1_1_ >> 1;
              R15R14._0_1_ = cVar20 << 7 | (byte)R15R14 >> 1;
              R13R12._1_1_ = bVar2 << 7 | R13R12._1_1_ >> 1;
              R13R12._0_1_ = bVar1 << 7 | (byte)R13R12 >> 1;
              R19R18._1_1_ = R19R18._1_1_ + -1;
            } while (R19R18._1_1_ != '\0');
            X = (UsbSetupPacket *)0xf3cb;
            *(undefined2 *)(uVar8 - 0x11) = 0x19b2;
            FUN_code_1bf7();
            if ((setup._1_1_ - (((byte)setup < 0xb0) + '<') & 0x80) == 0) {
              *(undefined2 *)(uVar8 - 0x11) = 0x19be;
              avr_unsigned_divide_32bit();
              R13R12._0_1_ = (byte)R19R18;
              R13R12._1_1_ = R19R18._1_1_;
              R15R14._0_1_ = (byte)R21R20;
              R15R14._1_1_ = R21R20._1_1_;
            }
            else {
              *(undefined2 *)(uVar8 - 0x11) = 0x19c5;
              avr_unsigned_divide_32bit();
              R13R12._0_1_ = (byte)R19R18 * '\x02';
              R13R12._1_1_ = R19R18._1_1_ * '\x02' + CARRY1((byte)R19R18,(byte)R19R18);
              bVar17 = CARRY1(R19R18._1_1_,R19R18._1_1_) ||
                       CARRY1(R19R18._1_1_ * '\x02',CARRY1((byte)R19R18,(byte)R19R18));
              R15R14._0_1_ = (byte)R21R20 * '\x02' + bVar17;
              R15R14._1_1_ = R21R20._1_1_ * '\x02' +
                             (CARRY1((byte)R21R20,(byte)R21R20) ||
                             CARRY1((byte)R21R20 * '\x02',bVar17));
            }
            R19R18._0_1_ = '\x03';
            do {
              R19R18._0_1_ = (byte)R19R18 + -1;
            } while ((byte)R19R18 != '\0');
            *(undefined2 *)(uVar8 - 0x11) = 0x19d8;
            avr_multiply_32bit();
            R23R22._0_1_ = '\r';
            do {
              R23R22._0_1_ = (byte)R23R22 + -1;
            } while ((byte)R23R22 != '\0');
            Z = (byte *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0xe9) + -6),(byte)R17R16 + 0x17);
            X = *(UsbSetupPacket **)Z;
            *(undefined2 *)(uVar8 - 0x11) = 0x19e8;
            FUN_code_1bf4();
            R9R8._0_1_ = (byte)R23R22;
            R9R8._1_1_ = R23R22._1_1_;
            R11R10 = setup;
            R23R22._1_1_ = '\f';
            do {
              bVar1 = R9R8._1_1_;
              cVar20 = R11R10._1_1_;
              bVar2 = (byte)R11R10;
              R11R10._1_1_ = (char)R11R10._1_1_ >> 1;
              R11R10._0_1_ = cVar20 << 7 | (byte)R11R10 >> 1;
              R9R8._1_1_ = bVar2 << 7 | R9R8._1_1_ >> 1;
              R9R8._0_1_ = bVar1 << 7 | (byte)R9R8 >> 1;
              R23R22._1_1_ = R23R22._1_1_ + -1;
            } while (R23R22._1_1_ != '\0');
            Z._0_1_ = '\x02';
            do {
              Z._0_1_ = (byte)Z + -1;
            } while ((byte)Z != '\0');
            Z = (byte *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0x2b) + -5),(byte)R17R16 - 0x2b);
            X = *(UsbSetupPacket **)Z;
            *(undefined2 *)(uVar8 - 0x11) = 0x1a01;
            FUN_code_1bf4();
            uVar8 = R1R0;
            X = setup;
            setup = R23R22;
            Z._1_1_ = '\r';
            do {
              cVar20 = X._1_1_;
              bVar2 = (byte)X;
              X._1_1_ = (char)X._1_1_ >> 1;
              X._0_1_ = cVar20 << 7 | (byte)X >> 1;
              bVar1 = setup._1_1_;
              setup._1_1_ = bVar2 << 7 | setup._1_1_ >> 1;
              setup._0_1_ = bVar1 << 7 | (byte)setup >> 1;
              Z._1_1_ = Z._1_1_ + -1;
            } while (Z._1_1_ != '\0');
            bVar7 = (byte)R9R8 + (byte)setup;
            bVar1 = R9R8._1_1_ + setup._1_1_ + CARRY1((byte)R9R8,(byte)setup);
            bVar18 = CARRY1(R9R8._1_1_,setup._1_1_) ||
                     CARRY1(R9R8._1_1_ + setup._1_1_,CARRY1((byte)R9R8,(byte)setup));
            bVar2 = (byte)R11R10 + (byte)X + bVar18;
            bVar17 = CARRY1((byte)R11R10,(byte)X);
            X._0_1_ = (byte)R11R10 + (byte)X;
            Z = (byte *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0xa9) + -6),(byte)R17R16 + 0x57);
            setup._0_1_ = *Z;
            setup._1_1_ = Z[1];
            pUVar11 = *(UsbSetupPacket **)Z;
            R1R0 = R1R0 & 0xff00;
            uVar12 = R1R0;
            bVar3 = -CARRY1(setup._1_1_,setup._1_1_);
            R9R8._0_1_ = bVar7 + (byte)setup;
            R9R8._1_1_ = bVar1 + setup._1_1_ + CARRY1(bVar7,(byte)setup);
            bVar19 = CARRY1(bVar1,setup._1_1_) ||
                     CARRY1(bVar1 + setup._1_1_,CARRY1(bVar7,(byte)setup));
            R11R10._0_1_ = bVar2 + bVar3 + bVar19;
            R11R10._1_1_ = ((R11R10._1_1_ + X._1_1_ + (bVar17 || CARRY1((byte)X,bVar18))) -
                           CARRY1(setup._1_1_,setup._1_1_)) +
                           (CARRY1(bVar2,bVar3) || CARRY1(bVar2 + bVar3,bVar19));
            X._0_1_ = '\x04';
            do {
              cVar20 = R11R10._1_1_;
              bVar2 = (byte)R11R10;
              bVar1 = R9R8._1_1_;
              R11R10._1_1_ = (char)R11R10._1_1_ >> 1;
              R11R10._0_1_ = cVar20 << 7 | (byte)R11R10 >> 1;
              R9R8._1_1_ = bVar2 << 7 | R9R8._1_1_ >> 1;
              R9R8._0_1_ = bVar1 << 7 | (byte)R9R8 >> 1;
              X._0_1_ = (byte)X + -1;
            } while ((byte)X != '\0');
            DAT_mem_035e = (byte)R13R12 + (byte)R9R8;
            DAT_mem_035d = R13R12._1_1_ + R9R8._1_1_ + CARRY1((byte)R13R12,(byte)R9R8);
            bVar17 = CARRY1(R13R12._1_1_,R9R8._1_1_) ||
                     CARRY1(R13R12._1_1_ + R9R8._1_1_,CARRY1((byte)R13R12,(byte)R9R8));
            DAT_mem_035c = (byte)R15R14 + (byte)R11R10 + bVar17;
            DAT_mem_035b = R15R14._1_1_ + R11R10._1_1_ +
                           (CARRY1((byte)R15R14,(byte)R11R10) ||
                           CARRY1((byte)R15R14 + (byte)R11R10,bVar17));
            X._0_1_ = *(char *)(Y + 5);
            DAT_mem_035a = (byte)X;
            X._1_1_ = *(byte *)(Y + 6);
            DAT_mem_0359 = X._1_1_;
            Z._0_1_ = *(char *)(Y + 7);
            DAT_mem_0358 = (byte)Z;
            R1R0._1_1_ = SUB21(uVar8,1);
            DAT_mem_0357 = R1R0._1_1_;
            Z._1_1_ = *(char *)(Y + 9);
            DAT_mem_0356 = Z._1_1_;
            R9R8._0_1_ = *(byte *)(Y + 10);
            DAT_mem_0355 = (byte)R9R8;
            DAT_mem_0354 = R1R0._1_1_;
            usb_reply_buffer = R1R0._1_1_;
            R17R16._1_1_ = 0xc;
            R1R0 = uVar12;
            setup = pUVar11;
            uVar9 = host_watchdog_threshold;
            goto LAB_code_1b6f;
          }
        }
      }
    }
    else if (R17R16._1_1_ == 0x14) {
      setup._0_1_ = (byte)setup->wIndex;
      bVar1 = (byte)setup * '\x02';
      setup._1_1_ = CARRY1((byte)setup,(byte)setup);
      Z = (byte *)CONCAT11(setup._1_1_ - ((bVar1 < 0xfb) + -6),bVar1 + 5);
      R19R18._0_1_ = *Z;
      R19R18 = (byte *)CONCAT11(3,(byte)R19R18);
      usb_reply_buffer = (byte)R19R18;
      Z = (byte *)CONCAT11(setup._1_1_ - ((bVar1 < 0xfa) + -6),bVar1 + 6);
      goto LAB_code_1354;
    }
  }
  else if (R17R16._1_1_ == 0x92) {
    dangerous_command_counter = dangerous_command_counter + 1;
    setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,dangerous_command_counter);
    if (4 < dangerous_command_counter) {
      bVar1 = PORTC;
      PORTC = bVar1 | 0x10;
    }
  }
  else if (R17R16._1_1_ == 0x93) {
    bVar1 = dangerous_command_counter + 1;
    setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,bVar1);
    cVar23 = SBORROW1(bVar1,'\x05');
    cVar20 = bVar1 < 5;
    cVar22 = (char)(dangerous_command_counter - 4) < '\0';
    cVar21 = dangerous_command_counter == 4;
    cVar24 = (char)bVar1 < '\x05';
    dangerous_command_counter = bVar1;
    if (!(bool)cVar20) {
      *(undefined2 *)(uVar8 - 0x11) = 0x1b09;
      eeprom_update_byte();
      R1R0._0_1_ = cVar20 == '\x01' | (cVar21 == '\x01') << 1 | (cVar22 == '\x01') << 2 |
                   (cVar23 == '\x01') << 3 | (cVar24 == '\x01') << 4 | (cVar25 == '\x01') << 5 |
                   (cVar26 == '\x01') << 6 | (cVar27 == '\x01') << 7;
      SREG = (byte)R1R0;
      watchdog_reset();
      WDTCSR = 0x18;
      SREG = (byte)R1R0;
      WDTCSR = 0xc;
      *(undefined2 *)(uVar8 - 0x11) = 0x1b15;
      oled_clear();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b18;
      oled_set_scale();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b1c;
      oled_set_text_cursor();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b20;
      oled_print_ram_string();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b24;
      oled_set_text_cursor();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b28;
      oled_print_ram_string();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b2b;
      oled_set_scale();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b2f;
      oled_set_text_cursor();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b33;
      oled_print_ram_string();
      setup = (UsbSetupPacket *)&TCCR3A;
      *(undefined2 *)(uVar8 - 0x11) = 0x1b37;
      eeprom_read_byte((ushort)setup);
      *(undefined2 *)(uVar8 - 0x11) = 0x1b3e;
      integer_to_string();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b42;
      oled_print_ram_string();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b46;
      oled_set_text_cursor();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b4a;
      oled_print_ram_string();
      setup = (UsbSetupPacket *)&UNK_mem_008d;
      *(undefined2 *)(uVar8 - 0x11) = 0x1b4e;
      eeprom_read_byte((ushort)setup);
      *(undefined2 *)(uVar8 - 0x11) = 0x1b55;
      integer_to_string();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b59;
      oled_print_ram_string();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b5d;
      oled_set_text_cursor();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b61;
      oled_print_ram_string();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b69;
      integer_to_string();
      *(undefined2 *)(uVar8 - 0x11) = 0x1b6d;
      oled_print_ram_string();
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  else if (R17R16._1_1_ == 0x91) {
    dangerous_command_counter = dangerous_command_counter + 1;
    setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,dangerous_command_counter);
    if (4 < dangerous_command_counter) {
      bVar1 = PORTC;
      PORTC = bVar1 | 8;
      R17R16._0_1_ = '\x7f';
      R17R16._1_1_ = 0x4f;
      bVar1 = 0x12;
      do {
        cVar20 = (byte)R17R16 + -1;
        bVar2 = R17R16._1_1_ - ((byte)R17R16 == '\0');
        bVar18 = R17R16._1_1_ < ((byte)R17R16 == '\0');
        bVar7 = bVar1 - bVar18;
        bVar17 = SBORROW1(bVar1,bVar18);
        bVar19 = bVar1 < bVar18;
        bVar18 = (char)bVar1 < bVar18;
        R17R16._0_1_ = cVar20;
        R17R16._1_1_ = bVar2;
        bVar1 = bVar7;
      } while ((cVar20 != '\0' || bVar2 != 0) || bVar7 != 0);
      bVar1 = PORTC;
      PORTC = bVar1 & 0xf7;
      R1R0._0_1_ = bVar19 | ((cVar20 == '\0' && bVar2 == 0) && bVar7 == 0) << 1 |
                   ((char)bVar7 < '\0') << 2 | bVar17 << 3 | bVar18 << 4 | cVar25 << 5 | cVar26 << 6
                   | (cVar27 == '\x01') << 7;
      SREG = (byte)R1R0;
      watchdog_reset();
      WDTCSR = 0x18;
      SREG = (byte)R1R0;
      WDTCSR = 0xc;
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  R17R16._1_1_ = 0;
  uVar9 = host_watchdog_threshold;
LAB_code_1b6f:
  uVar8 = Y;
  bVar1 = R17R16._1_1_;
  host_watchdog_threshold._1_1_ = (undefined1)(uVar9 >> 8);
  host_watchdog_threshold._0_1_ = (undefined1)uVar9;
  setup = (UsbSetupPacket *)CONCAT11(setup._1_1_,R17R16._1_1_);
  pUVar11 = setup;
  Y = Y + 0x10;
  R1R0._0_1_ = 0xffef < uVar8 | (uVar8 == 0xfff0) << 1 | ((int)Y < 0) << 2 | SCARRY2(Y,0x10) << 3 |
               ((int)Y < 0 != SCARRY2(Y,0x10)) << 4 | (cVar25 == '\x01') << 5 |
               (cVar26 == '\x01') << 6 | (cVar27 == '\x01') << 7;
  SREG = (byte)R1R0;
  SREG = (byte)R1R0;
  Y._1_1_ = *(undefined1 *)(uVar8 + 0x11);
  Y._0_1_ = *(undefined1 *)(uVar8 + 0x12);
  R17R16._1_1_ = *(undefined1 *)(uVar8 + 0x13);
  R17R16._0_1_ = *(undefined1 *)(uVar8 + 0x14);
  R15R14._1_1_ = *(undefined1 *)(uVar8 + 0x15);
  R15R14._0_1_ = *(undefined1 *)(uVar8 + 0x16);
  R13R12._1_1_ = *(undefined1 *)(uVar8 + 0x17);
  R13R12._0_1_ = *(undefined1 *)(uVar8 + 0x18);
  R11R10._1_1_ = *(undefined1 *)(uVar8 + 0x19);
  R11R10._0_1_ = *(undefined1 *)(uVar8 + 0x1a);
  R9R8._1_1_ = *(undefined1 *)(uVar8 + 0x1b);
  R9R8._0_1_ = *(undefined1 *)(uVar8 + 0x1c);
  R7R6._1_1_ = *(undefined1 *)(uVar8 + 0x1d);
  R7R6._0_1_ = *(undefined1 *)(uVar8 + 0x1e);
  R5R4._1_1_ = *(undefined1 *)(uVar8 + 0x1f);
  R5R4._0_1_ = *(undefined1 *)(uVar8 + 0x20);
  R3R2._1_1_ = *(undefined1 *)(uVar8 + 0x21);
  R3R2._0_1_ = *(undefined1 *)(uVar8 + 0x22);
  setup._0_1_ = bVar1;
  bVar1 = (byte)setup;
  setup = pUVar11;
  return bVar1;
}

