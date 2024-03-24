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