#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h> // Imports "system("@cls")" and "system("pause")" function

int main(void)
{
    srand(time(NULL));
    int num = (rand() % 10) + 1;
    long guess;
    int val_guess = 4;
    // Int checker variable
    char *p, s[100];
    //
    system("@cls");

    while (true) // Loops following code
    {
        printf("\nNumber of guesses left : %d", val_guess);
        printf("\nEnter a number from 1-10: ");

        while (fgets(s, sizeof(s), stdin)) // If user input does not = an "int" :
        {
            guess = strtol(s, &p, 10);
            if (p == s || *p != '\n')
            {
                system("@cls");
                printf("\nThat is'nt a valid number, try again");
                printf("\nNumber of guesses left : %d", val_guess);
                printf("\nEnter a number from 1-10: ");
            }
            else
            {
                break;
            }
        }

        if (guess != num) // If guess is not = number : use a valid guess
        {
            val_guess--;
        }

        if (val_guess >= 1) // If user valid guesses : run
        {

            if (guess < num) // If user guess is smaller than number : run
            {
                system("@cls");
                printf("\nYour guess '");
                printf("%d", guess);
                printf("' is to low");
            }

            else if (guess > num) // If user guess is bigger than number : run
            {
                system("@cls");
                printf("\nYour guess '");
                printf("%d", guess);
                printf("' is to high");
            }

            else // If user guesses correct number : run
            {
                system("@cls");
                printf("\nYou guessed it! The number was %d\n", num);
                system("pause");
                main();
            }
        }

        else // If user has no more valid guesses : end
        {
            system("@cls");
            printf("\nYou are out of guesses, you lose\n");
            system("pause");
            main();
        }
    }
}