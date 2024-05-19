#include "labs/lab_19/lab_19.h"

bool checkConvertedFormat(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file for checking");
        return false;
    }

    double number;
    bool success = true;

    while (fscanf(file, "%lf", &number) == 1) {
        char buffer[20];
        sprintf(buffer, "%.2e", number);
        if (strcmp(buffer, "0.00e+00") != 0 && strcmp(buffer, "0.00e+000") != 0) {
            success = false;
            break;
        }
    }

    fclose(file);
    return success;
}
void generateTestData(const char *filename, int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file for writing");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    for (int i = 0; i < count; i++) {
        double number = (rand() / (double)RAND_MAX) * 2000.0 - 1000.0;
        fprintf(file, "%.6f\n", number);
    }

    fclose(file);
}



int main() {
    const char *inputFilename = "testdata.txt";
    const char *outputFilename = "converted_data.txt";
    generateTestData(inputFilename, 100);

    FILE *inputFile = fopen(inputFilename, "r");
    if (!inputFile) {
        perror("Unable to open input file for reading");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFilename, "w");
    if (!outputFile) {
        perror("Unable to open output file for writing");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    convertToFloatingPoint(inputFile, outputFile);

    if (checkConvertedFormat(outputFilename)) {
        printf("Data conversion format is correct.\n");
    } else {
        printf("Data conversion format is incorrect.\n");
    }
    fclose(inputFile);
    fclose(outputFile);


    return 0;
}

