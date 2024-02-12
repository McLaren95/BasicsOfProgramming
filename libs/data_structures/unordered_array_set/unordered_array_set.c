#include "unordered_array_set.h"


unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {malloc(sizeof(int) * capacity),0,capacity};
}

static void unordered_array_set_shrinkToFit(unordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set set = unordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        unordered_array_set_insert(&set, a[i]);
    unordered_array_set_shrinkToFit(&set);
    return set;
}

size_t unordered_array_set_in(unordered_array_set *set, int value) {
    return linearSearch_(set->data, set->size, value);
}

bool unordered_array_set_isSubset(unordered_array_set subset, unordered_array_set set) {
    for (size_t i = 0; i < subset.size; i++) {
        size_t found = 0;
        for (size_t j = 0; j < set.size; j++) {
            if (subset.data[i] == set.data[j]) {
                found = 1;
                break;
            }
        }
        if (found == 0)
            return 0;
    }
    return 1;
}

int compare_ints(const void *a, const void *b) {
    const int *num1 = (const int *) a;
    const int *num2 = (const int *) b;
    return *num1 - *num2;
}

bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    if (set1.size != set2.size)
        return 0;

    qsort(set1.data, set1.size, sizeof(int), compare_ints);
    qsort(set2.data, set2.size, sizeof(int), compare_ints);

    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

void unordered_array_set_isAbleAppend(unordered_array_set *set, int value) {
    assert (set->size < set->capacity);
}

void unordered_array_set_insert(unordered_array_set *set, int value) {
    if (unordered_array_set_in(set, value) == set->size) {
        unordered_array_set_isAbleAppend(set, value);
        append_(set->data, &set->size, value);
    }
}

void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    for (size_t i = 0; i < set->size; i++) {
        if (set->data[i] == value) {
            deleteByPosSaveOrder_(set->data, &set->size, i);
            break;
        }
    }
}


unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set set = unordered_array_set_create(set1.size + set2.size);
    for (size_t i = 0; i < set1.size; i++) {
        unordered_array_set_insert(&set, set1.data[i]);
    }
    for (size_t j = 0; j < set2.size; j++) {
        unordered_array_set_insert(&set, set2.data[j]);
    }
    unordered_array_set_shrinkToFit(&set);
    return set;
}

unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set set = unordered_array_set_create(set1.size + set2.size);
    for (size_t i = 0; i < set1.size; i++) {
        for (size_t j = 0; j < set2.size; j++) {
            if (set1.data[i] == set2.data[j]) {
                unordered_array_set_insert(&set, set1.data[i]);
                break;
            }
        }
    }
    unordered_array_set_shrinkToFit(&set);
    return set;
}

unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set set = unordered_array_set_create(set1.size + set2.size);
    for (size_t i = 0; i < set1.size; i++) {
        size_t found = 0;
        for (size_t j = 0; j < set2.size; j++) {
            if (set1.data[i] == set2.data[j]) {
                found = 1;
                break;
            }
        }
        if (!found)
            unordered_array_set_insert(&set, set1.data[i]);
    }
    unordered_array_set_shrinkToFit(&set);
    return set;
}

unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    unordered_array_set comp = unordered_array_set_create(set.size + universumSet.size);
    assert(unordered_array_set_isSubset(set, universumSet));
    comp = unordered_array_set_difference(universumSet, set);
    unordered_array_set_shrinkToFit(&comp);
    return comp;
}

unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set a = unordered_array_set_difference(set1, set2);
    unordered_array_set b = unordered_array_set_difference(set2, set1);
    unordered_array_set c = unordered_array_set_union(a, b);
    unordered_array_set_delete(a);
    unordered_array_set_delete(b);
    return c;
}

void unordered_array_set_print(unordered_array_set set) {
    printf("{");
    if (set.size > 0) {
        for (int i = 0; i < set.size; ++i) {
            printf("%d", set.data[i]);
            if (i < set.size - 1) {
                printf(", ");
            }
        }
    }
    printf("}\n");
}

void unordered_array_set_delete(unordered_array_set set){
    free(set.data);
}

