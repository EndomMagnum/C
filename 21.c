#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h> // Imports "system("@cls")" and "system("pause")" function

bool game = true;
bool player_turn = false;
int total = 0;
int pn;
int bn;

int check_21(int total, int player_turn);
int player(int pn, int player_turn);
int bot(int bn, int player_turn);
int total_num(int total, int pn, int bn);

void main()
{
    player(pn, player_turn);
}

int check_21(int total, int player_turn)
{
    if (total >= 21 && player_turn == true)
    {
        printf("\nYou lose!");
        system("@pause");
    }
    else if (total >= 21 && player_turn == false)
    {
        printf("\nYou win!");
        system("@pause");
    }
    else
    {
        printf("\nKeep going");
        printf("\nTotal : %d", total);
        player(pn, player_turn);
    }
}

int player(int pn, int player_turn)
{
    bool *player_turnPtr;

    player_turnPtr = &player_turn;

    *player_turnPtr == true;
    printf("\nEnter a number from 1-3: ");
    scanf(" %d", &pn);
    printf("\nPlayer : %d", pn);
    bot(bn, *player_turnPtr);
}

int bot(int bn, int player_turn)
{
    bool *player_turnPtr;
    int *bnPtr;

    player_turnPtr = &player_turn;
    bnPtr = &bn;

    *player_turnPtr = false;
    *bnPtr = (rand() % 3) + 1;
    printf("\nBot : %d", *bnPtr);
    total_num(total, pn, bn);
}

int total_num(int total, int pn, int bn)
{
    int *totalPtr;

    totalPtr = &total;

    *totalPtr = (pn + bn);
    check_21(total, player_turn);
}
