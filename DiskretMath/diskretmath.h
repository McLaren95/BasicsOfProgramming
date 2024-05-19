#include <stdio.h>
#include <stdlib.h>
#include "../libs/algorithms/array/array.h"
#include <stdbool.h>

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

////выводит на экран подмножество множества, представленное в виде бинарного вектора, с указанием его номера.
//void printBinVector(int subset[], int n, int index);
//
//// выводит на экран подмножество множества в виде фигурных скобок
//// с перечислением элементов, номера которых установлены в соответствующем бинарном числе.
//void printSubsetFromBinVector(int subset[], int n);

// порождает и печатает все подмножества множества мощности n
// представленных в виде бинарных векторов, начиная с пустого подмножества
// и заканчивая полным множеством, в порядке увеличения численного значения соответствующих бинарных векторов.
//void generateBinVectors(int n);

//генерирует и выводит все подмножества множества мощности n в виде их числового представления,
// где каждое число представляет собой бинарный вектор, и выводит количество всех подмножеств в конце.
//void generateSubsets(int n);

// рекурсивно генерирует и выводит все подмножества множества мощности n в виде их числового представления,
// где каждое число представляет собой бинарный вектор, и выводит количество всех подмножеств в конце.
//void generateSubsetRecursive(int subset[], int n, int index);

// обёрточная функция для рекурсии.
//void generateSubsetsRecursive(int n);

// Функция для вычисления количества сочетаний.
int countCombinations(int n, int k);

//генерирует и выводит все возможные сочетания из n элементов по k в лексикографическом порядке,
// а затем выводит общее количество сгенерированных сочетаний.
void generateCombinations(int n, int k);

//генерирует и выводит все возможные сочетания из n элементов по k в лексикографическом порядке с помощью рекурсии.
void generateCombinationsRecursive(int n, int k, int i, int b, int C[]);

// обёрточная функция для рекурсии.
void generateCombinationsRecursiveOb(int n, int k);

//рекурсивно генерирует все перестановки элементов массива P длиной n,
// выводит каждую перестановку, и подсчитывает общее количество перестановок.
void permutation(int *P, int n, int i);

//генерирует все размещения из n элементов множества M по k местам.
void generate_placement(int M[], int n, int k, int i, int A[], int flag[]);

bool ordered_array_set_isEqual(int *set, size_t size_set, int *subset,
                               size_t size_subset);
