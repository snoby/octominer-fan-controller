/* BYTE0x0f32; WORDcode:0799; isr_PCINT0 */

void isr_PCINT0(void)

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
  R25R24._0_1_ = PINA;
  R25R24._0_1_ = DAT_mem_0482 ^ (byte)R25R24;
  DAT_mem_0482 = PINA;
  if (((byte)R25R24 & 1) != 0) {
    tach_edge_counts[2]._1_1_ = tach_edge_counts[2]._1_1_ - (((char)tach_edge_counts[2] != -1) + -1)
    ;
    tach_edge_counts[2]._0_1_ = (char)tach_edge_counts[2] + '\x01';
  }
  if (((byte)R25R24 & 2) != 0) {
    tach_edge_counts[3]._1_1_ = tach_edge_counts[3]._1_1_ - (((char)tach_edge_counts[3] != -1) + -1)
    ;
    tach_edge_counts[3]._0_1_ = (char)tach_edge_counts[3] + '\x01';
  }
  if (((byte)R25R24 & 4) != 0) {
    tach_edge_counts[0]._1_1_ = tach_edge_counts[0]._1_1_ - (((char)tach_edge_counts[0] != -1) + -1)
    ;
    tach_edge_counts[0]._0_1_ = (char)tach_edge_counts[0] + '\x01';
  }
  bVar1 = (byte)R25R24 & 8;
  R25R24 = tach_edge_counts[1];
  if (bVar1 != 0) {
    R25R24 = tach_edge_counts[1] + 1;
  }
  tach_edge_counts[1]._1_1_ = (undefined1)(R25R24 >> 8);
  tach_edge_counts[1]._0_1_ = (undefined1)R25R24;
  R25R24 = uVar3;
  SREG = R0;
  R0 = uVar2;
  R1 = 0;
  return;
}

