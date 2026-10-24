# Octominer host CLI: offline USB protocol reconstruction

## Scope, provenance, confidence

Only local static analysis was performed. The executable was **not executed**, and no rig, USB device, remote service, package installation, or global configuration was touched. This report is the only output file created.

Inputs:
- `/Users/snoby/octominer-re/analysis/cli-disassembly.txt`
- `/Users/snoby/octominer-re/analysis/cli-dwarf.txt`
- `/Users/snoby/octominer-re/artifacts/192.168.2.106/fan_controller_cli`

ELF: x86-64, statically linked, unstripped, GNU/Linux, DWARF from an unoptimized C compilation. SHA-256: `9f2dbaa9257d133b0c682e70d11ab6c2c6bcf42e98dc8842cdf2b5d1972a1cc5`.

Verification: fresh local `llvm-objdump` output for `0x400bad–0x40475e` matched all **3,259** instruction/address entries in the supplied disassembly. There are **44** calls to `usb_control_msg` within this application range, including descriptor lookup and bootloader handling. Read-only ELF section parsing recovered constants and option dispatch targets.

**High** = directly established host arguments, arithmetic, or DWARF types. **Medium** = intended device meaning inferred from option dispatch, diagnostics, and decoder use. **Unknown** = not established by this host binary. High confidence in a host encoding does not imply firmware support or operational safety.

All addresses below are ELF virtual addresses, not file offsets. No source-code passages are reproduced.

## 1. Transport and device discovery

### Control-transfer ABI — High

At call sites, the x86-64 SysV arguments are:

| Argument | Location | Meaning |
|---|---|---|
| 1 | RDI | USB handle |
| 2 | ESI | bmRequestType |
| 3 | EDX | bRequest |
| 4 | ECX | wValue |
| 5 | R8D | wIndex |
| 6 | R9 | response buffer |
| 7 | stack, first argument | maximum data length |
| 8 | stack, second argument | timeout in milliseconds |

The wrapper at `0x406b10` confirms this independently: `0x406b2b–0x406b54` stores the first two request fields as bytes, value/index/length as 16-bit words, then timeout and data pointer into the Linux USB control ioctl structure. `0x406b5a` submits the ioctl. Thus oversized CLI integers are truncated to the corresponding wire fields.

All application vendor requests use **bmRequestType = 0xc0**, **wLength = 0x0100 (256)** and **timeout = 0x1388 (5000 ms)**. This includes commands that change state: they are IN-direction control transfers carrying command parameters in the SETUP packet, **not OUT payload writes**. For example, the current-PWM setter is assembled at `0x404371–0x4043aa`. The requested length is an upper bound, not proof that the device returns 256 bytes.

SETUP bytes are `c0, request, value_lo, value_hi, index_lo, index_hi, 00, 01`. Endianness of response payloads is command-specific.

### Discovery — High

Normal-device setup at `0x4013d1–0x4013e9` requests VID **0x16c0**, PID **0x05dc**, manufacturer **info@octominer.com**, product **Fan-Controller**. Bootloader setup at `0x401185–0x40119d` uses the same VID/PID but manufacturer **www.fischl.de**, product **USBasp**. The descriptor strings distinguish these identities; VID/PID alone does not.

`usbOpenDevice` (`0x400d61`) checks IDs at `0x400dda–0x400e0e`, fetches manufacturer/product descriptors with language ID **0x0409** at `0x400e8c` and `0x400efc`, and compares both strings at `0x400f39–0x400f71`.

Descriptor helper call `0x400c27`: bmRequestType **0x80**, bRequest **6**, wValue **0x0300 + descriptor index**, wIndex **language ID**, length **256**, timeout **1000 ms**. Its decoder clamps to the descriptor's length, checks descriptor type 3, copies low bytes of UTF-16 code units when their high bytes are zero, substitutes a placeholder otherwise, and terminates the resulting string (`0x400c4a–0x400d48`).

## 2. Normal-device request catalog

Unless noted, all entries use the common vendor transport above. `B` means response bytes; offsets are zero-based. `LE16` and `BE32` specify byte order explicitly. Request fields and host interpretation: **High**. Physical effects and persistence: **Medium**, not tested.

### Read/status requests

| bRequest | wValue | wIndex | Host decoding / purpose | Call address |
|---|---:|---:|---|---|
| `0x01` | 0 | fan | `B[0]`: startup/default PWM | `0x402a52`; human `0x404124` |
| `0x03` | 0 | fan | unsigned `LE16(B+0)`: current RPM | `0x4029a0`; human `0x4041e8` |
| `0x06` | 0 | 0 | watchdog status, see below | `0x401c64`; human `0x403248` |
| `0x08` | 0 | sensor 0–3 | signed `LE16(B+0)`: integer Celsius | `0x401b50`; human `0x403cec` |
| `0x09` | 0 | fan | `B[0]`: current PWM | `0x402adb`; human `0x404186` |
| `0x0a` | 0 | 0 | version/revision bytes | `0x40197b`; human `0x403054` |
| `0x0b` | 0 | 0 | serial bytes `B[0..9]`, formatted in received order | `0x401877`; human `0x402f50` |
| `0x0e` | 0 | fan | unsigned `LE16(B+0)`: stored maximum RPM | `0x402b67`; human `0x404266` |
| `0x10` | 0 | 0 | OCTO 2000W PSU, nine little-endian words | `0x401d25`; human `0x403318` |
| `0x12` | 0 | PSU 0–7 | PSMI-compatible telemetry, see below | `0x4023fc`; human `0x403591` |
| `0x13` | 0 | climate sensor 0–1 | BME280, three big-endian dwords | `0x402791`; human `0x403e3c` |
| `0x14` | 0 | sensor 0–3 | signed `LE16(B+0)` × `0.006451613`: volts | `0x401bda`; human `0x403d92` |
| `0x15` | 0 | PSU 0–7 | variable model prefix and PMBus words | `0x401f92`; human `0x4038de` |

The shown index ranges are **host enumeration ranges**, not proven device limits. Machine-readable output tries `0x15` first for each PSU. A negative result skips that PSU; exactly zero bytes triggers the `0x12` fallback (`0x401fa1–0x401fd9`, `0x4023c6`). Human-readable output separately enumerates both families.

### Mutating/control requests — do not issue as passive probes

| bRequest | wValue | wIndex | Intended operation / CLI mapping | Call address |
|---|---:|---:|---|---|
| `0x00` | 0 | 0 | watchdog reset/service, `-s` | `0x402e26` |
| `0x02` | value | fan | set startup/default PWM, `-d fan -v value` | `0x40445f` |
| `0x04` | value | fan | set current PWM, `-f fan -v value` | `0x4043aa` |
| `0x05` | value | LED | set LED mode, `-l LED -v value` | `0x4045c9` |
| `0x07` | short-timeout argument | `0x6400 + floor(adjusted_long / 60)` | configure/re-enable watchdog, `-w short -v long` | `0x4046ba` |
| `0x0d` | 0 | 0 | test/calibrate maximum fan speed, `-t` | `0x402ebb` |
| `0x0f` | value | fan | set maximum RPM, `-m fan -v value` | `0x404514` |
| `0x11` | packed character/flag | packed position | OLED operation, `-o x,y,flag -v text` | `0x401594`, `0x4016a6`, `0x401722` |
| `0x91` | 0 | 0 | reset rig, `-x` | `0x402ca9` |
| `0x92` | 0 | 0 | power down rig, `-p` | `0x402d2c` |
| `0x93` | 0 | 0 | enter bootloader, `-b` | `0x402daf` |

Normal request `0x03` is an RPM read; do not confuse it with bootloader request `0x03` below. No normal-device call for request `0x0c` was found; this does not prove it is unsupported.

The fan/LED setters run after option parsing and require nonnegative selector and value, but do not establish upper-bound validation. The bootloader/reset/power paths issue up to **10 attempts**, stopping on a negative transfer result (`0x402cb8–0x402ccf`, `0x402d3b–0x402d52`, `0x402dbe–0x402dd5`). These loops may repeat state-changing requests; success does not mean the command was sent once.

## 3. Response layouts and exact decoder behavior

### Versions, fan count, watchdog

Request `0x0a` (`0x4019bb–0x401aa1`; human `0x403094–0x40319c`):
- `B[0] / 10`: firmware version.
- `B[1] / 10`: initially displayed hardware revision.
- `B[2] / 10`: bootloader version.
- If length > 3 and `B[3] != B[1]`, the host warns about firmware/hardware mismatch and **replaces its local hardware-revision byte with B[3]**. `B[3]` is therefore interpreted as the firmware's target hardware revision, not a second firmware version.
- The CLI version displayed is a local constant approximately **3.1**, not received from USB.

Fan count is based on that possibly replaced raw revision byte (`0x401aa7–0x401b04`): ≤4 → 6 fans; 5/6/7 → 18; 8/9 → 9; 12 → 12. Other values retain the initialized count of zero. This dispatch uses raw bytes, even though display divides by ten.

Request `0x06` (`0x401ca1–0x401ced`): mode = `B[0]`; short timeout = `3*B[3]`; long timeout = `3*B[5]`; reset counter = `B[7]`. Odd intervening bytes are not interpreted by this decoder. Minimum bytes needed: **8**.

Watchdog setter `0x07`: long values **1..59 are raised to 60** (`0x404645–0x404657`); zero remains zero. The signed multiply/shift sequence at `0x404661–0x40467f` implements division by 60; representative nonnegative boundary tests confirmed this independently. wIndex is the **sum** `0x6400 + floor(long/60)`, not an explicitly masked high/low-byte packing. Very large values can carry into the nominal high byte before 16-bit truncation. The short argument passes unchanged as wValue. Getter scaling does not prove firmware setter units or allowable limits.

### Fan and simple sensors

PWM byte decodes: `0x402a61` and `0x402aea`. RPM word decodes: `0x4029af–0x4029db`, `0x402b76–0x402ba2`. Percent output is current RPM × 100 / maximum RPM (`0x402be3–0x402c15`); the decoder does not guard a zero denominator.

Temperature sign extension is explicit at `0x401b66–0x401b69`. Voltage sign extension and scale are at `0x401bf0–0x401c00`; the double constant is stored at `0x4a1088`. These are the **host's** units/conversion, not independently calibrated sensor behavior.

### OCTO 2000W PSU (`0x10`)

All entries are unsigned LE16; minimum decoded length **18 bytes**. Decoder: `0x401d72–0x401f44`.

| Offset | Quantity | Multiplier | Decoder evidence |
|---:|---|---:|---|
| 0 | AC voltage | 0.1 | `0x401ef4–0x401f1c` |
| 2 | AC current | 0.1 | `0x401ec3–0x401eeb` |
| 4 | AC power | 0.5 | `0x401e92–0x401eba` |
| 6 | DC voltage | 0.025 | `0x401e62–0x401e8e` |
| 8 | DC current | 0.025 | `0x401e32–0x401e5e` |
| 10 | DC power | 0.1 | `0x401e02–0x401e2e` |
| 12 | temperature 1 | 0.025 | `0x401da2–0x401dce` |
| 14 | temperature 2 | 0.025 | `0x401dd2–0x401dfe` |
| 16 | temperature 3 | 0.025 | `0x401d72–0x401d9e` |

### PSMI-compatible PSU (`0x12`)

Minimum decoded length **26 bytes**. Word fields are unsigned LE16; energy is unsigned LE32. Decoder `0x402449–0x40272f`:

| Offset | Quantity | Multiplier | Decoder evidence |
|---:|---|---:|---|
| 0 | AC voltage | 1/32 | `0x40265a–0x402682` |
| 2 | AC current | 1/64 | `0x402629–0x402651` |
| 4 | AC power | 1 | `0x402608–0x402624` |
| 6 | DC voltage | 1/256 | `0x4025d7–0x402603` |
| 8 | DC current | 1/64 | `0x4025a6–0x4025d2` |
| 10 | DC power | 1 | `0x402585–0x4025a1` |
| 12 | temperature 1 | 1/64 | `0x402555–0x402581` |
| 14 | temperature 2 | 1/64 | `0x402525–0x402551` |
| 16 | fan RPM | 1 | `0x402505–0x402521` |
| 18 | peak AC power | 1 | `0x4024e5–0x402501` |
| 20 | peak DC current | 1/64 | `0x4024b5–0x4024e1` |
| 22 | accumulated energy, displayed kWh | 0.000000139 | `0x402449–0x4024b1` |

### PMBus PSU (`0x15`)

`N = B[0]`. The model string starts at `B+1`. The first telemetry word begins at **B[N+2]**, not at a fixed offset. The string's actual termination is assumed by the host; N plausibly measures model length, but the precise firmware convention is **Medium** confidence. Minimum bytes needed for all metrics: **N+20**. Decoder: `0x401fdf–0x4023b8`.

| Relative offset from N | Quantity | Conversion | Call evidence |
|---:|---|---|---|
| +2 | AC voltage | host LINEAR11 helper | `0x4022b7` |
| +4 | AC current | host LINEAR11 helper | `0x402264` |
| +6 | AC power | host LINEAR11 helper | `0x402213` |
| +8 | DC voltage | model-dependent VOUT helper | `0x4021c2` |
| +10 | DC current | host LINEAR11 helper | `0x402163` |
| +12 | DC power | host LINEAR11 helper | `0x402112` |
| +14 | temperature 1 | host LINEAR11 helper | `0x4020c1` |
| +16 | temperature 2 | host LINEAR11 helper | `0x402070` |
| +18 | fan RPM | host LINEAR11 helper | `0x40201f` |

Each word is LE16. The helper at `0x401021` returns NaN for `0xffff`; otherwise it computes `(word & 0x07ff) * 2^(signed16(word) >> 11)` (`0x401044–0x401074`). **It does not sign-extend the 11-bit mantissa.** Preserve this distinction when reproducing CLI behavior; interpreting it as a fully signed LINEAR11 decoder would change negative readings.

The VOUT helper at `0x40107b` also maps `0xffff` to NaN. It compares the model against **DPS1200MBA** (`0x4010a2–0x4010b7`): matching model uses unsigned word × **1/512**, others × **1/4096** (`0x4010b9–0x4010df`; constants `0x4a1074`, `0x4a1078`). No VOUT_MODE exponent is decoded here.

### BME280 climate (`0x13`)

Minimum decoded length **12 bytes**. **Big-endian**, unlike PSU telemetry. All three assembled values are zero-extended unsigned dwords:
- Temperature = `BE32(B+0) * 0.01` (`0x4028b6–0x40291a`). No signed conversion is performed.
- Humidity = `BE32(B+4) * 0.000976562` (`0x40284a–0x4028b2`); this is the actual stored approximate multiplier, not exactly 1/1024.
- Pressure = `BE32(B+8) * 0.01` (`0x4027de–0x402846`), displayed as hPa.

Negative-temperature handling and actual sensor calibration cannot be established from this unsigned host decoder.

## 4. OLED command packing (`0x11`)

Option dispatch parses x/y/flag at `0x4017dd–0x401839`. DWARF identifies these locals as oled_x, oled_y, oled_flag. On the later value option:
- Flag > 3: send **wValue = flag << 8**, **wIndex = 0**, once (`0x401559–0x401594`). Flag 4 is intended to erase stored display contents; other >3 values are not validated here.
- Flags 1 or 3: per character i, **wIndex = (y << 8) OR (x + 2*i)**; call `0x4016a6`.
- Other flags ≤3: per character i, **wIndex = (y << 8) OR (x + i)**; call `0x401722`.
- Both per-character paths set **wValue = (flag << 8) OR sign_extend(character)** (`0x401668–0x401677`, `0x4016e4–0x4016f3`). For ASCII this is a clean high-byte flag / low-byte character encoding. For bytes ≥0x80, sign extension can force the high byte to 0xff after wire truncation.
- The byte 0xc2 causes a one-byte increment of the global argument pointer (`0x40160d–0x40161f`), apparently an ad hoc UTF-8 treatment, not general Unicode handling.

Flags 0/2 imply small text; 1/3 imply large text; 2/3 imply persistence. These meanings are **Medium** confidence from CLI intent. Encodings and loops are **High**. The apparent coordinate packing is not masked: oversized x can alter the high byte. Responses are not interpreted beyond checking for a negative transfer result.

## 5. Bootloader exit: separate protocol identity

Only the initial exact `-bx` branch opens USBasp identity. It sends this sequence, each with `0xc0`, 256-byte maximum response, 5000 ms timeout:

| Order | bRequest | wValue | wIndex | Call | Host handling |
|---:|---:|---:|---:|---|---|
| 1 | `0x01` | 0 | 0 | `0x401208` | negative return is fatal |
| 2 | `0x7f` | 0 | 0 | `0x40128f` | **any nonzero return**, including positive length, is fatal |
| 3 | `0x03` | `0xffff` | `0xffff` | `0x401316` | negative return is fatal |
| 4 | `0x02` | 0 | 0 | `0x40139d` | return stored but not validated before success message |

Wire sequence: **High**. Overall intent to leave the bootloader: **Medium**. Individual USBasp operation names and actual reset behavior are not established by this host-only analysis. The final message does not verify re-enumeration or application startup.

## 6. Limitations and implementation cautions

1. **Do not classify by transfer direction alone.** The normal IN-direction requests include reset, shutdown, bootloader entry, fan calibration, EEPROM/display-related operations, PWM changes, and watchdog configuration.
2. **Host parsing is not a response-length contract.** Serial/version paths often only reject negative returns; several simple sensor/fan paths decode without checking the return at all. PSU/climate paths generally require only a positive length, not the full layout size. Buffer at `[rbp-0x120]` is reused. A replacement decoder should require the minimum lengths listed above, bound N, and bound model-string termination before parsing.
3. No verified acknowledgment payloads, actual device response lengths, EEPROM persistence guarantees, permitted ranges, firmware state machines, USB speed, polling requirements, or electrical behavior were recovered. Unused requests may exist in firmware.
4. The numeric device indices are zero-based in host loops. Hardware-dependent fan count is inferred from revision bytes rather than directly requested as a count.
5. This is a host-side protocol reconstruction, **not a recommendation or authorization to issue any request**. Firmware comparison and separately authorized controlled captures would be needed to establish device-side semantics. None were performed here.
