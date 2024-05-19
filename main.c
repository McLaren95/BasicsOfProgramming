#include "labs/lab_19/lab_19.h"


void generateTestData(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(file, "This is a test sentence with long words\n");
    fprintf(file, "Another sentence with some longer words\n");
    fprintf(file, "Short words\n");
    fprintf(file, "One\n");
    fprintf(file, "A sentence with very long words and some short\n");

    fclose(file);
}


int main() {
    generateTestData("test.txt");

    FILE* input = fopen("test.txt", "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        fclose(input);
        return 1;
    }

    printLongestWords(input, output);

    fclose(input);
    fclose(output);

    printf("Program executed successfully.\n");

    return 0;
}


