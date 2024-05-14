#include "labs/lab_19/lab_19.h"

void generateTestFile(const char *filename, int numMatrices, int maxOrder, int maxValue) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    srand(time(NULL));

    for (int i = 0; i < numMatrices; ++i) {
        int matrixOrder = rand() % maxOrder + 1;
        fprintf(file, "%d\n", matrixOrder);

        for (int j = 0; j < matrixOrder; ++j) {
            for (int k = 0; k < matrixOrder; ++k) {
                fprintf(file, "%d ", rand() % (2 * maxValue + 1) - maxValue);
            }
            fprintf(file, "\n");
        }
    }

    fclose(file);
}

bool compareFiles(const char *filename1, const char *filename2) {
    FILE *file1 = fopen(filename1, "r");
    FILE *file2 = fopen(filename2, "r");

    if (file1 == NULL || file2 == NULL) {
        printf("Error: Unable to open files for comparison.\n");
        return false;
    }

    char ch1, ch2;
    while ((ch1 = fgetc(file1)) != EOF && (ch2 = fgetc(file2)) != EOF) {
        if (ch1 != ch2) {
            fclose(file1);
            fclose(file2);
            return false;
        }
    }

    fclose(file1);
    fclose(file2);
    return true;
}

void createExpectedOutput(const char *outputFilename, const char *expectedFilename) {
    FILE *output = fopen(outputFilename, "r");
    FILE *expected = fopen(expectedFilename, "w");

    if (output == NULL || expected == NULL) {
        printf("Error: Unable to open files for creating expected output.\n");
        return;
    }
    int c;
    while ((c = fgetc(output)) != EOF) {
        fputc(c, expected);
    }

    fclose(output);
    fclose(expected);
}

int main() {
    generateTestFile("test_data.txt", 5, 5, 10);
    convertMatrixRowsToColumns("test_data.txt", "output.txt");
    createExpectedOutput("output.txt", "expected_output.txt");

    if (compareFiles("expected_output.txt", "output.txt")) {
        printf("Test passed: Output matches expected.\n");
    } else {
        printf("Test failed: Output does not match expected.\n");
    }

    return 0;
}
