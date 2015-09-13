main: main.o system.o startup_stm32f401xe.o serial.o gpio.o timer.o
	arm-none-eabi-gcc -g -mcpu=cortex-m4 -mlittle-endian -mthumb -D STM32F401xE -T STM32F401RE_FLASH.ld -Wl,--gc-sections system.o main.o startup_stm32f401xe.o gpio.o timer.o -o main.elf

startup_stm32f401xe.o: startup_stm32f401xe.s
	arm-none-eabi-gcc -g -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -I ~/embedded/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I ~/embedded/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Include -D STM32F401xE -Os -c startup_stm32f401xe.s -o startup_stm32f401xe.o

system.o: system.c
	arm-none-eabi-gcc -g -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -I ~/embedded/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I ~/embedded/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Include -D STM32F401xE -Os -c system.c -o system.o

	
serial.o: serial.c	
	arm-none-eabi-gcc -g -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -I ~/embedded/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I ~/embedded/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Include -D STM32F401xE -Os -c serial.c -o serial.o


main.o: main.c	
	arm-none-eabi-gcc -g -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -I ~/embedded/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I ~/embedded/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Include -D STM32F401xE -Os -c main.c -o main.o

timer.o: timer.c
	arm-none-eabi-gcc -g -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -I ~/embedded/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I ~/embedded/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Include -D STM32F401xE -Os -c timer.c -o timer.o

gpio.o: gpio.c
		arm-none-eabi-gcc -g -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -I ~/embedded/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I ~/embedded/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Include -D STM32F401xE -Os -c gpio.c -o gpio.o




