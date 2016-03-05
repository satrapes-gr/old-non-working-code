#include "unity_fixture.h"

TEST_GROUP_RUNNER(UARTDriver){
	RUN_TEST_CASE(UARTDriver, StartHere);
	RUN_TEST_CASE(UARTDriver, SecondTest);
}
