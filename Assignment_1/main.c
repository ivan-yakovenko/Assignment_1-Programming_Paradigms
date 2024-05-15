#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "DynamicArray.h"

int main() {
    struct DynamicArray dynamicArray;
    DynamicArrayDefault(&dynamicArray);

//    int command;
//
//    printf("Choose the command: \n");
//    scanf("%d", &command);

    PushBack(&dynamicArray, "Hello ");
    //AddNewLine(&dynamicArray, sizeof(text));
    PushBack(&dynamicArray, "BYE");

    PushBack(&dynamicArray, " NO");
    Print(&dynamicArray);

//    switch (command) {
//        case 1:
//            printf("Enter text to append:");
//            char* text;
//            scanf("%s", text);
//            PushBack(&dynamicArray, text);
//            break;
//        case 2:
//            AddNewLine(&dynamicArray);
//            printf("New line is started");
//        case 5:
//            Print(&dynamicArray);
//        default:
//            break;
//    }

//    PushBack(&dynamicArray, "Hi ");
//    PushBack(&dynamicArray, "Me ");
//    AddNewLine(&dynamicArray);
//    PushBack(&dynamicArray, "Bye");


}