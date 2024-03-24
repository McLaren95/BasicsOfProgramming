#include "../../labs/tests/lab_16_tests.h"

void test_exercise_1() {
    matrix m = getMemMatrix(3, 3);
    inputMatrix(&m);
    exercise_1(m);
    outputMatrix(m);
    freeMemMatrix(&m);
}

void test_exercise_2(){
    matrix m = getMemMatrix(3, 3);
    inputMatrix(&m);
    exercise_2(m);
    outputMatrix(m);
    freeMemMatrix(&m);
}

void test_exercise_3(){
    matrix m = getMemMatrix(3, 6);
    inputMatrix(&m);
    exercise_3(m);
    outputMatrix(m);
    freeMemMatrix(&m);
}

void test_exercise_4(){
    matrix m = getMemMatrix(3, 3);
    inputMatrix(&m);
    exercise_4(m);
    outputMatrix(m);
    freeMemMatrix(&m);
}