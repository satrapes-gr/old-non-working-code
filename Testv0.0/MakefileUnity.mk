#Set this to @ to keep the makefile quiet
SILENCE = 

#---- Outputs ----#
COMPONENT_NAME = TestV0.0_Unity

#--- Inputs ----#
PROJECT_HOME_DIR = .
UNITY_HOME = ../../tddUnitTestingCode/code/unity.framework
CPP_PLATFORM = arm-none-eabi-gcc
UNITY_BUILD_HOME = ../../tddUnitTestingCode/code/unity.framework/extras/fixture/build
UNITY_TEST_OBJS_DIR = $(PROJECT_HOME_DIR)/objs/unityTestObj
UNITY_CFLAGS += -DUNITY_OUTPUT_CHAR=UnityOutputCharSpy_OutputChar\
				-DUNITY_TEST_OBJS_DIR=$(PROJECT_HOME_DIR)/objs/unityTestObj

SRC_DIRS = \
		$(PROJECT_HOME_DIR)/src 
		#$(PROJECT_HOME_DIR)/src/UARTDriver 


UNITY_TEST_SRC_DIRS = \
	$(PROJECT_HOME_DIR)/unityTestSource\
	$(PROJECT_HOME_DIR)/unityTestSource/UARTDriver\
	$(UNITY_HOME)/src\
    $(UNITY_HOME)/extras/fixture/src\
    $(UNITY_HOME)/extras/fixture/test\

INCLUDE_DIRS =\
  .\
  $(UNITY_HOME)/src\
  $(UNITY_HOME)/extras/fixture/src\
  $(UNITY_HOME)/extras/fixture/test\
  $(PROJECT_HOME_DIR)/inc/
  #$(PROJECT_HOME_DIR)/inc/UARTDriver

export
include $(UNITY_BUILD_HOME)/MakefileWorker.mk
