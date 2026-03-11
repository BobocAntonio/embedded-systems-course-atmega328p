#include "drivers/gpio/gpio.h"
#include "drivers/timer/timer0.h"
#include "bsp/nano.h"
#include "utils/delay.h"

int main(void) {
    //1. Blink configurabil: LED-ul clipeste la 3 frecvente configurate in cod.
    Timer0_Init();
    GPIO_Init(LED_BUILTIN, GPIO_OUTPUT);

    int perioade[] = {1000,2000,3000}; // in ms
    uint32_t last_value = 0;
    uint8_t index = 0;
    while (1) {
        if(Millis() - last_value >= perioade[index]) {
            GPIO_Toggle(LED_BUILTIN);
            last_value = Millis();
            index = (index + 1) % 3;
        }

    }
}