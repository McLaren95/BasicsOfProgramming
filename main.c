#include "labs/lab_19/lab_19.h"

void generateTestData(const char *filename, int count) {
    const char *sampleWords[] = {
            "apple", "banana", "orange", "grape", "fruit", "vegetable", "carrot", "broccoli", "potato", "tomato",
            "animal", "dog", "cat", "bird", "fish", "insect", "bee", "ant", "butterfly", "spider",
            "vehicle", "car", "bike", "truck", "bus", "train", "airplane", "boat", "ship", "submarine"
    };
    int numSampleWords = sizeof(sampleWords) / sizeof(sampleWords[0]);

    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    for (int i = 0; i < count; i++) {
        int numWords = rand() % 10 + 1;
        for (int j = 0; j < numWords; j++) {
            fprintf(file, "%s ", sampleWords[rand() % numSampleWords]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    const char *inputFilename = "input_data.txt";
    const char *outputFilename = "output_data.txt";

    generateTestData(inputFilename, 10);

    FILE *inputFile = fopen(inputFilename, "r");
    if (!inputFile) {
        perror("Failed to open file for reading");
        return 1;
    }

    FILE *outputFile = fopen(outputFilename, "w");
    if (!outputFile) {
        perror("Failed to open file for writing");
        fclose(inputFile);
        return 1;
    }

    const char content[] = "an";
    filterWordsByPattern(inputFile, outputFile, content);

    fclose(inputFile);
    fclose(outputFile);

    printf("Filtration is complete. Check the output_data.txt file for results.\n");

    return 0;
}

