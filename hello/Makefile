## Name of executable
#
#ELF=$(notdir $(CURDIR)).elf
#
## Tool path
#
#TOOLROOT=~/
#
## Library path
#
#LIBROOT=~/
#IDIR=
#Declare the folders that I need to include
CIDIR=~/embedded/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include ~/embedded/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Include
#Declare your compiler here
CC=arm-none-eabi-gcc
#Flags to compile 
#Flags to compile c files
CFLAGS=-g -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -DSTM32F401xE -Os
#Extra flags to create the ELF file
EXTRA_FLAGS=-TSTM32F401RE_FLASH.ld -Wl,--gc-sections
#Declare all objects for the linker
OBJ=startup_stm32f401xe.o system.o serial.o gpio.o timer.o main.o

all: main.o system.o startup_stm32f401xe.o serial.o gpio.o timer.o 
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) system.o main.o startup_stm32f401xe.o gpio.o timer.o -o main.elf

startup_stm32f401xe.o: startup_stm32f401xe.s
	$(CC) $(CFLAGS) $(CIDIR) -c startup_stm32f401xe.s -o startup_stm32f401xe.o

system.o: system.c
	$(CC) $(CFLAGS) $(CIDIR) -c system.c -o system.o

	
serial.o: serial.c	
	$(CC) $(CFLAGS) $(CIDIR) -c serial.c -o serial.o


main.o: main.c	
	$(CC) $(CFLAGS) $(CIDIR) -c main.c -o main.o

timer.o: timer.c
	$(CC) $(CFLAGS) $(CIDIR) -c timer.c -o timer.o

gpio.o: gpio.c
	$(CC) $(CFLAGS) $(CIDIR) -c gpio.c -o gpio.o

#adctemp.o: adctemp.c
#	$(CC) $(CFLAGS) $(CIDIR) -c adctemp.c -o adctemp.o
#



