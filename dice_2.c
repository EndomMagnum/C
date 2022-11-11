// Lab 3
// Program #1
// By Tommy Levasseur
// Tuesday 4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h> // Imports "system("@cls")" and "system("pause")" function

void main()
{
    system("clear");
    srand(time(NULL));
    int dice1;
    int dice2;
    int sum;
    int score;
    bool playing = true;
    char i;

    while (playing)
    {
        system("@cls");
        printf("\nPress 'R' to roll dice : ");
        scanf(" %c", &i);

        while (i == 'r' || i == 'R')
        {                                 // Press 'R' key to roll dice
            for (int i = 0; i < 100; i++) // Dice roller
            {
                system("@cls");
                printf("Dice #1 : %d", dice1 = (rand() % 8) + 1);
                printf("\nDice #2 : %d", dice2 = (rand() % 8) + 1);
                sum = dice1 + dice2;
            }

            if (sum == 9 || sum == 15)
            {
                printf("\nYou win! The sum is %d", sum);
                score++;
            }

            else
            {
                printf("\nYou lose! The sum is %d get better!", sum);
            }

            printf("\nYour total score is of %d", score);

            printf("\nWould you like to continue? ('Y/N') : ");
            scanf(" %c", &i);

            if (i == 'y' || i == 'Y')
            {
            }
            if (i == 'n' || i == 'N')
            {
                return 0;
            }
        }
    }
}