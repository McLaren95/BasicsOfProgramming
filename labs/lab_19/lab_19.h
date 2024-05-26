#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

typedef struct {
    char name[50];
    char surname[50];
    char patronymic[50];
    float bestResult;
} Sportsman;

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

//фильтрует слова в текстовом файле, сохраняя только те,
// которые содержат указанную последовательность символов, и записывает их в выходной файл.
void filterWordsByPattern(FILE *input, FILE *output, const char *content);

//считывает строки из входного файла и для каждой строки выводит в выходной файл самое длинное слово,
// пропуская все остальные слова в строке.
void printLongestWords(FILE *input, FILE *output);

// Функция сортировки чисел по их знаку с сохранением порядка
void sortNumbersByPositivity(const char *input_filename, const char *output_filename);

//считывает информацию о спортсменах в память, сортирует их по убыванию их лучших результатов,
// сохраняет в файл информацию только о заданном количестве лучших спортсменов.
void collectTheBestTeam(const char *filename, int teamSize);