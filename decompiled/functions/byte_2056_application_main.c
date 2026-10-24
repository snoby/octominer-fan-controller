/* BYTE0x2056; WORDcode:102b; application_main */

void application_main(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  byte *pbVar6;
  char in_Cflg;
  char cVar7;
  char in_Zflg;
  char cVar8;
  char in_Nflg;
  char cVar9;
  char in_Vflg;
  char cVar10;
  char in_Sflg;
  bool bVar11;
  char cVar12;
  char in_Hflg;
  char cVar13;
  char in_Tflg;
  char cVar14;
  char in_Iflg;
  char cVar15;
  
  R1 = 0;
  cVar13 = in_Hflg == '\x01';
  cVar14 = in_Tflg == '\x01';
  R0 = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
       (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | cVar13 << 5 | cVar14 << 6 |
       (in_Iflg == '\x01') << 7;
  SREG = R0;
  watchdog_reset();
  WDTCSR = 0x18;
  SREG = R0;
  WDTCSR = 0xf;
  watchdog_reset();
  gpio_input_init();
  pwm_timer_init_from_eeprom();
  X = signature_serial_bytes;
  Z = &DAT_codebyte_000e;
  R25R24 = 0x2100;
  do {
    pbVar6 = X;
    SPMCSR = R25R24._1_1_;
    R25R24._0_1_ = *Z;
    X = X + 1;
    *pbVar6 = (byte)R25R24;
    Z = Z + 1;
  } while ((byte)Z != 0x18 || Z._1_1_ != (byte)(R1 + ((byte)Z < 0x18)));
  startup_display_and_eeprom_text();
  bme280_discovery_and_calibration();
  FUN_code_047f();
  bVar1 = DDRD;
  DDRD = bVar1 | 2;
  bVar1 = PORTD;
  PORTD = bVar1 | 2;
  cVar15 = '\x01';
  watchdog_reset();
  host_watchdog_threshold._1_1_ = R1;
  host_watchdog_threshold._0_1_ = R1;
  R25R24 = 100;
  R25R24._0_1_ = eeprom_read_byte(100);
  host_watchdog_mode = (byte)R25R24;
  if (2 < (byte)R25R24) {
    eeprom_update_byte();
    host_watchdog_mode = R1;
    eeprom_update_byte();
    eeprom_update_byte();
    eeprom_update_word();
    eeprom_update_word();
    eeprom_update_word();
  }
  R25R24 = 0x65;
  R25R24._0_1_ = eeprom_read_byte(0x65);
  host_watchdog_retry_stage = (byte)R25R24;
  R25R24 = 0x66;
  R25R24._0_1_ = eeprom_read_byte(0x66);
  extra_recovery_attempts = (byte)R25R24;
  if (host_watchdog_mode == 2) {
    R25R24 = 0x67;
  }
  else {
    if (host_watchdog_mode != 1) goto LAB_code_109e;
    R25R24 = 0x69;
  }
  R25R24 = eeprom_read_word(R25R24);
  host_watchdog_threshold._1_1_ = R25R24._1_1_;
  host_watchdog_threshold._0_1_ = (byte)R25R24;
LAB_code_109e:
  do {
    usb_poll();
    watchdog_reset();
    if (host_watchdog_threshold._1_1_ <= host_elapsed_ticks._1_1_ &&
        ((byte)host_elapsed_ticks < (byte)host_watchdog_threshold) <=
        (byte)(host_elapsed_ticks._1_1_ - host_watchdog_threshold._1_1_)) {
      if (host_watchdog_mode == 2) {
        if (host_watchdog_retry_stage != R1) {
          cVar10 = SBORROW1(host_watchdog_retry_stage,'\x01');
          cVar7 = host_watchdog_retry_stage == 0;
          cVar9 = (char)(host_watchdog_retry_stage - 1) < '\0';
          cVar8 = host_watchdog_retry_stage == 1;
          cVar12 = (char)host_watchdog_retry_stage < '\x01';
          eeprom_update_byte();
          R0 = cVar7 == '\x01' | (cVar8 == '\x01') << 1 | (cVar9 == '\x01') << 2 |
               (cVar10 == '\x01') << 3 | (cVar12 == '\x01') << 4 | (cVar13 == '\x01') << 5 |
               (cVar14 == '\x01') << 6 | (cVar15 == '\x01') << 7;
          SREG = R0;
          watchdog_reset();
          WDTCSR = 0x18;
          SREG = R0;
          WDTCSR = 0xc;
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        eeprom_update_byte();
        eeprom_update_byte();
        eeprom_read_word(0x6b);
        eeprom_write_word();
        R18 = '\x7f';
        R25R24._0_1_ = 0xa9;
        R25R24._1_1_ = '\x03';
        do {
          cVar7 = R18 + -1;
          bVar1 = (byte)R25R24 - (R18 == '\0');
          R25R24._1_1_ = R25R24._1_1_ - ((byte)R25R24 < (R18 == '\0'));
          R18 = cVar7;
          R25R24._0_1_ = bVar1;
        } while ((cVar7 != '\0' || bVar1 != 0) || R25R24._1_1_ != '\0');
        bVar1 = PORTC;
        PORTC = bVar1 | 8;
        R18 = '\x7f';
        R25R24._0_1_ = 0x4f;
        R25R24._1_1_ = 0x12;
        do {
          cVar7 = R18 + -1;
          bVar1 = (byte)R25R24 - (R18 == '\0');
          bVar11 = (byte)R25R24 < (R18 == '\0');
          bVar2 = R25R24._1_1_ - bVar11;
          bVar3 = SBORROW1(R25R24._1_1_,bVar11);
          bVar4 = R25R24._1_1_ < bVar11;
          bVar11 = (char)R25R24._1_1_ < bVar11;
          R18 = cVar7;
          R25R24._0_1_ = bVar1;
          R25R24._1_1_ = bVar2;
        } while ((cVar7 != '\0' || bVar1 != 0) || bVar2 != 0);
        bVar5 = PORTC;
        PORTC = bVar5 & 0xf7;
        R0 = bVar4 | ((cVar7 == '\0' && bVar1 == 0) && bVar2 == 0) << 1 | ((char)bVar2 < '\0') << 2
             | bVar3 << 3 | bVar11 << 4 | (cVar13 == '\x01') << 5 | (cVar14 == '\x01') << 6 |
             (cVar15 == '\x01') << 7;
        SREG = R0;
        watchdog_reset();
        WDTCSR = 0x18;
        SREG = R0;
        WDTCSR = 0xc;
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      if (host_watchdog_mode == 1) {
        if (host_watchdog_retry_stage != R1) {
          cVar10 = SBORROW1(host_watchdog_retry_stage,'\x01');
          cVar7 = host_watchdog_retry_stage == 0;
          cVar9 = (char)(host_watchdog_retry_stage - 1) < '\0';
          cVar8 = host_watchdog_retry_stage == 1;
          cVar12 = (char)host_watchdog_retry_stage < '\x01';
          eeprom_update_byte();
          R0 = cVar7 == '\x01' | (cVar8 == '\x01') << 1 | (cVar9 == '\x01') << 2 |
               (cVar10 == '\x01') << 3 | (cVar12 == '\x01') << 4 | (cVar13 == '\x01') << 5 |
               (cVar14 == '\x01') << 6 | (cVar15 == '\x01') << 7;
          SREG = R0;
          watchdog_reset();
          WDTCSR = 0x18;
          SREG = R0;
          WDTCSR = 0xc;
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        if (extra_recovery_attempts != R1) {
          eeprom_update_byte();
          eeprom_update_byte();
          eeprom_read_word(0x6b);
          eeprom_write_word();
          R18 = '\x7f';
          R25R24._0_1_ = 0xa9;
          R25R24._1_1_ = '\x03';
          do {
            cVar7 = R18 + -1;
            bVar1 = (byte)R25R24 - (R18 == '\0');
            R25R24._1_1_ = R25R24._1_1_ - ((byte)R25R24 < (R18 == '\0'));
            R18 = cVar7;
            R25R24._0_1_ = bVar1;
          } while ((cVar7 != '\0' || bVar1 != 0) || R25R24._1_1_ != '\0');
          bVar1 = PORTC;
          PORTC = bVar1 | 8;
          R18 = '\x7f';
          R25R24._0_1_ = 0x4f;
          R25R24._1_1_ = 0x12;
          do {
            cVar7 = R18 + -1;
            bVar1 = (byte)R25R24 - (R18 == '\0');
            bVar11 = (byte)R25R24 < (R18 == '\0');
            bVar2 = R25R24._1_1_ - bVar11;
            bVar3 = SBORROW1(R25R24._1_1_,bVar11);
            bVar4 = R25R24._1_1_ < bVar11;
            bVar11 = (char)R25R24._1_1_ < bVar11;
            R18 = cVar7;
            R25R24._0_1_ = bVar1;
            R25R24._1_1_ = bVar2;
          } while ((cVar7 != '\0' || bVar1 != 0) || bVar2 != 0);
          bVar5 = PORTC;
          PORTC = bVar5 & 0xf7;
          R0 = bVar4 | ((cVar7 == '\0' && bVar1 == 0) && bVar2 == 0) << 1 |
               ((char)bVar2 < '\0') << 2 | bVar3 << 3 | bVar11 << 4 | (cVar13 == '\x01') << 5 |
               (cVar14 == '\x01') << 6 | (cVar15 == '\x01') << 7;
          SREG = R0;
          watchdog_reset();
          WDTCSR = 0x18;
          SREG = R0;
          WDTCSR = 0xc;
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        eeprom_update_byte();
        host_watchdog_mode = R1;
        eeprom_update_byte();
        host_watchdog_retry_stage = 2;
        eeprom_read_word(0x6b);
        eeprom_write_word();
        R18 = '\x7f';
        R25R24._0_1_ = 0xa9;
        R25R24._1_1_ = '\x03';
        do {
          cVar7 = R18 + -1;
          bVar1 = (byte)R25R24 - (R18 == '\0');
          R25R24._1_1_ = R25R24._1_1_ - ((byte)R25R24 < (R18 == '\0'));
          R18 = cVar7;
          R25R24._0_1_ = bVar1;
        } while ((cVar7 != '\0' || bVar1 != 0) || R25R24._1_1_ != '\0');
        bVar1 = PORTC;
        PORTC = bVar1 | 0x10;
      }
    }
    if (host_watchdog_mode != 0) {
      if (host_watchdog_retry_stage == 1) {
        led_modes[1] = 3;
      }
      else if (host_watchdog_retry_stage == R1) {
        led_modes[1] = 2;
      }
      else {
        led_modes[1] = R1;
      }
    }
    if (led_modes[0] == R1) {
      bVar1 = PORTC;
      PORTC = bVar1 & 0xdf;
    }
    if (led_modes[0] == 1) {
      bVar1 = PORTC;
      PORTC = bVar1 | 0x20;
    }
    if (led_modes[1] == R1) {
      bVar1 = PORTC;
      PORTC = bVar1 & 0xbf;
    }
    else if (led_modes[1] == 1) {
      bVar1 = PORTC;
      PORTC = bVar1 | 0x40;
    }
    if (led_modes[2] == R1) {
      bVar1 = PORTC;
      PORTC = bVar1 & 0x7f;
    }
    else if (led_modes[2] == 1) {
      bVar1 = PORTC;
      PORTC = bVar1 | 0x80;
    }
    if (led_modes[3] == R1) {
      bVar1 = PORTE;
      PORTE = bVar1 & 0xf7;
    }
    else if (led_modes[3] == 1) {
      bVar1 = PORTE;
      PORTE = bVar1 | 8;
    }
  } while( true );
}

