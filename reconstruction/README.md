# EEPROM reconstruction: executable evidence, not decompiler trust

## Result
Six EEPROM helpers were reconstructed as clean host-side reference C and compared with a focused interpreter that fetches/executes actual opcodes from the verified installed FW3.0 image.

**28,654 differential cases passed**, including every valid byte address, every valid non-wrapping word start, equal/changed/partially-changed values, and both initial interrupt-enable states. A separate negative control compiled a deliberately wrong word reader matching Ghidra's bad return-address behavior: the same differential test rejected it immediately.

This is a stronger building block than manually accepting the pseudocode, but **not a proof of the whole firmware or a validation on physical silicon**. Both the interpreter and the C reference are new software and could have defects. Scope/assumptions are explicit below.

## What this establishes under the model

| Flash BYTE entry | Helper | Observed semantics |
|---|---|---|
|0x3880|read byte|Read EEPROM into R24; clear R25|
|0x3890|read word|Load two EEPROM bytes through X into data addresses0x18/0x19, which ARE CPU R24/R25; return their little-endian value|
|0x389c|update byte|Read first; skip identical values; otherwise program inside an interrupt-disabled strobe window and restore prior interrupt-enable state|
|0x38c0|update word|Process high byte FIRST, then low byte; independently skip unchanged bytes|
|0x38f6|write byte|Unconditional program, even if existing value matches|
|0x38cc|write word|Program low byte FIRST, then high byte; both unconditional|

The two word-writing helpers reach the same final value but have different byte ordering and wear semantics. Each byte has its own interrupt-masked strobe window; this does not make a word operation atomic against interrupts/reset/power failure.

### Concrete decompiler failure reproduced
The captured helper at0x3890 does NOT return its input address. Its block reader writes EEPROM data into the memory-mapped CPU-register aliases0x18 and0x19. A test vector with EEPROM[0x67..0x68]=34,12 returns0x1234 in R25:R24, not0x0067. This EEPROM content is a **synthetic test vector**, not a claim about those cells on the live rig.

The negative control uses the same compiled-C comparison pipeline and intentionally returns the address. At address0 its result0 disagreed with the interpreted return12299 (0x300b) from the deterministic test pattern. It failed with an assertion, as required; no fabricated result was substituted.

## Test matrix

| Helper | Differential cases |
|---|---:|
|Read byte|2,048|
|Read word|2,046|
|Update byte|4,096|
|Update word|8,184|
|Write byte|4,096|
|Write word|8,184|
|Total|28,654|

For each case, compare return value where applicable, the complete EEPROM data array, ordered modeled EEPROM-programming events, restored interrupt-enable state, and interrupt state at each programming strobe. The focused interpreter executed708,036 opcode steps from the captured helper region in this test run; these are **interpreted steps, not measured hardware cycles**.

The EEPROM pattern and candidate values are deterministic test inputs. They are not a current EEPROM dump. No out-of-range wrapping behavior, asynchronous interrupt injection, clock/fuse behavior, programming latency, endurance or power-loss behavior is asserted.

## Upstream corroboration
These behaviors match published AVR-LibC assembly patterns, rather than indicating a broken proprietary EEPROM algorithm. Its `eerd_word.S` explicitly selects CPU register24 as the block-read destination; `eeupd_word.S` processes the higher-address byte first; `eewr_word.S` calls the low-byte writer before handing off the high byte. This is corroboration of helper semantics, not proof of an exact linked AVR-LibC version or a byte-identical library build.

Primary source locations (checked during this reconstruction):
- `https://raw.githubusercontent.com/avrdudes/avr-libc/main/libc/misc/eerd_word.S`
- `https://raw.githubusercontent.com/avrdudes/avr-libc/main/libc/misc/eeupd_word.S`
- `https://raw.githubusercontent.com/avrdudes/avr-libc/main/libc/misc/eewr_word.S`
- `https://avrdudes.github.io/avr-libc/avr-libc-user-manual/group__avr__eeprom.html`

That distinction matters: recognize library machinery first, and reserve the next reconstruction effort for Octominer-specific PWM/watchdog policy.

## How the harness avoids the original alias trap
`avr_slice.py` uses one shared byte array for CPU R0..R31 and data-memory addresses0..31. An ST through X into0x18 therefore changes R24 directly. Fetch/decode comes from `firmware.bin`, not from a rewritten assembly listing or the C reconstruction. Unsupported opcodes and control-flow exits from byte0x3880..0x3911 fail explicitly; they are not guessed.

The reference C uses an ordinary EEPROM array and high-level operations rather than CPU register aliases, providing a separate implementation of the intended observables. It is compiled locally with warnings treated as errors and loaded through ctypes. All six helpers are compared on the same inputs.

## Explicit limitations
- The interpreter is a small, new instruction-subset executor, not a mature full AVR simulator or formal ISA model.
- Calls/returns use an abstract call stack. These helpers do not inspect the return-stack RAM; no general stack correctness is claimed.
- R1 is assumed zero at entry, as required by the examined GCC-style ABI; arbitrary corrupted caller state is not covered.
- EEPROM reads are modeled as immediate. Writes commit at the strobe and expose a deterministic two-poll busy interval. This is NOT measured device latency or a cycle-accurate electrical model.
- The model requires master-enable and an interrupt-disabled programming strobe, but does not validate exact four-cycle timing or inject interrupts between instructions.
- Only interrupt-enable preservation, relevant values, ordered write events and EEPROM contents are compared; caller-clobbered scratch registers/other SREG flags are not all compared to C.
- Valid addresses only: byte0..1023, word starts0..1022. C assertions enforce this harness domain; they are NOT checks present in the original firmware.
- Values cover matched and changed bytes, including independently changed word halves; this is not exhaustive over every possible EEPROM image and16-bit value combination.
- The reference trace has capacity for one operation's at-most-two writes. Each test starts a fresh context. This is a test model, not a production EEPROM API.
- No Ghidra project, firmware byte, service, fan setting or live controller was changed. The original generated C remains preserved with its known errors.

## Run
Requires Python3 and a local C compiler (clang or cc); no Python packages or network required.

```sh
cd reconstruction
python3 -m unittest test_eeprom -v
```

The test compiles `eeprom_reference.c` into `build/` and writes `results.json`. The included firmware fixture is the actual captured image, validated by SHA-256:

`186930d0fe8e4caa6fa2873e151225df6c7d1a6f6c4811a82601b113f65c6ddf`

The intentionally wrong negative-control source is under `build/negative_word_return.c`. To reproduce its EXPECTED nonzero test exit:

```sh
EE_REFERENCE_SOURCE="$PWD/build/negative_word_return.c" python3 -m unittest test_eeprom.InstructionTests.test_compiled_c_matches_captured_helpers_across_valid_addresses -v
```

Re-run the normal test afterward to restore the clean compiled reference library.

## Files
- `eeprom_reference.c`: readable reference implementation; NOT flashable AVR firmware.
- `avr_slice.py`: opcode executor and explicitly bounded EEPROM model.
- `test_eeprom.py`: focused regression and compiled-C differential tests.
- `firmware.bin`: unchanged32KB captured input.
- `results.json`, `test-run.log`: successful actual run output.
- `negative-control.json`, `negative-control.log`, `build/negative_word_return.c`: deliberate fault and actual rejection evidence.

A sensible next offline increment is to apply this technique to selected PWM/watchdog handlers with explicitly modeled peripherals. That extension has not been implemented here.
