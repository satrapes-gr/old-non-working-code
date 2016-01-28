Levels of unit tests
L0 TEST(TestGroupName, TestName)
L1 TEST_GROUP(TestGroupName) contains L0 + setup and tear down
---On same file----TestGroupNameTest.c
L2 TEST_GROUP_RUNNER(TestGroupName) RUN_TEST_CASE(TestGroupName, TestName)
--Can be on same file as well but in book it is in separate folder--TestGroupNameTestRunner.c
L3 main function function RunAllTests contains macro RUN_TEST_GROUP(TestGroupName)
int main(int argc, char **argv)
{
	return UnityMain(argc, argv, RunAllTests);
}
in AllTests.c
This is testing main. There will be a separate production code main
