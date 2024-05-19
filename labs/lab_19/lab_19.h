#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// считывает матрицу из файла, затем конвертирует строки матрицы в столбцы и
// записывает результат обратно в файл.
void convertMatrixRowsToColumns(const char *inputFilename, const char *outputFilename);

//читывает вещественные числа из текстового файла в формате с фиксированной точкой,
// преобразует их в формат с плавающей точкой,
// сохраняя две цифры после точки в мантиссе, и записывает результаты в другой файл.
void convertToFloatingPoint(FILE *input, FILE *output);

//выполняет арифметическую операцию между двумя операндами и возвращает результат,
// устанавливая флаг ошибки в случае деления на ноль или нераспознанного оператора.
static int performOperation(int leftOperand, int rightOperand, char operator, int *error);

// разбирает арифметическое выражение из строки,
// выполняет вычисления и записывает результат или сообщение об ошибке в указанный файл.
void evaluateAndWriteExpression(const char *sentence, FILE *outputFile);