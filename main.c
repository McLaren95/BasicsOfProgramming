#include "labs/lab_19/lab_19.h"
#include <assert.h>

void testNegative() {
    const char input_filename[] = "test_input.txt";
    const char output_filename[] = "test_output.txt";

    int x1 = -1;
    int x2 = -2;
    int x3 = -3;

    FILE *file = fopen(input_filename, "wb");

    fwrite(&x1, sizeof(int), 1, file);
    fwrite(&x2, sizeof(int), 1, file);
    fwrite(&x3, sizeof(int), 1, file);

    fclose(file);

    sortNumbersByPositivity(input_filename, output_filename);

    file = fopen(output_filename, "rb");

    int res_x1, res_x2, res_x3;
    fread(&res_x1, sizeof(int), 1, file);
    fread(&res_x2, sizeof(int), 1, file);
    fread(&res_x3, sizeof(int), 1, file);

    fclose(file);

    assert(x1 == res_x1);
    assert(x2 == res_x2);
    assert(x3 == res_x3);

    printf("Test passed\n");
}

void testPositive() {
    const char input_filename[] = "test_input.txt";
    const char output_filename[] = "test_output.txt";

    int x1 = 1;
    int x2 = 2;
    int x3 = 3;

    FILE *file = fopen(input_filename, "wb");

    fwrite(&x1, sizeof(int), 1, file);
    fwrite(&x2, sizeof(int), 1, file);
    fwrite(&x3, sizeof(int), 1, file);

    fclose(file);

    sortNumbersByPositivity(input_filename, output_filename);

    file = fopen(output_filename, "rb");

    int res_x1, res_x2, res_x3;
    fread(&res_x1, sizeof(int), 1, file);
    fread(&res_x2, sizeof(int), 1, file);
    fread(&res_x3, sizeof(int), 1, file);

    fclose(file);

    assert(x1 == res_x1);
    assert(x2 == res_x2);
    assert(x3 == res_x3);
    printf("Test passed\n");
}


void testBoth() {
    const char input_filename[] = "test_input.txt";
    const char output_filename[] = "test_output.txt";

    int x1 = -1;
    int x2 = 1;
    int x3 = -3;
    int x4 = 3;

    FILE *file = fopen(input_filename, "wb");

    fwrite(&x1, sizeof(int), 1, file);
    fwrite(&x2, sizeof(int), 1, file);
    fwrite(&x3, sizeof(int), 1, file);
    fwrite(&x4, sizeof(int), 1, file);

    fclose(file);

    sortNumbersByPositivity(input_filename, output_filename);

    file = fopen(output_filename, "rb");

    int res_x1, res_x2, res_x3, res_x4;
    fread(&res_x1, sizeof(int), 1, file);
    fread(&res_x2, sizeof(int), 1, file);
    fread(&res_x3, sizeof(int), 1, file);
    fread(&res_x4, sizeof(int), 1, file);

    fclose(file);

    assert(res_x1 == x2);
    assert(res_x2 == x4);
    assert(res_x3 == x1);
    assert(res_x4 == x3);
    printf("Test passed\n");
}


void testSortNumbersByPositivity() {
    testPositive();
    testNegative();
    testBoth();
}

int main() {
    testSortNumbersByPositivity();
    return 0;
}
