#include "libs/data_structures/matrix/matrix.h"

int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

void testGetMemMatrix() {
    int nRows = 2;
    int nCols = 3;
    matrix m = getMemMatrix(nRows, nCols);
    if (m.nRows == nRows && m.nCols == nCols) {
        printf("Good\n");
    } else {
        printf("Error\n");
    }
    freeMemMatrix(&m);
}

void testGetMemArrayOfMatrices() {
    int nMatrices = 2;
    int nRows = 2;
    int nCols = 3;
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    bool dimensionsCorrect = true;
    for (int i = 0; i < nMatrices; ++i) {
        if (ms[i].nRows != nRows || ms[i].nCols != nCols) {
            dimensionsCorrect = false;
            break;
        }
    }
    if (dimensionsCorrect) {
        printf("Good\n");
    } else {
        printf("Error\n");
    }
    freeMemMatrices(ms, nMatrices);
}

void testFreeMemMatrix() {
    int nRows = 2;
    int nCols = 3;
    matrix m = getMemMatrix(nRows, nCols);
    freeMemMatrix(&m);
    if (m.values == NULL && m.nRows == 0 && m.nCols == 0) {
        printf("Good\n");
    } else {
        printf("Error\n");
    }
}

void testInputMatrix() {
    int values[] = {1, 2, 3, 4};
    size_t nRows = 2;
    size_t nCols = 2;
    matrix m = getMemMatrix(nRows, nCols);
    printf("Enter %zu x %zu matrix:\n", nRows, nCols);
    inputMatrix(&m);
    printf("Entered matrix\n");
    outputMatrix(m);
    matrix m_expected = createMatrixFromArray(values, nRows, nCols);
    printf("Expected matrix\n");
    outputMatrix(m_expected);
    if (areTwoMatricesEqual(&m, &m_expected)) {
        printf("Test passed: Entered matrix matches the expected one.\n");
    } else {
        printf("Test failed: Entered matrix does not match the expected one.\n");
    }
    freeMemMatrix(&m);
    freeMemMatrix(&m_expected);
}

void testInputMatrices() {
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t nMatrices = 2;
    size_t nRows = 2;
    size_t nCols = 2;
    matrix *ms_input = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    printf("Enter %zu matrices of size %zu x %zu:\n", nMatrices, nRows, nCols);
    inputMatrices(ms_input, nMatrices);
    printf("Entered matrices\n");
    outputMatrices(ms_input, nMatrices);
    matrix *ms_expected = createArrayOfMatrixFromArray(values, nMatrices, nRows, nCols);
    printf("Expected matrices\n");
    outputMatrices(ms_expected, nMatrices);
    bool allEqual = true;
    for (size_t k = 0; k < nMatrices; k++) {
        if (!areTwoMatricesEqual(&ms_input[k], &ms_expected[k])) {
            allEqual = false;
            break;
        }
    }
    if (allEqual) {
        printf("Test passed: Entered matrices match the expected ones.\n");
    } else {
        printf("Test failed: Entered matrices do not match the expected ones.\n");
    }
    for (size_t i = 0; i < nMatrices; i++) {
        freeMemMatrix(&ms_input[i]);
        freeMemMatrix(&ms_expected[i]);
    }
    free(ms_input);
    free(ms_expected);
}

void testSwapRows() {
    int values[] = {3, 4, 1, 2};
    size_t nRows = 2;
    size_t nCols = 2;
    matrix m = getMemMatrix(nRows, nCols);
    printf("Enter %zu x %zu matrix:\n", nRows, nCols);
    inputMatrix(&m);
    swapRows(m, 0, 1);
    printf("Swaped matrix\n");
    outputMatrix(m);
    matrix m_expected = createMatrixFromArray(values, nRows, nCols);
    printf("Expected matrix\n");
    outputMatrix(m_expected);
    if (areTwoMatricesEqual(&m, &m_expected)) {
        printf("Test passed: Entered matrix matches the expected one.\n");
    } else {
        printf("Test failed: Entered matrix does not match the expected one.\n");
    }
    freeMemMatrix(&m);
    freeMemMatrix(&m_expected);
}

void testSwapColumns() {
    int values[] = {2, 1, 4, 3};
    size_t nRows = 2;
    size_t nCols = 2;
    matrix m = getMemMatrix(nRows, nCols);
    printf("Enter %zu x %zu matrix:\n", nRows, nCols);
    inputMatrix(&m);
    swapColumns(m, 0, 1);
    printf("Swaped matrix\n");
    outputMatrix(m);
    matrix m_expected = createMatrixFromArray(values, nRows, nCols);
    printf("Expected matrix\n");
    outputMatrix(m_expected);
    if (areTwoMatricesEqual(&m, &m_expected)) {
        printf("Test passed: Entered matrix matches the expected one.\n");
    } else {
        printf("Test failed: Entered matrix does not match the expected one.\n");
    }
    freeMemMatrix(&m);
    freeMemMatrix(&m_expected);
}

void testInsertionSortRowsMatrixByRowCriteria() {
    // 3 5 4 3 6 7 5 5 5 8 5 3 4 3 5
    int values[] = {5, 3, 4, 3, 5, 3, 5, 4, 3, 6, 7, 5, 5, 5, 8};
    size_t nRows = 3;
    size_t nCols = 5;
    matrix m = getMemMatrix(nRows, nCols);
    printf("Enter %zu x %zu matrix:\n", nRows, nCols);
    inputMatrix(&m);
    insertionSortRowsMatrixByRowCriteria(m, sumArray);
    printf("Swaped matrix\n");
    outputMatrix(m);
    matrix m_expected = createMatrixFromArray(values, nRows, nCols);
    printf("Expected matrix\n");
    outputMatrix(m_expected);
    if (areTwoMatricesEqual(&m, &m_expected)) {
        printf("Test passed: Entered matrix matches the expected one.\n");
    } else {
        printf("Test failed: Entered matrix does not match the expected one.\n");
    }
    freeMemMatrix(&m);
    freeMemMatrix(&m_expected);
}

void testSelectionSortColsMatrixByColCriteria() {
    int values[] = {1, 6, 8, 7, 3, 5, 0, 2, 9};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = getMemMatrix(nRows, nCols);
    printf("Enter %zu x %zu matrix:\n", nRows, nCols);
    inputMatrix(&m);
    selectionSortColsMatrixByColCriteria(m, sumArray);
    printf("Swaped matrix\n");
    outputMatrix(m);
    matrix m_expected = createMatrixFromArray(values, nRows, nCols);
    printf("Expected matrix\n");
    outputMatrix(m_expected);
    if (areTwoMatricesEqual(&m, &m_expected)) {
        printf("Test passed: Entered matrix matches the expected one.\n");
    } else {
        printf("Test failed: Entered matrix does not match the expected one.\n");
    }
    freeMemMatrix(&m);
    freeMemMatrix(&m_expected);
}

void testIsSquareMatrix() {
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = getMemMatrix(nRows, nCols);
    printf("Enter %zu x %zu matrix:\n", nRows, nCols);
    inputMatrix(&m);
    bool result = isSquareMatrix(&m);
    if (result)
        printf("Good\n");
    else
        printf("Bad\n");
    freeMemMatrix(&m);
}

void testAreTwoMatricesEqual() {
    size_t nRows_1 = 3;
    size_t nCols_1 = 3;
    matrix m1 = getMemMatrix(nRows_1, nCols_1);
    printf("Enter %zu x %zu matrix:\n", nRows_1, nCols_1);
    inputMatrix(&m1);
    size_t nRows_2 = 3;
    size_t nCols_2 = 3;
    matrix m2 = getMemMatrix(nRows_2, nCols_2);
    printf("Enter %zu x %zu matrix:\n", nRows_1, nCols_1);
    inputMatrix(&m2);
    bool result = areTwoMatricesEqual(&m1, &m2);
    if (result)
        printf("Good\n");
    else
        printf("Bad\n");
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void testIsEMatrix() {
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = getMemMatrix(nRows, nCols);
    printf("Enter %zu x %zu matrix:\n", nRows, nCols);
    inputMatrix(&m);
    bool result = isEMatrix(&m);
    if (result)
        printf("Good\n");
    else
        printf("Bad\n");
    freeMemMatrix(&m);
}

void testIsSymmetricMatrix() {
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = getMemMatrix(nRows, nCols);
    printf("Enter %zu x %zu matrix:\n", nRows, nCols);
    inputMatrix(&m);
    bool result = isSymmetricMatrix(&m);
    if (result)
        printf("Good\n");
    else
        printf("Bad\n");
    freeMemMatrix(&m);
}

void testTransposeSquareMatrix() {
    int values[] = {1, 4, 7, 2, 5, 8, 3, 6, 9};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = getMemMatrix(nRows, nCols);
    printf("Enter %zu x %zu matrix:\n", nRows, nCols);
    inputMatrix(&m);
    transposeSquareMatrix(&m);
    printf("Transposed matrix\n");
    outputMatrix(m);
    matrix m_expected = createMatrixFromArray(values, nRows, nCols);
    printf("Expected matrix\n");
    outputMatrix(m_expected);
    if (areTwoMatricesEqual(&m, &m_expected)) {
        printf("Test passed: Entered matrix matches the expected one.\n");
    } else {
        printf("Test failed: Entered matrix does not match the expected one.\n");
    }
    freeMemMatrix(&m);
    freeMemMatrix(&m_expected);
}

void testTransposeMatrix() {
    int values[] = {1, 5, 9, 2, 6, 10, 3, 7, 11, 4, 8, 12};
    size_t nRows = 4;
    size_t nCols = 3;
    matrix m = getMemMatrix(3, 4);
    printf("Enter %zu x %zu matrix:\n", 3, 4);
    inputMatrix(&m);
    transposeMatrix(&m);
    printf("Transposed matrix\n");
    outputMatrix(m);
    matrix m_expected = createMatrixFromArray(values, nRows, nCols);
    printf("Expected matrix\n");
    outputMatrix(m_expected);
    printf("transposition was successful\n");
    freeMemMatrix(&m);
    freeMemMatrix(&m_expected);
}

void testGetMinValuePos() {
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = getMemMatrix(nRows, nCols);
    printf("Enter %zu x %zu matrix:\n", nRows, nCols);
    inputMatrix(&m);
    position min_pos = getMinValuePos(m);
    if (min_pos.rowIndex == 0 && min_pos.colIndex == 0)
        printf("Good\n");
    else
        printf("Bad\n");
    freeMemMatrix(&m);
}

void testGetMaxValuePos() {
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = getMemMatrix(nRows, nCols);
    printf("Enter %zu x %zu matrix:\n", nRows, nCols);
    inputMatrix(&m);
    position max_pos = getMaxValuePos(m);
    if (max_pos.rowIndex == 2 && max_pos.colIndex == 2)
        printf("Good\n");
    else
        printf("Bad\n");
    freeMemMatrix(&m);
}

int main() {
    testGetMemMatrix();
    testGetMemArrayOfMatrices();
    testFreeMemMatrix();
    testInputMatrix();
    testInputMatrices();
    testSwapRows();
    testSwapColumns();
    testInsertionSortRowsMatrixByRowCriteria();
    testSelectionSortColsMatrixByColCriteria();
    testIsSquareMatrix();
    testAreTwoMatricesEqual();
    testIsEMatrix();
    testIsSymmetricMatrix();
    testTransposeSquareMatrix();
    testTransposeMatrix();
    testGetMinValuePos();
    testGetMaxValuePos();
    return 0;
}