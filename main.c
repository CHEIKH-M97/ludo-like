#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdlib.h>
#define RESET_COLOR "\x1B[0m"
#define COLOR_PLAYER1 "\x1B[31m" // Red
#define COLOR_PLAYER2 "\x1B[34m" // Blue
#define COLOR_TRAP "\x1B[33m"     // Yellow
#define COLOR_BOTH "\x1B[35m"     // Magenta
char grid[5][4] = {{' ', ' ',' ', ' '},{' ',' ', ' ', ' '},{' ',' ', ' ', ' '}, {' ',' ', ' ', ' '}, {' ',' ', ' ', ' '}};
int player1[2] = {1,0};
int player2[2] = {2,0};
void print_screen(char grid[5][4])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            grid[i][j] = ' ';
        }
    }
    grid[1][1] = 'T';
    grid[2][0] = 'T';
    grid[2][3] = 'T';
    grid[3][2] = 'T';
    grid[4][0] = 'T';
    grid[4][3] = 'T';
    if (player1[1] < 20)
    {
        int rows = player1[1] / 4;
        int columns = player1[1] % 4;
        grid[rows][columns] = 'X';
    }
    if (player2[1] < 20)
    {
        int rows = player2[1] / 4;
        int columns = player2[1] % 4;
        grid[rows][columns] = 'O';
    }
    if (player1[1] == player2[1])
    {
        int rows = player2[1] / 4;
        int columns = player2[1] % 4;
        grid[rows][columns] = 'B';
    }
    printf("************\nLudo Game         \n1 --> PLAYER1\n2 --> PLAYER2\nB --> BOTH\nT --> TRAP\n************\n               -----------------\n");
    printf("|START LINE| ->");
    for (int i =0 ; i<5 ; i++)
    {
        printf("");
        if (i>0)
        {
            printf("               ");
        }
        for (int j = 0 ; j<4 ; j++)
        {
            if (grid[i][j] == 'X') {
                printf("| %s%c%s ", COLOR_PLAYER1, grid[i][j], RESET_COLOR); // Player 1
            } else if (grid[i][j] == 'O') {
                printf("| %s%c%s ", COLOR_PLAYER2, grid[i][j], RESET_COLOR); // Player 2
            } else if (grid[i][j] == 'B') {
                printf("| %s%c%s ", COLOR_BOTH, grid[i][j], RESET_COLOR); // Both players
            } else if (grid[i][j] == 'T') {
                printf("| %s%c%s ", COLOR_TRAP, grid[i][j], RESET_COLOR); // Trap
            } else {
                printf("| %c ", grid[i][j]); // Empty space
            }
            if (i==4 && j ==3)
            {
                printf("|  ->|FINISH LINE",grid[i][j]);
                continue;
            }
        }
        printf("|");
        printf("\n               -----------------\n");
    }
}
int winner()
{
    if(player1[1] >= 20)
    {
        return 1;
    }
    else if (player2[1]>=20)
    {
        return 2;
    }
    return 0;
}
void play(int player[])
{
    printf("\n--> Player %d to play \n",player[0]);
    printf("Press ENTER to roll the dice ...");
    getchar();
    int dice = (rand() % 6) + 1;  //ai
    printf("--> Player %d rolled a %d\n",player[0],dice);
    player[1] += dice;
    int rows = player[1] / 4;
    int columns = player[1] %4;
    if (grid[rows][columns] == 'T')
    {
        player[1] = 0;
        printf("\nOops Player %d stepped on a trap !\n",player[0]);
    }
}
int main()
{
    srand(time(NULL)); //ai
    int det = 0;
    while (winner() == 0)
    {
        print_screen(grid);
        det ++;
        if (det % 2 ==0)
        {
            play(player1);
        }
        else
        {
            play(player2);
        }

    }
    if (winner()==1)
    {
        printf("\n\n**********Congrats Player 1 WON*********\n\n");
    }
    else
    {
        printf("\n\n**********Congrats Player 2 WON*********\n\n");
    }
    system("pause");
    return 0;
}
