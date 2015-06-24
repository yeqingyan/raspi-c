#ifndef __KERNEL__
#define __KERNEL__

/* gpio.c */
int GetGpioAddress();
void SetGpioFunction(int, int);
void SetGpio(int, int);

/* systemTimer.c */
int GetSystemTimerBase();
int GetTimeStamp();
void Wait(int);
#endif
