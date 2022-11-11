// Lab 6
// By Tommy Levasseur
// Tuesday, Nov 8, 2022
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h> // Imports "system("cls||clear")" and "system("pause")" function

int main(void)
{
    int choice;
    int num;
    int *ptr;

    char play = 'y';

    bool run = true;

    ptr = &num;

    while (play == 'y' || play == 'Y')
    {
        printf("\n\t- Enter a New Integer Value");
        printf("\n\t- Print Pointer Address");
        printf("\n\t- Print Integer Address");
        printf("\n\t- Print integer Value");

        printf("\n\nPlease select one of the 4 options (1,2,3,4): ");
        scanf("%d", &choice);

        switch (choice)
        {
            // Enter a New Integer Value
        case 1:
            system("cls||clear");

            printf("Enter a Integer: ");
            scanf(" %d", &*ptr);
            break;
            // Print Pointer Address
        case 2:
            system("cls||clear");

            printf("The address of the Pointer is %p\n", ptr);

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

            break;
            // Print Integer Address
        case 3:
            system("cls||clear");

            printf("The address of the Integer is %p\n", &num);

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

            break;
            // Print integer Value
        case 4:
            system("cls||clear");

            printf("The value of the Integer is %d\n", *ptr);

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

            break;
        default:

            break;
        }
    }
}