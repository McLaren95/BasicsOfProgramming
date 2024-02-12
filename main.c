#include "libs/data_structures/unordered_array_set/unordered_array_set.h"

void test_unordered_array_set_in1() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4}, 4);
    size_t res = unordered_array_set_in(&set, 3);
    assert (res == 2);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_in2() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4}, 4);
    size_t res = unordered_array_set_in(&set, 5);
    assert (res == 4);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_subset() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 3, 5, 7, 9}, 5);
    int res1 = unordered_array_set_isSubset(set1, set2);
    int res2 = unordered_array_set_isSubset(set2, set1);
    assert (res1 == 0);
    assert (res2 == 1);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test_unordered_array_set_insert1() {
    unordered_array_set set = unordered_array_set_create(10);
    for (int i = 0; i < 10; i++) {
        unordered_array_set_insert(&set, i);
    }
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 10);
    assert (unordered_array_set_isEqual(set, expectedSet));
    unordered_array_set_delete(set);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_insert2() {
    unordered_array_set set = unordered_array_set_create(10);
    int k = 0;
    while (k != 10) {
        unordered_array_set_insert(&set, 5);
        k++;
    }
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {5}, 1);
    assert (unordered_array_set_isEqual(set, expectedSet));
    unordered_array_set_delete(set);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_deleteElement1() {
    unordered_array_set set = unordered_array_set_create(10);
    for (int i = 0; i < 10; i++) {
        unordered_array_set_insert(&set, i);
    }
    for (int i = 0; i < 10; i++) {
        unordered_array_set_deleteElement(&set, i);
    }
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {}, 0);
    assert (unordered_array_set_isEqual(set, expectedSet));
    unordered_array_set_delete(set);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_deleteElement2() {
    unordered_array_set set = unordered_array_set_create(10);
    for (int i = 0; i < 10; i++) {
        unordered_array_set_insert(&set, i);
    }
    unordered_array_set_deleteElement(&set, 7);
    unordered_array_set_deleteElement(&set, 5);
    unordered_array_set_deleteElement(&set, -2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {0, 1, 2, 3, 4, 6, 8, 9}, 8);
    assert (unordered_array_set_isEqual(set, expectedSet));
    unordered_array_set_delete(set);
    unordered_array_set_delete(expectedSet);

}

void test_unordered_array_set_union1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 4, 5, 6}, 4);
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 4, 6}, 3);
    assert (unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {11, 12, 14, 15}, 4);
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {}, 0);
    assert (unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 4, 5, 6}, 4);
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {2, 3, 10}, 3);
    assert (unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {0, 8, 5, 11}, 4);
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    assert (unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetric_difference1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 4, 5, 6}, 4);
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {2, 3, 5, 10}, 4);
    assert (unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetric_difference2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {0, 5, 7, 8}, 4);
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {0, 1, 2, 3, 4, 5, 6, 7, 8, 10},
                                                                            10);
    assert (unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_complement1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array(
            (int[]) {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}, 15);
    unordered_array_set resSet = unordered_array_set_complement(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {0, 5, 7, 8, 9, 11, 12, 13, 14}, 9);
    assert (unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_in() {
    test_unordered_array_set_in1();
    test_unordered_array_set_in2();
}

void test_unordered_array_set_isSubset() {
    test_unordered_array_set_subset();
}

void test_unordered_array_set_insert() {
    test_unordered_array_set_insert1();
    test_unordered_array_set_insert2();
}

void test_unordered_array_set_deleteElement() {
    test_unordered_array_set_deleteElement1();
    test_unordered_array_set_deleteElement2();
}

void test_unordered_array_set_union() {
    test_unordered_array_set_union1();
    test_unordered_array_set_union2();
}

void test_unordered_array_set_intersection() {
    test_unordered_array_set_intersection1();
    test_unordered_array_set_intersection2();
}

void test_unordered_array_set_difference() {
    test_unordered_array_set_difference1();
    test_unordered_array_set_difference2();
}

void test_unordered_array_set_symmetricDifference() {
    test_unordered_array_set_symmetric_difference1();
    test_unordered_array_set_symmetric_difference2();
}

void test_unordered_array_set_complement() {
    test_unordered_array_set_complement1();
}

void test() {
    test_unordered_array_set_in();
    test_unordered_array_set_isSubset();
    test_unordered_array_set_insert();
    test_unordered_array_set_deleteElement();
    test_unordered_array_set_union();
    test_unordered_array_set_intersection();
    test_unordered_array_set_difference();
    test_unordered_array_set_symmetricDifference();
    test_unordered_array_set_complement();

}

int main() {
    test();

    return 0;
}
