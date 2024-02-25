#include "vectorVoid.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    void *data = malloc(baseTypeSize * n);
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vectorVoid) {data, 0, n, baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
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

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
}

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    if (index < v->size) {
        char *source = (char *) v->data + index * v->baseTypeSize;
        memcpy(destination, source, v->baseTypeSize);
    } else {
        fprintf(stderr, "%zu index is out of size", index);
        exit(1);
    }
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    if (index >= v->size) {
        fprintf(stderr, "%zu index not in vector", index);
        exit(1);
    }
    char *destination = (char *) (v->data + index * v->baseTypeSize);
    memcpy(destination, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "vector is empty");
        exit(1);
    } else {
        v->size--;
        shrinkToFitV(v);
    }
}

void pushBackV(vectorVoid *v, void *source) {
    if (isFullV(v)) {
        reserveV(v, v->capacity == 0 ? 1 : v->capacity * 2);
    }
    char *destination = (char *) (v->data + v->size++ * v->baseTypeSize);
    memcpy(destination, source, v->baseTypeSize);
}

