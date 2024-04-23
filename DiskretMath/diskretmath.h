#include <stdio.h>

//Операция объединения для элементов множества set1 и множества set2,
//хранящихся в массивах set1 и set2. Элементы массивов упорядочены
int ordered_array_set_union(int *set1, int *set2, int *set_union, size_t size_set1, size_t size_set2);

//Операция пересечения для элементов множества set1 и множества set2,
//хранящихся в массивах set1 и set2. Элементы массивов упорядочены
int ordered_array_set_intersection(int *set1, int *set2, int *set_intersection, size_t size_set1, size_t size_set2);

//Операция разности для элементов множества set1 и множества set2,
//хранящихся в массивах set1 и set2. Элементы массивов упорядочены
int ordered_array_set_difference(int *set1, int *set2, int *set_difference, size_t size_set1, size_t size_set2);

//Операция симметричной разности для элементов множества set1 и
//множества set2, хранящихся в массивах set1 и set2. Элементы массивов упорядочены
int ordered_array_set_symmetricDifference(int *set1, int *set2, int *set_symDifference, size_t size_set1, size_t size_set2);

//Операция дополнения до унивёрсума для элементов множества set1 и
//множества set2, хранящихся в массивах set1 и set2. Элементы массивов упорядочены:
int ordered_array_set_complement(int *set_universum, int *set1, int *set_complement, size_t size_universum, size_t size_set1);