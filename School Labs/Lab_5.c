// Lab 5
// By Tommy Levasseur
// Monday, Nov 7, 2022

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h> // Imports "system("cls||clear")" and "system("pause")" function

void main()
{

    char name[255];

    char play = 'y';

    bool run = true;

    while (play == 'y' || play == 'Y')
    {
        system("cls||clear");

        printf("\nEnter your name: ");
        scanf(" %s", &name);

        int length = strlen(name);

        printf("\n%d", length);

        for (int i = length - 1; i >= 0; i--)
        {
            if (i == 0 || i == length)
                printf("%c", name[i]);
            else
                printf("%c * ", name[i]);
        }
        // Run again?
        do
        {
            printf("\n\nWould you like to try again? (y/n): ");
            scanf(" %c", &play);
            if (play == 'n' || play == 'N')
            {
                printf("Goodbye!");
                return false;
            }
            else if (play == 'y' || play == 'Y')
            {
                run = false;
            }
        } while (run == true);
    }
}