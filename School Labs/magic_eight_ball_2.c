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
#include <string.h>

void main()
{
    srand(time(NULL));
    int ans = (rand() % 8) + 1;
    char question;
    char i;
    bool play = true;

    while (play)
    {
        system("@cls");
        printf("\nAsk a question and press 'Q' : ");
        scanf(" %c", &question);

        while (question == 'q' || question == 'Q')
        {
            switch (ans)
            {
            case 1:
                system("@cls");
                printf("\n Yes!");
                break;

            case 2:
                system("@cls");
                printf("\n No!");
                break;

            case 3:
                system("@cls");
                printf("\n Maybe...");
                break;

            case 4:
                system("@cls");
                printf("\n Ask someone else...");
                break;

            case 5:
                system("@cls");
                printf("\n I don't want to hear about you problems!");
                break;

            case 6:
                system("@cls");
                printf("\n Possible");
                break;

            case 7:
                system("@cls");
                printf("\n Don't think so");
                break;

            case 8:
                system("@cls");
                printf("\n Ur Mom!");
                break;
            }
            printf("\n Would you like to continue? ('Y/N') : ");
            scanf(" %c", &i);
            break;
        }
        if (i == 'y' || i == 'Y')
        {
        }
        if (i == 'n' || i == 'N')
        {
            return 0;
        }
    }
}