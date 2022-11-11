// Lab 4b
// Prime number calculator
// By Tommy Levasseur
// Thursday, Nov 3, 2022

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h> // Imports "system("@cls")" and "system("pause")" function

int main()
{
    int width = 12;
    int height = 12;

    int arr[width][height];
    int x, y, i;
    int input;

    int found = 0;

    char run = 'y';
    bool again = true;

    while (run == 'y' || run == 'Y')
    {
        system("@cls");

        printf("\nEnter a number from 1 - 144 : ");
        scanf(" %d", &input);

        if (input < 1 || input > 144)
        {
        }
        else
        {

            for (x = 2; x <= width; x++)
            {
                for (y = 2; y <= height; y++)
                {
                    // Makes the table
                    arr[x + 1][y + 1] = x * y;
                    // If input is in table
                    if (input == x * y)
                    {
                        printf("\n%d can be created by multiplying %d and %d", input, x, y);
                        found = 1;
                    }
                }
            }
            // If input is not in table
            if (found != 1)
            {
                printf("\n%d Is a prime number and is not in the table", input);
            }
            // Run again?
            do
            {
                printf("\n\nWould you like to search for a new number? (y/n): ");
                scanf(" %c", &run);
                if (run == 'n' || run == 'N')
                {
                    printf("Goodbye!");
                    again = false;
                }
                else if (run == 'y' || run == 'Y')
                {
                    again = false;
                    found = 0;
                }
            } while (again == true);
        }
    }
}
