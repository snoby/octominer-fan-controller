/* BYTE0x741a; WORDcode:3a0d; bootloader_isp_command */

void bootloader_isp_command(void)

{
  int iVar1;
  
  iVar1 = R25R24;
  R1 = 0;
  X = (byte *)(R25R24 + 3);
  R19 = *X;
  X = (byte *)(R25R24 + 4);
  Z._0_1_ = *X;
  R25R24._1_1_ = R19;
  X = (byte *)(iVar1 + 2);
  R18 = *X;
  X = (byte *)iVar1;
  if (R18 == '0') {
    Z._0_1_ = (byte)Z & 3;
    Z = (undefined1 *)CONCAT11(-(((byte)Z < 0xfe) + -2),(byte)Z + 2);
    R25R24._0_1_ = *Z;
    R25R24 = CONCAT11(R19,(undefined1)R25R24);
    R18 = 0x30;
    return;
  }
  if (R18 == 'X') {
    if (R19 == 0) {
      Z = (undefined1 *)0x1;
    }
    else {
      if (R19 != 8) goto LAB_code_3a59;
      Z = (undefined1 *)0x3;
    }
  }
  else {
    if (R18 != 'P') {
      if (R18 == ' ') {
        Z = (undefined1 *)CONCAT11(R19 * '\x02' + CARRY1((byte)Z,(byte)Z),(byte)Z * '\x02');
      }
      else {
        if (R18 != '(') {
          if (R18 == -0x60) {
            FUN_code_3ca5();
            return;
          }
          if (R18 == -0x40) {
            X = (byte *)(iVar1 + 5);
            FUN_code_3cbf();
          }
          else if (R18 == -1) {
            DAT_mem_010f = 0xf1;
          }
          goto LAB_code_3a59;
        }
        Z = (undefined1 *)CONCAT11(R19 * '\x02' + CARRY1((byte)Z,(byte)Z),(byte)Z * '\x02');
        Z = (undefined1 *)((int)Z + 1);
      }
      R25R24._0_1_ = *Z;
      R25R24 = CONCAT11(R19,(undefined1)R25R24);
      return;
    }
    if (R19 == 0) {
      Z = (undefined1 *)0x0;
    }
    else {
      if (R19 != 8) {
LAB_code_3a59:
        R25R24 = (uint)R25R24._1_1_ << 8;
        return;
      }
      Z = (undefined1 *)0x2;
    }
  }
  SPMCSR = 9;
  R25R24._0_1_ = *Z;
  R25R24 = CONCAT11(R19,(undefined1)R25R24);
  return;
}

