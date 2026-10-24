**Verdict: NEEDS_CORRECTIONS.** The core mechanics hold up against the disassembly, raw table bytes and decompiled C. Some wording needs fixing, and the reports leave out important timing, counting and race details.

**Claim-by-claim status**

1. **Six PWM channels, paired logical indices, independent tach values, EEPROM 0..5, no erased-value fallback: confirmed.**
   - Raw table words at 0xcc–0x12a (listing lines 58–105) match `jump-tables.json`. Each adjacent pair resolves to the same target: reads at 0x24e8–0x2510, defaults at 0x2530–0x2566, live writes at 0x25a2–0x25d2, live reads at 0x25f8–0x2622.
   - Startup (lines 2527–2554) reads EEPROM 0..5 into 0x27, 0x28, 0x88, 0x8a, 0xb3 and 0xb4, with no compare or clamp.
   - `main` calls 0x177c at 0x2070 right after watchdog setup, with no EEPROM check beforehand.
   - Timer0/1/2 are set to 0xa1/0x01: both compare outputs enabled, phase-correct 8-bit PWM, no prescaler (lines 2519–2526).
   - Tach counts are separate words: 0x0f32 maps bits 2,3,0,1 to fans 0,1,2,3 (lines 1726–1756). The other direct stores cover 0x4e9–0x4f8 (fans 4–11). No direct store hits slots 12–17 (0x4f9–0x504).
   - Pin names (PB3/PB4/PD4–PD7) depend on the ATmega324PB label set. They are consistent with the DDR bits set at 0x177c–0x1786. Connector wiring is not traced.

2. **Request 2 persists the default and also reaches the live update; request 4 is live-only: confirmed. "May not suppress EEPROM writes" is too weak.**
   - The EEPROM update call at 0x2570 runs before the calibration check at 0x2574–0x257a.
   - So calibration definitely does not block default writes. It only blocks the live write.
   - An out-of-range index branches at 0x2524 straight to 0x2574, skipping the EEPROM write.

3. **Request 13 and the final capture: confirmed, with gaps.**
   - At 0x265e–0x2686 all six compares are set to 255 (16-bit high bytes cleared) and 0x483 is set to 10.
   - The capture loop runs Y from 0x14 to 0x38, i.e. 18 words at EEPROM 20..54 (lines 1977–1995).
   - The normal loop covers 0x4e1–0x505, also 18 words (lines 1942–1962).
   - Nothing restores duty afterwards. The only writers of 0x483 are 0x2682 and 0x11ae.
   - Request 13 does not check 0x483 and is not behind the shared dangerous-command counter, so re-issuing it restarts the countdown.

4. **No autonomous temperature-to-PWM curve: confirmed as well as static analysis allows.**
   - I searched the whole listing for direct compare-register writes (I/O and data-space forms). They appear only at 0x17a8–0x17ec, 0x25a2–0x25d2 and 0x2660–0x267c.
   - There are no direct `lds` reads of the temperature (0x4d9–0x4e0) or RPM (0x52f/0x530) arrays. Only the indexed request handlers read them.
   - The rest of the Timer3 ISR (decompiled lines 119–282) computes voltages and table-lookup temperatures, clears accumulators, counts host ticks and toggles LEDs. It never touches PWM.
   - Not excluded: computed-pointer stores that could alias 0x47/0x48/0x88+. That is implausible but not exhaustively disproven.

**Corrections and missing points**

- **Capture uses the same scale, not a different formula.** The reports should not say capture is "raw instead of ×5". Normal publishing (cnt 0 or ≥6) stores 5×count and clears the counter each event.
  - At cnt 5,4,3,2 the counters are not cleared.
  - At cnt 1 the stored raw value is therefore the sum of the last 5 periods (cleared at the cnt=6 event).
  - That equals 5× the per-period average, the same scale as normal readings.
  - The calibration value is a single 5-period average at duty 255, not a running maximum.
  - Also missing: the published RPM array stops updating for about 4 events before capture.
- **Timing (inference, not established fact).**
  - Code facts: Timer3 uses TCCR3B=0x1d (CTC, TOP=ICR3, ÷1024), ICR3=0x8954 (35156) and TIMSK3=0x26.
  - Event period is 35157×1024/F_CPU. The 0x1112 vector identity also relies on the corrected 324PB vector table.
  - The ×5 factor implies a 3 s window if both edges are counted and fans give 2 pulses/rev. That points to a 12 MHz clock (35157×1024/12 MHz ≈ 3.000 s).
  - On that guess, calibration takes about 27–30 s with a 15 s measuring window. Fuses and crystal are unverified, so keep this labelled as a hypothesis.
- **Race conditions the reports leave out.**
  - The Timer3 ISR runs `sei` at 0x1112, so pin-change ISRs can interrupt it.
  - In capture, the EEPROM word update (0x11d8) sits between reading a counter (0x11ca) and clearing it (0x11de). Edges that arrive during the slow EEPROM write are lost. The normal loop has the same window, only shorter.
  - Separately, 0x0f32 reads PINA twice (0xf46 and 0xf4e). A change between the two reads updates the stored previous state without being counted.
  - All tach ISRs count both edges.
- **Unused slots 12–17.** Each calibration writes them to EEPROM 44..55. Whether anything else uses EEPROM 44–55 was not checked.
- **Indirect "policy" paths for claim 4.**
  - Any MCU reset (watchdog, or the gated 0x91/0x93 reset paths) reloads the EEPROM defaults through 0x177c. A reset therefore changes live duty without a host command.
  - The host-timeout recovery drives PORTC lines, not compare registers.
  - Erased EEPROM (0xFF) gives duty 255, which is likely full speed. That is an inference.
- **Request 2 during calibration.** After calibration the live duty stays at 255 even if a default was rewritten meanwhile. It changes only on request 4 or a reboot.

**Not verified:** clock and fuses, the vector-table mapping itself, exhaustive pointer-alias analysis, other callers of 0x389c that might write EEPROM 0..5, and whether anything else uses EEPROM 44–55.
