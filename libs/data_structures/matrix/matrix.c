#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);
    free(m->values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(&ms[i]);
    free(ms);
}

void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            scanf("%d", &(m->values[i][j]));
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(&ms[i]);
}

void outputMatrix(matrix m) {
    int max_digits = findLongNumberInMatrix(m);

    for (int i = 0; i < m.nRows; i++) {
        printf("|");
        for (int j = 0; j < m.nCols; j++) {
            int num = m.values[i][j];

            int digits = countDigits(num);

            int spacesBefore = (max_digits - digits) / 2;

            int spacesAfter = max_digits - digits - spacesBefore;

            for (int k = 0; k < spacesBefore; k++) {
                printf(" ");
            }
            printf("%d", m.values[i][j]);

            for (int k = 0; k < spacesAfter; k++) {
                printf(" ");
            }
            printf(" ");
        }
        printf("|\n");
    }
    printf("\n");
}

int countDigits(int n) {
    int digits = 0;
    while (n != 0) {
        n /= 10;
        digits++;
    }
    return digits;
}

int findLongNumberInMatrix(matrix m) {
    int maxDigits = 0;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            int num = m.values[i][j];
            int digits = 0;
            while (num != 0) {
                num /= 10;
                digits++;
            }
            if (digits > maxDigits) {
                maxDigits = digits;
            }
        }
    }
    return maxDigits;
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

void swapRows(matrix m, int i1, int i2) {
    assert(i1 >= 0 && i1 < m.nRows && i2 >= 0 && i2 < m.nRows);
    int *temp = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = temp;
}

void swapColumns(matrix m, int j1, int j2) {
    assert(j1 >= 0 && j1 < m.nCols && j2 >= 0 && j2 < m.nCols);
    for(int i = 0; i < m.nRows; i++) {
        int temp = m.values[i][j2];
        m.values[i][j2] = m.values[i][j1];
        m.values[i][j1] = temp;
    }
}

