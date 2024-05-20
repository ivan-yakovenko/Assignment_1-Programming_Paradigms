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

    char* text = "Hi";
    AddNewLine(&dynamicArray);
    PushBack(&dynamicArray, text);
    AddNewLine(&dynamicArray);
    //PushBack(&dynamicArray, text);
    PushBack(&dynamicArray, text);
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

   // return 0;
}