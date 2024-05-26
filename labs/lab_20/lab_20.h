#include <stdio.h>
#include <stdlib.h>

// создает матрицу размером n x n, заполненную нулями, и затем по заданным
// запросам увеличивает на 1 значения в подматрицах,
// определяемых координатами верхнего левого и нижнего правого углов.
int **incrementSubmatrices(size_t n, int **query, int size_query);

void nextGeneration(int **board, size_t rows, size_t columns);

void printBoard(int **board, size_t rows, size_t columns);

int countNeighbors(int **board, size_t rows, size_t columns, int i, int j);
