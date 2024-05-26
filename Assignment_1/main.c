#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "DynamicArray.h"

int main() {
    struct DynamicArray dynamicArray;
    DynamicArrayDefault(&dynamicArray);
    while (1) {
        printf("Choose the command: \n");
        char command;
        scanf(" %c", &command);
        while((getchar() != '\n'));

        switch (command) {
            case '1' : {
                printf("Enter text to append: ");
                char *text = malloc(256 * sizeof (char));
                scanf("%[^\n]", text);
                PushBack(&dynamicArray, text);
                free(text);
                break;
            }
            case '2': {
                AddNewLine(&dynamicArray);
                printf("New line is started \n");
                break;
            }
            case '3': {
                char *filename;
                while(1) {
                    printf("Enter the file name for saving: ");
                    scanf("%s", filename);
                    if(strstr(filename, ".txt") != NULL) {
                        break;
                    }
                    printf("Invalid file name, try again with '.txt' \n");
                }
                SaveInfo(&dynamicArray, filename);
                break;
            }
            case '4': {
                char *filename;
                while(1) {
                    printf("Enter the file name for loading: ");
                    scanf("%s", filename);
                    if(strstr(filename, ".txt") != NULL) {
                        break;
                    }
                    printf("Invalid file name, try again with '.txt' \n");
                }
                LoadInfo(&dynamicArray, filename);
                break;
            }
            case '5': {
                Print(&dynamicArray);
                printf("\n");
                break;
            }
            case '6': {
                printf("Choose line and index: ");
                int line, index;
                scanf("%d %d", &line, &index);
                while((getchar() != '\n'));
                printf("Enter text to insert: ");
                char *text = malloc(256*sizeof (char));
                scanf("%[^\n]", text);
                Insert(&dynamicArray, line, index, text);
                free(text);
                break;
            }
            case '7': {
                printf("Enter text to search: ");
                char *text = malloc(256 * sizeof (char));
                scanf("%[^\n]", text);
                Search(&dynamicArray, text);
                free(text);
                break;
            }
            default: {
                printf("Wrong command \n");
                break;
            }
        }

    }

}