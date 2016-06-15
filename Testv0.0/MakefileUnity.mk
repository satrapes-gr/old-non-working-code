#This acts as a header file for the MakefileWorker.mk file. You set the project settings and locations
#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = TestV0.0_Unity

#--- Inputs ----#
PROJECT_HOME_DIR = .
#UNITY_HOME is the same as UNITY_FRAMEWORK_DIR
UNITY_HOME = $(PROJECT_HOME_DIR)/src/test/unity.framework
CPP_PLATFORM = arm-none-eabi-gcc
UNITY_BUILD_HOME = ../../unitTestingTestCode/code/unity.framework/extras/fixture/build

#UNITY_TEST_SOURCE_DIR is the location of my unittests
UNITY_TEST_SOURCE_DIR = \
	src/test/unity
#Location of object files from my unity test files
UNITY_TEST_OBJECTS_DIR = $(PROJECT_HOME_DIR)/objs/test/unity


#This is the location of the files needed to run UNITY tests	
#This is exactly the same as UNITY_HOME
UNITY_FRAMEWORK_DIR = $(PROJECT_HOME_DIR)/src/test/unity.framework

#Location of the object files from the unity.framework files
UNITY_FRAMEWORK_OBJECTS_DIR = $(PROJECT_HOME_DIR)/objs/test/unity.framework
UNITY_CFLAGS += -DUNITY_OUTPUT_CHAR=UnityOutputCharSpy_OutputChar\
				-DUNITY_TEST_OBJECTS_DIR=$(PROJECT_HOME_DIR)/objs/test/unity
#Location of all program source files
SOURCE_DIR = \
		src/code
		#$(PROJECT_HOME_DIR)/src/UARTDriver 
#Location of object files of program source files
OBJECTS_DIR = \
		objs/code

	

UNITY_TEST_ORIGINAL_DIR = \
	$(UNITY_HOME)/extras/fixture\
	$(UNITY_HOME)/src

#    $(UNITY_HOME)/extras/fixture/src\

UNITY_TEST_INCLUDE_DIR = \
	$(UNITY_HOME)/extras/fixture\
	$(UNITY_HOME)/src

INCLUDE_DIR =\
  .\
  inc/code
  #$(PROJECT_HOME_DIR)/inc/UARTDriver

UNITY_ADDITIONAL_LDFLAGS = -TSTM32F401RE_FLASH.ld -Wl,--gc-sections --specs=nosys.specs
export
include $(UNITY_BUILD_HOME)/MakefileWorker.mk
