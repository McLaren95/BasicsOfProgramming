#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"
#include <assert.h>
void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}
int main() {
    test_popBack_notEmptyVector();

    return 0;
}
