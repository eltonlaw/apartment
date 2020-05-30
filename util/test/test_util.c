#include "util.h"
#include "unity.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_gives_5(void)
{
    TEST_ASSERT_EQUAL_INT(5, gives_5());
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_gives_5);
    return UNITY_END();
}
