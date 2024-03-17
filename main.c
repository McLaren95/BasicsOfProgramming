#include "libs/data_structures/matrix/matrix.h"
int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main(){
    matrix m1= getMemMatrix(1,3);
    inputMatrix(&m1);
    outputMatrix(m1);
    position pos = getMaxValuePos(m1);
    printf("Минимальный элемент матрицы находится в строке %d и столбце %d\n", pos.rowIndex, pos.colIndex);

    return 0;
}