#include "libs/data_structures/matrix/matrix.h"
int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main(){
    matrix m1= getMemMatrix(3,3);
    inputMatrix(&m1);
    outputMatrix(m1);
    bool result = isSymmetricMatrix(&m1);
    printf("%d",result);

    return 0;
}