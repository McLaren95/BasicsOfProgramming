#include "lab_16.h"

void exercise_1(matrix m) {
    position min_pos = getMinValuePos(m);
    position max_pos = getMaxValuePos(m);
    swapRows(m, min_pos.rowIndex, max_pos.rowIndex);
}

void exercise_2(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void exercise_3(matrix m) {
    selectionSortColsMatrixByColCriteria(m, getMin);
}

void exercise_4(matrix m) {
    if (isSymmetricMatrix(&m)) {
        squareMatrix(&m);
    } else {
        printf("This matrix is not symmetric\n");
    }
}

void exercise_5(matrix m) {
    int *values = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; i++) {
        values[i] = sumArray(m.values[i], m.nCols);
    }
    bool uniqueness = isUnique(values, m.nRows);
    if (!uniqueness)
        printf("impossible to transpose\n");
    else
        transposeSquareMatrix(&m);
    free(values);
}

bool exercise_6(matrix m1, matrix m2) {
    matrix result = squareMatrixMultiplication(&m1, &m2);
    if (!isEMatrix(&result)) {
        freeMemMatrix(&result);
        return false;
    } else {
        freeMemMatrix(&result);
        return true;
    }
}

long long exercise_7(matrix m) {
    int array_size = m.nRows + m.nCols - 1;
    int max_values[array_size];
    for (int i = 0; i < array_size; i++) {
        max_values[i] = INT_MIN;
    }
    int increment = m.nCols - 1;
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            int index = i - j + increment;
            max_values[index] = max_values[index] > m.values[i][j] ? max_values[index] : m.values[i][j];
        }
    }
    long long sum = 0;
    for (int i = 0; i < array_size; ++i) {
        if (i != increment) {
            sum += max_values[i];
        }
    }
    return sum;
}

int exercise_8(matrix m) {
    position max_pos = getMaxValuePos(m);
    int min_value = INT_MAX;

    for (int i = 0; i <= max_pos.rowIndex; ++i) {
        int column_offset = (max_pos.rowIndex - i) * 2;
        int start_column = max(0, max_pos.colIndex + 1 - column_offset);
        int end_column = min(m.nCols - 1, max_pos.colIndex - 1 + column_offset);

        for (int j = start_column; j <= end_column; ++j) {
            min_value = min(min_value, m.values[i][j]);

        }
    }
    return min_value;
}

void exercise_9(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m,getDistance);
}