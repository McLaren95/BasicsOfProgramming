#ifndef INC_ARRAY_H
#define INC_ARRAY_H

#include <stddef.h>
#include <math.h>
#include <stdlib.h>

// ввод массива data размера n
void inputArray_(int *a, size_t n);

// вывод массива data размера n
void outputArray_(const int *a, size_t n);

// возвращает значение первого вхождения элемента x
// в массиве a размера n при его наличии, иначе - n
size_t linearSearch_(const int *a, const size_t n, int x);

// возвращает позицию вхождения элемента x
// в отсортированном массиве a размера n при его наличии, иначе - SIZE_MAX
int binarySearch_(const int *a, const size_t n, int x);

// возвращает позицию первого элемента равного или большего x
// в отсортированном массиве a размера n
// при отсутствии такого элемента возвращает n
int binarySearchMoreOrEqual_(const int *a, const size_t n, int x);

// вставка элемента со значением value
// в массив data размера n на позицию pos
void insert_(int *a, size_t *n, size_t pos, int value);

// добавление элемента value в конец массива data размера n
void append_(int *a, size_t *n, int value);

// удаление из массива data размера n элемента на позиции pos
// с сохранением порядка оставшихся элементов
void deleteByPosSaveOrder_(int *a, size_t *n, size_t pos);

// удаление из массива data размера n элемента на позиции pos
// без сохранения порядка оставшихся элементов
// размер массива data уменьшается на единицу
void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos);

// возвращает значение ’истина’ если все элементы
// массива data размера n соответствует функции-предикату predicate
// иначе - ’ложь’
int all_(const int *a, size_t n, int (*predicate )(int));

// возвращает значение ’истина’ если хотя бы один элемент
// массива data размера n соответствует функции-предикату predicate
// иначе - ’ложь’
int any_(const int *a, size_t n, int (*predicate )(int));

// применяет функцию predicate ко всем элементам массива source
// размера n и сохраняет результат в массиве dest размера n
void forEach_(const int *source, int *dest, size_t n, const int (*
predicate )(int));

// возвращает количество элементов массива data размера n
// удовлетворяющих функции-предикату predicate
int countIf_(const int *a, size_t n, int (*predicate )(int));

// удаляет из массива data размера n все элементы, удовлетворяющие
// функции-предикату deletePredicate, записывает в n новый размер
// массива
void deleteIf_(int *a, size_t *n, int (*deletePredicate )(int));

// возвращает максимальный элемент из двух.
int max(int a, int b);

// возвращает минимальный элемент из двух.
int min(int a, int b);

// возвращает расстояние точек от начала координат
float getDistance(int *a, int n);

// считает количество одинаковых элементов.
int countEqual(long long *a, int n);

//Эта функция предназначена для сравнения двух значений типа long long
// и используется как параметр для стандартной функции сортировки qsort
int cmp_long_long(const void *pa, const void *pb);

// выводит массив типа long long.
void outputArray_LL(const long long *a, size_t n);

//принимает два указателя на целочисленные переменные и меняет их значения местами,
// используя временную переменную для сохранения одного из значений.
void swap(int *a, int *b);

#endif
