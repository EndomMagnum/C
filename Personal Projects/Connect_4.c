#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> // Imports "system("@cls")" and "system("pause")" function

void printBoard(char boardIndex[6][7]);
void playerMove(char boardIndex[6][7], char frees);
int checkWin(char boardIndex[6][7]);

void printBoard(char boardIndex[6][7])
{
    printf("___________________________________________\n");
    printf("|     |     |     |     |     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", boardIndex[0][0], boardIndex[0][1], boardIndex[0][2], boardIndex[0][3], boardIndex[0][4], boardIndex[0][5], boardIndex[0][6]);
    printf("|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("|     |     |     |     |     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", boardIndex[1][0], boardIndex[1][1], boardIndex[1][2], boardIndex[1][3], boardIndex[1][4], boardIndex[1][5], boardIndex[1][6]);
    printf("|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("|     |     |     |     |     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", boardIndex[2][0], boardIndex[2][1], boardIndex[2][2], boardIndex[2][3], boardIndex[2][4], boardIndex[2][5], boardIndex[2][6]);
    printf("|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("|     |     |     |     |     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", boardIndex[3][0], boardIndex[3][1], boardIndex[3][2], boardIndex[3][3], boardIndex[3][4], boardIndex[3][5], boardIndex[3][6]);
    printf("|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("|     |     |     |     |     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", boardIndex[4][0], boardIndex[4][1], boardIndex[4][2], boardIndex[4][3], boardIndex[4][4], boardIndex[4][5], boardIndex[4][6]);
    printf("|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("|     |     |     |     |     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", boardIndex[5][0], boardIndex[5][1], boardIndex[5][2], boardIndex[5][3], boardIndex[5][4], boardIndex[5][5], boardIndex[5][6]);
    printf("|_____|_____|_____|_____|_____|_____|_____|\n\n");
}

void playerMove(char boardIndex[6][7], char free)
{
    int move;

    printf("What is your move? (1-7): ");
    scanf(" %d", &move);

    for (int i = 5; i >= 0; i--)
    {
        if (boardIndex[i][move - 1] == free)
            boardIndex[i][move - 1] = 'X';
    }
}

void main()
{
    bool playing = true;
    char free = ' ';
    int player = 1;
    bool win = false;

    char boardIndex[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', ' ', ' ', ' '}};
    while (playing == true)
    {
        // system("@cls");

        printBoard(boardIndex);
        playerMove(boardIndex, free);
    }
}