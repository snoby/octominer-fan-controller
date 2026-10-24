/* BYTE0x0fc4; WORDcode:07e2; isr_PCINT1 */

void isr_PCINT1(void)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  char in_Cflg;
  char in_Zflg;
  char in_Nflg;
  char in_Vflg;
  char in_Sflg;
  char in_Hflg;
  char in_Tflg;
  
  uVar3 = R25R24;
  uVar2 = R0;
  R0 = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
       (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | (in_Hflg == '\x01') << 5 |
       (in_Tflg == '\x01') << 6 | 0x80;
  SREG = R0;
  R25R24._0_1_ = PINB;
  R25R24._0_1_ = DAT_mem_0481 ^ (byte)R25R24;
  DAT_mem_0481 = PINB;
  if (((byte)R25R24 & 1) != 0) {
    tach_edge_counts[7]._1_1_ = tach_edge_counts[7]._1_1_ - (((char)tach_edge_counts[7] != -1) + -1)
    ;
    tach_edge_counts[7]._0_1_ = (char)tach_edge_counts[7] + '\x01';
  }
  if (((byte)R25R24 & 2) != 0) {
    tach_edge_counts[6]._1_1_ = tach_edge_counts[6]._1_1_ - (((char)tach_edge_counts[6] != -1) + -1)
    ;
    tach_edge_counts[6]._0_1_ = (char)tach_edge_counts[6] + '\x01';
  }
  if (((byte)R25R24 & 4) != 0) {
    tach_edge_counts[9]._1_1_ = tach_edge_counts[9]._1_1_ - (((char)tach_edge_counts[9] != -1) + -1)
    ;
    tach_edge_counts[9]._0_1_ = (char)tach_edge_counts[9] + '\x01';
  }
  if (((byte)R25R24 & 0x20) != 0) {
    tach_edge_counts[10]._1_1_ =
         tach_edge_counts[10]._1_1_ - (((char)tach_edge_counts[10] != -1) + -1);
    tach_edge_counts[10]._0_1_ = (char)tach_edge_counts[10] + '\x01';
  }
  bVar1 = (byte)R25R24 & 0x40;
  R25R24 = tach_edge_counts[0xb];
  if (bVar1 != 0) {
    R25R24 = tach_edge_counts[0xb] + 1;
  }
  tach_edge_counts[0xb]._1_1_ = (undefined1)(R25R24 >> 8);
  tach_edge_counts[0xb]._0_1_ = (undefined1)R25R24;
  R25R24 = uVar3;
  SREG = R0;
  R0 = uVar2;
  R1 = 0;
  return;
}

