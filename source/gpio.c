int GetGpioAddress() {
        return 0x20200000;
}

void SetGpioFunction(int pin, int function) {
        if(pin > 53)    goto ERROR;     /* Check pin between 0 to 53 */
        if(pin < 0)     goto ERROR;
        if(function > 8) goto ERROR;    /* Check function between 0 to 7 */
        if(function < 0) goto ERROR;    
        
        int* gpio_addr = (int *)GetGpioAddress();
        
        gpio_addr += pin / 10;  /* Find gpio address */

        function = function << (pin % 10 * 3);
        int mask = 7 << (pin % 10 * 3); /* Create mask */
        mask = ~mask;
        
        int gpio_val = *gpio_addr;      /* Got old bit set */
        gpio_val = gpio_val & mask;
        gpio_val = gpio_val ^ function; /* Got final bit set */
        
        *gpio_addr = gpio_val;

ERROR:  return;
}

void SetGpio(int pinNum, int pinVal){
        if(pinNum > 53) goto ERROR;
        if(pinNum < 0) goto ERROR;

        int* gpio_addr = (int *)GetGpioAddress();

        if (pinNum >= 32)
                gpio_addr += 1;
        
        int bitValue;
        bitValue = 1 << (pinNum % 32);

        if (pinVal == 0) {
                *(gpio_addr + 10) = bitValue;   /* Turn off pin */
        } else {        
                *(gpio_addr + 7) = bitValue;    /* Turn on pin */
        }
         
ERROR:  return;
}
