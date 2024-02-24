#include <stdio.h>
#include <stdlib.h>
#include "libs/data_structures/vector/vectorVoid.h"

int main() {
    vectorVoid vV;
    vV.size = 5;
    vV.capacity = 10;
    vV.baseTypeSize = sizeof(int);
    vV.data = malloc(vV.size * vV.baseTypeSize);
    if (vV.data == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return 1;
    }
    free(vV.data);
    return 0;
}