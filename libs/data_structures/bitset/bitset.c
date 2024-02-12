#include <stdio.h >
#include <assert.h >

#include "bitset.h"

int bitset_checkValue(bitset *a, unsigned value) {
    return value >= 0 && value <= a->maxValue;
}

bitset bitset_create(unsigned setMaxValue) {
    assert(setMaxValue <= 32);
    return (bitset) {0, setMaxValue};
}

bool bitset_in(bitset set, unsigned int value) {
    return set.values & 1 << value;
}

bool bitset_isEqual(bitset set1, bitset set2) {
    return set1.values == set2.values;
}

bool bitset_isSubset(bitset subset, bitset set) {
    return (set.values & subset.values) == subset.values;
}

void bitset_insert(bitset *set, unsigned int value) {
    set->values |= (1 << value);
}

void bitset_deleteElement(bitset *set, unsigned int value) {
    set->values &= ~(1 << value);
}

bitset bitset_union(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values | set2.values, set1.maxValue};
}

bitset bitset_intersection(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & set2.values, set1.maxValue};
}

bitset bitset_difference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & ~(set2.values), set1.maxValue};
}

bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values ^ set2.values, set1.maxValue};
}

bitset bitset_complement(bitset set) {
    unsigned int n = 32 - set.maxValue;
    return (bitset) {((~set.values) << n) >> n, set.maxValue};
}

void bitset_print(bitset set) {
    printf("{");
    int isEmpty = 1;
    for (int i = 0; i <= set.maxValue; ++i) {
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            isEmpty = 0;
        }
    }
    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}


