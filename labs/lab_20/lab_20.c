#include "lab_20.h"

int **incrementSubmatrices(size_t n, int **query, int size_query) {
    // Выделяем память под матрицу размером n x n, заполненную нулями
    int **matrix = (int **) malloc(n * sizeof(int *));
    for (size_t i = 0; i < n; i++) {
        matrix[i] = (int *) calloc(n, sizeof(int));
    }
    // Обрабатываем каждый запрос
    for (size_t i = 0; i < size_query; i++) {
        // Получаем координаты верхнего левого угла (start_row, start_col) и нижнего правого угла (end_row, end_col) подматрицы из запроса
        int start_row = query[i][0];
        int start_col = query[i][1];
        int end_row = query[i][2];
        int end_col = query[i][3];

        // Увеличиваем значения в элементах подматрицы на 1
        for (size_t x = start_row; x <= end_row; x++) {
            for (size_t y = start_col; y <= end_col; y++) {
                matrix[x][y]++;
            }
        }
    }
    return matrix;
}

int countNeighbors(int **board, size_t rows, size_t columns, int i, int j) {
    int count = 0;

    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            count += board[(i + x + rows) % rows][(j + y + columns) % columns];
        }
    }

    return count - board[i][j];
}

void printBoard(int **board, size_t rows, size_t columns) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            printf("%d ", board[i][j]);
        }

        printf("\n");
    }
}

void nextGeneration(int **board, size_t rows, size_t columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int neighbors = countNeighbors(board, rows, columns, i, j);

            if (board[i][j] == 1) {
                board[i][j] = ((neighbors < 2) || (neighbors > 3)) ? 0 : 1;
            } else {
                board[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
}
