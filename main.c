#include <stdio.h>
#include "libs/algorithms/array/array.h"

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

int main() {
    int n, k;
    printf("Enter set size and number of seats: ");
    scanf("%d %d", &n, &k);

    int M[n];
    for (int i = 0; i < n; i++) {
        M[i] = i + 1;
    }

    int A[k];
    int flag[n];
    for (int i = 0; i < n; i++) {
        flag[i] = 0;
    }

    generate_placement(M, n, k, 0, A, flag);

    return 0;
}
