# Installed FW3.0: peripherals, persistent layout, and boot component

## Evidence and interpretation rules

Evidence: the actual 32,768-byte installed dump `artifacts/installed-3.0/octominer-fw3.0-hw1.2-flash.bin`, SHA-256 `186930d0fe8e4caa6fa2873e151225df6c7d1a6f6c4811a82601b113f65c6ddf`, independently recomputed during this analysis, and its LLVM listing `analysis/installed-3.0-disassembly.txt`. No live access, installation, hardware action, or source recovery was performed. No host protocol report is used as firmware evidence.

All code/data flash addresses below are **byte addresses**. EEPROM and SRAM addresses are identified explicitly and are different address spaces. Names are analyst-assigned roles, not recovered symbols. H = direct instruction/dataflow evidence; M = convincing feature/signature match with qualifications. Code ranges inside the large USB handler are blocks, **not separate recovered functions**.

The subsequently available Ghidra 12.2 `decompiled/functions.tsv` was cross-checked for entry addresses and byte body ranges, and `decompiled/functions/byte_1c10_FUN_code_0e08.c` was read as a complement to the BME280 assembly/dataflow analysis. Export filenames use byte addresses while pseudocode labels use word addresses. The 122 exported entries include 51 vectors, not 122 substantive functions. Corrected ATmega324PB register labels, not generic ATmega64 labels, are the relevant register reference. No decompiler export was modified; peripheral/library names below remain analyst interpretations rather than recovered source symbols.

## Byte-address role table

| Flash byte address | Analyst role | Firmware cross-reference / decisive evidence | Confidence |
|---|---|---|---|
| `0x0438` | Application runtime startup | Reset vector `0x0000`; initialized-data source `0x3916` copied to SRAM `0x0100..0x034f`, BSS cleared `0x0350..0x059e`; calls main `0x2056` at `0x046a` | H |
| `0x090c` | TWI initialization | Called at `0x0b6e`; sets TWI bitrate register at SRAM-mapped `0x00b8` to `0x48`, status/prescaler register `0x00b9` to zero and control `0x00bc` to `0x04` | H |
| `0x091e` | Bounded TWI START and address transmission | OLED callers `0x09fc`, `0x0a40`, `0x0bbe`, `0x0bf2`; waits on completion with decrementing bound `0x0140`; error bits 0/1 in SRAM `0x04c5` | H |
| `0x0966` | TWI STOP | Command/data writers tail-transfer here; control value `0x94` | H |
| `0x096e` | Bounded TWI byte transmit | Called throughout OLED path; bound `0x0140`; error bit 2 in SRAM `0x04c5` | H |
| `0x0996`, `0x09c0` | Bounded TWI receive with ACK / final NACK | Control values `0xc4` / `0x84`; return received byte, or zero on timeout; error bits 3 / 4. No direct application callers found | H role; reachability unresolved |
| `0x09ea` | OLED command-buffer send | Address byte `0x78` (7-bit `0x3c`), control byte zero, caller-length RAM buffer, then STOP | H |
| `0x0a2e` | OLED pixel-data buffer send | Same address byte `0x78`, control byte `0x40`, RAM buffer and length; called by clear at `0x0b2e` | H |
| `0x0a6e` | Text-cell/page positioning | Bounds column <22, page <8; column multiplied by six; stores cursor in SRAM `0x0351/0x0352`; sends page and column commands. Calls at `0x1adc`, `0x1b20`, `0x3496` | H |
| `0x0ab8` | Reset OLED cursor | Clears cursor pair, sends page-zero / column-range command buffer | H |
| `0x0af2` | OLED clear | Eight pages, each 128 zero bytes, via `0x0a6e` / `0x0a2e`, then reset cursor; called `0x0b96`, `0x1aa0`, `0x358a`, `0x3626` | H |
| `0x0b56` | Initialize SSD1306-compatible OLED | Copies 28-byte command template from flash `0x041c`, replaces its final byte with argument; caller `0x1a9c` supplies `0xaf`; calls TWI initialization and display clear | H behavior; M exact controller identity |
| `0x0bae`, `0x0be2`, `0x0c16` | OLED inverse-mode, display enable/disable, contrast wrappers | Commands selected from `0xa6/0xa7`, `0xaf/0xae`, or `0x81` plus argument; `0x0c16` called at `0x1aa6`. No direct callers found for first two | H role; first two reachability unresolved |
| `0x0c3a` | Character renderer | Control characters handled separately; six-column glyph lookup via program-memory reads; scale-two path expands vertical bits and duplicates columns into two pages. Callers `0x0f08`, `0x0f24`, `0x1ae2`, `0x34be` | H |
| `0x0ef6`, `0x0efc`, `0x0f14` | Select text scale; RAM string render; flash string render | Scale in SRAM `0x0102`; both string walkers stop at zero and call `0x0c3a`; RAM writer called during startup and boot-entry display. No direct callers found for flash walker | H |
| `0x154e` | ADC conversion ISR | Vector at `0x0060`; reads ADC result `0x0078/0x0079`, switches channels 4→5→6→7→4, accumulates sums/counts, starts next conversion | H |
| `0x1710` | GPIO/input interrupts and ADC setup | Called `0x206c`; initializes ADMUX `0x44` and ADCSRA `0xcf` at `0x176e..0x1776` | H |
| `0x183e` | TWI length-prefixed/block read | Called `0x2c32` with device index+`0x58`, command `0x9a`, destination SRAM `0x057a`; first received byte is length, then remaining bytes are stored. Checks TWI states; no finite wait timeout | H |
| `0x197c` | General TWI write/read transaction | 7-bit address shifted left; sends requested write bytes, optionally repeated START and reads requested count into destination, then STOP. Extensive sensor/PSU callers. TWI waits have no finite bound | H |
| `0x1a80` | Startup OLED / persistent text presentation | Called `0x208e`; initializes display, checks EEPROM text banks, renders populated cells, otherwise renders default identification text and versions | H |
| `0x1c10` | BME280 discovery/configuration/calibration | Called `0x2092`; loops over `0x76`, `0x77`; reads register `0xd0`, requires `0x60`; writes configuration pairs; reads temperature, pressure and humidity calibration including packed signed humidity coefficients | H |
| `0x280a..0x2956` | Fixed-address telemetry block | Calls `0x197c` against 7-bit address `0x01`; reads commands `0x82,0x83,0x86,0x81,0x88,0x85,0x84,0x85,0x87`; returns 18 bytes in SRAM `0x0353..0x0364`, swapping each pair | H bytes; M PSU/device meaning |
| `0x2958..0x2c1e` | Indexed PSU-like telemetry block | Index restricted <8, address index+`0x58`, command/check byte pairs, first 3-byte read then further reads; 26-byte response, no unit conversion demonstrated | H bytes; M PSU model/field names |
| `0x2c20..0x2e76` | Indexed PSU identity/extended telemetry | Index <8, address index+`0x58`; length-prefixed command `0x9a` through `0x183e`, then two-byte commands `0x88,0x89,0x97,0x8b,0x8c,0x8d,0x8e,0x8f,0xd5`; returns length+20 bytes | H bytes; M semantic labels |
| `0x2e78..0x3488` | BME280 measurement/compensation block | Index <2, address index+`0x76`; eight-byte read beginning `0xf7` via call `0x2e94`; assembles 20-bit pressure/temperature and 16-bit humidity, applies stored coefficients and fixed-point arithmetic, returns 12 bytes | H feature; exact signedness/units caveat below |
| `0x348a..0x35a6` | Character render / persistent-cell update / text clear | Uses cursor and character functions; persistent modes update corresponding EEPROM text bank. Clear mode erases EEPROM `0x00c8..0x0207` while clearing screen | H |
| `0x35f8..0x36da` | Application boot-entry block | Five-count threshold; writes EEPROM byte `0x0093 = 0x93` through call `0x360e`, configures MCU watchdog reset, renders boot-mode screen, spins | H |
| `0x3880` | EEPROM read byte | EECR/EEAR/EEDR access; called for PWM defaults, identification, watchdog state and display text | H |
| `0x3890`, `0x38d6/0x38da` | EEPROM read word; shared block-read engine | Word wrapper reads two bytes into return-register storage; block engine iterates EEPROM reads into RAM | H |
| `0x389c/0x389e`, `0x38c0` | EEPROM update byte; update word | Reads existing value, skips identical write; interrupt-masked programming strobe; word entry updates high then low byte | H |
| `0x38cc`, `0x38f6/0x38f8` | EEPROM unconditional write word; write byte | Word entry writes low then high using shared engine; unlike update helper does not compare old contents | H |
| `0x7000`, `0x713e` | Boot component vector base / runtime startup | Boot vector branches to `0x713e`; separate initialized-data source `0x799e`; boot data/BSS distinct from application | H |
| `0x70cc` | Boot SPM helper | Program-memory self-write operation, busy wait and RWW handling; role evident, callers not completely recovered | H role |
| `0x70ec`, `0x70fe`, `0x7110`, `0x711e` | Boot USB configuration/device/product/manufacturer descriptors | Separate descriptor set: USBasp product and fischl manufacturer; same VID/PID bytes as app at device offsets +8/+10 | H |
| `0x74b6` | Boot main / application-entry gate | Startup call `0x7188`; reads boot marker at `0x74c2`, writes version metadata, relocates vectors; second marker check/clear `0x750e/0x751a`; conditional entry to application reset via zero-target indirect call `0x754c` | H |
| `0x7724..0x7818` | Boot incoming memory-write handling region | EEPROM-vs-flash branches; flash-page buffer load at `0x7796`, erase `0x77dc`, page write `0x77f8`, RWW enable `0x780a`; rejects flash addresses ≥`0x7000`, page-boundary mask `0x7f` | H |
| `0x7860..0x78a8` | Boot outgoing memory-read loop | EEPROM read via `0x7888` or flash program-memory byte at `0x788e`; increments byte address | H |
| `0x794a`, `0x795a`, `0x797e` | Boot EEPROM byte read/update/write helpers | Same peripheral behavior as app counterparts; relative callers resolved using instruction address+2+signed displacement | H |

## EEPROM configuration layout (actual code references)

| EEPROM byte address | Observed interpretation | Evidence / limits |
|---|---|---|
| `0x0000..0x0005` | Six stored PWM defaults | `0x17a0..0x17ec` loads them into the six timer compare outputs. Not a claim of six independent physical fans |
| `2*(10+index)` | 16-bit fan calibration/max-speed slot | Reader `0x2444..0x2462`, writer `0x2646..0x2656`; calibration ISR writes consecutive words from `0x0014` through word starting `0x0036` at `0x11c4..0x11ea`. Physical channel mapping belongs in PWM analysis |
| `0x0064` | Persistent watchdog/action mode | Startup `0x20ae`, valid 0..2; invalid values reset to zero. Runtime SRAM `0x04ce` |
| `0x0065` | Persistent attempt/retry counter | Startup `0x2104`, default 2; decrement and reset paths `0x217c`, `0x21da`, `0x2266`, `0x22c4` |
| `0x0066` | Persistent secondary action/retry setting | Startup `0x2110`, default zero; stored into SRAM `0x055d` |
| `0x0067..0x0068`, `0x0069..0x006a` | Two stored 16-bit timeout/action intervals | Read selected by mode at `0x2120..0x2136`; writers `0x2782`, `0x27c8`. Exact timing interpretation delegated to watchdog analysis |
| `0x006b..0x006c` | Persistent event/action count word | Read/increment/write at `0x2184..0x2192`, `0x222a..0x2238`, `0x226e..0x227c` |
| `0x008d` | Bootloader revision value | Boot main writes decimal 20 at `0x74e6..0x74ec`; app version reply reads at `0x2412` and startup display at `0x1bb2` |
| `0x0090` | Hardware revision value | Boot main writes decimal 12 at `0x74ee..0x74f4`; app reads at `0x2406` and display at `0x1b84` |
| `0x0093` | One-shot boot-mode marker | Application sets `0x93` at `0x3608..0x360e`; boot main checks twice and clears at `0x7514..0x751a`. Not executable flash |
| `0x00c8..0x0167` | 160-byte large-text cell bank | Startup reads `0x00c8+i` at `0x1ac0..0x1af0`; 20 cells per row, scale two; `0x351c` updates selected cell |
| `0x0168..0x0207` | 160-byte small-text cell bank | Startup reads `0x0168+i` at `0x1b04..0x1b3a`; 20 cells per row, scale one; `0x34ec` updates cell |

Text banks skip bytes zero and `0xff`. The two banks overlap spatially on screen; they are not a framebuffer. Persistent text write mode also clears following cells in the large bank (`0x353e`, `0x355a`, `0x357c`). The whole 320-byte persistent area is zeroed by the clear loop `0x358e..0x35a4`. No EEPROM image was supplied: the table proves layout/code behavior, **not current stored values**.

## Sensor dataflow and feature evidence

### ADC

The ADC ISR tracks four channels with independent 32-bit accumulators and counts:

| ADC input | Sum SRAM | Count SRAM | ISR block |
|---|---|---|---|
| 4 | `0x051f..0x0522` | `0x048b..0x048e` | `0x157a..0x15d2` |
| 5 | `0x0523..0x0526` | `0x048f..0x0492` | `0x163a..0x1692` |
| 6 | `0x0527..0x052a` | `0x0493..0x0496` | `0x1694..0x16ec` |
| 7 | `0x052b..0x052e` | `0x0497..0x049a` | `0x15e0..0x1638` |

A timer ISR at `0x1112` invokes the 32-bit unsigned divide helper at `0x120e`, `0x1236`, `0x125e`, `0x1286`, producing averaged values beginning SRAM `0x0505`. This establishes sampled/averaged analog telemetry, not which board net is voltage, temperature or current. ADC scaling, divider ratios, reference-voltage accuracy, sample timing and exact request payload ordering remain to be independently checked. No thermistor model or physical ADC pin wiring is asserted.

### BME280

The combined identity/address/calibration/raw-register signature is decisive, rather than a host label: `0x1c10` tries two legal device addresses, accepts ID `0x60`, reads calibration `0x88..0x9f`, `0xa1`, `0xe1..0xe7`, including nibble-spliced signed H4/H5. It uses shared scratch SRAM `0x057a`.

The six-byte configuration payload built at `0x1ce0..0x1d10` is three **register/data pairs**: `F2=05`, `F5=5C`, `F4=B7`. This is supported by Bosch's paired-write I2C protocol, not an assumed auto-increment write. Measurement block `0x2e78` reads eight bytes at `0xf7`, performs temperature calculation first (`0x2f3a..0x303c`), humidity calculation/clamping (`0x303e..0x31fe`), then pressure calculation with divisor-zero bailout (`0x3200..0x344a`). Output assembly `0x344c..0x3486` returns 12 bytes in scratch reply SRAM `0x0353..0x035e`. Exact output signedness, padding and engineering-unit presentation require a separate bit-accurate model; no floating-point implementation is evidenced here.

Calibration storage traced from `0x1c44..0x1fa4` (SRAM bases; sensor index adds two for word arrays and one for byte arrays):

| Coefficients | SRAM bases in coefficient order |
|---|---|
| T1, T2, T3 | `0x04ca`, `0x0553`, `0x0568` |
| P1 through P9 | `0x0576`, `0x04c6`, `0x0564`, `0x0560`, `0x050d`, `0x051b`, `0x0557`, `0x04d5`, `0x0517` |
| H1, H2, H3, H4, H5, H6 | `0x055b` (byte), `0x04d1`, `0x0515` (byte), `0x0511`, `0x059b`, `0x04cf` (byte) |

Primary interpretation reference: Bosch Sensortec *BME280 Data sheet*, cover revision 1.24 / BST-BME280-DS001-24 (interior footers retain DS001-23), sections 5, 6.2.1/6.2.2 and integer compensation appendix, retrieved from the official Bosch datasheet endpoint (document URL basename `bst-bme280-ds002.pdf`). The datasheet establishes chip/register semantics; all code addresses above come from the installed dump.

### PSU and auxiliary telemetry

Three independent paths exist, not a single inferred PSU implementation: fixed address `0x01`; indexed `0x58..0x5f` custom/check-byte path; indexed `0x58..0x5f` length-prefixed identity plus PMBus-like commands. The indexed custom path constructs its second transmitted byte as the negative sum of shifted slave address and command, e.g. at `0x296a..0x2974`. This supports vendor-specific framing, not proof of SMBus PEC.

The extended path restricts the length returned by `0x183e` to 1..32 before copying. That check occurs **after** the low-level read, which itself has no caller-supplied destination bound. Treat this as an unresolved robustness concern, not a demonstrated exploit. Do not assign PSU models or decode the raw words into watts/volts/amps using host expectations alone. Code presence does not prove that any PSU or BME280 is physically attached or responding on the restored rig.

## Display data, fonts, and version provenance

- Flash `0x0198..0x01ab` is a terminated exceptional-character mapping consumed by renderer `0x0d14..0x0d50`; it is data, not instructions.
- Flash `0x01ac..0x041b` is 624 bytes, interpreted by renderer as 104 six-byte glyph records. Glyph count is derived from the exact boundaries, not a recovered original font name. Printable characters start from character code `0x20`; exceptional mappings extend the repertoire. No claim that every record is independently reachable.
- Flash `0x041c..0x0437` is the 28-byte OLED startup command template. It carries 128-column/eight-page addressing, mux, charge-pump and related SSD1306-family settings. No photographed hardware identification or panel validation occurred.
- Firmware version 30 is an application literal (`0x23fc`) and startup display input (`0x1be4`), not read from EEPROM. Hardware 12 and boot revision 20 instead originate from boot code's EEPROM writes.
- Flash `0x3916..0x3b65` is initialized-data backing, including default display text. Its strings at `0x3b19..0x3b65` become RAM addresses `0x0303` onward at runtime; apparent RAM string pointers are not missing flash references.

## Compiler/library-like support: separate from board features

These labels describe observed algorithms and calling patterns, not an identified compiler version or proven linkage to a particular library build.

| Flash entry | Algorithmic role | Example cross-reference | Confidence |
|---|---|---|---|
| `0x3712` | 32-bit multiply helper | BME math calls `0x2fc0`, `0x3092`, `0x3164`, `0x321e` | H algorithm; M conventional `__mulsi3` name |
| `0x3732` | Unsigned 16-bit quotient/remainder | Watchdog arithmetic `0x27c0/0x27d4` | H; `__udivmodhi4`-like |
| `0x375a` | Signed 16-bit division wrapper | Startup text positioning `0x1ad8/0x1b1c` | H; `__divmodhi4`-like |
| `0x3782` | Unsigned 32-bit quotient/remainder | ADC averaging and pressure `0x3378/0x3386` | H; `__udivmodsi4`-like |
| `0x37c6` | Program-memory jump-table dispatch | Loads word-address target from program memory then indirect jump; do not confuse with sensor logic | H role |
| `0x37d2`, `0x37f8` | 16×32 low-result multiply; 16×16→32 unsigned multiply core | `0x3008`, `0x3050`, `0x3718` | H widths/operations |
| `0x37e8`, `0x37ee` | Signed-operand multiply selection and negative correction variant | Compensation calls `0x2fa2`, `0x307c`, `0x3360` | H arithmetic role; original helper names unresolved |
| `0x3816`, `0x382c/0x382e` | Signed integer-to-string entry and unsigned/common conversion core | Base-ten display revisions at `0x1b92`, `0x1bc0`, `0x1be8` | H; `itoa`/`utoa`-like |
| `0x3860` | In-place zero-terminated string reversal | Tail target `0x385c`; reverses generated digits | H; `strrev`-like |
| `0x3880..0x3910` | EEPROM library-shaped routines | Persistent layout above | H role; exact library provenance unresolved |
| `0x3912` | Application terminal exit loop | Startup return target `0x046e` | H |
| `0x718e`, `0x71b8` | Boot USB CRC16 accumulator and append wrapper | Polynomial-shaped shift/XOR with `0xa001`; separate from application sensor checks | H algorithm; exact original symbol unresolved |

## Boot component boundaries and limits

Boot vectors/code begin at `0x7000`. Separate USBasp descriptors, application-return gate, direct flash read, and self-programming sequences demonstrate a real resident programming component, not merely a display string. Its initialized-data tail is `0x799e..0x79a3`; `0x79a4..0x7fff` is erased-value padding in this dump. The application initialized-data ends at `0x3b65`, followed by erased-value gap `0x3b66..0x6fff`. The memory-write path's `<0x7000` guard and 128-byte page boundary are code observations, not fuse/lock-bit readbacks or a guarantee against every possible programming path.

The marker-driven application reset and boot gate are cross-confirmed by **both** components. Boot metadata writing also explains why version EEPROM cells are not ordinary user configuration. GPIO boot-selection conditions exist at `0x751e..0x7524` in addition to the marker; board wiring/polarity and reset-cause effects need a full control-flow reconstruction. Full boot request-ID dispatch, erase/fuse/lock support, and all USB state-machine helpers were not exhaustively mapped in this support-function pass.

## Unresolved / verification status

Static identification is strong for EEPROM helpers/layout, ADC channel rotation and averaging, OLED/font rendering, BME280 support, raw I2C telemetry paths and resident self-programming boot component. Physical sensor/PSU presence, numeric telemetry accuracy, bus frequency, oscillator assumptions, analog wiring, EEPROM current contents and boot fuses are not established. No source symbols or library/compiler versions were recovered. No live functional tests were attempted. This is a **partial subsystem map**, with exact evidence anchors for the verified portions rather than invented semantic completeness.
