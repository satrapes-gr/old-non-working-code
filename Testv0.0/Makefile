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
OBJECTS_DIR = objs
SOURCE_DIR = src
INCLUDE_DIR = inc

#Find all source files (.c, .s, .cpp)
SOURCE := $(wildcard $(SOURCE_DIR)/*.c) $(wildcard $(SOURCE_DIR)/*.s) $(wildcard $(SOURCE_DIR)/*.cpp)

#Find .o files for all source files (.c, .s, .cpp)
OBJECTS:= $(addsuffix .o, $(addprefix $(OBJECTS_DIR)/, $(notdir $(basename $(SOURCE)))))

#SOURCE = $(wildcard $(SOURCE_DIR)/*.c)
#OBJECTS:= $(addprefix $(OBJECTS_DIR)/, $(patsubst %.c, %.o, $(notdir $(SOURCE))))
#OBJECTS+= $(OBJECTS_DIR)/startup_stm32f401xe.o
#SOURCE += ./src/startup_stm32f401xe.s

#########
#       #
# Rules #
#       #
#########
all: $(OBJECTS) 
	@echo "Src files: $(SOURCE)"
	@echo "Obj files: $(OBJECTS)"
	@echo "Linking..."
	$(CC) $(CFLAGS) $(LD) $(OBJECTS) -o testSerial.elf
	@echo "Link successful."

$(OBJECTS_DIR)/%.o: $(SOURCE_DIR)/%.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@
	@echo "Compile successful."
	
$(OBJECTS_DIR)/%.o: $(SOURCE_DIR)/%.s
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@
	@echo "Compile successful."
	
$(OBJECTS_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@
	@echo "Compile successful."

#./objs/startup_stm32f401xe.o: ./src/startup_stm32f401xe.s
#	@echo "Compiling $<..."
#	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c ./src/startup_stm32f401xe.s -o ./objs/startup_stm32f401xe.o
#	@echo "Compile successful."

clean:
	@echo "Removing binary and object files..."
	rm -f testSerial.elf objs/*.o
