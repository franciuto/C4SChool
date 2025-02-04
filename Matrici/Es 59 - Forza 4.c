#include <stdio.h>
#include <stdlib.h>

#define righe 6
#define colonne 7

#define RESET "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"

void gamePrint(char matrix[righe][colonne])
{
    int i, j;
    for (i = 0; i < righe; i++)
    {
        printf("|");
        for (j = 0; j < colonne; j++)
        {
            if (matrix[i][j] == ' ')
            {
                printf("   ");
            }
            if (matrix[i][j] == 'X')
            {
                printf(RED " %c " RESET, matrix[i][j]);
            }
            else if (matrix[i][j] == 'O')
            {
                printf(BLUE " %c " RESET, matrix[i][j]);
            }
            printf("|");
        }
        printf("\n+---+---+---+---+---+---+---+\n");
    }
    for (j = 0; j < colonne; j++)
    {
        printf("  %d ", j + 1);
    }
    printf("\n\n");
}

int checkWin(char gameMatrix[righe][colonne])
{
    int i, j;

    // Controllo delle righe
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne - 3; j++)
        {
            if (gameMatrix[i][j] != ' ' && gameMatrix[i][j] == gameMatrix[i][j + 1] && gameMatrix[i][j] == gameMatrix[i][j + 2] && gameMatrix[i][j] == gameMatrix[i][j + 3])
            {
                return (gameMatrix[i][j] == 'X') ? 1 : 2;
            }
        }
    }

    // Controllo delle colonne
    for (j = 0; j < colonne; j++)
    {
        for (i = 0; i < righe - 3; i++)
        {
            if (gameMatrix[i][j] != ' ' && gameMatrix[i][j] == gameMatrix[i + 1][j] && gameMatrix[i][j] == gameMatrix[i + 2][j] && gameMatrix[i][j] == gameMatrix[i + 3][j])
            {
                return (gameMatrix[i][j] == 'X') ? 1 : 2;
            }
        }
    }

    // Controllo diagonale principale
    for (i = 0; i < righe - 3; i++)
    {
        for (j = 0; j < colonne - 3; j++)
        {
            if (gameMatrix[i][j] != ' ' && gameMatrix[i][j] == gameMatrix[i + 1][j + 1] && gameMatrix[i][j] == gameMatrix[i + 2][j + 2] && gameMatrix[i][j] == gameMatrix[i + 3][j + 3])
            {
                return (gameMatrix[i][j] == 'X') ? 1 : 2;
            }
        }
    }

    // Controllo diagonale secondaria
    for (i = 0; i < righe - 3; i++)
    {
        for (j = 3; j < colonne; j++)
        {
            if (gameMatrix[i][j] != ' ' && gameMatrix[i][j] == gameMatrix[i + 1][j - 1] && gameMatrix[i][j] == gameMatrix[i + 2][j - 2] && gameMatrix[i][j] == gameMatrix[i + 3][j - 3])
            {
                return (gameMatrix[i][j] == 'X') ? 1 : 2;
            }
        }
    }

    // Nessun vincitore
    return 0;
}


void inputHandler(char matrix[righe][colonne], int current_player)
{
    int colonna, i;
    char simbolo;
    if (current_player == 1)
    {
        simbolo = 'X';
    }
    else
    {
        simbolo = 'O';
    }

    printf("Inserisci colonna (1-7): ");
    scanf("%d", &colonna);

    while (colonna < 1 || colonna > 7)
    {
        printf("Colonna inesistente! Inserisci un numero da 1 a 7: ");
        scanf("%d", &colonna);
    }

    for (i = righe - 1; i >= 0; i--)
    {
        if (matrix[i][colonna - 1] == ' ')
        {
            matrix[i][colonna - 1] = simbolo;
            return;
        }
    }

    printf("La colonna è piena. Scegli un'altra colonna.\n");
}

int main()
{
    int victory = 0, round_switcher = 0;
    char Player1[20];
    char Player2[20];
    char gameMatrix[6][7] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

    printf(RED "Inserisci nome giocatore 1: " RESET);
    scanf("%s", Player1);
    printf(BLUE "Inserisci nome giocatore 2: " RESET);
    scanf("%s", Player2);

    while (victory == 0)
    {
        // Pulisco la shell
        system("clear");

        // Alterno i turni con pari/dispari
        printf("E' il turno di: ");
        if (round_switcher % 2 == 0)
        {
            printf(RED "%s\n\n" RESET, Player1);
            gamePrint(gameMatrix);
            inputHandler(gameMatrix, 1);
        }
        else
        {
            printf(BLUE "%s\n\n" RESET, Player2);
            gamePrint(gameMatrix);
            inputHandler(gameMatrix, 2);
        }
        round_switcher++;
        victory = checkWin(gameMatrix);
    }
    if (victory == 1)
    {
        printf("Ha vinto %s", Player1);
    }
    else if (victory == 2)
    {
        printf("Ha vinto il giocatore %s", Player2);
    }
    else {
        printf("Nessuno ha vinto");
    }
}