# Installed Octominer firmware 3.0: acquired and verified

## Result
Actual controller flash readback from `cmp-100` / `192.168.2.106`, NOT the older filesystem update images.

- Physical address range requested: **0x0000–0x7fff**, **32,768 bytes** per pass.
- Two separate complete reads match **byte-for-byte**.
- SHA-256 of each read: `186930d0fe8e4caa6fa2873e151225df6c7d1a6f6c4811a82601b113f65c6ddf`.
- The remote files' SHA-256 and copied local files' SHA-256 agree.
- Before entry and after restoration, the application returned raw version bytes **1e 0c 14 0c**: FW3.0 / HW1.2 / BL2.0 / target HW1.2.
- Static corroboration in the acquired flash: request0x0a's branch at byte0x23f4 leads to version handler0x23fc, which places constant0x1e (30, displayed3.0) in the first response byte; target HW constant0x0c appears at0x241a. This agrees with the live response.
- AVR vector table has51 entries; reset vector points to byte0x438.
- Application and USBasp boot descriptors and strings are present, not a uniform/blank response. Boot-region0x7000–0x7fff has235 distinct byte values. The recovered bytes differ from both older packaged images.

Verification here establishes a repeatable readback from the identified controller and agreement with its version handler. It is not manufacturer signature/authenticity validation, and a hardware-independent programming-probe comparison was not performed.

## Authorized maintenance
The user explicitly authorized stopping mining/controller services, switching only the fan controller into bootloader mode, read-only flash acquisition, then restoring operation. No host reboot, flash erase/program, fuse write, or protection change was performed.

The controller's boot-entry command internally changes its boot marker and resets the MCU; this is mode switching, not a flash-programming operation. Do not describe the entire maintenance procedure as free of all device state changes.

### Successful acquisition (UTC)
- 2026-10-24 01:36:35: mining stopped; all GPUs idle, hottest51C. Original controller shells paused after active CLI children finished.
- 01:36:35–37: boot entry sequence; device changed to USBasp identity. Five requests sufficed before disconnect.
- 01:36:37–44: two full flash reads, using request4 in8-byte chunks only in verified USBasp mode.
- 01:36:45: application returned with unchanged3.0/1.2/2.0 version report.
- 01:36:45–51: original controller shells resumed; fan RPM confirmed.
- 01:36:53: mining start requested.

Times correspond to October23 evening EDT. Raw timestamps and events are retained in report.json.

### Failed attempts retained honestly
1. A single boot-entry request did not switch modes. No flash read was issued; controller/mining restoration completed. Offline tracing then confirmed the five-request entry gate used by vendor CLI's up-to-ten-request sequence.
2. A retry aborted before entry because transient bash command-substitution processes shared their parent's argv. Selection was corrected to the original session-leader shells. Controller/mining restoration completed.
3. The successful attempt above acquired both complete copies and restored operation.

## Restoration checks
- Controller original shell PIDs1036 and3124 resumed, not replaced/restarted.
- All12 startup-PWM and max-RPM settings returned by the application matched before/after.
- Raw watchdog status before/after/restored matched exactly: `0202642800f40118`.
- Restored nonzero tach channels reported4640,4710,4700,4700RPM. Zero unused channels are retained in raw snapshots rather than omitted.
- Subsequent live verification: all five GPUs back at100% utilization,48–54C at that observation. onezerominer log reported312.39TH/s and one accepted share, zero rejected/stale in the displayed table. This is a point-in-time restoration check, not a long-duration stability claim.
- Host uptime remained over536,000seconds; host was not rebooted.

## Artifacts
Original remote capture directory: `/home/user/octominer-readback/capture-20261024T013632Z`.

Local originals: `artifacts/installed-3.0/firmware-3.0-pass1.bin`, `firmware-3.0-pass2.bin`, `report.json`, `before.json`, `after.json`, `restored.json`.

Canonical deliverable: `artifacts/installed-3.0/octominer-fw3.0-hw1.2-flash.bin`, byte-identical copy of pass1.

Derived offline analysis: `analysis/installed-3.0-validation.json`, `analysis/installed-3.0-disassembly.txt`. LLVM atmega324p was used as an instruction-set decoder; PB peripheral interpretation still requires the PB datasheet.

Acquisition code and five passing tests: `analysis/acquire_installed_flash.py`, `analysis/readback_core.py`, `analysis/test_readback_core.py`. Scripts contain no flash/fuse programming operation. These are evidence of this authorized run, not permission for future live interruptions.
