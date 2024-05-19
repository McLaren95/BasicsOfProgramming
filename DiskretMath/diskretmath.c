#include "diskretmath.h"

int ordered_array_set_union(int *set1, int *set2, int *set_union, size_t
size_set1, size_t size_set2) {
    int index_set1 = 0, index_set2 = 0, amount_elements = 0;
    while (index_set1 < size_set1 && index_set2 < size_set2) {
        if (set1[index_set1] < set2[index_set2]) {
            set_union[amount_elements++] = set1[index_set1++];
        } else if (set1[index_set1] > set2[index_set2]) {
            set_union[amount_elements++] = set2[index_set2++];
        } else {
            set_union[amount_elements++] = set1[index_set1++];
            index_set2++;
        }
    }
    while (index_set1 < size_set1) {
        set_union[amount_elements++] = set1[index_set1++];
    }
    while (index_set2 < size_set2) {
        set_union[amount_elements++] = set2[index_set2++];
    }
    return amount_elements;
}

int ordered_array_set_intersection(int *set1, int *set2, int *set_intersection, size_t size_set1, size_t size_set2) {
    int index_set1 = 0, index_set2 = 0, amount_elements = 0;
    while (index_set1 < size_set1 && index_set2 < size_set2) {
        if (set1[index_set1] == set2[index_set2]) {
            set_intersection[amount_elements++] = set1[index_set1];
            index_set1++;
            index_set2++;
        } else if (set1[index_set1] < set2[index_set2]) {
            index_set1++;
        } else {
            index_set2++;
        }
    }
    return amount_elements;
}

int ordered_array_set_difference(int *set1, int *set2, int *set_difference, size_t size_set1, size_t size_set2) {
    int index_set1 = 0, index_set2 = 0, amount_elements = 0;
    while (index_set1 < size_set1 && index_set2 < size_set2) {
        if (set1[index_set1] == set2[index_set2]) {
            index_set1++;
            index_set2++;
        } else if (set1[index_set1] < set2[index_set2]) {
            set_difference[amount_elements++] = set1[index_set1++];
        } else {
            index_set2++;
        }
    }
    while (index_set1 < size_set1) {
        set_difference[amount_elements++] = set1[index_set1++];
    }
    return amount_elements;
}

int ordered_array_set_symmetricDifference(int *set1, int *set2, int *set_symDifference, size_t size_set1,
                                          size_t size_set2) {
    int temp1[size_set1 + size_set2];
    int temp2[size_set1 + size_set2];
    int first_difference = ordered_array_set_difference(set1, set2, temp1, size_set1, size_set2);
    int second_difference = ordered_array_set_difference(set2, set1, temp2, size_set2, size_set1);
    int amount_elements = ordered_array_set_union(temp1, temp2, set_symDifference, first_difference, second_difference);

    return amount_elements;
}

int ordered_array_set_complement(int *set_universum, int *set1, int *set_complement, size_t size_universum,
                                 size_t size_set1) {
    int amount_elements = ordered_array_set_difference(set_universum, set1, set_complement, size_universum, size_set1);
    return amount_elements;
}

//void printBinVector(int subset[], int n, int index) {
//    printf("%d) { ", index);
//    for (int i = 0; i < n; i++) {
//        printf("%d", subset[i]);
//    }
//    printf(" }\n");
//}
//
//void printSubsetFromBinVector(int subset[], int n) {
//    printf("{");
//    int isComma = 0;
//    for (int i = 0; i < n; i++) {
//        if (subset[i] == 1) {
//            if (isComma) {
//                printf(",");
//            }
//            printf("%d", i + 1);
//            isComma = 1;
//        }
//    }
//    printf("}\n");
//}

//void generateBinVectors(int n) {
//    int *subset = (int *) malloc(n * sizeof(int));
//    int count = 0;
//    for (int i = 0; i < n; i++) {
//        subset[i] = 0;
//    }
//    printBinVector(subset, n, count);
//    for (int i = 1; i < (1 << n); i++) {
//        int j = n - 1;
//        while (subset[j] != 0) {
//            subset[j] = 0;
//            j--;
//        }
//        subset[j] = 1;
//        count++;
//        printBinVector(subset, n, count);
//
//    }
//    printf("Amount subsets = %d", ++count);
//    free(subset);
//}

//void generateSubsets(int n) {
//    int *subset = (int *) malloc(n * sizeof(int));
//    int count = 0;
//    for (int i = 0; i < n; i++) {
//        subset[i] = 0;
//    }
//    printSubsetFromBinVector(subset, n);
//    for (int i = 1; i < (1 << n); i++) {
//        int j = n - 1;
//        while (subset[j] != 0) {
//            subset[j] = 0;
//            j--;
//        }
//        subset[j] = 1;
//        count++;
//        printSubsetFromBinVector(subset, n);
//
//    }
//    printf("Amount subsets = %d", ++count);
//    free(subset);
//}

//void generateSubsetRecursive(int subset[], int n, int index) {
//    if (index == n) {
//        printSubsetFromBinVector(subset, n);
//        return;
//    }
//
//    for (int x = 0; x < 2; x++) {
//        subset[index] = x;
//        generateSubsetRecursive(subset, n, index + 1);
//    }
//}

////void generateSubsetsRecursive(int n) {
//    int *subset = (int *) malloc(n * sizeof(int));
//    printf("Subsets of set with power %d:\n", n);
//    generateSubsetRecursive(subset, n, 0);
//    free(subset);
//}

int countCombinations(int n, int k) {
    int numerator = 1;
    int denominator = 1;

    for (int i = 1; i <= k; i++) {
        numerator *= i;
    }

    for (int i = n - k + 1; i <= n; i++) {
        denominator *= i;
    }

    return denominator / numerator;
}

void generateCombinations(int n, int k) {
    int C[k];
    for (int i = 0; i < k; i++) {
        C[i] = i + 1;
    }
    int amount = 0;
    while (1) {
        outputArray_(C, k);
        amount++;

        int i = k - 1;
        while (C[i] == n - k + i + 1) {
            i--;
        }

        if (i < 0) {
            break;
        }

        C[i]++;

        for (int j = i + 1; j < k; j++) {
            C[j] = C[j - 1] + 1;
        }
    }
    printf("number of combinations: %d\n", amount);
}

void generateCombinationsRecursive(int n, int k, int i, int b, int C[]) {
    if (i == k) {
        outputArray_(C, k);
        return;
    }

    for (int x = b; x <= n; x++) {
        C[i] = x;
        generateCombinationsRecursive(n, k, i + 1, x + 1, C);
    }
}

void generateCombinationsRecursiveOb(int n, int k) {
    int C[k];
    generateCombinationsRecursive(n, k, 0, 1, C);
}

void permutation(int *P, int n, int i) {
    if (i == n) {
        outputArray_(P, n);
        return;
    } else {
        for (int j = i; j < n; j++) {
            swap(&P[i], &P[j]);
            permutation(P, n, i + 1);
            swap(&P[i], &P[j]);
        }
    }
}

void generate_placement(int M[], int n, int k, int i, int A[], int flag[]) {
    if (i == k) {
        outputArray_(A, k);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (!flag[j]) {
            A[i] = M[j];
            flag[j] = 1;
            generate_placement(M, n, k, i + 1, A, flag);
            flag[j] = 0;
        }
    }
}

bool ordered_array_set_isEqual(int *set, size_t size_set, int *subset, size_t size_subset) {
    // Если множества имеют разный размер, они не могут быть равны
    if (size_set != size_subset) {
        return false;
    }

    // Проверяем, что все элементы совпадают
    for (size_t i = 0; i < size_set; i++) {
        if (set[i] != subset[i]) {
            return false;
        }
    }

    return true;
}