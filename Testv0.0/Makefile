#############
#           #
# Variables #
#           #
#############
#Compiler variable
CC=arm-none-eabi-gcc

#Compiler flags
CFLAGS=-g -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -DSTM32F401xE -Os

#Linker flags
LD=-TSTM32F401RE_FLASH.ld -Wl,--gc-sections


#Project directories
OBJDIR = objs
SRCDIR = src
INCDIR = -Iinc

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJS:= $(addprefix $(OBJDIR)/, $(patsubst %.c, %.o, $(notdir $(SOURCES))))
OBJS+= $(OBJDIR)/startup_stm32f401xe.o
SOURCES += ./src/startup_stm32f401xe.s

#########
#       #
# Rules #
#       #
#########
all: $(OBJS) 
	@echo "Src files: $(SOURCES)"
	@echo "Obj files: $(OBJS)"
	@echo "Linking..."
	$(CC) $(CFLAGS) $(LD) $(OBJS) -o testSerial.elf
	@echo "Link successful."

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@
	@echo "Compile successful."

./objs/startup_stm32f401xe.o: ./src/startup_stm32f401xe.s
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) $(INCDIR) -c ./src/startup_stm32f401xe.s -o ./objs/startup_stm32f401xe.o
	@echo "Compile successful."

clean:
	@echo "Removing binary and object files..."
	rm -f testSerial.elf objs/*.o
