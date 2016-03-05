#include "unity_fixture.h"
#include "UARTDriver.h"

TEST_GROUP(UARTDriver);

TEST_SETUP(UARTDriver){
}

TEST_TEAR_DOWN(UARTDriver){
}

TEST(UARTDriver, StartHere){
	TEST_ASSERT_TRUE(1);
}

TEST(UARTDriver, SecondTest){
	TEST_ASSERT_TRUE(1);
}
