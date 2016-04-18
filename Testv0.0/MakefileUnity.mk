#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = TestV0.0_Unity

#--- Inputs ----#
PROJECT_HOME_DIR = .
UNITY_HOME = ../../tddUnitTestingCode/code/unity.framework
CPP_PLATFORM = arm-none-eabi-gcc
UNITY_BUILD_HOME = ../../tddUnitTestingCode/code/unity.framework/extras/fixture/build
UNITY_OBJECTS_DIR = $(PROJECT_HOME_DIR)/objs/test/unity
UNITY_CFLAGS += -DUNITY_OUTPUT_CHAR=UnityOutputCharSpy_OutputChar\
				-DUNITY_OBJS_DIR=$(PROJECT_HOME_DIR)/objs/test/unity

SOURCE_DIR = \
		src/code
		#$(PROJECT_HOME_DIR)/src/UARTDriver 

OBJECTS_DIR = \
		objs/code

UNITY_TEST_SOURCE_DIR = \
	src/test/unity
#    $(UNITY_HOME)/extras/fixture/src\
#    $(UNITY_HOME)/extras/fixture/test

UNITY_TEST_INCLUDE_DIR = \
	$(UNITY_HOME)/extras/fixture/src\
	$(UNITY_HOME)/src
INCLUDE_DIR =\
  .\
  $(UNITY_HOME)/extras/fixture/test\
  inc/code
  #$(PROJECT_HOME_DIR)/inc/UARTDriver

export
include $(UNITY_BUILD_HOME)/MakefileWorker.mk
