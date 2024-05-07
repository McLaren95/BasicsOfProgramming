#include "../../labs/tests/lab_18_tests.h"

void printTest(char* testableComponent, void (*testingFunction)()) {
    printf("Testing %s:\n\n", testableComponent);

    testingFunction();

    printf("\n--------------------------------------------------\n\n");
}

void testRemoveExtraSpaces() {
    char *firstTest = moveStringToHeap("123 456");
    char *secondTest = moveStringToHeap("123  456");
    char *thirdTest = moveStringToHeap("123 456  789");

    removeExtraSpaces(firstTest);
    removeExtraSpaces(secondTest);
    removeExtraSpaces(thirdTest);

    ASSERT_STRING("123 456", firstTest);
    ASSERT_STRING("123 456", secondTest);
    ASSERT_STRING("123 456 789", thirdTest);

    free(firstTest);
    free(secondTest);
    free(thirdTest);
}