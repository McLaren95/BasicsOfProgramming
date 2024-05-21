#include "labs/lab_20/lab_20.h"
#include <assert.h>

void testIncrementSubmatrices() {
    int query1[4] = {0, 0, 1, 1};
    int query2[4] = {1, 1, 2, 2};
    int *queries[] = {query1, query2};

    int **matrix = incrementSubmatrices(3, (int **) queries, 2);

    assert(matrix[0][0] == 1);
    assert(matrix[0][1] == 1);
    assert(matrix[0][2] == 0);
    assert(matrix[1][0] == 1);
    assert(matrix[1][1] == 2);
    assert(matrix[1][2] == 1);
    assert(matrix[2][0] == 0);
    assert(matrix[2][1] == 1);
    assert(matrix[2][2] == 1);
}


void tests() {
    testIncrementSubmatrices();
}

int main() {
    tests();
}


