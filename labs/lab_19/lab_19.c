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

void convertToFloatingPoint(FILE *input, FILE *output) {
    double number;

    while (fscanf(input, "%lf", &number) == 1) {
        fprintf(output, "%.2f\n", number);
    }
}

static int performOperation(int leftOperand, int rightOperand, char operator, int *error) {
    switch (operator) {
        case '+':
            return leftOperand + rightOperand;
        case '-':
            return leftOperand - rightOperand;
        case '*':
            return leftOperand * rightOperand;
        case '/':
            if (rightOperand == 0) {
                *error = 1;
                return 0;
            }
            return leftOperand / rightOperand;
        default:
            *error = 1;
            return 0;
    }
}

void evaluateAndWriteExpression(const char *sentence, FILE *outputFile) {
    int operands[3] = {0, 0, 0};
    char operators[2] = {'\0', '\0'};
    int operandIndex = 0, operatorIndex = 0;
    int error = 0;

    const char *ptr = sentence;

    while (*ptr) {
        if (isspace(*ptr)) {
            ptr++;
            continue;
        }

        if (isdigit(*ptr)) {
            operands[operandIndex++] = *ptr - '0';
        } else {
            operators[operatorIndex++] = *ptr;
        }
        ptr++;
    }

    int result;

    if (operandIndex == 2) {
        result = performOperation(operands[0], operands[1], operators[0], &error);
    } else {
        if (operators[1] == '/' || operators[1] == '*') {
            result = performOperation(
                    operands[0], performOperation(operands[1], operands[2], operators[1], &error), operators[0], &error
            );
        } else {
            result = performOperation(
                    performOperation(operands[0], operands[1], operators[0], &error), operands[2], operators[1], &error
            );
        }
    }

    if (error) {
        fprintf(outputFile, "%s = error\n", sentence);
    } else {
        fprintf(outputFile, "%s = %d\n", sentence, result);
    }
}

void filterWordsByPattern(FILE *input, FILE *output, const char *content) {
    char line[256];

    while (fgets(line, sizeof(line), input) != NULL) {

        line[strcspn(line, "\n")] = 0;
        char *word = strtok(line, " ");
        int wordFound = 0;

        while (word != NULL) {
            if (strstr(word, content)) {
                fprintf(output, "%s ", word);
                wordFound = 1;
            }
            word = strtok(NULL, " ");
        }

        if (wordFound) {
            fprintf(output, "\n");
        }
    }
}

void printLongestWords(FILE* input, FILE* output) {
    char line[100];

    while (fgets(line, 100, input) != NULL) {
        char* word = strtok(line, " ");
        char* longestWord = word;
        size_t biggestLength = strlen(longestWord);

        word = strtok(NULL, " ");

        while (word != NULL) {
            size_t length = strlen(word);

            if (length > biggestLength) {
                longestWord = word;
                biggestLength = length;
            }

            word = strtok(NULL, " ");
        }

        fprintf(output, "%s\n", longestWord);
    }
}





