#include "vectorVoid.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize){
    void *data = malloc(baseTypeSize * n);
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vectorVoid) {data, 0, n,baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity){
    if (newCapacity == 0) {
        free(v->data);
    } else {
        void *newData = realloc(v->data, newCapacity * v->baseTypeSize);
        if (newData == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        } else {
            if (newCapacity <= v->size)
                v->size = newCapacity;
            v->data = newData;
            v->capacity = newCapacity;
        }
    }
}

void shrinkToFitV(vectorVoid *v){
    reserveV(v, v->size);
}

void clearV(vectorVoid *v){
    v->size = 0;
}

void deleteVectorV(vectorVoid *v){
    free(v->data);
}