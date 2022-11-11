// Test #1
// By Tommy Levasseur
// Friday 21

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h> // Imports "system("@cls")" and "system("pause")" function

int IsNumberLower(int guess, int num);
void IsNumberCorrect(int guess, int num, char play);
void PlayAgain(char play);

void main()
{
    srand(time(NULL));
    int num = (rand() % 75) + 1;
    // int num = 50;
    int guess;
    char play;

    while (true) // Loops following code
    {
        printf("\nEnter a number from 1-75: ");
        scanf(" %d", &guess);

        if (IsNumberLower(guess, num) == 1)
        {
            system("@cls");
            printf("\nYour guess '");
            printf("%d", guess);
            printf("' is to high");
        }

        IsNumberCorrect(guess, num, play);
    }
}

int IsNumberLower(int guess, int num)
{
    if (guess < num) // If user guess is smaller than number
    {
        system("@cls");
        printf("\nYour guess '");
        printf("%d", guess);
        printf("' is to low");
    }

    else // If user guess is bigger than number
    {
        return 1;
    }
}

void IsNumberCorrect(int guess, int num, char play)
{
    if (guess == num) // If user guess is correct to number : run
    {
        system("@cls");
        printf("\nYour guess '");
        printf("%d", guess);
        printf("' is correct!");
        PlayAgain(play);
    }
}

void PlayAgain(char play)
{
    printf("\nWould you like to play again? 'y/n' : ");
    scanf(" %c", &play);

    if (play == 'y' || play == 'Y')
    {
        main();
    }

    else if (play == 'n' || play == 'N')
    {
        printf("\nThanks for playing!");
        exit(0);
    }
}