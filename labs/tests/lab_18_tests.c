#include "../../labs/tests/lab_18_tests.h"

void printTest(char *testableComponent, void (*testingFunction)()) {
    printf("Testing %s:\n\n", testableComponent);

    testingFunction();

    printf("\n--------------------------------------------------\n\n");
}

void testRemoveExtraSpaces() {
    char *firstTest = moveStringToHeap("1 2 3 4 5");
    char *secondTest = moveStringToHeap("1  23  45");
    char *thirdTest = moveStringToHeap("  123 45  ");

    removeExtraSpaces(firstTest);
    removeExtraSpaces(secondTest);
    removeExtraSpaces(thirdTest);

    ASSERT_STRING("1 2 3 4 5", firstTest);
    ASSERT_STRING("1 23 45", secondTest);
    ASSERT_STRING(" 123 45", thirdTest);

    free(firstTest);
    free(secondTest);
    free(thirdTest);
}

void testLettersToStartDigitsToEnd() {
    char* firstTest = moveStringToHeap("abc123");
    char* secondTest = moveStringToHeap("123abc");
    char* thirdTest = moveStringToHeap("a1b2c3");

    forEachWord(firstTest, lettersToStartDigitsToEnd);
    forEachWord(secondTest, lettersToStartDigitsToEnd);
    forEachWord(thirdTest, lettersToStartDigitsToEnd);

    ASSERT_STRING("abc123", firstTest);
    ASSERT_STRING("abc123", secondTest);
    ASSERT_STRING("abc123", thirdTest);

    free(firstTest);
    free(secondTest);
    free(thirdTest);
}
