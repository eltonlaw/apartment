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

void test_arrcmp(void) {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {2, 1, 3, 4, 5};
    int arr3[5] = {1, 2, 3, 4, 6};
	TEST_ASSERT_TRUE(arrcmp(5, arr1, arr1));
	TEST_ASSERT_FALSE(arrcmp(5, arr1, arr2));
	TEST_ASSERT_FALSE(arrcmp(5, arr1, arr3));
}

void test_insertion_sort(void) {
	int unsorted[7] = {5, 4, 6, 2, 3, 9, 8};
    int actual[7];
	insertion_sort(7, unsorted, actual);
	int expected[7] = {2, 3, 4, 5, 6, 8, 9};

	TEST_ASSERT_TRUE(arrcmp(7, expected, actual));
}

void test_insertion_sort_mut(void) {
	int actual[7] = {5, 4, 6, 2, 3, 9, 8};
	insertion_sort_mut(7, actual);
	int expected[7] = {2, 3, 4, 5, 6, 8, 9};

	TEST_ASSERT_TRUE(arrcmp(7, expected, actual));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_gives_5);
    RUN_TEST(test_arrcmp);
    RUN_TEST(test_insertion_sort);
    RUN_TEST(test_insertion_sort_mut);
    return UNITY_END();
}
