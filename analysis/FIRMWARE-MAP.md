# Offline firmware map

## Scope, evidence, and address conventions

Static analysis only of the supplied firmware_07/09 binaries, images.json, the corresponding LLVM AVR disassemblies, and the copied octofan wrapper. Nothing was executed on an AVR or rig; no network connection, flash read, installation, or fuse operation was performed. These are packaged update images, not controller flash dumps.

All code addresses below are **flash byte addresses**, not AVR program-word addresses. SRAM, EEPROM, and peripheral addresses are explicitly distinguished. Function labels are descriptive candidates, not recovered source symbols.

The wrapper selects avrdude part m324pb. The parent-supplied Microchip vector-table reference, independently retrieved during this analysis, corroborates that selection: the image jump table ends at byte 0x00c8; INT0 is byte 0x0004, PCINT0/1 at 0x0010/0x0014, ADC at 0x0060, TIMER3_CAPT/COMPA/COMPB at 0x007c/0x0080/0x0084, and PCINT4 at 0x0094. **Data after 0x00c8 is not an interrupt vector.** The disassembler's atmega324p selection is ISA scaffolding, not independent MCU identification. Peripheral interpretations below use the corroborated 324PB map but do not establish board wiring, clock, or fuse state.

Verification: every printed instruction/data row's encoded bytes was compared against its binary at the printed byte offset: 10,075 rows for 07 and 10,336 for 09; zero mismatches. This verifies correspondence, not complete instruction coverage: LLVM sometimes groups real instructions with adjacent data under an unknown decode, notably immediately before application startup.

| Image | Application occupied interval | Upper occupied interval | S9 entry |
|---|---|---|---|
| 07 | 0x0000–0x28ab | 0x7000–0x797b | 0x7000 |
| 09 | 0x0000–0x2dc5 | 0x7000–0x79a3 | 0x7000 |

The intervening 0xff bytes are synthetic fill in the linearized files, not evidence of a controller readout.

Binary SHA-256:
- 07: d74cf54122a35ae967bba103e349bb05e7f07b89a6d49d8847c39d4ec62cd556
- 09: 678432d35891d41ef2b8aa4e83a8dddb8cc31ca342b8216dab0f95a8439aa2ad

## Recovered application entry points

| Observed role | 07 entry | 09 entry | Evidence |
|---|---|---|---|
| Application runtime startup | 0x0468 | 0x03d8 | Reset vector destination; SRAM data copy and zero initialization; calls application main candidate |
| Main candidate | 0x1a7a | 0x1e3e | Direct startup call; watchdog configuration, peripheral initialization, EEPROM configuration and repeating USB service loop |
| USB service/poll candidate | 0x0752 | 0x06c2 | Main-loop call; validates received setup-size packet, handles standard descriptor/address requests, dispatches nonstandard requests |
| Nonstandard USB request dispatcher candidate | 0x1d60 | 0x215e | Call from nonstandard setup path; reads request byte at setup offset 1, branches by request ID, establishes reply pointer and returns reply length |
| GPIO/input initialization | 0x17a4 | 0x161e | Main calls it before timer/output initializer; pin directions, pullups and interrupt/ADC configuration |
| Timer/output initializer | 0x1822 | 0x168e | Main calls it; four output enables, timer control writes and EEPROM-derived compare values |
| TIMER3 capture-vector handler | 0x11f6 | 0x1040 | Vector at byte 0x007c; compare scheduling, sample accumulation and calibration countdown |
| EEPROM byte-read helper | 0x25d0 | 0x297c | Waits on EEPROM busy flag, sets address, triggers read, returns data |

## USB dispatch trace and concrete requests

For 09, main calls 0x06c2 at 0x1f24. The service routine checks packet state and an eight-byte setup payload; at 0x0700–0x0708, nonzero request-type bits masked by 0x60 select the call to 0x215e. The other path handles recognizable standard request IDs, including descriptor selection and device address. Therefore 0x215e is a strong nonstandard setup-handler candidate, not an arbitrary switch routine. The mask accepts either class or vendor types; the firmware gate alone does not prove vendor-only acceptance. The matching 07 call is at 0x0798 to 0x1d60.

09 dispatcher uses SRAM 0x04f2/0x04f3 as reply pointer, initially pointing to SRAM 0x04b7. 07 uses SRAM 0x0384/0x0385, initially 0x0349. Return length feeds the USB service routine's control-transfer length handling. Recognizable setup offsets: 1=request ID; 2–3=value bytes; 4=index low byte; 6–7=requested length.

Selected requests traced in 09:

| Request ID | Handler block | Observed effect, not assumed source name |
|---|---|---|
| 1 | 0x226e | Reads EEPROM byte 0/1/2 selected by setup index groups 0–2 / 3–5 / 6–8; rejects higher indices; returns one byte |
| 2 | 0x229a | Writes value-low to the same selected EEPROM byte. If SRAM 0x04cc is zero, also updates corresponding timer compare immediately; otherwise skips the live update |
| 4 | 0x22ce | Shares request 2's live-update gate and index mapping, but bypasses its EEPROM write |
| 5 | 0x2376 | For index below four, stores value-low into SRAM 0x04d0 plus index |
| 6 | 0x23c2 | Begins reading sequential EEPROM configuration bytes from offset 0x64 into reply buffer |
| 7 | 0x23e8 | Clears a two-byte SRAM counter and begins resetting EEPROM-backed state; full semantics not assigned here |
| 9 | 0x2308 | Reads current compare value for the grouped output and returns its low byte |
| 13 (0x0d) | 0x234a | Sets all four timer compares to 0x00ff and sets SRAM calibration countdown 0x04cc to decimal 20 |
| 14 | 0x2224 | Reads two EEPROM bytes starting at 2 × (index + 10), returning the pair |
| 15 | 0x2334 | Writes value word to EEPROM starting at 2 × (index + 10) |

Request 4's shared-entry behavior follows the dispatch branch at 0x2198 to 0x22ce; it must not be assigned the EEPROM-write block merely because it appears nearby.

09 requests 2/4 target OCR0A for indices 0–2, OCR0B for 3–5, OCR1B for 6–8; no live OCR1A update is reached through those index groups. The initializer still loads OCR1A from EEPROM byte 3. This is a real distinction between initialization and exposed grouped requests.

07 differs materially: requests 1/2/4 accept indices below decimal 18 and use program-memory word-address tables at flash bytes 0x00cc, 0x00f0 and 0x0114 respectively. The helper at 0x255a converts the table index to a flash byte address, loads a program-word target and jumps indirectly. The three tables select four EEPROM/output groups: indices 0–5, 6–8, 9–15 and 16–17. Live request-2/4 destinations are 0x1f1e, 0x1f22, 0x1f26 and 0x1f32, writing OCR0A, OCR0B, OCR1B and OCR1A respectively. The word-address table entries must be doubled before comparing with disassembly addresses.

## Watchdog and PWM boot behavior

### Application startup, both images

The startup call reaches main 07 0x1a7a / 09 0x1e3e. Before peripheral initialization it performs a watchdog-reset instruction and the watchdog timed-change sequence at data address 0x0060, ending with value 0x0f. Under the corroborated register map this enables watchdog reset with prescaler bits 0b111. This is a hardware watchdog reset mechanism, not proof of a host communications timeout.

09's initialization call chain is 0x1824, 0x089e, 0x161e, then 0x168e; the equivalent 07 calls are 0x19b4, 0x092e, 0x17a4, then 0x1822. Interrupts are enabled after the timer/output initializer returns. The first routines service the watchdog internally; the persistent main USB loop also services it. Their exact high-level display/device names are intentionally not asserted.

Timer initializer enables PB3, PB4, PD4 and PD5 as outputs, writes 0xa1 to Timer0/Timer1 control-A and 0x01 to their control-B, then loads EEPROM bytes 0, 1, 2 and 3 into OCR0A, OCR0B, OCR1B and OCR1A respectively, zero-extending the Timer1 values. With this register map the configuration is non-inverting phase-correct eight-bit PWM with no timer prescaling. No unconditional startup overwrite to 100% was found in this chain: startup duty comes from persisted EEPROM bytes, without a visible validity clamp in the initializer. Actual fan speed, electrical inversion, PWM frequency and erased-EEPROM state remain unmeasured.

### Calibration versus watchdog

Request 13 (0x0d) explicitly forces all four compare registers to 255 and initializes a countdown to 20 (09 block 0x234a; 07 block 0x1f92). The TIMER3 capture handler decrements that countdown. In 09, at 0x109c–0x111a it takes different sample-processing paths depending on the countdown, and on the final count writes accumulated measurements to EEPROM words beginning at offset 20. Requests 2/4 suppress live duty changes while the countdown is nonzero; EEPROM persistence for request 2 happens before that gate. No claim of a twenty-second duration follows from a count of twenty interrupts.

09 additionally contains a main-loop-reachable routine at 0x19b4: it disables the watchdog through the timed-change sequence at 0x19cc–0x19e0, sets OCR0A/OCR0B/OCR1B to 255, performs other operations, then sets those same three compares to 127 at 0x1b08–0x1b16. Main reaches it after repeatedly observing the tested input condition, with a software threshold of decimal 301 iterations. This is not the unconditional main startup path and not a proven communications-loss fail-safe. No physical button or fan label is assigned to that input here.

Main's EEPROM-backed state paths contain several explicit watchdog reconfigurations to 0x0c followed by a permanent self-loop, e.g. 09 0x1fca–0x1fde and corresponding 07 0x1bde–0x1bf2. These are strong intentional watchdog-reset candidates; do not confuse them with the regularly serviced main loop. No reset-delay measurement is claimed.

## Upper segment and limitations

Both upper images contain UTF-16 USB descriptors for USBasp and www.fischl.de beginning at 0x7110/0x711e, and their entry at 0x7000 branches to runtime startup 0x713e. In 09, the boot-region path at 0x7526–0x754c disables interrupts, releases selected pins, disables interrupt controls, changes vector selection, and invokes address zero. The alternate path at 0x7554–0x756a clears reset flags and disables the watchdog before enabling USB-related interrupts. This supports an embedded USBasp-related boot component, but branding alone does not establish original source provenance, supported programming operations, fuses, boot-lock state, or the reset path taken on the actual hardware.

Remaining uncertainty: EEPROM contents, clock/fuse settings, physical output wiring, USB transaction captures and runtime timing were not available. Unmapped dispatcher branches have deliberately not been named. No source-level function identities or complete protocol implementation are claimed.
