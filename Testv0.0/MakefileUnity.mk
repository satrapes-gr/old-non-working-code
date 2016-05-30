#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = TestV0.0_Unity

#--- Inputs ----#
PROJECT_HOME_DIR = .
UNITY_HOME = ../../unitTestingTestCode/code/unity.framework
CPP_PLATFORM = arm-none-eabi-gcc
UNITY_BUILD_HOME = ../../unitTestingTestCode/code/unity.framework/extras/fixture/build
UNITY_TEST_OBJECTS_DIR = $(PROJECT_HOME_DIR)/objs/test/unity
UNITY_CFLAGS += -DUNITY_OUTPUT_CHAR=UnityOutputCharSpy_OutputChar\
				-DUNITY_TEST_OBJECTS_DIR=$(PROJECT_HOME_DIR)/objs/test/unity

SOURCE_DIR = \
		src/code
		#$(PROJECT_HOME_DIR)/src/UARTDriver 

OBJECTS_DIR = \
		objs/code

UNITY_TEST_SOURCE_DIR = \
	src/test/unity
	
	
UNITY_FRAMEWORK_DIR = $(PROJECT_HOME_DIR)/unity.framework	

UNITY_TEST_ORIGINAL_DIR = \
	$(UNITY_HOME)/extras/fixture/test \
	$(UNITY_HOME)/extras/fixture/src \
	$(UNITY_HOME)/src

#    $(UNITY_HOME)/extras/fixture/src\

UNITY_TEST_INCLUDE_DIR = \
	$(UNITY_HOME)/extras/fixture/src\
	$(UNITY_HOME)/extras/fixture/test\
	$(UNITY_HOME)/auto\
	$(UNITY_HOME)/src

INCLUDE_DIR =\
  .\
  inc/code
  #$(PROJECT_HOME_DIR)/inc/UARTDriver

UNITY_ADDITIONAL_LDFLAGS = -TSTM32F401RE_FLASH.ld -Wl,--gc-sections --specs=nosys.specs
export
include $(UNITY_BUILD_HOME)/MakefileWorker.mk
