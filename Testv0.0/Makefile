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
LDFLAGS=-TSTM32F401RE_FLASH.ld -Wl,--gc-sections

#Project directories
OBJECTS_DIR = objs/code
SOURCE_DIR = src/code
INCLUDE_DIR = inc/code

UNITY_TEST_OBJECTS_DIR = objs/test/unity
UNITY_TEST_SOURCE_DIR = src/test/unity

CPPUNIT_TEST_OBJECTS_DIR = objs/test/cppunit
CPPUNIT_TEST_SOURCE_DIR = src/test/cppunit

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
#@return substitute .c/.s files with .o file extension
__src_to = $(subst .c,$1, $(subst .s,$1,$2))
src_to = $(call __src_to,$1,$2)
src_to_o = $(call src_to,.o,$1)

debug_print_list = $(foreach word,$1,echo "  $(word)";) echo;

#Find all source files (.c, .s)
SOURCE := $(shell find $(SOURCE_DIR) -name '*.[cs]')

#Find .o files for all source files (.c, .s, .cpp)
OBJECTS := $(patsubst $(SOURCE_DIR)/%, $(OBJECTS_DIR)/%, $(call src_to_o, $(SOURCE)))

#Find all the test source files (.c, .s, .cpp)
UNITY_TEST_SOURCE := $(shell find $(UNITY_TEST_SOURCE_DIR) -name '*.c')

UNITY_TEST_OBJECTS := $(patsubst $(UNITY_TEST_SOURCE_DIR)/%, $(UNITY_TEST_OBJECTS_DIR)/%, $(call src_to_o, $(UNITY_TEST_SOURCE)))

#########
#       #
# Rules #
#       #
#########
all: $(OBJECTS) 
	@echo "Src files: $(SOURCE)"
	@echo "Obj files: $(OBJECTS)"
	@echo "Linking..."
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) -o testSerial.elf
	@echo "Link successful."

$(OBJECTS_DIR)/%.o: $(SOURCE_DIR)/%.[cs]
	@echo "Compiling $<..."
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@
	@echo "Compile successful."
		
$(OBJECTS_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@
	@echo "Compile successful."

clean:
	@echo "Removing binary and object files..."
	rm -rf testSerial.elf $(OBJECTS) $(UNITY_TEST_OBJECTS) $(OBJECTS_DIR)/*

debug:
	@echo
	@echo "Target Source files:"
	@$(call debug_print_list,$(SOURCE))
	@echo "Target Object files:"
	@$(call debug_print_list,$(OBJECTS))
	@echo "Test Source files:"
	@$(call debug_print_list,$(UNITY_TEST_SOURCE))
	@echo "Test Object files:"
	@$(call debug_print_list,$(UNITY_TEST_OBJECTS))
	@echo "Mock Source files:"
	@$(call debug_print_list,$(MOCKS_SRC))
	@echo "Mock Object files:"
	@$(call debug_print_list,$(MOCKS_OBJS))
	@echo "All Input Dependency files:"
	@$(call debug_print_list,$(DEP_FILES))
	@echo Stuff to clean:
	@$(call debug_print_list,$(STUFF_TO_CLEAN))
	@echo Includes:
	@$(call debug_print_list,$(INCLUDES))

.PHONY: flags
flags: 
	@echo
	@echo "Compile C source with CFLAGS:"
	@$(call debug_print_list,$(CFLAGS))
	@echo "Link with LDFLAGS:"
	@$(call debug_print_list,$(LDFLAGS))
	@echo "Link with LD_LIBRARIES:"
	@$(call debug_print_list,$(LD_LIBRARIES))
	@echo "Create libraries with ARFLAGS:"
	@$(call debug_print_list,$(ARFLAGS))
	@echo "OBJ files:"
	@$(call debug_print_list,$(OBJECTS))

