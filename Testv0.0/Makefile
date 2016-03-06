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
SOURCES_DIR = src
INCLUDE_DIR = -I ./inc

SOURCES := $(shell find $(SOURCES_DIR) -name '*.c')\
			$(shell find $(SOURCES_DIR) -name '*.s')\
			$(shell find $(SOURCES_DIR) -name '*.cpp') 

$(warning SOURCES is $(SOURCES))
OBJECTS:= $(addsuffix .o, $(addprefix $(OBJECTS_DIR)/, $(basename $(SOURCES))))

$(warning OBJECTS is $(OBJECTS))


#########
#       #
# Rules #
#       #
#########
all: $(OBJECTS) 
	@echo "Src files: $(SOURCES)"
	@echo "Obj files: $(OBJECTS)"
	@echo "Linking..."
	$(CC) $(CFLAGS) $(LD) $(OBJECTS) -o testSerial.elf
	@echo "Link successful."

$(OBJECTS_DIR)/$(SOURCES_DIR)/%.o: $(SOURCES_DIR)/%.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@
	@echo "Compile successful."

$(OBJECTS_DIR)/$(SOURCES_DIR)/%.o: $(SOURCES_DIR)/%.s
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@
	@echo "Compile successful."

#$(OBJECTS_DIR)/$(SOURCES_DIR)/%.o: $(SOURCES_DIR)/%.cpp
#	@echo "Compiling $<..."
#	mkdir -p $(dir $<)
#	$(CC) $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@
#	@echo "Compile successful."

clean:
	@echo "Removing binary and object files..."
	rm -f ./testSerial.elf ./objs/src/*.o
