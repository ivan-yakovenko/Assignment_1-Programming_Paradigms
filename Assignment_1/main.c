#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "DynamicArray.h"

int main() {
    struct DynamicArray dynamicArray;
    DynamicArrayDefault(&dynamicArray);

    char *text = "Hi";
    char *text1 = "My name is Ivan";
    char *text2 = "I am student of KE";
    char *text3 = "Bye";
    char *text4 = "Yours sincerely";
    char *text5 = "Ivan";
    char *text6 = "S";
    char *text7 = " ITBA";

    AddNewLine(&dynamicArray);
    PushBack(&dynamicArray, text);
    AddNewLine(&dynamicArray);
    PushBack(&dynamicArray, text1);
    AddNewLine(&dynamicArray);
    PushBack(&dynamicArray, text2);
    AddNewLine(&dynamicArray);
    PushBack(&dynamicArray, text3);
    AddNewLine(&dynamicArray);
    PushBack(&dynamicArray, text4);
    AddNewLine(&dynamicArray);
    PushBack(&dynamicArray, text5);
    Insert(&dynamicArray, 3, 17, text6);
    Insert(&dynamicArray, 3, 19, text7);
    Print(&dynamicArray);
    Search(&dynamicArray, "CHAN");
    return 0;
}