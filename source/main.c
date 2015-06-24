#include <kernel.h>

void _start() __attribute__ ((section (".init")));
int main();

void _start(){
        asm("mov sp, #0x8000");         /* Setup stack pointer */
        main();
}

int main(){
        /* Morse code, 0 for turn off LED, 1 for turn on LED */
        int pattern = 0b11111111101010100010001000101010;
        int seq = 0;
        int code;

        SetGpioFunction(16, 1);         /* Enable 16th GPIO pin */

        while(1){
                code = pattern & (1 << seq);
                SetGpio(16, code);         /* Turn on/off the light */
                seq++;
                seq &= 0b11111;         /* Reset q to 0 if it reaches 32 */
                Wait(250000);
                
        }
}
