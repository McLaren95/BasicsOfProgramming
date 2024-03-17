#include "matrix.h"
#include "../../algorithms/array/array.h"

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
    int max_digits = 0;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            int num = m.values[i][j];
            int digits = 0;
            while (num != 0) {
                num /= 10;
                digits++;
            }
            if (digits > max_digits) {
                max_digits = digits;
            }
        }
    }
    return max_digits;
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
    for (int i = 0; i < m.nRows; i++) {
        int temp = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = temp;
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *criteria_values = (int *) malloc(sizeof(int) * m.nRows);
    assert(criteria_values != NULL);
    for (int i = 0; i < m.nRows; i++) {
        criteria_values[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 1; i < m.nRows; i++) {
        int key_value = criteria_values[i];
        int j = i;
        while (j > 0 && criteria_values[j - 1] > key_value) {
            swapRows(m, j - 1, j);
            int temp = criteria_values[j - 1];
            criteria_values[j - 1] = criteria_values[j];
            criteria_values[j] = temp;
            j--;
        }
    }
    free(criteria_values);
}

void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *criteria_values = (int *) malloc(sizeof(int) * m.nCols);
    int *intermediate_array = (int *) malloc(sizeof(int) * m.nRows);
    assert(criteria_values != NULL && intermediate_array != NULL);

    for (int j = 0; j < m.nCols; j++) {
        for (int i = 0; i < m.nRows; i++) {
            intermediate_array[i] = m.values[i][j];
        }
        criteria_values[j] = criteria(intermediate_array, m.nRows);
    }
    for (int i = 0; i < m.nCols - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < m.nCols; j++) {
            if (criteria_values[j] < criteria_values[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = criteria_values[i];
            criteria_values[i] = criteria_values[min_index];
            criteria_values[min_index] = temp;
            swapColumns(m, i, min_index);
        }
    }
    free(criteria_values);
    free(intermediate_array);
}


