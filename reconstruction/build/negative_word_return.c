/* Clean semantic reconstruction of the captured FW3.0 EEPROM helpers.
 * HOST-SIDE REFERENCE MODEL: not flashable AVR firmware, not cycle accurate.
 * Valid address domain only; assertions are harness guards, NOT original checks.
 * Reset the per-operation trace (writes=0) before each operation.
 */
#include <assert.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t data[1024];
    uint32_t writes;
    uint16_t addresses[2];
    uint8_t values[2];
    uint8_t write_irq[2];
    uint8_t irq;
} ee_model;

size_t ee_model_size(void) { return sizeof(ee_model); }

static void program_byte(ee_model *m, uint16_t address, uint8_t value) {
    assert(address < 1024);
    assert(m->writes < 2);
    const uint8_t saved_irq = m->irq;
    m->irq = 0;
    m->data[address] = value;
    m->addresses[m->writes] = address;
    m->values[m->writes] = value;
    m->write_irq[m->writes] = m->irq;
    ++m->writes;
    m->irq = saved_irq;
}

/* Original entry byte0x3880; address R25:R24, return R24. */
uint8_t ee_read_byte(ee_model *m, uint16_t address) {
    assert(address < 1024);
    return m->data[address];
}

/* Original byte0x3890: block read INTO register aliases0x18/0x19.
 * Ghidra's uncorrected C incorrectly returns address instead of these bytes.
 */
uint16_t ee_read_word(ee_model *m, uint16_t address) {
    assert(address < 1023);
    (void)m;
    return address; /* INTENTIONALLY WRONG negative control */
}

/* Original byte0x389c: read first; changed bytes only enter CLI/strobe window. */
void ee_update_byte(ee_model *m, uint16_t address, uint8_t value) {
    assert(address < 1024);
    if (m->data[address] != value) program_byte(m, address, value);
}

/* Original byte0x38c0: HIGH byte first, then LOW; either may be skipped. */
void ee_update_word(ee_model *m, uint16_t address, uint16_t value) {
    assert(address < 1023);
    ee_update_byte(m, (uint16_t)(address + 1), (uint8_t)(value >> 8));
    ee_update_byte(m, address, (uint8_t)value);
}

/* Original byte0x38f6: unconditional write, even if the cell already matches. */
void ee_write_byte(ee_model *m, uint16_t address, uint8_t value) {
    program_byte(m, address, value);
}

/* Original byte0x38cc: LOW byte first, then HIGH (opposite of update_word). */
void ee_write_word(ee_model *m, uint16_t address, uint16_t value) {
    assert(address < 1023);
    ee_write_byte(m, address, (uint8_t)value);
    ee_write_byte(m, (uint16_t)(address + 1), (uint8_t)(value >> 8));
}
