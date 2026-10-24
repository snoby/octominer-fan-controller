**Verdict: NEEDS_CORRECTIONS.** The main findings hold up against the disassembly, but some wording overstates things and several safety-relevant facts are missing.

### Claim-by-claim status

1. **Confirmed, with nuance.** The code observations hold:
   - **MCU watchdog setup:** WDTCSR (data address 0x60) is written 0x18 then 0x0f at 0x2056–0x206a (disassembly lines 3455–3463). That is reset mode with no interrupt enabled.
   - **Main-loop feed:** the `wdr` at 0x2140 (line 3544) runs on every loop pass after `call 0x722` at 0x213c. It does not depend on host traffic.
   - **Comms counter:** SRAM 0x0484:0x0485 is increased only in two timer ISRs (0x13ca–0x13d8 and 0x1480–0x148e). It is cleared only at 0x26d6/0x26da (request 0) and 0x272a/0x272e (request 7).
   - **Dispatch:** request 0 reaches 0x26d4 through 0x23ba (+792); request 7 reaches 0x272a through 0x23e8 (+832).
   - Fan and status getters never touch 0x0484.
   - **Overstated:** "independently of USB" is too strong. The feed shares one loop with the USB poll, so a callback that never returns would stop it. Proving that blocked-bus recovery actually works needs a timeout analysis that hasn't been done.
   - **Wording:** say "request 0, or request 7 as a side effect," not "only request 0."
2. **Confirmed.**
   - **Start-up checks:** the EEPROM 100 read and the ≥3 normalisation are at 0x20aa–0x20fc. The layout is 100 mode, 101 stage, 102 extra retries, 103/105/107 LE16 words. Threshold selection is at 0x2118–0x2136; mode 0 keeps the threshold zeroed at 0x20a2.
   - **Mode 0:** both branch outcomes reach 0x22de (via 0x2162 and 0x21f8). No PWM register is written anywhere in 0x213c–0x2350.
   - **Mode 2:** if the stage is non-zero, it decrements EEPROM 101 and resets via the watchdog (0x21d4–0x21f2). If the stage is zero, it pulses PC3 and sets mode 1 (0x216c–0x21d2).
   - **Mode 1:** 0x22be gives a reset only. 0x2252 gives a PC3 pulse plus reset. 0x220a–0x224e sets PC4 high and mode 0 with no reset.
   - Board wiring and exact seconds are correctly left unproven.
3. **Confirmed.**
   - **Dispatch:** 0x91→0x35a8 (0x24c6), 0x92→0x35e4 (0x24b2), 0x93→0x35f8 (0x24ba).
   - **Shared counter:** each handler loads, increments and stores 0x0486, then branches on unsigned ≥5 (lines 5753–5791). The ISR at 0x13c6 clears it.
   - **Boot entry:** it calls 0x389c with address 0x93 and value 0x93 (0x3608–0x360e). Then it sets WDTCSR to 0x0c and draws on the OLED. The display helpers contain no `wdr`, so the reset is only implied.
   - **Timer TOP:** TCCR3B=0x1d (0x180e) selects CTC with ICR3 as TOP and clk/1024; ICR3=0x8954; TIMSK3=0x26. The 0x1112 ISR is vector byte 0x7c, which is TIMER3_CAPT on the ATmega324PB, so "timer top" holds.
4. **Partially confirmed; one gap.**
   - **Request 15:** handler 0x2646–0x265a computes (IL+10)·2 and calls the LE16 update at 0x38c0 with no bounds check. Confirmed.
   - **Request 14:** the read at 0x2444 is equally unbounded.
   - **Hex vs decimal:** 0x12 goes to 0x2958 (0x242a). Decimal 12 (0x0c) falls through to the default at 0x2440. Confirmed.
   - **Unresolved:** I did not check the guards in the current/default PWM handlers (0x24ca/0x2516/0x2574). They remain the report's claim.

### Corrections and missing counter-evidence

- **Most serious gap: request 15 bypasses the dangerous-command gate.** IL is 8 bits, so it can write even addresses from EEPROM 20 to 530 (pairs up to 531):
  - IL=40 writes EEPROM 100/101 (mode and stage) directly.
  - IL=63 writes EEPROM 146/147. Setting the high byte of wValue to 0x93 places the boot marker without the five-count gate.
  - It can also overwrite 102–109 and the OLED planes.

  The reports should say plainly that the 0x0486 gate is not a barrier against persistent boot-marker or watchdog-arming writes. Whether the bootloader actually reads EEPROM 147 is still unverified; I did not trace code at 0x74d0 and above.
- **Request 7 can arm an instant escalation loop.** With IL≠0 and wValue 1–2, the threshold becomes 1/3 or 2/3, which floors to 0 (0x27ba–0x27dc). The ≥ comparison at 0x2152–0x2156 is then true on the first loop pass. The rig would reset straight into stage exhaustion and a PC3 pulse. Stored modes 1/2 with a zero threshold word behave the same way, since normalisation only applies when mode ≥3.
- **The extra-retry budget only goes down.** EEPROM 102 is decremented (0x225c–0x2266), and request 0 restores only EEPROM 101. Only request 7 refills 102. Keepalives therefore don't restore the full budget.
- **The counter has two sources.** 0x0484 is increased in both TIMER3_CAPT and TIMER3_COMPA. COMPA starts at OCR3A=0x2dc7 and advances by 0x2dc7 (0x1474–0x147c); the third step, 35157, exceeds TOP 35156. That gives about 3 increments per ICR3 period. If the clock were 12 MHz (not proven), one increment would be about 1.00 s and the 0x0486 window about 3 s. Present this as a hypothesis only.
- **The gate counter is never cleared on trigger.** After a 0x92 trigger it stays ≥5 until the next TOP, so any following 0x91/0x93 in that window fires on the first try. The counter wraps after 256 increments.
- **`wdr` also appears in start-up display code** (0x1a98–0x1bf4, called only from 0x208e). The bootloader region (around 0x7566) writes WDTCSR=0. Neither affects the main-loop conclusion.
- **Timing figures are datasheet inferences.** "2 s / 0.25 s" for WDTCSR values 0x0f and 0x0c comes from the datasheet, not from the code, and should be labelled that way.

### Unverified

- The PWM handler index guards.
- Whether the bootloader consumes the EEPROM 147 marker.
- Whether every path through 0x11ee–0x13c6 reaches the 0x0486 clear.
- That 0x722 is the USB poll; I relied on the report's statement that 0x0768 sits inside it.
- I2C timeout behaviour.

The `application_main` pseudocode (`decompiled/functions/byte_2056_application_main.c`, lines 38–281) matches the WDTCSR and PORTC sequences above.
