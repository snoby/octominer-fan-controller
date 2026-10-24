# Offline readback feasibility

**Verdict:** bundled bootloader supports flash reads; installed FW3.0/BL2.0 remains unverified. All addresses are flash bytes, except explicit SRAM/EEPROM addresses. No rig contact or firmware/CLI execution occurred.

- **Request4:** 09 setup 0x75fe–0x7630 copies wValue as byte address into SRAM0x010d/e; saves wLength-low. IN streaming 0x7856–0x78a8 reads program memory at 0x788e and increments address. No software 0x7000 read boundary exists; the 0x7774–0x777a boundary protects writes only. Hardware boot-lock restrictions remain unknown; stay within physical 0x0000–0x7fff.
- **Lengths:** 0x7618 and 0x770e–0x771e effectively retain wLength-low; 0x7824–0x7834 sends eight-byte packets. Low-byte255 collides with 0xff sentinel; length256 becomes zero. Use 1–254-byte requests, preferably eight bytes; larger lengths truncate.
- **Request3:** helper 0x741a–0x74b4 returns synthetic signature1e9517 from initialized SRAM, not silicon identification. Fuse/lock selectors 0x50/0x58 use 0x745c–0x7462 special reads; unsupported commands return zero. Legacy flash opcodes0x20/0x28 also read without boundary checks.
- **Entry/exit:** bundled application request0x93 reaches EEPROM0x93 marker write and watchdog reset at 0x278c–0x27a6. Boot consumes marker at 0x750a–0x751a; disables watchdog at 0x7554–0x756a. Request1 holds boot state; request2 releases it (0x7632–0x7640). Request3 opcode0xff sets exit countdown (0x74a8–0x74ae); eventual exit calls application0x0000 at 0x754c.
- **Cross-check:** 07 equivalents agree; binary/disassembly comparisons found zero mismatches.

**Safest next step:** obtain actual BL2.0 image/source offline before authorizing maintenance-window entry/readback. Normal application request4 changes PWM, not flash reads.
