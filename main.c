#include "labs/lab_19/lab_19.h"

int string_strcmp(const char* s1, const char* s2) {
    return strcmp(s1, s2);
}

void testOneBest() {
    const char fname[] = "test.txt";

    FILE* file = fopen(fname, "wb");

    Sportsman s1 = {.bestResult = 10.0f, .name = "Max", .surname = "Ivanov", .patronymic = "Ivanovich"};
    Sportsman s2 = {.bestResult = 7.0f, .name = "Dan", .surname = "Lashin", .patronymic = "Petrovich"};

    fwrite(&s1, sizeof(Sportsman), 1, file);
    fwrite(&s2, sizeof(Sportsman), 1, file);

    fclose(file);

    collectTheBestTeam(fname, 1);

    file = fopen(fname, "rb");

    Sportsman res_s1;
    fread(&res_s1, sizeof(Sportsman), 1, file);

    fclose(file);

    assert(string_strcmp(s1.name, res_s1.name) == 0);
    assert(string_strcmp(s1.surname, res_s1.surname) == 0);
    assert(string_strcmp(s1.patronymic, res_s1.patronymic) == 0);
    assert(fabsf(s1.bestResult - res_s1.bestResult) <= 0.001f);

    printf("Test 1 passed\n");
}

void testSomeBest() {
    const char fname[] = "test.txt";

    FILE* file = fopen(fname, "wb");

    Sportsman s1 = {.bestResult = 10.0f, .name = "Max", .surname = "Ivanov", .patronymic = "Ivanovich"};
    Sportsman s2 = {.bestResult = 7.0f, .name = "Dan", .surname = "Lashin", .patronymic = "Petrovich"};

    fwrite(&s1, sizeof(Sportsman), 1, file);
    fwrite(&s2, sizeof(Sportsman), 1, file);

    fclose(file);

    collectTheBestTeam(fname, 2);

    file = fopen(fname, "rb");

    Sportsman res_s1, res_s2;
    fread(&res_s1, sizeof(Sportsman), 1, file);
    fread(&res_s2, sizeof(Sportsman), 1, file);

    fclose(file);

    assert(string_strcmp(s1.name, res_s1.name) == 0);
    assert(string_strcmp(s1.surname, res_s1.surname) == 0);
    assert(string_strcmp(s1.patronymic, res_s1.patronymic) == 0);
    assert(fabsf(s1.bestResult - res_s1.bestResult) <= 0.001f);

    assert(string_strcmp(s2.name, res_s2.name) == 0);
    assert(string_strcmp(s2.surname, res_s2.surname) == 0);
    assert(string_strcmp(s2.patronymic, res_s2.patronymic) == 0);
    assert(fabsf(s2.bestResult - res_s2.bestResult) <= 0.001f);

    printf("Test 2 passed\n");
}

void testCollectTheBestTeam() {
    testOneBest();
    testSomeBest();
}

int main() {
    testCollectTheBestTeam();
    return 0;
}
