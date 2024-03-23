#include "../../labs/lab_16/lab_16.h"

void test_for_exercise_1() {
    matrix m = getMemMatrix(3, 3);
    inputMatrix(&m);
    exercise_1(m);
    outputMatrix(m);
    freeMemMatrix(&m);
}