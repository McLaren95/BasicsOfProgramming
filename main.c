#include "labs/lab_19/lab_19.h"
#include <assert.h>

void testSortNumbersByPositivity() {
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

int main() {
    testSortNumbersByPositivity();
    return 0;
}
