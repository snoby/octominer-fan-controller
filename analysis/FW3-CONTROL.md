# Installed FW3.0 control map

## Scope, evidence and confidence

Static analysis of the installed image only; no rig contact, execution, flashing, or tool installation. Binary: `artifacts/installed-3.0/octominer-fw3.0-hw1.2-flash.bin`, 32768 bytes, independently hashed SHA-256 `186930d0fe8e4caa6fa2873e151225df6c7d1a6f6c4811a82601b113f65c6ddf`. Instruction evidence is `analysis/installed-3.0-disassembly.txt`. Older FIRMWARE-MAP conclusions were not used.

**Every code address below is a flash BYTE address.** EEPROM and SRAM addresses are separately identified. Microchip program-word vector addresses must be doubled. Jump-table entries are word pointers and likewise doubled. Labels here are descriptive, not recovered source symbols. High confidence = direct control/data-flow; medium = peripheral or physical interpretation without board validation. ATmega324PB is strongly supported by vectors and register layout, not physically identified by this report.

Primary references: cached `analysis/microchip-vectors.html`, Table 14-1; Microchip ATmega324PB online Register Summary, GUID-6683EB1A-DA91-4C67-A041-2C6BE048D138; I/O Multiplexing, GUID-70A456F9-B9A1-4501-8FFD-4305652ABF3F (retrieved directly); Phase Correct PWM Mode, GUID-D5530FB7-723B-4D9B-B219-7E085A21E284 and GUID-12CBE53C-29A8-45EC-B04B-F03ABA366465. Online publication identity is GUID-74F8229E-4C43-4FA0-BE7D-1AA303C6F8A4-en-US-6. Their documentation interpretation is distinguished below from image evidence.

## Human-readable function summary

| Entry/range | Meaning | Confidence |
|---|---|---|
| 0x0438–0x0470 | C runtime: stack setup, initialized-data copy, zero BSS, call application | High |
| 0x2056–0x213a | Application initialization: MCU watchdog, tach/ADC, PWM, display, sensor setup, USB, persistent host-watchdog settings | High |
| 0x213c–0x2350 | Endless USB-poll / MCU-watchdog-feed / host-timeout / indicator service loop | High |
| 0x1710–0x177a | Tach input directions/pull-ups and pin-change masks; ADC initialization | High |
| 0x177c–0x183c | Six hardware PWM outputs and Timer3 scheduler initialization | High |
| 0x0f32, 0x0fc4, 0x106e, 0x10b0 | Port A/B/D/E pin-change tach counters | High for code; Port E enabling has discrepancy below |
| 0x1112–0x145a | Timer3 top/capture service: tach result publication/calibration, ADC averaging/lookup, counters and indicator toggles | High |
| 0x145c–0x14dc / 0x14de–0x154c | Timer3 A/B compare scheduling and indicator toggles | High |
| 0x2352–0x3710 | Vendor USB request dispatch | High |
| 0x3880 / 0x3890 | EEPROM byte / little-endian word read | High |
| 0x389c / 0x38c0 / 0x38cc | EEPROM changed-byte update / changed-word update / unconditional word write | High |

## Startup and main loop

Reset vector 0x0000 targets 0x0438. Runtime copies flash 0x3916 onward into SRAM 0x0100–0x034f and clears SRAM 0x0350–0x059e (0x0444–0x0468); application entry is 0x2056 (call at 0x046a). Default unhandled-vector handler 0x0472 restarts via application vector 0x0000; this is a software restart, not itself a hardware reset.

At 0x2056–0x206a WDTCSR (data address 0x0060) is configured to 0x0f. Input/ADC and PWM/scheduler initializers follow at 0x206c/0x2070. 0x2074–0x208c obtains ten signature-row bytes with SPMCSR=0x21; these are not EEPROM calibration defaults. Display initialization 0x1a80 and I2C sensor probing 0x1c10 precede USB interrupt setup 0x08fe. Global interrupts are enabled at 0x209e. Host-watchdog EEPROM initialization/loading is 0x20aa–0x2138.

Loop at 0x213c polls USB through 0x0722, feeds the MCU watchdog at 0x2140, compares SRAM elapsed counter 0x0484:0x0485 against threshold 0x055e:0x055f, applies mode-specific recovery, then services four indicator states. It does not continuously regulate fan speed against temperatures or tach values. ADC calculations supply reported measurements, not an observed autonomous temperature-to-PWM policy. Evidence: loop 0x213c–0x2350, dispatch PWM writes 0x2574–0x25d6.

## Hardware PWM and logical fan groups

Initialization at 0x1788–0x179c sets each timer's control A=0xa1, B=0x01. Interpreted against ATmega324PB: non-inverting, phase-correct 8-bit PWM, TOP=255, no prescaler. Timer0/1/2 provide six independent compare registers; Timer3 is a scheduler, not a seventh fan PWM. Physical pin interpretation uses Microchip register/pin documentation. GPIO direction evidence is 0x177c–0x1786; compare writes are 0x17a0–0x17ec and 0x25a2–0x25d6.

| Zero-based logical IDs | PWM pin | Peripheral/data register | EEPROM startup duty | Set-path address |
|---|---|---|---|---|
| 0, 1 | PB3 | OCR0A, 0x0047 | 0x0000 | 0x25a2 |
| 2, 3 | PB4 | OCR0B, 0x0048 | 0x0001 | 0x25a8 |
| 4, 5 | PD5 | OCR1A, 0x0088:0x0089 | 0x0002 | 0x25ae |
| 6, 7 | PD4 | OCR1B, 0x008a:0x008b | 0x0003 | 0x25bc |
| 8, 9 | PD7 | OCR2A, 0x00b3 | 0x0004 | 0x25ca |
| 10, 11 | PD6 | OCR2B, 0x00b4 | 0x0005 | 0x25d2 |

Logical pairing is directly proven by four 12-entry word-pointer tables at flash 0x00cc, 0x00e4, 0x00fc, 0x0114: each adjacent pair targets the same duty read/persistent update/live write/live read case. Thus twelve tach IDs are not twelve independent duty outputs. Connector labels and external buffering/polarity are unknown; these are MCU pins, not traced chassis connector positions. PWM numbers are raw compare bytes, not a proven host percentage scale.

Startup uses EEPROM duty bytes verbatim; there is no erased-EEPROM validation or factory-duty fallback in 0x17a0–0x17ec. The flash dump alone does not contain EEPROM. Separately captured before/after application snapshots show all six paired startup defaults returning255 on this rig; a complete EEPROM image was not acquired. Request 0x02 persists a duty before following the live-write path (0x2516–0x2574); request 0x04 enters live-write logic at 0x2574. Both suppress live changes while calibration SRAM byte 0x0483 is nonzero. Persistent changes can therefore occur while live duty remains forced high. Request 0x01 reads stored duty; 0x09 reads live compare value.

## Tach inputs, interrupt selection and calibration

Tach ISRs XOR the newly read port against a saved sample, incrementing the associated 16-bit counter on **either** changed edge. There is no rising-only filter or demonstrated pulse-width debounce. They enable global interrupts near ISR entry, permitting nesting. Logical indices follow twelve populated counters within an eighteen-slot backing array at SRAM 0x04e1 + 2*ID, used by result publication and request 0x03 (0x2628–0x2644).

| Logical ID | MCU tach input | SRAM edge counter | ISR/evidence |
|---|---|---|---|
| 0 | PA2 | 0x04e1 | 0x0f84–0x0f98 |
| 1 | PA3 | 0x04e3 | 0x0f9c–0x0fae |
| 2 | PA0 | 0x04e5 | 0x0f54–0x0f68 |
| 3 | PA1 | 0x04e7 | 0x0f6c–0x0f80 |
| 4 | PE6 | 0x04e9 | 0x10ea–0x10fc |
| 5 | PE5 | 0x04eb | 0x10d2–0x10e6 |
| 6 | PB1 | 0x04ed | 0x0ffe–0x1012 |
| 7 | PB0 | 0x04ef | 0x0fe6–0x0ffa |
| 8 | PD0 | 0x04f1 | 0x108c–0x109e |
| 9 | PB2 | 0x04f3 | 0x1016–0x102a |
| 10 | PB5 | 0x04f5 | 0x102e–0x1042 |
| 11 | PB6 | 0x04f7 | 0x1046–0x1058 |

Vector bytes 0x0010/0x0014/0x001c/0x0094 select PCINT0/1/3/4, respectively, from the cached primary vector table. Masks: 0x0f to data 0x006b at 0x174c–0x174e, 0x67 to 0x006c at 0x1752–0x1754, 0x01 to 0x0073 at 0x1758–0x175a. PCICR is ORed with 0x1b at 0x1764–0x176c.

**Port E documentation conflict, not an established firmware fault:** 0x175e–0x1760 writes mask0x60 to data address0x0075. One Microchip online register-summary table places PCMSK4 at0x0074, but the official AVR-libc iom324pb.h definition places it at0x0075, matching this firmware. Moreover, the acquired restored-state snapshot reports logical tachID4=4710RPM. Thus a claim that PE tach is disabled based on that online summary is not supported by the combined evidence. The project uses the AVR-libc register labels; resolve documentation/silicon revisions before diagnosing a register-address bug.

At normal Timer3 top events, 0x117a–0x11a2 multiplies each 16-bit edge count by 5, stores the low 16-bit result at SRAM 0x052f + 2*ID, and clears the counter. This is a firmware-scaled tach value; physical RPM is not independently calibrated here. Request 0x03 returns this value. No supplied evidence proves fan pulses/revolution or physical clock.

Request 0x0d starts calibration at 0x265e: all six duties become 255, SRAM 0x0483 becomes 10. At Timer3 top, values 10 through 6 publish count*5 and clear counters; values 5 through 2 skip that publication/clearing; at value 1, 0x11b8–0x11ea copies the accumulated unscaled counts to the result array and writes eighteen little-endian EEPROM words at starts0x0014,0x0016,...,0x0036 (occupied bytes0x0014–0x0037), clearing each count. Then the countdown becomes zero. Thus final calibration integrates across five top intervals (assuming uninterrupted scheduling), not an independently proven number of seconds. No duty restoration appears in completion: fans remain at compare 255 until another accepted duty write or restart. Request 0x0f writes an indexed EEPROM calibration word at 2*(10+ID), 0x2646–0x2656; request 0x0e reads it at 0x2444–0x2466.

## Scheduler and timing limits

0x1808–0x1838 programs Timer3 control A=0, B=0x1d, ICR3=0x8954, OCR3A=0x2dc7, OCR3B=0x044b, TIMSK3=0x26. The documented decoding is CTC with ICR3 TOP and I/O-clock prescale 1024. Timer3 capture/top ISR at 0x1112 reloads both compare positions (0x1156–0x116a). Compare A at 0x146c–0x147c advances its compare by 0x2dc7; B at 0x14ee–0x14fe advances by 0x044b.

The host elapsed counter increments at top (0x13ca–0x13d8) **and** compare A (0x1480–0x148e), not at compare B. With ideal interrupt delivery, two A matches plus top occur per scheduler cycle. Calibration decrements at top only. These are distinct units. Symbolic scheduler cycle length is (0x8954+1)*1024 / f_IO; PWM carrier is f_IO/510 for the configured synchronous timer modes. No numeric Hz, seconds, reset-pulse duration or RPM is asserted: flash bytes do not establish oscillator frequency, CKDIV8/clock fuses, or a measured effective clock. No direct CLKPR access was found. Busy-loop constants are not clock proof.

## Host communications watchdog versus MCU watchdog

**MCU watchdog:** application WDTCSR=0x0f at 0x2056–0x2066 is reset-enabled without interrupt mode. The main loop feeds it even without USB traffic (0x2140). A running controller with lost communications therefore need not suffer an MCU watchdog reset. Several I2C loops can block; absent watchdog feeds, this independent hardware mechanism can reset the MCU. Intentional reset paths reconfigure WDTCSR=0x0c and stop feeding it (e.g. 0x21be–0x21d2, 0x21de–0x21f2, 0x22a8–0x22bc). No physical-clock-based time estimate is offered for the watchdog's separate oscillator either.

**Host timeout:** request 0x07 at 0x272a clears SRAM elapsed 0x0484:0x0485, resets persistent/RAM mode and retry state, and optionally enables mode 1 or 2. Its low wIndex byte times 20 becomes the mode-1 threshold at EEPROM 0x0069:0x006a and SRAM 0x055e:0x055f (0x276c–0x27a6); high wIndex byte supplies additional recovery count at EEPROM 0x0066. A nonzero wValue overrides this with mode 2, storing the quotient wValue/3 at EEPROM 0x0067:0x0068 and SRAM threshold (0x27aa–0x27ec). Division is integer truncation. Threshold zero disables the corresponding enable step, not a presumed default timeout.

**Request 0x00 is the explicit keepalive:** dispatch at 0x23b6–0x23ba reaches 0x26d4, pulses PC6, clears SRAM elapsed 0x0484:0x0485 at 0x26d6–0x26da, persists retry stage 2, and restores RAM stage 2 (0x26de–0x26ea). Request 0x07 also clears elapsed while reconfiguring watchdog settings. Ordinary duty reads/writes and USB presence are not equivalent keepalives. Request 0x06 returns the nine EEPROM bytes 0x0064–0x006c (0x2704–0x2728).

On expiration (0x2142–0x2158):

- **Mode 0:** no rig-reset/power action; loop continues, with live PWM unchanged. There is no observed generic communications-loss force-to-255 path.
- **Mode 2, EEPROM/RAM retry stage nonzero:** decrement persistent EEPROM 0x0065 then intentionally reset MCU only (0x21d4–0x21f2). The RAM stage is not decremented because reset/reload follows.
- **Mode 2, stage zero:** persist mode 1, restore EEPROM stage=2, increment EEPROM event counter 0x006b:0x006c, delay, pulse PC3 high then low, intentionally reset MCU (0x216c–0x21d2). PC3 is a probable motherboard-reset output; its external wiring is unproven.
- **Mode 1, stage nonzero:** decrement persistent stage and intentionally reset MCU only (0x22be–0x22dc).
- **Mode 1, stage zero, extra recovery count nonzero:** persist stage=2, decrement EEPROM 0x0066, increment event word, pulse PC3, intentionally reset MCU (0x2252–0x22bc).
- **Mode 1, stage zero, extra count zero:** persist mode=0 and stage=2, increment event word, delay and set PC4 high (0x220a–0x224e), then return to looping. PC4 is a probable power-control output, not proven chassis power-off. No clearing pulse or intentional MCU-reset loop is reached in this branch. PWM compare values are not changed here.

Request 0x91 uses a shared request counter at SRAM 0x0486; at count >=5 it pulses PC3 then intentionally resets MCU (0x35a8–0x35e2). Request 0x92 sets PC4 high at the same threshold (0x35e4–0x35f6). Request 0x93 writes EEPROM 0x0093=0x93 and triggers watchdog-based restart after display handling (0x35f8–0x36da), not a direct application jump to boot code. Shared request counter clears at Timer3 top (0x13c6), so five requests need to fall inside that scheduler window; they need not all have the same request ID. Bootloader handoff/selection is not fully mapped here. Boot code samples MCUSR at 0x714a and can clear MCUSR/disable WDT at 0x7554–0x756a; application-vector entry versus fuse-selected boot entry must not be conflated.

## EEPROM map and actual defaults

| EEPROM byte offset(s) | Meaning, default/validation | Evidence |
|---|---|---|
| 0x0000–0x0005 | Six persisted startup duty bytes; no image-proven factory fallback; acquisition snapshots returned255 for all six paired defaults | 0x17a0–0x17ec; 0x2530–0x2570 |
| 0x0014–0x0037 | Eighteen backing calibration words (twelve populated tach inputs), indexed 2*(10+ID); no startup default initialization found | 0x11b8–0x11ea, 0x2646–0x2656 |
| 0x0064 | Host-watchdog mode: 0 disabled, 1 later recovery, 2 initial recovery. Values >=3 cause whole watchdog settings block normalization | 0x20aa–0x20c4 |
| 0x0065 | Persistent MCU-restart stage/retry byte, default 2 on invalid-mode normalization; runtime copy SRAM 0x059a | 0x20c8–0x20ce, 0x2100–0x2108 |
| 0x0066 | Additional mode-1 recovery count, default 0 on normalization; SRAM 0x055d | 0x20d2–0x20d8, 0x210c–0x2114 |
| 0x0067–0x0068 | Mode-2 threshold word; default 0 on normalization | 0x20dc–0x20e4, 0x2120–0x2138 |
| 0x0069–0x006a | Mode-1 threshold word; default 0 on normalization | 0x20e8–0x20f0, 0x212a–0x2138 |
| 0x006b–0x006c | Recovery-event counter word; default 0 on normalization, increments on PC3/PC4 escalation | 0x20f4–0x20fc; 0x2180–0x2192 etc. |
| 0x008d, 0x0090 | Stored bootloader/hardware revision bytes read for display and request 0x0a; no application default established | 0x2402–0x2416, 0x1b80–0x1bc8 |
| 0x0093 | Boot-entry marker written 0x93 by repeated request 0x93 | 0x3608–0x360e |
| 0x00c8–0x0167 | 160-byte display text region; 0 and 255 treated as absent on startup | 0x1ac0–0x1af0; 0x3518–0x353e |
| 0x0168–0x0207 | Second 160-byte display text region; same absent-byte handling | 0x1b04–0x1b3a; 0x34ce–0x34ec |

Normalization only occurs when stored mode >=3. Valid mode 0/1/2 does not independently validate retry counts or threshold words. EEPROM contents cannot be reconstructed from this flash dump; apparent image constants are not installed EEPROM values.

## Remaining uncertainties / review cautions

Clock/fuses, true connector numbering, physical fan pulses/revolution, external signal inversion, PC3/PC4 motherboard wiring, exact reset/power pulse durations, silicon identity, and the PE mask discrepancy need independent evidence. No safe live behavior is asserted from static analysis. ISR nesting also means ideal timing/count integration can be disturbed by service latency; tach sample/counter updates and host elapsed reads are not proven atomic. A missing optional Python HTML parser was bypassed using standard-library parsing. The configured extraction backend rejected URL extraction; direct standard-library HTTPS retrieval supplied the primary pin-multiplexing page, and primary register information was returned by search. Only this designated report was written.
