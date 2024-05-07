#include "../../labs/lab_18/lab_18.h"

//принимает название тестируемого компонента и указатель на функцию для тестирования этого компонента,
// выполняет тестирование, выводя информацию о
// тестируемом компоненте, и отделяет результаты тестирования от других тестов.
void printTest(char *testableComponent, void (*testingFunction)());

// тест функции removeExtraSpaces.
void testRemoveExtraSpaces();

// тест функции LettersToStartDigitsToEnd.
void testLettersToStartDigitsToEnd();

// тест функции ReplaceDigitsBySpaces.
void testReplaceDigitsBySpaces();

// тест функции replace.
void testReplace();

// тест функции areWordsSorted.
void testAreWordsSorted();

// тест функции areWordsEqual.
void testAreWordsEqual();