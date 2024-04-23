#include "libs/algorithms/array/array.h"
#include "DiskretMath/diskretmath.h"

int main() {
    int A[3] = {1, 4, 10};
    int B[4] = {3, 5, 6, 7};
    int C[4] = {3, 6, 7, 10};
    int U[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int result1_1[10];
    int result1_2[10];
    int result1_3[10];
    int result2_1[10];
    int result2_2[10];
    int result2_3[10];
    int result3[10];
    int result4[10];
    int result5[10];
    int result6[10];
    int result7[10];
    int amount1_1 = ordered_array_set_complement(U, U, result1_1, 10, 10);
    int amount1_2 = ordered_array_set_intersection(C, result1_1, result1_2, 4, amount1_1);
    int amount1_3 = ordered_array_set_complement(U, result1_2, result1_3, 10, amount1_2);
    int amount2_1 = ordered_array_set_difference(C, U, result2_1, 4, 10);
    int amount2_2 = ordered_array_set_intersection(B, result2_1, result2_2, 4, amount2_1);
    int amount2_3 = ordered_array_set_complement(U, result2_2, result2_3, 10, amount2_2);
    int amount3 = ordered_array_set_intersection(B, result1_3, result3, 4, amount1_3);
    int amount4 = ordered_array_set_intersection(A, result2_3, result4, 3, amount2_3);
    int amount5 = ordered_array_set_difference(A, result3, result5, 3, amount3);
    int amount6 = ordered_array_set_symmetricDifference(result5, result4, result6, amount5, amount4);
    int amount7 = ordered_array_set_complement(U, result6, result7, 10, amount6);
    outputArray_(result7, amount7);
}

