#include "lab_18.h"

void removeExtraSpaces(char *s) {
    char *outputPointer = s;
    int wasSpaceBefore = 0; // флаг, указывающий, был ли предыдущий символ пробелом

    while (*s != '\0') {
        if (!isspace(*s)) {
            *outputPointer = *s;
            outputPointer++;
            wasSpaceBefore = 0; // сбрасываем флаг, если текущий символ не пробел
        } else {
            if (!wasSpaceBefore) { // если предыдущий символ не был пробелом записываем текущий пробел
                *outputPointer = *s;
                outputPointer++;
                wasSpaceBefore = 1; // устанавливаем флаг, что предыдущий символ был пробелом
            }
        }
        s++;
    }
    // Проверяем, закончилась ли строка на пробел и удаляем его, если это так
    if (wasSpaceBefore) {
        *(outputPointer - 1) = '\0';
    } else {
        *outputPointer = '\0';
    }
}