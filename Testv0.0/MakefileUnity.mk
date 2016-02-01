#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = TestV0.0_Unity

#--- Inputs ----#
PROJECT_HOME_DIR = .
UNITY_HOME = ../../tddUnitTestingCode/code/unity.framework
CPP_PLATFORM = arm-none-eabi-gcc
UNITY_BUILD_HOME = ../../tddUnitTestingCode/code/unity.framework/extras/fixture/build

UNITY_CFLAGS += -DUNITY_OUTPUT_CHAR=UnityOutputCharSpy_OutputChar

SRC_DIRS = \
		$(PROJECT_HOME_DIR)/src/ 
		#$(PROJECT_HOME_DIR)/src/UARTDriver 


TEST_SRC_DIRS = \
	$(PROJECT_HOME_DIR)/unity\
	$(PROJECT_HOME_DIR)/unity/UARTDriver\
	$(UNITY_HOME)/src\
    $(UNITY_HOME)/extras/fixture/src\
    $(UNITY_HOME)/extras/fixture/test\

INCLUDE_DIRS =\
  .\
  $(UNITY_HOME)/src\
  $(UNITY_HOME)/src\
  $(UNITY_HOME)/extras/fixture/src\
  $(UNITY_HOME)/extras/fixture/test\
  $(PROJECT_HOME_DIR)/inc/
  #$(PROJECT_HOME_DIR)/inc/UARTDriver


include $(UNITY_BUILD_HOME)/MakefileWorker.mk
