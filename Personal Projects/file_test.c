#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> // Imports "system("@cls")" and "system("pause")" function
#include <string.h>

void main()
{
    FILE *file;
    char name[25] = {'\0'};
    int num;
    int choice;

    // system("@cls");

    file = fopen("TicTacToe_LeaderBoard.txt", "r+");

    printf("\n\nWrite or Read? ");
    scanf(" %d", &choice);

    if (choice == 1)
    {
        // printf("\n\nEnter your name: ");
        // scanf(" %s", &name);

        printf("\n\nEnter a number: ");
        scanf(" %d", &num);

        // fputs(name, file);

        putw(num, file);

        fclose(file);
    }

    else if (choice == 2)
    {
        fscanf(file, " %s", &name);
        fscanf(file, " %d", &num);

        printf("\n%s - %d", name, num);

        fclose(file);
    }
}