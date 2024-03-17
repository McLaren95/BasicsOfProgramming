#include "libs/data_structures/matrix/matrix.h"

int main(){
    matrix m = getMemMatrix(2,3);
    inputMatrix(&m);
    outputMatrix(m);
    swapColumns(m,0,1);
    outputMatrix(m);

    return 0;
}