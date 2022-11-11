// Lab 2
// Program #2
// By Tommy Levasseur
// Friday 30

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h> // Imports "system("@cls")" and "system("pause")" function

void main()
{
    system("@cls");
    srand(time(NULL));
    int dice1;
    int dice2;
    int sum;

    system("pause"); // Press a key to roll dice

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
    }

    else
    {
        printf("\nYou lose! The sum is %d get better!", sum);
    }
}