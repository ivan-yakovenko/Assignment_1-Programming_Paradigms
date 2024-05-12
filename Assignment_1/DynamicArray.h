#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct DynamicArray {
    char** data;
    size_t size;
    size_t capacity;

};

void DynamicArrayDefault(struct DynamicArray* dynamicArray) {
    dynamicArray->data = malloc(dynamicArray->capacity);
    dynamicArray->size = 0;
    dynamicArray->capacity = 1;
}

//void DynamicArray(struct DynamicArray* dynamicArray, int capacity) {
//    dynamicArray->capacity = capacity;
//    dynamicArray->data = malloc(dynamicArray->capacity);
//    dynamicArray->size = 0;
//}

size_t getSize(struct DynamicArray* dynamicArray) {
    return dynamicArray->size;
}

size_t getCapacity(struct DynamicArray* dynamicArray) {
    return dynamicArray->capacity;
}

void Resize(struct DynamicArray* dynamicArray) {
    size_t newCapacity = dynamicArray->capacity * 2;
    char** newData = (char**)realloc(dynamicArray->data,newCapacity*sizeof(char*));

    dynamicArray->data = newData;
    dynamicArray->capacity = newCapacity;
}

void PushBack(struct DynamicArray* dynamicArray, char* newValue) {
    if(dynamicArray->size == dynamicArray->capacity) {
        Resize(dynamicArray);
    }
    dynamicArray->data[dynamicArray->size++] = newValue;
}

void Print(struct DynamicArray* dynamicArray) {
    for(int i = 0; i < dynamicArray->size; i++) {
        printf("%s\n", dynamicArray->data[i]);
    }
}