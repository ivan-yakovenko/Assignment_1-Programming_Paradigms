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
    dynamicArray->capacity = 1;
    dynamicArray->data = malloc(dynamicArray->capacity * sizeof(char *));
    for (size_t i = 0; i <= dynamicArray->capacity; i++) {
        dynamicArray->data[i] = (char *) malloc(dynamicArray->capacity * sizeof(char ));
            if(dynamicArray->data[i] == NULL) {
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
//    if(dynamicArray->cols == dynamicArray->capacity) {
//        Resize(dynamicArray, strlen(newValue));
//    }

//    size_t size = dynamicArray->rows*dynamicArray->cols;

//    for(size_t i = 0; i < strlen(newValue) / dynamicArray->capacity; i++) {
//if(dynamicArray->cols == dynamicArray->capacity) {

//    if (dynamicArray->cols == 0 && dynamicArray->rows >= 0) {
//        dynamicArray->data[dynamicArray->rows] = (char **) malloc(dynamicArray->capacity * sizeof(char *));
//        for (size_t j = 0; j < dynamicArray->capacity; j++) {
//            dynamicArray->data[dynamicArray->rows][j] = (char *) malloc(dynamicArray->capacity * sizeof(char));
//        }
//    }

    for (size_t i = 0; i < strlen(newValue); i++) {
//        if (dynamicArray->cols == dynamicArray->capacity) {
//            Resize(dynamicArray, 1);
//        }
        Resize(dynamicArray, 1);
        dynamicArray->data[dynamicArray->rows][dynamicArray->cols] = newValue[i];
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

void AddNewLine(struct DynamicArray *dynamicArray) {
    PushBack(dynamicArray, "\0");

//    Resize(dynamicArray, 1);

//    dynamicArray->data[dynamicArray->rows] = malloc(dynamicArray->capacity*sizeof(char*));
//    for (size_t i = 0; i < dynamicArray->capacity; i++) {
//        dynamicArray->data[dynamicArray->rows][i] = (char*) malloc(dynamicArray->capacity*sizeof (char));
//    }
    dynamicArray->rows++;
    dynamicArray->cols = 0;

//    dynamicArray->data[dynamicArray->rows][dynamicArray->cols] = malloc(sizeof(char));

//    if(dynamicArray->rows == dynamicArray->capacity) {
//        Resize(dynamicArray, 1);
//    }


//    dynamicArray->data[dynamicArray->rows] = (char**) malloc(newValuesSize * sizeof(char *));
//    for (size_t i = 0; i < newValuesSize; i++) {
//        dynamicArray->data[dynamicArray->rows][i] = (char*) malloc(newValuesSize*sizeof(char));
//    }
}


void Print(struct DynamicArray *dynamicArray) {
    printf("2D Array:\n");

    for (size_t i = 0; i <= dynamicArray->rows; i++) {
        for (size_t j = 0; j < dynamicArray->cols; j++) {
            if(dynamicArray->data[i][j] != '\0') {
                printf("%c", dynamicArray->data[i][j]);
            }

        }
        printf("\n");
        }

}


//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//
//struct DynamicArray {
//    char ***data;
//    size_t rows;
//    size_t cols;
//    size_t capacity;
//};
//
//void DynamicArrayDefault(struct DynamicArray *dynamicArray) {
//    dynamicArray->rows = 0;
//    dynamicArray->cols = 0;
//    dynamicArray->capacity = 1;
//    dynamicArray->data = malloc(dynamicArray->capacity * sizeof(char **));
//    for (size_t i = 0; i <= dynamicArray->capacity; i++) {
//        dynamicArray->data[i] = (char **) malloc(dynamicArray->capacity * sizeof(char *));
//        for (size_t j = 0; j <= dynamicArray->capacity; j++) {
//            dynamicArray->data[i][j] = (char *) malloc(dynamicArray->capacity * sizeof(char));
//            if(dynamicArray->data[i][j] == NULL) {
//                return;
//            }
//        }
//    }
//}
//
//size_t getCapacity(struct DynamicArray *dynamicArray) {
//    return dynamicArray->capacity;
//}
//
//void Resize(struct DynamicArray *dynamicArray, size_t newValuesSize) {
//    size_t oldCapacity = getCapacity(dynamicArray);
//    size_t newCapacity = oldCapacity + newValuesSize;
//    char ***newData = (char ***) realloc(dynamicArray->data, newCapacity * sizeof(char **));
//    if (newData == NULL) {
//        return;
//    }
//    dynamicArray->data = newData;
//    for (size_t i = oldCapacity; i < newCapacity; i++) {
//        dynamicArray->data[i] = (char **) realloc(dynamicArray->data[i], newCapacity * sizeof(char *));
//        if (dynamicArray->data[i] == NULL) {
//            return;
//        }
//        for (size_t j = 0; j < newCapacity; j++) {
//            dynamicArray->data[i][j] = (char *) realloc(dynamicArray->data[i][j], newCapacity * sizeof(char));
//            if (dynamicArray->data[i][j] == NULL) {
//                return;
//            }
//        }
//    }
//    dynamicArray->capacity = newCapacity;
//
//}
//
//void PushBack(struct DynamicArray *dynamicArray, char *newValue) {
////    if(dynamicArray->cols == dynamicArray->capacity) {
////        Resize(dynamicArray, strlen(newValue));
////    }
//
////    size_t size = dynamicArray->rows*dynamicArray->cols;
//
////    for(size_t i = 0; i < strlen(newValue) / dynamicArray->capacity; i++) {
////if(dynamicArray->cols == dynamicArray->capacity) {
//
////    if (dynamicArray->cols == 0 && dynamicArray->rows >= 0) {
////        dynamicArray->data[dynamicArray->rows] = (char **) malloc(dynamicArray->capacity * sizeof(char *));
////        for (size_t j = 0; j < dynamicArray->capacity; j++) {
////            dynamicArray->data[dynamicArray->rows][j] = (char *) malloc(dynamicArray->capacity * sizeof(char));
////        }
////    }
//
//    for (size_t i = 0; i < strlen(newValue); i++) {
////        if (dynamicArray->cols == dynamicArray->capacity) {
////            Resize(dynamicArray, 1);
////        }
//        Resize(dynamicArray, 1);
//        dynamicArray->data[dynamicArray->rows][dynamicArray->cols] = (char*)malloc(sizeof(char));
//        *dynamicArray->data[dynamicArray->rows][dynamicArray->cols] = newValue[i];
//        dynamicArray->cols++;
//    }
//
//
////    Resize(dynamicArray, strlen(newValue));
////    strcpy(dynamicArray->data, newValue);
////    dynamicArray->cols++;
////    }
////
////    size_t length = sizeof(newValue);
////    printf("%zu", length);
//}
//
//void AddNewLine(struct DynamicArray *dynamicArray) {
//    PushBack(dynamicArray, "\0");
//
////    Resize(dynamicArray, 1);
//
//    dynamicArray->data[dynamicArray->rows] = malloc(dynamicArray->capacity*sizeof(char*));
//    for (size_t i = 0; i < dynamicArray->capacity; i++) {
//        dynamicArray->data[dynamicArray->rows][i] = (char*) malloc(dynamicArray->capacity*sizeof (char));
//    }
//    dynamicArray->rows++;
//    dynamicArray->cols = 0;
//
////    dynamicArray->data[dynamicArray->rows][dynamicArray->cols] = malloc(sizeof(char));
//
////    if(dynamicArray->rows == dynamicArray->capacity) {
////        Resize(dynamicArray, 1);
////    }
//
//
////    dynamicArray->data[dynamicArray->rows] = (char**) malloc(newValuesSize * sizeof(char *));
////    for (size_t i = 0; i < newValuesSize; i++) {
////        dynamicArray->data[dynamicArray->rows][i] = (char*) malloc(newValuesSize*sizeof(char));
////    }
//}
//
//
//void Print(struct DynamicArray *dynamicArray) {
//    printf("2D Array:\n");
//
//    for (size_t i = 0; i <= dynamicArray->rows; i++) {
//        for (size_t j = 0; j < dynamicArray->cols; j++) {
//            if(*dynamicArray->data[i][j] == '\0') {
//                i++;
//                printf("\n");
//            }
//            else {
//                printf("%c", *dynamicArray->data[i][j]);
//            }
//        }
//    }
//
//}



