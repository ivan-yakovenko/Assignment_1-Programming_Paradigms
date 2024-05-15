#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct DynamicArray {
    char*** data;
    size_t rows;
    size_t cols;
    size_t capacity;
};

void DynamicArrayDefault(struct DynamicArray* dynamicArray) {
    dynamicArray->rows = 0;
    dynamicArray->cols = 0;
    dynamicArray->capacity = 0;
    dynamicArray->data = malloc(dynamicArray->capacity * sizeof(char**));
    for(size_t i = 0; i <= dynamicArray->capacity; i++) {
        dynamicArray->data[i] = (char**)malloc(dynamicArray->capacity * sizeof(char*));
        for(size_t j = 0; j <= dynamicArray->capacity; j++) {
            dynamicArray->data[i][j] = (char*)malloc(dynamicArray->capacity * sizeof(char));
//            if(dynamicArray->data[i] = NULL) {
//                return;
//            }
        }
    }
}

size_t getCapacity(struct DynamicArray* dynamicArray) {
    return dynamicArray->capacity;
}

void Resize(struct DynamicArray* dynamicArray, int newValuesSize) {
//    size_t oldCapacity = getCapacity(dynamicArray);

    size_t newCapacity = getCapacity(dynamicArray) + newValuesSize;
    char*** newData = (char***)realloc(dynamicArray->data, newCapacity * sizeof(char**));
//    if (newData == NULL) {
//        return;
//    }
    dynamicArray->data = newData;
    dynamicArray->capacity = newCapacity;
    for(size_t i = getCapacity(dynamicArray); i < newCapacity; i++) {
        dynamicArray->data[i] = (char**)malloc(newCapacity * sizeof(char *));
        for(size_t j = getCapacity(dynamicArray); j < newCapacity; j++) {
            dynamicArray->data[i][j] = (char*)malloc(newCapacity * sizeof(char));
            if (dynamicArray->data[i][j] == NULL) {
                return;
            }
        }
    }

}

void AddNewLine(struct DynamicArray* dynamicArray, int newValueSize) {
    Resize(dynamicArray, newValueSize);
    dynamicArray->rows++;
}

void PushBack(struct DynamicArray* dynamicArray, char* newValue) {
//    if(dynamicArray->cols == dynamicArray->capacity) {
//        Resize(dynamicArray);
//    }

//    size_t size = dynamicArray->rows*dynamicArray->cols;

//    for(size_t i = 0; i < strlen(newValue) / dynamicArray->capacity; i++) {
//if(dynamicArray->cols == dynamicArray->capacity) {
    for(size_t i = 0; i < strlen(newValue); i++) {
        Resize(dynamicArray, 1);
        dynamicArray->data[dynamicArray->rows][dynamicArray->cols] = &newValue[i];
        dynamicArray->cols++;
    }


//    Resize(dynamicArray, strlen(newValue));
//    strcpy(dynamicArray->data, newValue);
//    dynamicArray->cols++;
//    }
//
//    size_t length = sizeof(newValue);
//    printf("%zu", length);
}

void Print(struct DynamicArray* dynamicArray) {
    printf("2D Array:\n");

//    for (size_t j = 0; j < dynamicArray->cols; j++) {
//        printf("%zu", sizeof(dynamicArray->cols));
//    }

    for (size_t i = 0; i <= dynamicArray->rows; i++) {
        for (size_t j = 0; j < dynamicArray->cols; j++) {
            printf("%c", *dynamicArray->data[i][j]);
        }

    }
}