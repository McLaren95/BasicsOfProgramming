#include "lab_19.h"

void convertMatrixRowsToColumns(const char *inputFilename, const char *outputFilename) {
    FILE *input = fopen(inputFilename, "r");
    FILE *output = fopen(outputFilename, "w");

    if (input == NULL || output == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    int matrixOrder;

    while (fscanf(input, "%d", &matrixOrder) == 1) {
        int matrix[matrixOrder][matrixOrder];

        for (int i = 0; i < matrixOrder; ++i) {
            for (int j = 0; j < matrixOrder; ++j) {
                if (fscanf(input, "%d", &matrix[i][j]) != 1) {
                    printf("Error: Unable to read matrix element.\n");
                    return;
                }
            }
        }

        fprintf(output, "%d\n", matrixOrder);

        for (int i = 0; i < matrixOrder; ++i) {
            for (int j = 0; j < matrixOrder; ++j) {
                fprintf(output, "%d ", matrix[j][i]);
            }
            fprintf(output, "\n");
        }
    }

    fclose(input);
    fclose(output);
}

void convertToFloatingPoint(FILE* input, FILE* output) {
    double number;

    while (fscanf(input, "%lf", &number) == 1) {
        fprintf(output, "%.2f\n", number);
    }
}
