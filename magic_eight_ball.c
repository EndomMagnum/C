// Lab 2
// Program #1
// By Tommy Levasseur
// Friday 30

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
    int ans_type = (rand() % 3) + 1;
    char question[50];

    system("@cls");
    printf("\nAsk the magic eight ball a question : ");
    scanf(" %s", &question);

    switch (ans_type)
    {
    case 1: // 10 affirmative answers
        srand(time(NULL));
        int aff_ans = (rand() % 10) + 1;
        system("@cls");

        switch (aff_ans)
        {
        case 1:
            system("@cls");
            printf("It is certain.");
            break;

        case 2:
            system("@cls");
            printf("It is decidedly so.");
            break;

        case 3:
            system("@cls");
            printf("Without a doubt");
            break;

        case 4:
            system("@cls");
            printf("Yes definitely.");
            break;

        case 5:
            system("@cls");
            printf("You may rely on it.");
            break;

        case 6:
            system("@cls");
            printf("As I see it, yes.");
            break;

        case 7:
            system("@cls");
            printf("Most likely.");
            break;

        case 8:
            system("@cls");
            printf("Outlook good.");
            break;

        case 9:
            system("@cls");
            printf("Yes.");
            break;

        case 10:
            system("@cls");
            printf("Signs point to yes.");
            break;
        }
        break;

    case 2: // 5 non-committal answers

        srand(time(NULL));
        int nonc_ans = (rand() % 5) + 1;
        system("@cls");

        switch (nonc_ans)
        {
        case 1:
            system("@cls");
            printf("Reply hazy, try again.");
            break;
        case 2:
            system("@cls");
            printf("Ask again later.");
            break;
        case 3:
            system("@cls");
            printf("Better not tell you now.");
            break;
        case 4:
            system("@cls");
            printf("Cannot predict now.");
            break;
        case 5:
            system("@cls");
            printf("Concentrate and ask again.");
            break;
        }

        break;

    case 3: // 5 negative answers

        srand(time(NULL));
        int neg_ans = (rand() % 5) + 1;
        system("@cls");

        switch (neg_ans)
        {
        case 1:
            system("@cls");
            printf("Don't count on it.");
            break;
        case 2:
            system("@cls");
            printf("My reply is no.");
            break;
        case 3:
            system("@cls");
            printf("My sources say no.");
            break;
        case 4:
            system("@cls");
            printf("Outlook not so good.");
            break;
        case 5:
            system("@cls");
            printf("Very doubtful.");
            break;
        }

        break;
    }
}