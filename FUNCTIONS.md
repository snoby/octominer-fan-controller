# Octominer installed firmware3.0: functional guide

## What was actually done
Ghidra12.2 decompiled the actual32KB installed image from cmp-100, SHA256 `186930d0fe8e4caa6fa2873e151225df6c7d1a6f6c4811a82601b113f65c6ddf`. This is NOT the earlier firmware07/09 update-file analysis. No rig access or interruption occurred during decompilation.

The export contains122 discovered function entries:51 interrupt/vector stubs and71 other entries, including application, interrupt, bootloader and compiler-library routines. All122 produced pseudocode; that is a tool-success count, NOT proof of122 fully understood source functions or semantic completeness.

The project uses AVR8/gcc instruction semantics, corrected ATmega324PB peripheral labels from AVR-libc iom324pb.h, and the correct51-vector table. Generic Ghidra AVR8 peripheral/vector defaults describe another AVR and were removed. Ghidra displays code addresses in16-bit WORD units; this guide and export indexes use BYTE offsets. For example BYTE0x2056 appears as WORD0x102b. The original captured firmware bytes remain unchanged.

## Independent Claude review
Claude's three focused reviews returned **NEEDS_CORRECTIONS**. The core fan/control map was supported, but the generated C is not semantically reliable throughout: `eeprom_read_word` returns the wrong value in the pseudocode because a memory-mapped register alias is missed, and `eeprom_update_byte` hides arguments/interrupt masking. Use the disassembly as authority. `CLAUDE-REVIEW.md` records verified findings, reviewer limitations and corrections; it is not a claim that the firmware or decompilation has passed full verification.

## Architecture at a glance

```
reset -> C runtime/data initialization
      -> GPIO/tach/ADC setup
      -> six PWM outputs loaded from EEPROM
      -> display/persistent text, BME280 discovery, USB initialization
      -> main loop
           USB command processing
           MCU watchdog service
           host-communications timeout/recovery state machine
           indicator service

pin-change interrupts -> twelve populated tach inputs
ADC interrupt        -> rotate analog channels4..7 and accumulate samples
Timer3 interrupts    -> tach publication/calibration, analog processing,
                        host-timeout accounting and indicators

USB commands         -> fan duties/defaults, telemetry, OLED/EEPROM,
                        watchdog settings, gated reset/power/boot actions
```

This is an analyst's structural summary, not original source or a literal decompiler listing. Interrupt timing, connector wiring, sensor calibration and actual clock/fuses remain outside static verification.

## Important functions and regions
All addresses below are flash BYTE offsets. Names are descriptive annotations, not recovered symbols.

| Entry | Role | Established behavior |
|---|---|---|
|0x0438|reset_startup|Initialize stack; copy data from flash0x3916 into SRAM; clear BSS; call main|
|0x2056|application_main|Set up watchdog/peripherals, load host-watchdog state; loop over USB, recovery and indicators|
|0x0722|usb_poll|USB control/setup handling; invokes application callback for nonstandard requests|
|0x2352|usb_setup_dispatch|Large request dispatcher, ending0x3710; maps setup parameters to actions/replies|
|0x1710|gpio_input_init|Tach pin-change masks and analog conversion initialization|
|0x177c|pwm_timer_init_from_eeprom|Configure Timer0/1/2 and load six saved duties; initialize Timer3 scheduler|
|0x0f32/0x0fc4/0x106e/0x10b0|tach interrupt handlers|Count changed input transitions into per-input counters|
|0x1112|Timer3 top/capture handler|Publish/scaled tach results; calibration completion; analog processing/counters|
|0x145c/0x14de|Timer3 compare handlers|Scheduled counter/indicator processing|
|0x154e|ADC handler|Cycle channels4,5,6,7; accumulate sums/counts|
|0x090c/0x091e/0x0966/0x096e|basic TWI/I2C routines|Initialize, start/address, stop, transmit; bounded loops in basic OLED path|
|0x183e/0x197c|block/combined TWI transactions|Length-prefixed block reads and combined write/read transfers; some wait loops unbounded|
|0x1c10|bme280_discovery_and_calibration|Probe0x76/0x77, require chipID0x60; configure and load compensation coefficients|
|0x2e78..0x3488|BME measurement block|Read raw sensor registers, fixed-point compensation, return12-byte response|
|0x280a/0x2958/0x2c20|PSU telemetry blocks|Three transaction families, including indexed0x58..0x5f devices and PMBus-like identity/words|
|0x0b56/0x0c3a|OLED initialization/character rendering|SSD1306-family command template; fonts, cursor and scaled glyph rendering|
|0x1a80|startup_display_and_eeprom_text|Replay two persistent text planes or show default identification/version text|
|0x3880/0x3890|EEPROM reads|Byte/little-endian word reads|
|0x389c/0x38c0|EEPROM update helpers|Avoid physical rewrite when stored bytes already match|
|0x3712..0x3880|compiler/library support|Integer arithmetic, division, conversion/string processing, table dispatch; not separate board features|
|0x7000/0x713e/0x74b6|resident boot component|Separate startup and USBasp programming protocol; application-return gate and flash readback|

## 1. Six PWM channels, not twelve independent duty controls
The four fan-dispatch tables in actual flash map each adjacent logical pair to one compare register and one startup EEPROM byte:

| Logical fan IDs | Compare register | MCU output pin | Startup EEPROM byte |
|---|---|---|---|
|0,1|OCR0A|PB3|0|
|2,3|OCR0B|PB4|1|
|4,5|OCR1A|PD5|2|
|6,7|OCR1B|PD4|3|
|8,9|OCR2A|PD7|4|
|10,11|OCR2B|PD6|5|

This proves software/peripheral aliasing, not the external connector labels or number of physical fans. Tach readings and maximum-RPM storage remain per logical input; do not pair-collapse those arrays.

Request0x04 sets current duty. Request0x02 updates the persistent startup byte and then also follows the current-duty path. Startup uses the six stored values directly, without a factory/default validity clamp in this initializer. Separate acquisition snapshots showed all twelve logical default reads returning255 on this rig (six paired values), unchanged after readback.

## 2. Temperature reporting is not an autonomous fan curve
Only PWM initialization and the application command/calibration paths contained the identified compare-register writes in the recovered function set. The main loop services USB, watchdog/recovery and indicators; it does not expose a temperature-to-duty policy. The HiveOS host controller software supplies that policy. Consequently a replacement host daemon should not assume the microcontroller will independently maintain a desired GPU temperature. This is a static-analysis conclusion about the recovered code, not a live communications-loss experiment.

## 3. Calibration temporarily overrides normal duty control
Request0x0d at0x265e forces all six compares to255 and starts a countdown of10 Timer3 top events. While active, normal current-duty changes are suppressed; startup EEPROM updates can still occur before that gate. Completion writes eighteen backing calibration words at EEPROM starts20,22,...,54, although only twelve tach inputs are populated by the identified pin-change handlers. The final capture integrates five intervals without an extra multiply, whereas normal publication multiplies one interval's count byfive; for equal intervals these represent the same scale with an effective five-interval average. This is not a running maximum. Normal tach publication is skipped during part of calibration. The read/update/clear sequence can lose edges arriving in its interval, particularly around EEPROM updates; quantitative error has not been measured. Completion does not restore the previous duty itself. Do not equate10 timer events with10seconds.

## 4. Two different watchdog mechanisms
- MCU watchdog: main regularly services the hardware watchdog. It can reset a stuck microcontroller, including a blocked peripheral path.
- Host-communications watchdog: explicit request0x00 resets a software elapsed counter and retry stage. Merely issuing fan/sensor commands is not equivalent to this keepalive. Persistent modes and retry stages can escalate through controller restarts and GPIO actions associated with motherboard reset/power control.

Physical motherboard wiring and precise timeout seconds are not established from the flash dump. Do not treat the watchdog as merely an optional USB-health indicator, and do not experimentally disable it on the restored rig from this guide.

## 5. OLED and EEPROM are significant features
The firmware renders characters, handles control characters and1x/2x glyph scaling, and drives a128-column/eight-page SSD1306-compatible display. It stores two160-byte text planes in EEPROM200..359 and360..519 and replays them at startup. Request0x11 uses an equality-selected mode byte, not a bitmask. Modes2/3 persist text. Mode3 writes the character plus zeros to the other three cells of a2x2 footprint; at the bottom/right edges this can cross row or text-bank boundaries. Mode4 first follows the normal character-draw path, then clears the screen and uses change-only EEPROM updates to zero the320-byte text area. It is not a harmless volatile-only display operation or a flash-style erase-to-0xff.

## 6. Commands requiring careful callers
The detailed request catalog is in analysis/FW3-USB.md. Examples established in actual3.0:
- Application requests—including mutations—use setup parameters; USB IN direction is not a safety boundary.
- Current PWM/default PWM selectors are guarded0..11, but some RPM/sensor/max-RPM selectors lack bounds checking.
- Maximum-RPM setter0x0f can address EEPROM outside the nominal fan slots if given malformed indices, including watchdog fields and the boot-marker cell. Thus the five-request gate on reset/boot commands does not protect all EEPROM-backed control state from other writers. No live malformed requests were sent.
- Watchdog configuration can select an enabled mode with a zero threshold after integer truncation of small nonzero inputs, making its timeout comparison immediately true. Static startup validation normalizes invalid modes, not all invalid threshold combinations. No such configuration was tested on the rig.
- Reset0x91, power0x92 and boot-entry0x93 share one counter. Five accumulated commands can trigger the selected action; they need not be five identical requests. Timer processing clears that shared counter.
- Decimal request12 is unsupported. Hexadecimal0x12 is decimal18 and is a supported PSU telemetry path; keep decimal/hex notation explicit.

## What the decompiler did not solve automatically
- Original source, comments, names and exact original type declarations cannot be recovered from this stripped flash image.
- The GCC table-jump helper retains inlining/jump-table warnings. Its four actual12-entry flash tables were manually decoded and assembly-cross-checked; do not blindly trust the generated C around these branches.
- AVR ABI inference initially produced incorrect EEPROM return typing; explicit register-storage prototypes were applied, but did NOT solve all semantics. The generated `eeprom_read_word` at0x3890 still incorrectly returns its input address: the actual assembly loads bytes through X into memory-mapped R24/R25, an alias the decompiler misses. The generated `eeprom_update_byte` at0x389c has no visible arguments and obscures the CLI/interrupt-masking window. Its R1=0 statements can be injected assumptions, not instructions. I2C call arguments and BME stack handling also remain unreliable in pseudocode. Use assembly and explicit register-level models, not this C, for return values, atomicity or reimplementation.
- Decompiled interrupt code contains low-level status/register artifacts. These are not proof of strange original source.
- Exact timing, ADC engineering calibration, physical I2C device presence, output connector mapping, complete EEPROM contents and fuse/protection settings were not established.
- One online Microchip register summary disagrees with the AVR-libc PCMSK4 offset. The firmware matches AVR-libc at0x75, and the earlier acquired tachID4 reading was nonzero; no disabled-Port-E diagnosis is justified from the online summary alone.

## Files to open
- `decompiled/octominer-fw3.0.gzf`: native saved Ghidra program; import in Ghidra12.2 or compatible newer release.
- `decompiled/firmware-3.0-ghidra.c`: genuine combined machine-generated pseudocode.
- `decompiled/functions/`: genuine per-entry pseudocode with BYTE offset in each filename/header.
- `decompiled/functions.tsv`, `calls.tsv`, `ghidra-listing.tsv`: index, recovered call graph, instruction listing.
- `analysis/FW3-USB.md`, `FW3-CONTROL.md`, `FW3-PERIPHERALS.md`: evidence-based subsystem reports. Parent review corrected request-ID/count mistakes and the register-map interpretation in the control report.
- `analysis/ghidra-scripts/`: reproducible preparation/annotation/export scripts and parsed register/vector/jump-table inputs.

The guide explains the principal behavior and provides navigable artifacts. It does not claim full semantic verification, a compilable source reconstruction, or a safe replacement firmware ready to flash.
