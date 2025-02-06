#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define dimension 8

void gamePrint(char matrix[dimension][dimension]);
void clearMatrix(char matrix[dimension][dimension]);
int checkWin(int r_player, int c_player, int r_treasure, int c_treasure);

int main()
{
    int c_player = 0, r_player = 0;
    // Setup
    srand(time(NULL));
    char gameMatrix[dimension][dimension];

    // Clear matrix
    clearMatrix(gameMatrix);

    // Place treasure
    int r_treasure = rand() % dimension;
    int c_treasure = rand() % dimension;

    printf("DEBUG - Il tesoro è in: %d , %d\n", r_treasure + 1, c_treasure + 1); // Mostra la posizione reale (+1 per allineare con l'input)

    do
    {
        // Input request
        printf("\nDove si trova il tesoro?\n");
        
        // Riga
        do {
            printf("Riga (1-8): ");
            scanf("%d", &r_player);
            if (r_player < 1 || r_player > 8) {
                printf("Errore: inserisci un valore tra 1 e 8.\n");
            }
        } while (r_player < 1 || r_player > 8);

        // Colonna
        do {
            printf("Colonna (1-8): ");
            scanf("%d", &c_player);
            if (c_player < 1 || c_player > 8) {
                printf("Errore: inserisci un valore tra 1 e 8.\n");
            }
        } while (c_player < 1 || c_player > 8);

        // Converti input da 1-8 a 0-7 per confrontarlo con il tesoro
        r_player--;
        c_player--;

    } while (!checkWin(r_player, c_player, r_treasure, c_treasure)); // Continua finché il tesoro non è trovato

    printf("\n🎉 Tesoro trovato!! 🎉\n");

    return 0;
}

void clearMatrix(char matrix[dimension][dimension])
{
    int i, j;
    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            matrix[i][j] = ' ';
        }
    }
}

int checkWin(int r_player, int c_player, int r_treasure, int c_treasure)
{
    return (r_player == r_treasure && c_player == c_treasure);
}

void gamePrint(char matrix[dimension][dimension])
{
    printf("+---+---+---+---+---+---+---+---+\n");
    int i, j;
    for (i = 0; i < dimension; i++)
    {
        printf("|");
        for (j = 0; j < dimension; j++)
        {
            if (matrix[i][j] == ' ')
            {
                printf("   ");
            }
            printf("|");
        }
        printf("\n+---+---+---+---+---+---+---+---+\n");
    }
    for (j = 0; j < dimension; j++)
    {
        printf("  %d ", j + 1);
    }
    printf("\n\n");
}