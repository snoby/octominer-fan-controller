/* BYTE0x106e; WORDcode:0837; isr_PCINT3 */

void isr_PCINT3(void)

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
  R25R24._0_1_ = PIND;
  R25R24._0_1_ = DAT_mem_0480 ^ (byte)R25R24;
  DAT_mem_0480 = PIND;
  bVar1 = (byte)R25R24 & 1;
  R25R24 = tach_edge_counts[8];
  if (bVar1 != 0) {
    R25R24 = tach_edge_counts[8] + 1;
  }
  tach_edge_counts[8]._1_1_ = (undefined1)(R25R24 >> 8);
  tach_edge_counts[8]._0_1_ = (undefined1)R25R24;
  R25R24 = uVar3;
  SREG = R0;
  R0 = uVar2;
  R1 = 0;
  return;
}

