# STM32F401RE
My folder to play with installing an open source toolchain for linux.
I started from this tutorial and I will try to improve it and finally start making my own projects.
http://regalis.com.pl/en/arm-cortex-stm32-gnulinux/

Edit:
I found that I can't follow the exact steps by using the aforementioned
sites instructions so I will add the following steps that work for me.

First of all there was a problem with the define LED_ON function, 
as BSRRLH and BSRRH have been merged in one BSRR.

Therefore change
\#define LED_ON() GPIOA->BSSRL |= (1 << 5)

\#define LED_OFF() GPIOA->BSSRH |= (1 << 5)

to:

\#define LED_ON() GPIOA->BSRR |= (1 << 5)

\#define LED_OFF() GPIOA->BSRR |= (1 << 21)

And then:
instead of running 
telnet localhost 4444 
I run
arm-none-eabi-gdb main.elf

then inside the prompt> run
>target remote localhost:3333

>monitor reset halt

>load 

>continue

Everything else remains in the same exact way as the aforementioned forum post.

The included files now switch the led light (the green LD2) with interrupts from Timer2.
This is done without HAL, just by writing to the registers directly.
