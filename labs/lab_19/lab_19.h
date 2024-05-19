#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

// считывает матрицу из файла, затем конвертирует строки матрицы в столбцы и
// записывает результат обратно в файл.
void convertMatrixRowsToColumns(const char *inputFilename, const char *outputFilename);

//читывает вещественные числа из текстового файла в формате с фиксированной точкой,
// преобразует их в формат с плавающей точкой,
// сохраняя две цифры после точки в мантиссе, и записывает результаты в другой файл.
void convertToFloatingPoint(FILE* input, FILE* output);
