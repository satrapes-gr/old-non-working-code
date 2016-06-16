#include "unity_fixture.h"
#include "UARTDriver.h"

TEST_GROUP(UARTDriver);

TEST_SETUP(UARTDriver){
	serialInit();
}

TEST_TEAR_DOWN(UARTDriver){
}

TEST(UARTDriver, StartHere){
	TEST_ASSERT_TRUE(0);
}

TEST(UARTDriver, FirstTest)
{
	sendChar(100);
	TEST_ASSERT_TRUE(0);
}
	
