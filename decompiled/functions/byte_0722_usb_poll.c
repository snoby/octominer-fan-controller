/* BYTE0x0722; WORDcode:0391; usb_poll */

void usb_poll(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined2 uVar5;
  undefined1 *puVar6;
  
  uVar5 = Y;
  R1 = 0;
  if ((DAT_mem_04ab - 3U & 0x80) != 0) goto LAB_code_0422;
  if ((DAT_mem_04a7 == '-') && ((byte)(DAT_mem_04ab - 3U) == 8)) {
    Y = (UsbSetupPacket *)
        CONCAT11(-(((byte)(-DAT_mem_04a8 + 0xc) < 0x51) + -5) - (0xc < DAT_mem_04a8),
                 -DAT_mem_04a8 + -0x45);
    DAT_mem_049b = 0xc3;
    DAT_mem_0101 = 0x5a;
    DAT_mem_0350 = 0;
    R25R24._0_1_ = Y->bmRequestType;
    R25R24._0_1_ = (byte)R25R24 & 0x60;
    if ((byte)R25R24 == 0) {
      R25R24._0_1_ = (byte)Y->wValue;
      DAT_mem_04a4 = 0;
      R25R24._1_1_ = Y->bRequest;
      if (R25R24._1_1_ == 0) {
        DAT_mem_04a5 = 0;
        R18 = 0xa4;
        R25R24._0_1_ = 2;
      }
      else if (R25R24._1_1_ == 5) {
        DAT_mem_04ac = (byte)R25R24;
LAB_code_0405:
        R18 = 0xa4;
        R25R24._0_1_ = 0;
      }
      else {
        if (R25R24._1_1_ == 6) {
          R25R24._1_1_ = *(char *)((int)&Y->wValue + 1);
          if (R25R24._1_1_ == '\x01') {
            R25R24 = (UsbSetupPacket *)0x13e;
LAB_code_03d4:
            usb_reply_pointer._1_1_ = R25R24._1_1_;
            usb_reply_pointer._0_1_ = (byte)R25R24;
            R25R24._0_1_ = 0x12;
          }
          else {
            if (R25R24._1_1_ == '\x02') {
              R25R24 = (UsbSetupPacket *)0x12c;
              goto LAB_code_03d4;
            }
            if (R25R24._1_1_ == '\x03') {
              if ((byte)R25R24 == '\0') {
                usb_reply_pointer._1_1_ = '\x01';
                usb_reply_pointer._0_1_ = 0x94;
                R25R24._0_1_ = 4;
              }
              else if ((byte)R25R24 == '\x01') {
                usb_reply_pointer._1_1_ = '\x01';
                usb_reply_pointer._0_1_ = 0x6e;
                R25R24._0_1_ = 0x26;
              }
              else {
                if ((byte)R25R24 != '\x02') goto LAB_code_03fa;
                usb_reply_pointer._1_1_ = '\x01';
                usb_reply_pointer._0_1_ = 0x50;
                R25R24._0_1_ = 0x1e;
              }
            }
            else {
LAB_code_03fa:
              R25R24._0_1_ = 0;
            }
          }
          DAT_mem_0350 = 0x40;
          goto LAB_code_0417;
        }
        if (R25R24._1_1_ == 8) {
          R18 = 0xae;
          R25R24._0_1_ = 1;
        }
        else {
          if (R25R24._1_1_ == 9) {
            DAT_mem_04ae = (byte)R25R24;
            goto LAB_code_0405;
          }
          R25R24._0_1_ = R25R24._1_1_ == 10;
          R18 = 0xa4;
        }
      }
      R19 = 4;
      usb_reply_pointer._1_1_ = '\x04';
      usb_reply_pointer._0_1_ = R18;
    }
    else {
      R25R24 = Y;
      R25R24._0_1_ = usb_setup_dispatch(Y);
    }
LAB_code_0417:
    R25R24._1_1_ = *(char *)((int)&Y->wLength + 1);
    if ((R25R24._1_1_ == '\0') && (R25R24._1_1_ = (byte)Y->wLength, R25R24._1_1_ < (byte)R25R24)) {
      R25R24._0_1_ = R25R24._1_1_;
    }
    DAT_mem_0100 = (byte)R25R24;
  }
  DAT_mem_04ab = '\0';
LAB_code_0422:
  if (((DAT_mem_0101 & 0x10) != 0) && (DAT_mem_0100 != 0xff)) {
    R18 = DAT_mem_0100;
    if (8 < DAT_mem_0100) {
      R18 = 8;
    }
    DAT_mem_0100 = DAT_mem_0100 - R18;
    R25R24._0_1_ = DAT_mem_049b ^ 0x88;
    DAT_mem_049b = (byte)R25R24;
    Y = (UsbSetupPacket *)(uint)R18;
    bVar2 = R18;
    if (R18 != 0) {
      R25R24 = (UsbSetupPacket *)CONCAT11(usb_reply_pointer._1_1_,(byte)usb_reply_pointer);
      if ((DAT_mem_0350 & 0x40) == 0) {
        Z = &DAT_mem_049c;
        X = (undefined1 *)R25R24;
        do {
          puVar6 = Z;
          puVar4 = X;
          X = X + 1;
          R19 = *puVar4;
          Z = Z + 1;
          *puVar6 = R19;
          R18 = R18 - 1;
        } while (R18 != 0);
      }
      else {
        X = &DAT_mem_049b;
        R21R20._0_1_ = (byte)usb_reply_pointer + 0x65;
        R21R20._1_1_ = usb_reply_pointer._1_1_ - (((byte)usb_reply_pointer < 0x9b) + '\x04');
        do {
          cVar1 = R21R20._1_1_ + X._1_1_ + CARRY1((byte)R21R20,(byte)X);
          Z = (undefined1 *)CONCAT11(cVar1,(byte)R21R20 + (byte)X);
          Z._0_1_ = *Z;
          Z = (undefined1 *)CONCAT11(cVar1,Z._0_1_);
          X = X + 1;
          *X = Z._0_1_;
          R18 = R18 - 1;
        } while (R18 != R1);
      }
      R25R24 = (UsbSetupPacket *)((int)R25R24 + 1);
      usb_reply_pointer._0_1_ = (byte)R25R24 + ((byte)Y - 1);
      usb_reply_pointer._1_1_ = R25R24._1_1_ + R1 + CARRY1((byte)R25R24,(byte)Y - 1);
      bVar2 = (byte)Y;
    }
    Y._0_1_ = bVar2;
    FUN_code_0260();
    DAT_mem_0101 = (byte)Y + 4;
    if (DAT_mem_0101 != 0xc) {
      DAT_mem_0100 = 0xff;
    }
  }
  R25R24 = (UsbSetupPacket *)0x14;
  do {
    bVar2 = PIND;
    R25R24._1_1_ = bVar2 & 0xc;
    bVar3 = R25R24._1_1_;
    R25R24 = (UsbSetupPacket *)(CONCAT11(bVar2,(byte)R25R24) & 0xcff);
    if (bVar3 != 0) {
      Y = (UsbSetupPacket *)uVar5;
      return;
    }
    cVar1 = (byte)R25R24 + -1;
    R25R24 = (UsbSetupPacket *)(CONCAT11(bVar2,cVar1) & 0xcff);
  } while (cVar1 != '\0');
  DAT_mem_04ac = R1;
  DAT_mem_04a6 = R1;
  Y = (UsbSetupPacket *)uVar5;
  return;
}

