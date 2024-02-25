#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"
#include <assert.h>

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 5);
    assert(v.size == 1);
}

void test_pushBack_fullVector() {
    vector v = createVector(3);
    pushBack(&v, 5);
    pushBack(&v, 1);
    pushBack(&v, 6);
    assert(v.size == 3);
    pushBack(&v, 7);
    assert(v.size == 4);
    assert(v.capacity == 6);
}

void test_popBack_emptyVector() {
    vector v = createVector(0);
    popBack(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(5);
    pushBack(&v, 10);
    pushBack(&v, 7);
    pushBack(&v, 8);
    pushBack(&v, 9);
    pushBack(&v, 15);
    int *index = atVector(&v, 3);
    assert(*index == 9);
}

void test_atVector_requestToLastElement(){
    vector v = createVector(5);
    pushBack(&v, 10);
    pushBack(&v, 7);
    pushBack(&v, 8);
    pushBack(&v, 9);
    pushBack(&v, 15);
    int *index = atVector(&v, 4);
    assert(*index == 15);
}

void test_back_oneElementInVector(){
    vector v = createVector(1);
    pushBack(&v, 10);
    int *index = back(&v);
    assert(*index == 10);
}
void test_front_oneElementInVector(){
    vector v = createVector(1);
    pushBack(&v, 10);
    int *index = front(&v);
    assert(*index == 10);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    //test_popBack_emptyVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();
}