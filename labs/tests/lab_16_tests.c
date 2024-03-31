#include "../../labs/tests/lab_16_tests.h"

void test_exercise_1() {
    matrix m = getMemMatrix(3, 3);
    inputMatrix(&m);
    exercise_1(m);
    outputMatrix(m);
    freeMemMatrix(&m);
}

void test_exercise_2() {
    matrix m = getMemMatrix(3, 3);
    inputMatrix(&m);
    exercise_2(m);
    outputMatrix(m);
    freeMemMatrix(&m);
}

void test_exercise_3() {
    matrix m = getMemMatrix(3, 6);
    inputMatrix(&m);
    exercise_3(m);
    outputMatrix(m);
    freeMemMatrix(&m);
}

void test_exercise_4() {
    matrix m = getMemMatrix(3, 3);
    inputMatrix(&m);
    exercise_4(m);
    outputMatrix(m);
    freeMemMatrix(&m);
}

void test_exercise_5() {
    matrix m = getMemMatrix(3, 3);
    inputMatrix(&m);
    exercise_5(m);
    outputMatrix(m);
    freeMemMatrix(&m);
}

void test_exercise_6() {
    matrix m1 = getMemMatrix(3, 3);
    inputMatrix(&m1);
    outputMatrix(m1);
    matrix m2 = getMemMatrix(3, 3);
    inputMatrix(&m2);
    outputMatrix(m2);
    bool result = exercise_6(m1, m2);
    matrix m3 = getMemMatrix(3, 3);
    m3 = squareMatrixMultiplication(&m1, &m2);
    outputMatrix(m3);
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&m3);
    printf("%d\n", result);
}

void test_exercise_7(){
    matrix m = getMemMatrix(3, 4);
    inputMatrix(&m);
    outputMatrix(m);
    long long int result = exercise_7(m);
    printf("%lld",result);
}

void test_exercise_8(){
    matrix m = getMemMatrix(3, 4);
    inputMatrix(&m);
    outputMatrix(m);
    int result = exercise_8(m);
    printf("%d",result);
}

void test_exercise_9(){
    matrix m = getMemMatrix(3, 4);
    inputMatrix(&m);
    outputMatrix(m);
    exercise_9(m);
    outputMatrix(m);
}

void test_exercise_10(){
    matrix m = getMemMatrix(6, 2);
    inputMatrix(&m);
    outputMatrix(m);
    int result = exercise_10(m);
    printf("%d",result);
}
