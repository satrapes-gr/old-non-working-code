
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
#The location where I have saved the STM32CubeF4 folder
STM32CUBEFOLDER=~/embedded/STM32Cube_FW_F4_V1.7.0/
#Declare the folders that I need to include
CIDIR=-I $(STM32CUBEFOLDER)Drivers/CMSIS/Device/ST/STM32F4xx/Include -I $(STM32CUBEFOLDER)Drivers/CMSIS/Include
#Declare your compiler here
CC=arm-none-eabi-gcc
#Flags to compile c files
CFLAGS=-g -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -DSTM32F401xE -Os
#Extra flags to create the ELF file
EXTRA_FLAGS=-TSTM32F401RE_FLASH.ld -Wl,--gc-sections
#Declare all objects for the linker
OBJ=startup_stm32f401xe.o system.o gpio.o timer.o serial.o main.o

all: main.o system.o startup_stm32f401xe.o serial.o gpio.o timer.o 
	@echo "STM32CUBEFOLDER: $(STM32CUBEFOLDER)"
	@echo "Compiler: $(CC)"
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) $(OBJ) -o main.elf

#Compile all c files to object files with same identifier
#e.g. file.c -> file.o
%.o: %.c
	@echo "Compiling $< module..."
	$(CC) $(CFLAGS) $(CIDIR) -c $< -o $@

startup_stm32f401xe.o: startup_stm32f401xe.s
	$(CC) $(CFLAGS) $(CIDIR) -c startup_stm32f401xe.s -o startup_stm32f401xe.o

clean:
	@echo "Removing all object files..."
	rm -f *.o
#adctemp.o: adctemp.c
#	$(CC) $(CFLAGS) $(CIDIR) -c adctemp.c -o adctemp.o
#



