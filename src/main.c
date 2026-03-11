#include "drivers/gpio/gpio.h"
#include "drivers/timer/timer0.h"
#include "bsp/nano.h"
#include "utils/delay.h"

int main(void) {
    //2.Counter pe LED-uri: foloseste 4 LED-uri ca afisare binara pentru un contor 0...15.
    Timer0_Init();
    GPIO_Init(B10,GPIO_OUTPUT);
    GPIO_Init(B11,GPIO_OUTPUT);
    GPIO_Init(B12,GPIO_OUTPUT);
    GPIO_Init(B13,GPIO_OUTPUT);
    uint8_t i;
 
    while (1) {
        for (i = 0; i < 16; i++) {
            GPIO_WritePin(B10, (i >> 0) & 1);
            GPIO_WritePin(B11, (i >> 1) & 1);
            GPIO_WritePin(B12, (i >> 2) & 1);
            GPIO_WritePin(B13, (i >> 3) & 1);
            Delay_ms(1000);
        }

    }
}