#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "DynamicArray.h"

int main() {
    struct DynamicArray dynamicArray;
    DynamicArrayDefault(&dynamicArray);

    PushBack(&dynamicArray, "Hi ");
//    PushBack(&dynamicArray, "Me ");
    AddNewLine(&dynamicArray);
    PushBack(&dynamicArray, "Bye");


    Print(&dynamicArray);

}