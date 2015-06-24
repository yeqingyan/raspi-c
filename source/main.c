#include <kernel.h>

void _start() __attribute__ ((section (".init")));
int main();

void _start(){
        asm("mov sp, #0x8000");         /* Setup stack pointer */
        main();
}

int main(){
        int i;
        SetGpioFunction(16, 1);         /* Enable 16th GPIO pin */

        while(1){
                SetGpio(16, 0);         /* Turn on the light */
                
                i = 0x3f0000;
                while(i !=0) i--;
                
                SetGpio(16, 1);         /* Turn off the light */
                
                i = 0x3f0000;
                while(i !=0) i--;
        }
}
