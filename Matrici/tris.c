#include <stdlib.h>
#include <stdio.h>

#define righe 6
#define colonne 7

void gamePrint(char matrix[righe][colonne])
{
    int i, j;
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            if (j == 0)
            {
                printf(" %c", matrix[i][j]);
            }
            else if (j == 1)
            {
                printf(" %c ", matrix[i][j]);
            }
            else
            {
                printf(" %c", matrix[i][j]);
            }

            if (!(j > 1))
            {
                printf(" | ");
            }
        }
        if (i != righe - 1)
        {
            printf("\n-------------\n");
        }
    }
}

int main()
{
    char gameMatrix[righe][colonne] = { {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                        {' ', ' ', ' ', ' ', ' ', ' ', ' '} };
    char Player1[20];
    char Player2[20];
    int i, round = 9;

    // Intro & Player names
    printf("Tris Game\n\nInserisci nome primo giocatore: ");
    scanf("%s", Player1);
    printf("Inserisci nome secondo giocatore: ");
    scanf("%s", Player2);

    // Symbol assignment
    printf("\n-- Giocatori --\n");
    printf("%s => X\n", Player1);
    printf("%s => O\n", Player2);
    gamePrint(gameMatrix);
}
