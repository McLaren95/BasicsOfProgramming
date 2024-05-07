#include "labs/tests/lab_18_tests.h"

int main() {
    printTest("removeExtraSpaces", testRemoveExtraSpaces);
    printTest("LettersToStartDigitsToEnd", testLettersToStartDigitsToEnd);
    printTest("replaceDigitsBySpaces", testReplaceDigitsBySpaces);
    printTest("replace", testReplace);
    printTest("areWordsSorted", testAreWordsSorted);
    printTest("areWordsEqual", testAreWordsEqual);
    printTest("printWordsInReverseOrder", testPrintWordsInReverseOrder);
    printTest("countPalindromes", testCountPalindromes);
}
