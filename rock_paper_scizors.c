#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>

void player() // Player move function
{
    char playerMove;
    printf("\nEnter a number from 1-10: ");
    scanf(" %c", &playerMove);

    if (playerMove == 'r') // When player plays 'r'
    {
        system("@cls");
        printf("player played rock");
    }

    else if (playerMove == 'p') // When player plays 'p'
    {
        system("@cls");
        printf("player played paper");
    }

    else if (playerMove == 's') // When player plays 's'
    {
        system("@cls");
        printf("player played scissors");
    }

    else // When player plays 'other'
    {
        system("@cls");
        printf("that isnt a legal move, pick again");
        player();
    }
    bot();
}

void bot(botMove) // Bot Move Function
{
    if (botMove == 1)
    { // When bot rolls 1
        printf("\nbot played rock");
    }

    if (botMove == 2)
    { // When bot rolls 2
        printf("\nbot played paper");
    }

    if (botMove == 3)
    { // When bot rolls 3
        printf("\nbot played scissors");
    }
    win();
}

void win(playerMove, botMove)
{

    // Player Win
    if (playerMove == "r" && botMove == 3)
    {
        printf("\nPlayer wins!");
    }
    else if (playerMove == "p" && botMove == 1)
    {
        printf("\nPlayer wins!");
    }
    else if (playerMove == "s" && botMove == 2)
    {
        printf("\nPlayer wins!");
    }

    // Bot Win
    if (playerMove == "r" && botMove == 2)
    {
        printf("\nBot wins!");
    }
    else if (playerMove == "p" && botMove == 3)
    {
        printf("\nBot wins!");
    }
    else if (playerMove == "s" && botMove == 1)
    {
        printf("\nBot wins!");
    }

    // Tie
    if (playerMove == "r" && botMove == 1)
    {
        printf("\nIt's a tie!, no one wins.");
    }
    else if (playerMove == "p" && botMove == 2)
    {
        printf("\nIt's a tie!, no one wins.");
    }
    else if (playerMove == "s" && botMove == 3)
    {
        printf("\nIt's a tie!, no one wins.");
    }
    system("@cls");
    rpsGame();
}

void rpsGame()
{
    srand(time(NULL));
    int botMove = (rand() % 3) + 1; // Generates bot move

    player();
    bot();
    win();
    player();
}

int main(void)
{
    rpsGame();
}
