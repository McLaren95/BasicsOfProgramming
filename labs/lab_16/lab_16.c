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
    if (!isEMatrix(&result))
        return false;
    else
        return true;
}