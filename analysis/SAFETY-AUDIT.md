# Offline host safety audit

## Verdict

**NO-GO for new live CLI/wrapper invocations under the no-reset/no-interruption constraint.** Bare `fan_controller_cli -r` has no explicit host-side EEPROM write, watchdog configuration/reset, bootloader entry, rig reset, or power-down command. That is not proof its vendor-IN requests are side-effect-free in firmware. `octofan -r` is entirely different: it recalibrates and writes settings.

Scope: static inspection of copied disassembly, DWARF, symbols, wrapper, and read-only ELF string/jump-table decoding. No target executable or wrapper executed, no rig contacted, no tools installed. Addresses below are host virtual code addresses, not AVR addresses. Firmware-side request semantics and actual watchdog expiry behavior remain unverified.

## Findings (five)

### 1. Bare CLI status is bounded telemetry, not an automatic recovery routine

At `0x4013d1–0x401410`, normal startup opens VID:PID 16c0:05dc with manufacturer/product string matching; failure exits, rather than falling back to USBasp or resetting USB. Device discovery/string reads occur before option parsing. The dispatch table sends `-r` to `0x401844`; the handler ends with close/return-zero at `0x402c51–0x402c65`, bypassing deferred setter/watchdog processing.

Status issues vendor/device IN (`bmRequestType=0xc0`) requests, each requesting 256 bytes with a 5000 ms timeout: 0x0b serial, 0x0a versions; four indexed 0x08 and four 0x14 sensor reads; 0x06, 0x10; eight indexed PSU iterations using 0x15 and conditionally 0x12; two indexed 0x13 climate reads; and per-fan 0x03, 0x01, 0x09, 0x0e for RPM/startup PWM/current PWM/max RPM. Fan count is derived from the returned hardware revision (6, 18, 9, or 12; otherwise zero). Calls include `0x401877`, `0x40197b`, `0x401b50`, `0x401bda`, `0x401c64`, `0x401d25`, `0x401f92`, `0x4023fc`, `0x402791`, `0x4029a0`, `0x402a52`, `0x402adb`, `0x402b67`.

Several reads consume the reusable buffer without validating success or minimum length (e.g. `0x401b59–0x401b80`, `0x402ae4–0x402b08`). Errors can therefore yield stale/invalid telemetry and still return zero. Wrapper lines 724–736 accept output based on one serial marker, not complete telemetry; they retain stale output until over 50 failures. No recovery/reset is present in that function. An IN direction does not establish firmware read-only behavior.

### 2. Wrapper status-looking aliases and startup can modify persistent configuration

`octofan -r` selects recalibration at wrapper lines 1263–1264, not CLI status. Lines 1055–1108 edit configuration, drive all 12 fan IDs to PWM 255, sample repeatedly, and write every max-RPM setting, including zero when no sample exists. CLI `-m` sends request 0x0f at `0x404514`; startup-PWM `-d` sends request 0x02 at `0x40445f`. These are configuration-write paths; host code alone cannot prove the EEPROM layout/endurance behavior.

Wrapper lines 118–134 explicitly erase/save OLED EEPROM. CLI OLED flags are encoded into request 0x11 (`0x401594`, `0x4016a6`, `0x401722`): flags 2/3 save text, flag 4 selects erase. Neither EEPROM operation is needed for offline analysis.

### 3. Watchdog controls are explicit, not silently appended to status

`-s` sends request 0x00 at `0x402e26` and returns zero even after a negative transfer. `-w short -v long` reaches `0x40462b–0x40472f`: both values must be nonnegative; long values 1–59 become 60; request 0x07 uses `wValue=short`, `wIndex=0x6400+floor(long/60)` at `0x4046ba` (USB fields truncate to 16 bits). There are no upper-bound checks. Failed configuration still returns zero. Do not infer safe disable semantics from zero values or infer expiry timings/actions from the host alone. Status `-r` exits before this block and does not explicitly feed/configure the watchdog. Do not interrupt the existing control loop or experiment with these options.

### 4. Reset/bootloader paths tolerate failure and are not observational

`-x`, `-p`, and `-b` send requests 0x91, 0x92, and 0x93 respectively at `0x402ca9`, `0x402d2c`, `0x402daf`. Each loops up to ten transfers, stops on a negative result, then returns zero regardless; exit status does not establish success.

Only an exact first argument `-bx` takes `0x401160–0x4013cc`: it opens the USBasp string identity on the same VID:PID, sends requests 0x01, 0x7f, 0x03 (`wValue=wIndex=0xffff`), then 0x02, at `0x401208`, `0x40128f`, `0x401316`, `0x40139d`. The first and third require nonnegative returns; 0x7f requires exactly zero; the final return is not checked. It then reports apparent success and exits zero without re-opening/verifying the application. This is bootloader exit/recovery, not a readback or dump. No automatic `-bx` fallback exists in ordinary CLI startup.

### 5. Wrapper firmware recovery can resume mining despite failure

Wrapper `run` invokes automatic version-based update checks at lines 1248–1256 and 1113–1138; no-argument/dontattach can launch `run` (1265–1284). After checksum validation, update stops mining, enters bootloader, flashes through avrdude, retries flashing once, and unconditionally attempts `-bx` (950–988). CLI's false-success bootloader return weakens its gate. The wrapper proceeds to status/version check, restarts mining, and recalibrates even when its error flag is set (995–1024). Its maintenance file expires after 60 seconds (1146–1157), is not an exclusive lock, and does not prevent every status read (724–737). It cannot guarantee safe exclusion during a stalled update. Active flash commands write flash, not explicit fuse/EEPROM regions; commented fuse commands are not executed. Flashing still risks firmware/EEPROM consequences that this host-only audit cannot resolve.

## Exact safe next step

**Leave the live rig, existing service, USB connection, and watchdog state untouched. Continue offline only: map the copied AVR firmware's USB setup dispatch for requests 0x00, 0x01–0x15, 0x7f, and 0x91–0x93; trace every EEPROM write, watchdog instruction/configuration, and reset/power/boot transition before approving any live command. Do not run either CLI or wrapper, including status, recalibration, or recovery.**
