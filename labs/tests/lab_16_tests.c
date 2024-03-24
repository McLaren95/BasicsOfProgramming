#include "../../labs/lab_16/lab_16.h"
#include "../../labs/tests/lab_16_tests.h"

void test_exercise_1() {
    matrix m = getMemMatrix(3, 3);
    inputMatrix(&m);
    exercise_1(m);
    outputMatrix(m);
    freeMemMatrix(&m);
}