#include "diskretmath.h"

int ordered_array_set_union(int *set1, int *set2, int *set_union, size_t
size_set1, size_t size_set2) {
    int index_set1 = 0, index_set2 = 0, amount_elements = 0;
    while (index_set1 < size_set1 && index_set2 < size_set2) {
        if (set1[index_set1] < set2[index_set2]) {
            set_union[amount_elements++] = set1[index_set1++];
        } else if (set1[index_set1] > set2[index_set2]) {
            set_union[amount_elements++] = set2[index_set2++];
        } else {
            set_union[amount_elements++] = set1[index_set1++];
            index_set2++;
        }
    }
    while (index_set1 < size_set1) {
        set_union[amount_elements++] = set1[index_set1++];
    }
    while (index_set2 < size_set2) {
        set_union[amount_elements++] = set2[index_set2++];
    }
    return amount_elements;
}

int ordered_array_set_intersection(int *set1, int *set2, int *set_intersection, size_t size_set1, size_t size_set2) {
    int index_set1 = 0, index_set2 = 0, amount_elements = 0;
    while (index_set1 < size_set1 && index_set2 < size_set2) {
        if (set1[index_set1] == set2[index_set2]) {
            set_intersection[amount_elements++] = set1[index_set1];
            index_set1++;
            index_set2++;
        } else if (set1[index_set1] < set2[index_set2]) {
            index_set1++;
        } else {
            index_set2++;
        }
    }
    return amount_elements;
}

int ordered_array_set_difference(int *set1, int *set2, int *set_difference, size_t size_set1, size_t size_set2) {
    int index_set1 = 0, index_set2 = 0, amount_elements = 0;
    while (index_set1 < size_set1 && index_set2 < size_set2) {
        if (set1[index_set1] == set2[index_set2]) {
            index_set1++;
            index_set2++;
        } else if (set1[index_set1] < set2[index_set2]) {
            set_difference[amount_elements++] = set1[index_set1++];
        } else {
            index_set2++;
        }
    }
    while (index_set1 < size_set1) {
        set_difference[amount_elements++] = set1[index_set1++];
    }
    return amount_elements;
}

int ordered_array_set_symmetricDifference(int *set1, int *set2, int *set_symDifference, size_t size_set1,size_t size_set2) {
    int temp1[size_set1 + size_set2];
    int temp2[size_set1 + size_set2];
    int first_difference = ordered_array_set_difference(set1, set2, temp1, size_set1, size_set2);
    int second_difference = ordered_array_set_difference(set2, set1, temp2, size_set2, size_set1);
    int amount_elements = ordered_array_set_union(temp1, temp2, set_symDifference, first_difference, second_difference);

    return amount_elements;
}

int ordered_array_set_complement(int *set_universum, int *set1, int *set_complement, size_t size_universum, size_t size_set1){
    int amount_elements = ordered_array_set_difference(set_universum, set1,set_complement,size_universum,size_set1);
    return amount_elements;
}