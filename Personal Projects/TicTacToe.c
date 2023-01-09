#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> // Imports "system("@cls")" and "system("pause")" function

// Function Prototypes
void printGameBoard(char gameBoardIndex[9]);
void playerMove(char gameBoardIndex[9], int player, char blank, char playerName[2][25], char playerLetter[3]);
int checkWin(char gameBoardIndex[9], int player, char blank, int num_blank, char playerName[2][25], char playerLetter[3]);

// Prints the game bored on the screen
void printGameBoard(char gameBoardIndex[9])
{
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \tQ  W  E\n", gameBoardIndex[0], gameBoardIndex[1], gameBoardIndex[2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \tA  S  D\n", gameBoardIndex[3], gameBoardIndex[4], gameBoardIndex[5]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \tZ  X  C\n", gameBoardIndex[6], gameBoardIndex[7], gameBoardIndex[8]);
    printf("     |     |     \n\n");
}

// Players moves
void playerMove(char gameBoardIndex[9], int player, char blank, char playerName[2][25], char playerLetter[3])
{
    // Blank spot pointer
    char *blankPtr;
    blankPtr = &blank;
    // Player pointer
    int *playerPtr;
    playerPtr = &player;
    // player move choice
    char move;

    printf("It's %s's (%c) turn: ", playerName[*playerPtr - 1], playerLetter[*playerPtr - 1]);
    scanf(" %c", &move);

    // If player input is 'Q'
    if (move == 'q' && gameBoardIndex[0] == *blankPtr)
    {
        gameBoardIndex[0] = playerLetter[*playerPtr - 1];
    }
    // If player input is 'W'
    else if (move == 'w' && gameBoardIndex[1] == *blankPtr)
    {
        gameBoardIndex[1] = playerLetter[*playerPtr - 1];
    }
    // If player inout is 'E'
    else if (move == 'e' && gameBoardIndex[2] == *blankPtr)
    {
        gameBoardIndex[2] = playerLetter[*playerPtr - 1];
    }
    // If player input is 'A'
    else if (move == 'a' && gameBoardIndex[3] == *blankPtr)
    {
        gameBoardIndex[3] = playerLetter[*playerPtr - 1];
    }
    // If player is 'S'
    else if (move == 's' && gameBoardIndex[4] == *blankPtr)
    {
        gameBoardIndex[4] = playerLetter[*playerPtr - 1];
    }
    // If player is 'D'
    else if (move == 'd' && gameBoardIndex[5] == *blankPtr)
    {
        gameBoardIndex[5] = playerLetter[*playerPtr - 1];
    }
    // If player is 'Z'
    else if (move == 'z' && gameBoardIndex[6] == *blankPtr)
    {
        gameBoardIndex[6] = playerLetter[*playerPtr - 1];
    }
    // If player is 'X'
    else if (move == 'x' && gameBoardIndex[7] == *blankPtr)
    {
        gameBoardIndex[7] = playerLetter[*playerPtr - 1];
    }
    // If player is 'C'
    else if (move == 'c' && gameBoardIndex[8] == *blankPtr)
    {
        gameBoardIndex[8] = playerLetter[*playerPtr - 1];
    }
    // If player inputs invalid spot or taken spot
    else
    {
        printf("\nThat is not a valid spot, try again\n");
        // Run function again to pick spot again
        playerMove(gameBoardIndex, player, blank, playerName, playerLetter);
    }
}

// Checks if win conditions are met
int checkWin(char gameBoardIndex[9], int player, char blank, int num_blank, char playerName[2][25], char playerLetter[3])
{
    // Blank spot pointer
    char *blankPtr;
    blankPtr = &blank;
    // Blank spots pointer
    int *num_blankPtr;
    num_blankPtr = &num_blank;
    // Player pointer
    int *playerPtr;
    playerPtr = &player;

    //  // Horizontal win
    if ((gameBoardIndex[0] == playerLetter[*playerPtr - 1] && gameBoardIndex[1] == playerLetter[*playerPtr - 1] && gameBoardIndex[2] == playerLetter[*playerPtr - 1]) ||
        (gameBoardIndex[3] == playerLetter[*playerPtr - 1] && gameBoardIndex[4] == playerLetter[*playerPtr - 1] && gameBoardIndex[5] == playerLetter[*playerPtr - 1]) ||
        (gameBoardIndex[6] == playerLetter[*playerPtr - 1] && gameBoardIndex[7] == playerLetter[*playerPtr - 1] && gameBoardIndex[8] == playerLetter[*playerPtr - 1]) ||
        // Vertical win
        (gameBoardIndex[0] == playerLetter[*playerPtr - 1] && gameBoardIndex[3] == playerLetter[*playerPtr - 1] && gameBoardIndex[6] == playerLetter[*playerPtr - 1]) ||
        (gameBoardIndex[1] == playerLetter[*playerPtr - 1] && gameBoardIndex[4] == playerLetter[*playerPtr - 1] && gameBoardIndex[7] == playerLetter[*playerPtr - 1]) ||
        (gameBoardIndex[2] == playerLetter[*playerPtr - 1] && gameBoardIndex[5] == playerLetter[*playerPtr - 1] && gameBoardIndex[8] == playerLetter[*playerPtr - 1]) ||
        // Left diagonal win
        (gameBoardIndex[0] == playerLetter[*playerPtr - 1] && gameBoardIndex[4] == playerLetter[*playerPtr - 1] && gameBoardIndex[8] == playerLetter[*playerPtr - 1]) ||
        // Right diagonal win
        (gameBoardIndex[2] == playerLetter[*playerPtr - 1] && gameBoardIndex[4] == playerLetter[*playerPtr - 1] && gameBoardIndex[6] == playerLetter[*playerPtr - 1]))
    {
        system("@cls");

        // Prints board
        printGameBoard(gameBoardIndex);
        printf("%s (%c) wins!\n\n", playerName[*playerPtr - 1], playerLetter[*playerPtr - 1]);

        // Used to ask players if they would like to play again
        return 0;
    }

    else if (*num_blankPtr <= 0)
    {
        system("@cls");

        // Prints board
        printGameBoard(gameBoardIndex);
        printf("It's a tie!\n\n");

        // Used to ask players if they would like to play again
        return 0;
    }
}

void main()
{
    system("@cls");

    // Used to add X or O on the bored in relation the player move, and check win conditions,
    char gameBoardIndex[9] = {' ', ' ', ' ',
                              ' ', ' ', ' ',
                              ' ', ' ', ' '};
    // Helps with indexing
    char blank = ' ';
    // Player playing, player 1 = X, player 2 = O
    int player;
    // Used to loop the main code
    bool playing = true;
    // Used to check how many available spots are left on the bored
    int num_blank = 9;
    // Used to play or quit game
    char choice = 'y';
    // Used to store player names
    char playerName[2][25] = {"\0", "\0"};
    // Used to store the letter of the players
    char playerLetter[3] = {'x', 'o', 'x'};
    // Used to determine what player starts
    char playerStart;

    // Loops 2 times to add both players names
    for (int i = 1; i < 3; i++)
    {
        printf("Enter player %d's name: ", i);
        scanf(" %s", &playerName[i - 1]);
    }

    printf("\nWhat letter will %s be? (x/o): ", playerName[0]);
    scanf(" %c", &playerLetter[0]);

    // Fixes players letters
    if (playerLetter[0] == playerLetter[1])
    {
        playerLetter[1] = playerLetter[2];
    }
    // If anything else other than 'x' or 'o' is pressed, player 1 is 'x'
    else if (playerLetter[0] != playerLetter[2] || playerLetter[0] != playerLetter[1])
    {
        playerLetter[0] = 'x';
    }

    printf("\nWho will go first? '%s' '%s' (%c/%c): ", playerName[0], playerName[1], playerLetter[0], playerLetter[1]);
    scanf(" %c", &playerStart);

    // First name is assigned to player 1, second name is assigned to player 2 //
    // Changes player value in relation to playerStart letter //
    if (playerStart == playerLetter[0])
    {
        player = 1;
    }
    else if (playerStart == playerLetter[1])
    {
        player = 2;
    }
    // Player 1 starts if any other key other than 'x' or 'o' is pressed
    else
    {
        player = 1;
    }

    // Game //
    while (playing == true)
    {
        system("@cls");

        // Prints the Board
        printGameBoard(gameBoardIndex);
        // Player makes their move
        playerMove(gameBoardIndex, player, blank, playerName, playerLetter);

        // Spots left decreases by 1
        num_blank--;

        // Check if a player has won
        if (checkWin(gameBoardIndex, player, blank, num_blank, playerName, playerLetter) == 0)
        {
            // Stop the main loop
            playing = false;

            printf("Would you like to play again? (y/n): ");
            scanf(" %c", &choice);

            // If players want to play again
            if (choice == 'y' || choice == 'Y')
            {
                // Restarts the game
                main();
            }
            // If players dont want to play again
            else if (choice == 'n' || choice == 'N')
            {
                printf("\nThank you for playing!");
            }
            // if player miss click
            else
            {
                printf("\nMaybe you meant to say no?");
                printf("\nThank you for playing!");
            }
        }

        // Player value increments by 1
        player++;

        // After player 2 makes their move, player value goes back to 1
        if (player > 2)
            player = 1;
    }
}