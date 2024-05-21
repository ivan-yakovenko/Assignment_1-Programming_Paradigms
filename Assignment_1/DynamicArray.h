#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct DynamicArray {
    char **data;
    size_t rows;
    size_t cols;
    size_t capacity;
};

void DynamicArrayDefault(struct DynamicArray *dynamicArray) {
    dynamicArray->rows = 0;
    dynamicArray->cols = 0;
    dynamicArray->capacity = 0;
    dynamicArray->data = malloc(dynamicArray->capacity * sizeof(char *));
    for (size_t i = 0; i <= dynamicArray->capacity; i++) {
        dynamicArray->data[i] = (char *) malloc(dynamicArray->capacity * sizeof(char));
        if (dynamicArray->data[i] == NULL) {
            return;
        }
    }
}

size_t getCapacity(struct DynamicArray *dynamicArray) {
    return dynamicArray->capacity;
}

void Resize(struct DynamicArray *dynamicArray, size_t newValuesSize) {
    size_t oldCapacity = getCapacity(dynamicArray);
    size_t newCapacity = oldCapacity + newValuesSize;
    char **newData = (char **) realloc(dynamicArray->data, newCapacity * sizeof(char *));
    if (newData == NULL) {
        return;
    }
    dynamicArray->data = newData;
    for (size_t i = oldCapacity; i < newCapacity; i++) {
        dynamicArray->data[i] = (char *) realloc(dynamicArray->data[i], newCapacity * sizeof(char));
        if (dynamicArray->data[i] == NULL) {
            return;
        }
    }

    dynamicArray->capacity = newCapacity;
}


void PushBack(struct DynamicArray *dynamicArray, char *newValue) {

    size_t newValueLength = strlen(newValue);
    Resize(dynamicArray, newValueLength);


    for (size_t i = 0; i < newValueLength; i++) {
        dynamicArray->data[dynamicArray->rows][dynamicArray->cols] = newValue[i];
        dynamicArray->cols++;
    }

}

void AddNewLine(struct DynamicArray *dynamicArray) {
    PushBack(dynamicArray, "\0");

    Resize(dynamicArray, 1);

    dynamicArray->rows++;
    dynamicArray->cols = 0;

}

void Insert(struct DynamicArray *dynamicArray, int line, int index, char *newValue) {
    if (line >= dynamicArray->rows) {
        printf("Out of range");
        return;
    }

    int length = strlen(dynamicArray->data[line]);
    if (index > length) {
        Resize(dynamicArray, index - length + strlen(newValue));
        for (int i = length; i < index; i++) {
            dynamicArray->data[line][i] = ' ';
        }
    } else {
        Resize(dynamicArray, strlen(newValue));
        memmove(&dynamicArray->data[line][index + strlen(newValue)], &dynamicArray->data[line][index],
                length - index + 1);
    }

    for (int k = 0; k < strlen(newValue); k++) {
        dynamicArray->data[line][index + k] = newValue[k];
        dynamicArray->cols += strlen(newValue);
    }

}

void Search(struct DynamicArray *dynamicArray, char *text) {
    size_t textLength = strlen(text);
    for (size_t i = 0; i < dynamicArray->rows; i++) {
        size_t rowLength = strlen(dynamicArray->data[i]);
        for (size_t j = 0; j < rowLength; j++) {
            if (strncmp(&dynamicArray->data[i][j], text, textLength) == 0) {
                printf("%zu, %zu", i, j);
                return;
            }
        }
    }
    printf("Text not found");
}

void Print(struct DynamicArray *dynamicArray) {
    printf("2D Array:\n");

    for (size_t i = 0; i <= dynamicArray->rows; i++) {
        size_t j = 0;
        while (dynamicArray->data[i][j] != '\0') {
            printf("%c", dynamicArray->data[i][j]);
            j++;
        }
        printf("\n");

    }
}
