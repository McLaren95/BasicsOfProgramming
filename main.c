#include "libs/data_structures/matrix/matrix.h"
int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main(){
    matrix m = getMemMatrix(3,5);
    inputMatrix(&m);
    outputMatrix(m);
    selectionSortColsMatrixByColCriteria(m,sumArray);
    insertionSortRowsMatrixByRowCriteria(m,sumArray);
    outputMatrix(m);

    return 0;
}