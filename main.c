#include <stdio.h>
#include <stdlib.h>
#include "libs/data_structures/vector/vectorVoid.h"

int main() {
    // Создание вектора для хранения целых чисел (int)
    vectorVoid vV;
    vV.size = 5;
    vV.capacity = 10;
    vV.baseTypeSize = sizeof(int);
    // Выделение памяти под массив целых чисел и передача указателя на этот массив в поле data
    vV.data = malloc(vV.size * vV.baseTypeSize);
    if (vV.data == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return 1;
    }

    // Использование вектора vV...

    // Освобождение памяти, выделенной для вектора
    free(vV.data);

    return 0;
}
