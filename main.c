#include "labs/lab_19/lab_19.h"

void generateTestData(const char *filename, int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    char operators[] = {'+', '-', '*', '/'};

    for (int i = 0; i < count; i++) {
        int opCount = rand() % 2 + 1;
        fprintf(file, "%d", rand() % 10);

        for (int j = 0; j < opCount; j++) {
            fprintf(file, " %c %d", operators[rand() % 4], rand() % 10);
        }

        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    const char *filename = "test_data.txt";
    generateTestData(filename, 10);

    FILE *inputFile = fopen(filename, "r");
    if (!inputFile) {
        perror("Failed to open file for reading");
        return 1;
    }

    FILE *outputFile = fopen("output_data.txt", "w");
    if (!outputFile) {
        perror("Failed to open file for writing");
        fclose(inputFile);
        return 1;
    }

    char line[256];
    printf("Arithmetic expression results:\n");
    while (fgets(line, sizeof(line), inputFile)) {
        line[strcspn(line, "\n")] = 0;
        evaluateAndWriteExpression(line, outputFile);
        printf("%s\n", line);
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}

