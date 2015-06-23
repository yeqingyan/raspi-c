int main();

void _start(){
        asm("mov sp, #0x8000");         /* Setup stack pointer */
        main();
}

int main(){
        int *gpio_addr = (int *)0x20200000;
        int cmd = 1 << 18;
        *(gpio_addr + 1) = cmd;         /* Enable 16th GPIO pin */

        cmd = 1 << 16;
        
        int i;

        
        while(1){
                *(gpio_addr + 10) = cmd;        /* Turn on the light */
                
                i = 0x3f0000;
                while(i !=0) i--;
                
                *(gpio_addr + 7) = cmd;         /* Turn off the light */
                
                i = 0x3f0000;
                while(i !=0) i--;
        }
}
