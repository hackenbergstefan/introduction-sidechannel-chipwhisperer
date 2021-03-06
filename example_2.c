#include "hal.h"
#include "simpleserial.h"
#include <stdint.h>
#include <string.h>

const uint8_t stored_password[] = "infineon";

uint8_t check_password(uint8_t cmd, uint8_t scmd, uint8_t len, uint8_t *input)
{
    trigger_high();

    uint8_t password_correct = 1;
    for (unsigned int i = 0; i < sizeof(stored_password) - 1; i++)
    {
        if (stored_password[i] != input[i])
        {
            password_correct = 0;
            break;
        }
    }

    trigger_low();

    simpleserial_put(0x01, 1, &password_correct);
    return 0;
}

int main(void)
{
    platform_init();
    init_uart();
    trigger_setup();

    simpleserial_init();
    simpleserial_addcmd(0x01, 0, check_password);
    while (1)
        simpleserial_get();
}