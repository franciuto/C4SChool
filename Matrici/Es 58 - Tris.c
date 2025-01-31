#include <stdlib.h>
#include <stdio.h>

#define dimension 3

char gameMatrix[dimension][dimension] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void gamePrint(char matrix[dimension][dimension])
{
    int i, j;
    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
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
        if (i != dimension - 1)
        {
            printf("\n-------------\n");
        }
    }
}

void inputHandler(int player)
{
    int play_righe = 1, play_colonne = 1;
    int valid_input = 0;

    while (valid_input == 0)
    {

        // Input req
        printf("\nInserisci riga: ");
        scanf("%d", &play_righe);
        printf("Inserisci colonna: ");
        scanf("%d", &play_colonne);

        // Check righe
        while (play_righe < 1 || play_righe > 3)
        {
            printf("\nHai inserito una riga non valida\nInserisci riga: ");
            scanf("%d", &play_righe);
        }

        // Check colonne
        while (play_colonne < 1 || play_colonne > 3)
        {
            printf("\nHai inserito una colonna non valida\nInserisci colonna: ");
            scanf("%d", &play_colonne);
        }

        // Check if free
        if (gameMatrix[play_righe - 1][play_colonne - 1] != ' ')
        {
            printf("Posizione occupata");
            continue;
        }
        valid_input = 1;
    }

    // Calcola real pointer
    int real_righe = play_righe - 1;
    int real_colonne = play_colonne - 1;

    if (player == 1)
    {
        gameMatrix[real_righe][real_colonne] = 'X';
    }
    else if (player == 2)
    {
        gameMatrix[real_righe][real_colonne] = 'O';
    }
}

int checkWin()
{
    int i, j;

    // Controllo delle righe
    for (i = 0; i < dimension; i++)
    {
        if (gameMatrix[i][0] != ' ' && gameMatrix[i][0] == gameMatrix[i][1] && gameMatrix[i][1] == gameMatrix[i][2])
        {
            if (gameMatrix[i][0] == 'X')
                return 1;
            else
                return 2;
        }
    }

    // Controllo delle colonne
    for (j = 0; j < dimension; j++)
    {
        if (gameMatrix[0][j] != ' ' && gameMatrix[0][j] == gameMatrix[1][j] && gameMatrix[1][j] == gameMatrix[2][j])
        {
            if (gameMatrix[0][j] == 'X')
                return 1;
            else
                return 2;
        }
    }

    // Controllo delle diagonali
    if (gameMatrix[0][0] != ' ' && gameMatrix[0][0] == gameMatrix[1][1] && gameMatrix[1][1] == gameMatrix[2][2])
    {
        if (gameMatrix[0][0] == 'X')
            return 1;
        else
            return 2;
    }

    if (gameMatrix[0][2] != ' ' && gameMatrix[0][2] == gameMatrix[1][1] && gameMatrix[1][1] == gameMatrix[2][0])
    {
        if (gameMatrix[0][2] == 'X')
            return 1;
        else
            return 2;
    }

    // Nessun vincitore
    return 0;
}
int main()
{
    char Player1[20];
    char Player2[20];
    int i, round = 9;

    // Intro & Player names
    printf("Tris Game\n\nInserisci nome primo giocatore: ");
    scanf("%s", &Player1);
    printf("Inserisci nome secondo giocatore: ");
    scanf("%s", &Player2);

    // Symbol assignment
    printf("\n-- Giocatori --\n");
    printf("%s => X\n", Player1);
    printf("%s => O\n", Player2);

    // Input request
    while (round > 0)
    {
        if (round % 2 != 0)
        {
            printf("\n\nE' il turno di %s\nDove vuoi inserire l'elemento: ", Player1);
            inputHandler(1);
        }
        else if (round % 2 == 0)
        {
            printf("\n\nE' il turno di %s\nDove vuoi inserire l'elemento", Player2);
            inputHandler(2);
        }
        system("clear");
        gamePrint(gameMatrix);
        if (checkWin() == 1)
        {
            printf("\n\nHa vinto %s", Player1);
            break;
        }
        else if (checkWin() == 2)
        {
            printf("\n\nHa vinto %s", Player2);
            break;
        }
        round--;
    }
}