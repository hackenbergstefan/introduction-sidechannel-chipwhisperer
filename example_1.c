#include "hal.h"
#include "simpleserial.h"
#include <stdint.h>
#include <string.h>

uint8_t hello(uint8_t cmd, uint8_t scmd, uint8_t len, uint8_t *buf)
{
    trigger_high();

    simpleserial_put(0x01, 12, "hello world.");

    trigger_low();
    return 0;
}

int main(void)
{
    platform_init();
    init_uart();
    trigger_setup();

    simpleserial_init();
    simpleserial_addcmd(0x01, 0, hello);
    while (1)
        simpleserial_get();
}