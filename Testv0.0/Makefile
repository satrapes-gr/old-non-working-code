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

#Helper Functions
#@param: dir
#@return all .cpp, .c files from dir
get_src_from_dir  = $(wildcard $1/*.cpp) $(wildcard $1/*.c) $(wildcard $1/*.s)

#@param multiple dirs
#@return multiple dirs
#@comment seems a bit pointless
get_dirs_from_dirspec  = $(wildcard $1)

#@param list of dirs
#@return list of all source files contained in the dirs
get_src_from_dir_list = $(foreach dir, $1, $(call get_src_from_dir,$(dir)))

#@param file extension (e.g. .o, .d etc)
#@param text to substitute
#@return substitute .c/.cpp files with .o, .d file extension
__src_to = $(subst .c,$1, $(subst .cpp,$1,$2))
src_to = $(call __src_to,$1,$2)
src_to_o = $(call src_to,.o,$1)

#Find all source files (.c, .s, .cpp)
SOURCE := $(call get_src_from_dir, $(SOURCE_DIR))

#Find .o files for all source files (.c, .s, .cpp)
OBJECTS:= $(addsuffix .o, $(addprefix $(OBJECTS_DIR)/, $(notdir $(basename $(SOURCE)))))

#Find all the test source files (.c, .s, .cpp)
#TEST_SOURCE := $(call get_src_from_dir, $(SOURCE_DIR)/test)
UNITY_TEST_SOURCE := $(shell find $(SOURCE_DIR)/test -name '*.c')
$(warning UNITY_TEST_SOURCE ------------- $(UNITY_TEST_SOURCE))

UNITY_TEST_OBJECTS := $(patsubst $(SOURCE_DIR)/%, $(OBJECTS_DIR)/%, $(call src_to_o, $(UNITY_TEST_SOURCE)))
$(warning UNITY_TEST_OBJECTS ------------- $(UNITY_TEST_OBJECTS))

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

clean:
	@echo "Removing binary and object files..."
	rm -f testSerial.elf objs/*.o
