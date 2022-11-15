// Lab 7
// By Tommy Levasseur
// Monday 14

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Imports "system("cls||clear")" and "system("pause")" function

void main()
{
    char *phrase = "A computer once beat me at chess, but it was no match for me at kick boxing!";
    char input[255] = {'\0'};

    system("cls||clear");

    printf("\nThe phrase is: %s", phrase);

    printf("\n\n\tEnter something to search: ");
    scanf(" %s", input);

    if (strstr(phrase, input) != NULL)
        printf("\n|%s| was found in the phrase", input);
    else
        printf("\n|%s| was not found in the phrase", input);
}
