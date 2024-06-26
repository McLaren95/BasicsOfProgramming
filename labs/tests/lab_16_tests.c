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

void test_exercise_7() {
    matrix m = getMemMatrix(3, 4);
    inputMatrix(&m);
    outputMatrix(m);
    long long int result = exercise_7(m);
    printf("%lld", result);
    freeMemMatrix(&m);
}

void test_exercise_8() {
    matrix m = getMemMatrix(3, 4);
    inputMatrix(&m);
    outputMatrix(m);
    int result = exercise_8(m);
    printf("%d", result);
    freeMemMatrix(&m);
}

void test_exercise_9() {
    matrix m = getMemMatrix(3, 4);
    inputMatrix(&m);
    outputMatrix(m);
    exercise_9(m);
    outputMatrix(m);
    freeMemMatrix(&m);
}

void test_exercise_10() {
    matrix m = getMemMatrix(6, 2);
    inputMatrix(&m);
    outputMatrix(m);
    int result = exercise_10(m);
    printf("%d", result);
    freeMemMatrix(&m);
}

void test_exercise_11() {
    matrix m = getMemMatrix(3, 4);
    inputMatrix(&m);
    outputMatrix(m);
    int result = exercise_11(m);
    printf("%d", result);
    freeMemMatrix(&m);
}

void test_exercise_12() {
    matrix m = getMemMatrix(3, 3);
    inputMatrix(&m);
    outputMatrix(m);
    exercise_12(m);
    outputMatrix(m);
    freeMemMatrix(&m);
}

void test_exercise_13() {
    matrix *ms = getMemArrayOfMatrices(4, 2, 2);
    inputMatrices(ms, 4);
    outputMatrices(ms, 4);
    int result = exercise_13(ms, 4);
    printf("%d", result);
    freeMemMatrices(ms, 4);
}

void test_exercise_14() {
    matrix *ms = getMemArrayOfMatrices(5, 3, 2);
    inputMatrices(ms, 5);
    exercise_14(ms, 5);
    freeMemMatrices(ms, 5);
}

void test_exercise_15() {
    matrix *ms = getMemArrayOfMatrices(3, 3, 3);
    inputMatrices(ms, 3);
    exercise_15(ms, 3);
    freeMemMatrices(ms, 3);
}
