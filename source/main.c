void _start(){
        int *gpio_addr = (int *)0x20200000;
        int cmd = 1 << 18;
        *(gpio_addr + 1) = cmd;         /* Enable 16th GPIO pin */

        cmd = 1 << 16;
        *(gpio_addr + 10) = cmd;        /* Turn the 16th pin off, the light will on */
        while(1);
}
