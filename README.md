# Octominer controller deconstruction

## Decompiled3.0 program and functional guide
Genuine Ghidra12.2 output and a native importable program are under `decompiled/`. See `FUNCTIONS.md` for the human-readable behavioral guide and limitations. All122 discovered entries produced pseudocode (51vector stubs plus71other entries); successful decompilation is not a semantic-completeness claim. Byte-for-byte project-memory verification matches the acquired flash hash. Evidence reports are `analysis/FW3-USB.md`, `FW3-CONTROL.md`, and `FW3-PERIPHERALS.md`. Detailed3.0 analysis was offline; no new rig access/interruption occurred.

## Current result: installed firmware3.0 acquired
The actual controller flash has now been read twice during an explicitly authorized maintenance window:32768bytes each, identical SHA-256 `186930d0fe8e4caa6fa2873e151225df6c7d1a6f6c4811a82601b113f65c6ddf`. Originals are under `artifacts/installed-3.0/`; see `INSTALLED-3.0-READBACK.md` for verification, restoration and limitations. The controller returned to FW3.0 and mining was verified active afterward. The remaining sections describe the earlier acquisition/analysis of older bundled update images and should not be mistaken for a complete3.0 behavior map.

## Initial acquisition
Read-only file copy from user@192.168.2.106 (host cmp-100, HiveOS Linux 6.10.0-hiveos). Nine files copied from /hive/opt/octofan; SHA-256 of every local artifact matched the remote copy. Cached sysfs attributes were read without running the vendor CLI or a programmer. No restart, reset, fan adjustment, firmware write, debug attach or bootloader command was performed.

IMPORTANT: these are firmware UPDATE FILES on the rig's filesystem, NOT a dump of the firmware currently executing in controller flash. The copied update log says FW 3.0 / HW 1.2, but the wrapper's two bundled images correspond to older releases (1.1/1.6). The log is cached, not a fresh controller query. Do not flash either bundled image to this board on that evidence.

## Confirmed first-pass results
- USB sysfs: 16c0:05dc, manufacturer info@octominer.com, product Fan-Controller, bcdDevice 0100.
- fan_controller_cli: x86-64 statically linked ELF with debug_info, not stripped. DWARF reports GNU C11 GCC7.5.0, -g3 -O0. This is a valuable protocol reference; do not execute it before auditing startup/recovery.
- Wrapper active update command selects m324pb (ATmega324PB); commented older m328pb commands do not prove that part is present.
- Each image has 51 leading AVR JMP vectors, agreeing with the ATmega324PB vector-table length. This strongly corroborates the firmware target; physical chip identity on this specific board is not established.
- Both images contain two device descriptors using 16c0:05dc: application descriptor bcdDevice0100; upper-region descriptor bcdDevice0102.
- Application USB product string is Fan-Controller; upper-region product is USBasp, manufacturer www.fischl.de. Same VID/PID does not distinguish modes; descriptor strings/control flow matter.
- Motorola S-records despite .hex extension. Every record length/checksum validated. Sparse segments must be preserved rather than mistaken for contiguous code.

| Image | Data actually present | Lower segment inclusive | Upper segment inclusive | S9 start |
|---|---:|---|---|---|
| firmware_07 | 12,840 bytes | 0x0000–0x28ab | 0x7000–0x797b | 0x7000 |
| firmware_09 | 14,186 bytes | 0x0000–0x2dc5 | 0x7000–0x79a3 | 0x7000 |

The upper segment is a strong bootloader candidate, independently supported by its USBasp strings and S9 start. Exact fuse-selected boot region on the actual board remains unverified. Derived linear binaries explicitly use 0xff for gaps; gap bytes were not supplied by the images.

## Safety-significant CLI constants (strings; call-site validation needed)
USB_RESET_WATCHDOG=0, USB_READ_FAN_DEFAULT=1, USB_WRITE_FAN_DEFAULT=2, USB_READ_FAN_RPM=3, USB_WRITE_FAN_PWM=4, USB_WRITE_LED=5, USB_READ_WATCHDOG=6, USB_WRITE_WATCHDOG=7, USB_READ_TEMPERATURE=8, USB_READ_FAN_PWM=9, USB_READ_VERSION=10, USB_READ_SERIAL_NUMBER=11, USB_AUTHENTICATE_DEVICE=12, USB_TEST_NEW_FANS=13, USB_READ_FAN_MAX_RPM=14, USB_WRITE_FAN_MAX_RPM=15, USB_READ_2000W_METRICS=16, USB_WRITE_OLED_CHAR=17, USB_READ_PSMI_METRICS=18, USB_READ_BME280=19, USB_READ_VOLTAGE=20, USB_READ_PMBUS_METRICS=21, USB_RESET_RIG=145, USB_POWERDOWN_RIG=146, USB_ENTER_BOOTLOADER=147.

These are candidate protocol identifiers from the CLI's debug macro strings, not a permission to issue requests. USB transfer direction alone does not establish absence of device side effects.

## Analysis artifacts
- artifacts/192.168.2.106/: originals, including firmware files, CLI, wrapper and cached update log.
- analysis/manifest.json and remote-sha256.txt: integrity verification.
- analysis/acquisition.txt: source and cached USB identity.
- analysis/analyze_images.py: checksum validator, addressed parser, AVR vectors/string extraction and LLVM disassembly builder; it performs local-only operations.
- analysis/images.json: addressed segments, vectors, strings and device descriptor candidates.
- analysis/firmware_07-disassembly.txt and firmware_09-disassembly.txt: actual LLVM AVR disassembly. atmega324p selected as available ISA decoder, not an exact PB peripheral model; data/gaps may appear as instructions and are not automatically code.
- analysis/cli-dwarf.txt, cli-symbols.txt, cli-disassembly.txt and cli-usb-constants.txt: actual host binary static analysis.
- analysis/PROTOCOL.md and SAFETY-AUDIT.md: completed host-side protocol reconstruction and safety audit. Parent spot-checks confirmed the PWM/reset/bootloader/watchdog transfer arguments and wrapper recalibration branch against actual disassembly/script lines.
- analysis/FIRMWARE-MAP.md: completed first-pass firmware-function analysis. Parent spot-checks confirmed startup EEPROM loads, grouped live PWM writes and calibration register/countdown writes against the instructions.

## Host-side reconstruction results
The application encodes state-changing requests as vendor IN control transfers (bmRequestType 0xc0), with command parameters in wValue/wIndex. Thus an IN request is NOT inherently read-only. Verified PWM call at ELF address 0x4043aa uses bRequest4, wValue=PWM, wIndex=fan, requested response capacity256 and timeout5000ms. Reset/boot entry use requests0x91/0x93 at0x402ca9/0x402daf, also vendor IN.

Critical naming trap, confirmed in wrapper lines1263–1264: `octofan -r` means RECALIBRATE, not status. That path sets all12 fan IDs to PWM255 (lines1066–1067) and writes maximum-RPM settings (1091–1093). The separate `fan_controller_cli -r` path is a telemetry path in host code; firmware-side effects remain to be audited, so neither is approved as a live probe.

The host startup audit found no automatic bootloader-exit fallback on the normal status path. Exact first-argument `-bx` is the separate recovery branch. This resolves the earlier uncertainty: the CLI containing recovery code does not mean ordinary status automatically runs it.

## Reference used for architecture corroboration
Microchip ATmega324PB interrupt vector table (saved as analysis/microchip-vectors.html):
https://onlinedocs.microchip.com/oxy/GUID-74F8229E-4C43-4FA0-BE7D-1AA303C6F8A4-en-US-6/GUID-17DC7BA7-6985-4E13-AD56-5F675170DB14.html
Datasheet vector addresses are program word addresses; multiply by two for byte addresses in our disassembly.

## Live version verification
A separately authorized version-only query to the application on cmp-100 returned four bytes `1e 0c 14 0c` twice, identically. Decoded using the statically recovered CLI format: firmware3.0, hardware1.2, bootloader2.0, firmware target hardware1.2 (matches). Evidence: analysis/live-version.json; exact reader: analysis/read_live_version.py. Acquisition timestamp: 2026-10-24T01:20:22.831261+00:00 (October23 evening EDT).

Only vendor version request0x0a was submitted, twice, during that initial query. No wrapper/CLI execution, USB reset/claim/detach, fan-setting, watchdog-setting, or bootloader-entry request was performed by that reader. The initial query confirmed the device's self-reported version, NOT installed code. The later authorized readback is documented separately in `INSTALLED-3.0-READBACK.md`.

## Still not verified
Physical MCU marking; lock bits/fuses/EEPROM as a complete image; complete3.0 request/function semantics; general live request compatibility; live watchdog timing; actual fan pin mapping. Installed flash has been acquired repeatably, but vendor signature/authenticity was not established. No claim of recovered original source or a tested replacement controller client.
