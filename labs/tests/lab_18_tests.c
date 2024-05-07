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
    char *firstTest = moveStringToHeap("abc123");
    char *secondTest = moveStringToHeap("123abc");
    char *thirdTest = moveStringToHeap("a1b2c3");

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

void testReplaceDigitsBySpaces() {
    char *firstTest = moveStringToHeap("");
    char *secondTest = moveStringToHeap("abc");
    char *thirdTest = moveStringToHeap("1a2b3c4");

    replaceDigitsBySpaces(firstTest);
    replaceDigitsBySpaces(secondTest);
    replaceDigitsBySpaces(thirdTest);

    ASSERT_STRING("", firstTest);
    ASSERT_STRING("abc", secondTest);
    ASSERT_STRING(" a  b   c    ", thirdTest);

    free(firstTest);
    free(secondTest);
    free(thirdTest);
}

void testReplace() {
    char *test = moveStringToHeap("very bad cat");

    replace(test, "bad", "good");

    ASSERT_STRING("very good cat", test);

    free(test);
}

void testAreWordsSorted() {
    char *firstTest = moveStringToHeap("abc def");
    char *secondTest = moveStringToHeap("xyz xyz");
    char *thirdTest = moveStringToHeap("xyz abc");

    ASSERT_BOOLEAN(true, areWordsSorted(firstTest));
    ASSERT_BOOLEAN(true, areWordsSorted(secondTest));
    ASSERT_BOOLEAN(false, areWordsSorted(thirdTest));

    free(firstTest);
    free(secondTest);
    free(thirdTest);
}

void testAreWordsEqual() {
    WordDescriptor word1 = {"abc", "def"};
    WordDescriptor word2 = {"xyz", "xyz"};
    WordDescriptor word3 = {"xyz", "abc"};

    ASSERT_BOOLEAN(false, areWordsEqual(word1, word2));
    ASSERT_BOOLEAN(true, areWordsEqual(word2, word2));
    ASSERT_BOOLEAN(false, areWordsEqual(word2, word3));
}

void testPrintWordsInReverseOrder() {
    char* testString = "This is a test string";

    printf("Expected output:\n");
    printf("string\n");
    printf("test\n");
    printf("a\n");
    printf("is\n");
    printf("This\n");

    printf("Actual output:\n");
    printWordsInReverseOrder(testString);
}

void testCountPalindromes() {
    char* firstTest = moveStringToHeap("abba baab");
    char* secondTest = moveStringToHeap("abcd dcba");
    char* thirdTest = moveStringToHeap("abba baab abc cbbc");

    ASSERT_INT(2, countPalindromes(firstTest));
    ASSERT_INT(0, countPalindromes(secondTest));
    ASSERT_INT(3, countPalindromes(thirdTest));

    free(firstTest);
    free(secondTest);
    free(thirdTest);
}











