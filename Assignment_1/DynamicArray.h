#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct DynamicArray {
    int* data;
    size_t size;
    size_t capacity;

};

void DynamicArray_init(struct DynamicArray* dynamicArray) {
    dynamicArray->data = nullptr;
    dynamicArray->size = 0;
    dynamicArray->capacity = 1;
}

size_t getSize(struct DynamicArray* dynamicArray) {
    return dynamicArray->size;
}

size_t getCapacity(struct DynamicArray* dynamicArray) {
    return dynamicArray->capacity;
}

void Resize(struct DynamicArray* dynamicArray) {
    size_t newCapacity = dynamicArray->capacity * 2;
    int* newData = (int*)realloc(dynamicArray->data,newCapacity*sizeof(int));

    dynamicArray->data = newData;
    dynamicArray->capacity = newCapacity;
}

void PushBack(struct DynamicArray* dynamicArray, int newValue) {
    if(dynamicArray->size == dynamicArray->capacity) {
        Resize(dynamicArray);
    }
    dynamicArray->data[dynamicArray->size++] = newValue;
}








