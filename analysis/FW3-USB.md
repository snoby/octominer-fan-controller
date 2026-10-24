# Installed FW3.0: USB application dispatcher and request catalog

## Scope and evidence

Local static analysis only; no remote access, USB requests, firmware execution, installation, or changes to other reports. This is an assembly-derived behavioral reconstruction, not recovered C source or a hardware test.

Inputs:
- `/Users/snoby/octominer-re/artifacts/installed-3.0/octominer-fw3.0-hw1.2-flash.bin`
- `/Users/snoby/octominer-re/analysis/installed-3.0-disassembly.txt`
- `PROTOCOL.md` for host-side intent only; no old firmware address maps were used.

Verified binary size: 32768 bytes. SHA-256: `186930d0fe8e4caa6fa2873e151225df6c7d1a6f6c4811a82601b113f65c6ddf`. A local Python comparison checked all 11310 addressed byte records in the supplied disassembly against the binary: zero mismatches. Flash-resident fan jump tables were independently decoded directly from the binary as little-endian program-word pointers and converted to byte addresses.

**Address convention:** every code/table address below is a flash **byte address**. EEPROM and SRAM addresses are explicitly labeled. AVR I/O-register addresses are distinguished from data-space addresses. No Ghidra word-address assumptions are used.

Confidence: dispatcher destinations, setup offsets, return lengths, register effects and EEPROM calls are directly established. Device labels such as temperature/PSU are interpretations corroborated by the host protocol. Physical connector numbering, electrical polarity, actual sensor presence and wall-clock timing are not established here.

## 1. Dispatcher, setup layout and USB response behavior

Application callback: **0x2352–0x3710**. USB setup processing calls it at **0x0768** when the request-type class bits are nonzero (test at 0x0760–0x0764). Thus the application callback is not restricted to exact `bmRequestType=0xc0`; neither direction nor recipient is an authorization check here. The examined host uses 0xc0 even for writes.

Callback argument points to the eight-byte setup packet:

| Offset | Field |
|---:|---|
| 0 | bmRequestType |
| 1 | bRequest |
| 2, 3 | wValue low, high |
| 4, 5 | wIndex low, high |
| 6, 7 | wLength low, high |

At **0x2386–0x238e** it selects SRAM **0x0353** as the common response buffer through the USB response pointer at SRAM 0x04a9–0x04aa. The request byte is loaded at **0x2392–0x2396**. Comparison/branch dispatcher: **0x2398–0x24c6**. This is a comparison tree, not a request jump table. Default/unsupported path **0x36dc** returns zero; common return is **0x36de**. The callback does not itself inspect wLength. USB transport caps the callback's response length against wLength at **0x082e–0x083c**. Therefore the lengths below are callback-produced lengths, and a short host wLength can truncate them. Zero-length replies acknowledge no payload; they do not prove no mutation.

Notation: V = full LE16 wValue; VL/VH its low/high bytes; I = full LE16 wIndex; IL/IH its low/high bytes. An unused field is not validated. All setters carry their data in setup fields, not an OUT data stage.

## 2. Complete request catalog

Numeric IDs 0–21 below are **decimal**, with their hexadecimal equivalents shown. Unsupported decimal 12 (0x0c) is distinct from supported hexadecimal 0x12 (decimal 18).

| Decimal / hex | Byte handler entry | Setup consumed | Produced bytes | Behavior, mutation and persistence |
|---|---|---|---:|---|
| 0 / 0x00 | **0x26d4** | none | 0 | Host watchdog service: sets I/O 0x08 bit 6, clears SRAM counter 0x0484–0x0485, EEPROM-updates address 101 to 2, sets SRAM 0x059a to 2, delays, then clears that output bit. Not purely read-only and not an AVR MCU watchdog-feed instruction. |
| 1 / 0x01 | **0x24ca** | IL, valid 0–11 | 1; invalid 0 | Read startup PWM from EEPROM address floor(IL/2). Pair mapping comes from table at 0x00cc; byte read helper 0x3880. No mutation. |
| 2 / 0x02 | **0x2516** | IL 0–11; VL | 0 | EEPROM-update startup PWM at floor(IL/2), then **falls through into current-PWM handler at 0x2574**. Also changes the paired live hardware channel unless calibration is active. Invalid IL performs no startup EEPROM write and encounters the live handler's range guard. VH/IH ignored. |
| 3 / 0x03 | **0x2628** | IL; no callback bounds check | 2 | Copy LE16 from SRAM 0x052f + 2*IL (current RPM array for intended indices 0–11). Does not validate IL, so larger selectors read adjacent SRAM rather than safely return zero. No persistent mutation. |
| 4 / 0x04 | **0x2574** | IL 0–11; VL | 0 | Change paired PWM compare register using table 0x00fc, provided SRAM calibration counter 0x0483 is zero. Invalid selector or active calibration suppresses write. No EEPROM write. VH/IH ignored. |
| 5 / 0x05 | **0x26b4** | IL 0–3; VL | 0 | Set SRAM LED-mode byte at 0x0487 + IL. Invalid IL is ignored. No EEPROM write; no immediate GPIO change in this handler. |
| 6 / 0x06 | **0x2704** | none | **9** | Read EEPROM bytes **100 through 108 inclusive** into response, in ascending order. Not merely the eight bytes consumed by the old host decoder. No mutation. |
| 7 / 0x07 | **0x272a** | VL/VH; IL/IH | 0 | Persistent watchdog configuration. Clears service counter; first sets EEPROM 100 to 0, EEPROM 101 to 2, and EEPROM 102 to IH; updates corresponding runtime state. IL=0 exits here, leaving mode disabled and ignoring V. Otherwise stores IL*20 as LE16 at EEPROM 105, sets runtime 0x055e–0x055f to that value, and mode 1. If V is nonzero, stores floor(V/3) as LE16 at EEPROM 103, **overwrites the same runtime 0x055e–0x055f pair** with floor(V/3), and changes mode to 2. See caveat below. |
| 8 / 0x08 | **0x268a** | IL; no callback bounds check | 2 | LE16 snapshot from SRAM 0x04d9 + 2*IL, host interpreted as temperature. No mutation; intended host range 0–3 is not enforced here. |
| 9 / 0x09 | **0x25da** | IL 0–11 | 1; invalid 0 | Read paired live PWM register, table 0x0114. Returns low compare byte for 16-bit channels. No mutation. |
| 10 / 0x0a | **0x23fc** | none | **4** | Version bytes: 30, EEPROM[144], EEPROM[141], 12. FW3.0 and target HW1.2 are compiled constants; actual hardware/bootloader bytes are read from EEPROM. No mutation. |
| 11 / 0x0b | **0x27f2** | none | **10** | Copy SRAM 0x056c–0x0575 to response, interpreted by host as serial. No callback mutation. |
| 12 / 0x0c | **0x36dc** (default) | none | **0** | Unsupported. Dispatcher reaches the 0x2436/0x243c comparisons, matches neither 13 nor 14, then defaults at 0x2440. No OLED function belongs to this request. |
| 13 / 0x0d | **0x265e** | none | 0 | Immediately forces all six PWM channels to 255, then sets calibration countdown SRAM 0x0483 to **10**. Timer-driven completion processes an **18-slot backing array** and EEPROM-updates eighteen LE16 maximum values starting at EEPROM 20; only twelve tach inputs are populated by the pin-change handlers described below. Persistent calibration mutation is deferred; see section 4. |
| 14 / 0x0e | **0x2444** | IL; no callback bounds check | 2 | Read LE16 EEPROM maximum at **20 + 2*IL** using two byte reads. No mutation; no safe range validation. |
| 15 / 0x0f | **0x2646** | IL; V full 16-bit | 0 | EEPROM-update LE16 maximum at **20 + 2*IL**. **No selector bounds check**; malformed selectors can target other EEPROM locations. Does not directly update the RPM snapshot in SRAM. |
| 16 / 0x10 | **0x280a** | none | 18 on initial transaction success; 0 on initial failure | Fixed-address PSU transaction family via helper 0x197c. Nine LE16 words assembled, generally reversing the two scratch bytes per word. Later transaction return codes are not checked at each call. No EEPROM writes, but active peripheral/bus transactions, not passive SRAM reading. |
| 17 / 0x11 | **0x348a** | VL character; VH flag; IL x; IH y | 0 | OLED cursor/font/character operations with flag-dependent EEPROM persistence and erase. See section 5. |
| 18 / 0x12 | **0x2958** | IL 0–7 | 26 on success; otherwise 0 | PSMI PSU telemetry at bus address IL+0x58. First transaction must succeed and first returned byte must not be 0xff. Twelve LE16 words followed by two further bytes form the 26-byte response (host combines the last four bytes as energy). Later transaction failures are not individually rejected. No EEPROM writes; performs peripheral transactions. |
| 19 / 0x13 | **0x2e78** | IL 0–1 | 12 on initial read success; otherwise 0 | Climate-sensor transaction using register 0xf7 at address IL+0x76, followed by integer compensation. Returns three four-byte big-endian quantities, matching temperature/humidity/pressure host interpretation. No EEPROM write; active bus transaction. |
| 20 / 0x14 | **0x2490** | IL; no callback bounds check | 2 | LE16 snapshot from SRAM 0x0505 + 2*IL, host interpreted as voltage. No mutation; host range 0–3 not enforced. |
| 21 / 0x15 | **0x2c20** | IL 0–7 | N+20 on success; otherwise 0 | PMBus-style model block plus nine LE16 words at address IL+0x58. Helper 0x183e reads model register 0x9a. Accepts **N=1–32**, copies N model bytes, inserts NUL, then appends telemetry at response offset N+2. Return length set at 0x2e70–0x2e76. No EEPROM writes; bus operations. |
| 145 / 0x91 | **0x35a8** | none | 0 before threshold; no normal return once triggered | Shared gate increment. At count >=5, asserts then clears I/O 0x08 bit 3, enables AVR watchdog-reset state and loops forever at 0x35e2. No direct EEPROM write in this handler. Intended rig reset followed by controller reset. |
| 146 / 0x92 | **0x35e4** | none | 0 | Shared gate increment. At count >=5, sets I/O 0x08 bit 4 and returns. Intended rig power-down output. No direct EEPROM write. |
| 147 / 0x93 | **0x35f8** | none | 0 before threshold; no normal return once triggered | Shared gate increment. At count >=5, EEPROM-updates **address 147 to value 0x93** at 0x3608–0x360e; enables AVR watchdog-reset state; updates OLED and loops forever at 0x36da. Persistent boot-entry marker plus reset, not a direct jump into flash boot code here. |

### Watchdog configuration and status caveat

The exact EEPROM layout read by request 6 is: response offset 0 = EEPROM 100 mode; offset 1 = EEPROM 101; offset 2 = EEPROM 102/IH configuration; offsets 3–4 = EEPROM 103–104 short quotient; offsets 5–6 = EEPROM 105–106 long count; offsets 7–8 = EEPROM 107–108. The host decodes only selected low bytes and calls offset 7 a reset counter; this callback merely copies EEPROM, so host interpretation is not proof of a complete firmware semantic type.

Request 7's reuse of SRAM 0x055e–0x055f for both calculations is literal data flow at **0x2792–0x2796** and **0x27d8–0x27dc**, not a transcription error. A complete watchdog timing/state-machine analysis is outside this USB report. Do not silently replace this with an idealized two-independent-timer implementation or infer milliseconds/seconds from the multiplier 20. EEPROM read/update helpers were identified by their actual EEPROM register accesses: byte read **0x3880**, change-only byte update **0x389c**, LE16 update **0x38c0**.

## 3. Exact logical-fan versus hardware-output indexing

There are **twelve populated logical tach inputs and six PWM output channels**, while ordinary RPM sampling and calibration iterate an **18-word backing array** (SRAM 0x04e1–0x0504 raw counters and 0x052f–0x0552 snapshots). Request 3 is unbounded: indices 12–17 still address the backing snapshot array, not necessarily meaningful fans; index 18 and above address subsequent state. Logical fan indices are zero-based. Every adjacent pair aliases the same startup EEPROM byte and live PWM register. The following mapping is directly decoded from binary tables and corroborated by handler register writes and initialization **0x17a0–0x17ec**:

| Logical fans | Internal output ordinal | Startup EEPROM | PWM data-space register(s) | Current-write byte target | Current-read byte target |
|---|---:|---:|---|---|---|
| 0, 1 | 0 | 0 | 0x0047 (I/O 0x27) | **0x25a2** | **0x25f8** |
| 2, 3 | 1 | 1 | 0x0048 (I/O 0x28) | **0x25a8** | **0x25fc** |
| 4, 5 | 2 | 2 | 0x0088 low, 0x0089 high | **0x25ae** | **0x2608** |
| 6, 7 | 3 | 3 | 0x008a low, 0x008b high | **0x25bc** | **0x2612** |
| 8, 9 | 4 | 4 | 0x00b3 | **0x25ca** | **0x261c** |
| 10, 11 | 5 | 5 | 0x00b4 | **0x25d2** | **0x2622** |

The 16-bit compare-register writes explicitly set the high byte to zero. These are actual MCU register identities, not twelve independent software setpoints. Connector labels and pin-to-connector wiring require a board schematic or physical observation and are not claimed.

Four tables, each twelve little-endian program-word destinations:
- **0x00cc–0x00e3**: request 1 EEPROM index choices; pair destinations 0x24e8, 0x24ee, 0x24fe, 0x2504, 0x250a, 0x2510.
- **0x00e4–0x00fb**: request 2 EEPROM-update choices; pair destinations 0x2530, 0x253a, 0x2546, 0x2550, 0x255c, 0x2566.
- **0x00fc–0x0113**: request 4 compare-register writes, as above.
- **0x0114–0x012b**: request 9 compare-register reads, as above.

All four use the table-jump helper **0x37c6**, which converts the table-index address to a byte address for flash reads and then jumps through the stored word pointer. In contrast, request 3 indexes a distinct LE16 per logical fan in SRAM. Likewise maxima use separate EEPROM words per logical fan. Do not pair-collapse tach or maximum-RPM indexing just because PWM is paired.

The populated tach inputs are independently ordered, not paired at the input: pin-change ISR **0x0f32** maps I/O 0x00 changed bits 2,3,0,1 to logical fans 0,1,2,3; ISR **0x10b0** maps I/O 0x0c bits 6,5 to fans 4,5; ISR **0x0fc4** maps I/O 0x03 bits 1,0,2,5,6 to fans 6,7,9,10,11; ISR **0x106e** maps I/O 0x09 bit 0 to fan 8. These routines compare current and previous pin states, so they count transitions rather than filtering only one edge direction. Their SRAM targets are 0x04e1 + 2*fan. No pin-change increment for backing slots 12–17 appears in these four handlers.

Startup initialization reads the six EEPROM defaults directly into the six compare registers. Thus request 2 changes both persistent startup PWM and (when calibration is inactive) immediate paired PWM; request 4 changes immediate PWM only. The request-2 fallthrough to 0x2574 is essential and differs from treating it as a persistence-only setter.

## 4. Calibration and dangerous-request gates

### Calibration

Request 13 entry **0x265e–0x2686** writes 255 into all six outputs and sets SRAM **0x0483=10**. Requests 4 and the live portion of request 2 are suppressed while that byte is nonzero; request 2's EEPROM update still happens first.

Timer ISR beginning **0x1112** reads the calibration byte at **0x116e**. Values 1–5 bypass ordinary RPM snapshot work; the special value 1 enters capture at **0x11b4–0x11ea**. That path copies **eighteen** LE16 raw counter slots from SRAM 0x04e1 onward into the RPM/max working array at 0x052f onward, EEPROM-updates eighteen words at **20,22,...,54** (loop endpoint 56 at 0x11e6), clears the captured counter slots, and decrements the calibration countdown through **0x11a4–0x11ae**. Ordinary RPM sampling at **0x117a–0x11a2** multiplies tach counts by 5. The different capture path must not be replaced with the normal sampling formula. A restart can delay completion by resetting the countdown to 10. This report establishes ISR invocations, not elapsed seconds or a physical calibration guarantee. The completion path does not itself restore PWM to the saved defaults.

### Shared dangerous-request counter

All three dangerous handlers increment **the same SRAM byte 0x0486**, not separate counters. Threshold comparison happens **after** the increment and accepts unsigned values **>=5**:
- request 0x91: **0x35a8–0x35b6**;
- request 0x92: **0x35e4–0x35f2**;
- request 0x93: **0x35f8–0x3606**.

Consequently a mixed sequence can satisfy the gate; it is not proof of five identical commands. Counter is eight-bit and increment wraps. It is cleared by timer ISR at **0x13c6**, so attempts must accumulate between those clears. It is **not** cleared on every ordinary USB request and is not an authentication mechanism. No exact time window is asserted without verifying the timer clock setup. The triggering command determines which operation executes after the shared threshold is reached.

The reset-programming sequences at **0x35ce–0x35e2** and **0x3612–0x3622** access data-space register 0x0060 and include watchdog enable/reset programming. Request 0x93's persistent marker is written before this reset path. Merely receiving a zero-byte response from an earlier gated call does not mean bootloader entry occurred.

## 5. OLED: supported on request 17 (0x11), not request 12 (0x0c)

At **0x348a**, cursor helper **0x0a6e** receives IL as x and IH as y. It accepts **x<22 and y<8**, converts x to six pixel columns and stores the current cursor. An invalid coordinate causes the cursor helper to return without changing the cursor; **the USB handler continues**, so it can still print at the previous cursor and can still perform EEPROM persistence using unchecked original coordinates.

At **0x349a–0x34b6**, flags 0/2 select font scale 1 and flags 1/3 select scale 2 through helper **0x0ef6**. Other flag values leave the previous scale unchanged. The character VL is sent to print helper **0x0c3a** at **0x34ba–0x34be**, **before** the persistence/clear flag branches. The print helper also handles control characters; it is not limited to rendering printable ASCII.

Let L = **20*IH + IL**, computed as a 16-bit value by the handler:

| VH flag | Immediate effect | Persistent effect and byte evidence |
|---:|---|---|
| 0 | Set scale 1, print VL | None |
| 1 | Set scale 2, print VL | None |
| 2 | Set scale 1, print VL | Update EEPROM **360+L** to VL; call at **0x34ec** |
| 3 | Set scale 2, print VL | Update EEPROM **200+L** to VL at **0x351c**; zero **201+L**, **220+L**, **221+L** at **0x353e**, **0x355a**, **0x357c** |
| 4 | Print VL using prior scale, then clear OLED | Helper **0x0af2** clears display; EEPROM **200 through 519 inclusive (320 bytes)** zeroed by **0x358e–0x35a4** |
| Other | Print VL with prior scale | None |

All OLED requests return zero bytes. The stride for persistent storage is **20**, even though the cursor helper accepts x=20 and x=21; do not silently correct either constant. Persistence branches do not validate IL/IH and can therefore write outside the nominal two 160-byte text planes. Flag 4 is a destructive persistent erase, not merely a volatile display clear. Invalid coordinates do not make a persistence request safe.

Startup replay at **0x1ac0–0x1af0** reads 160 bytes from EEPROM 200 onward and renders with scale 2. Replay at **0x1b04–0x1b38** reads 160 bytes from EEPROM 360 onward and renders with scale 1. Both skip zero/0xff character slots and convert the slot to coordinates with stride 20. This independently corroborates persistence and the two text-plane bases.

## 6. Limitations / safety conclusions

- Static callbacks and side effects are verified; actual live replies, hardware timing, fan wiring, PSU availability and display hardware have not been tested.
- Request 12 decimal is unimplemented; request 18 decimal/0x12 is implemented PSU telemetry. Both should remain explicit in any replacement request catalog.
- Fan getters 3/14, sensors 8/20 and maximum setter 15 lack callback index validation. Host enumeration limits are not firmware validation.
- EEPROM mutations include requests 0, 2, 7, 13 (deferred), 15, 17 (flags 2–4), and gated 0x93. Repeated service commands may call change-only EEPROM update without physically rewriting an unchanged cell.
- No operation in this report is authorization to probe the restored rig. No remote connection or live device operation was performed.
