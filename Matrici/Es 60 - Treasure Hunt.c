#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define dimension 8

void gamePrint(char matrix[dimension][dimension]);
void clearMatrix(char matrix[dimension][dimension]);
int checkWin(int r_player, int c_player, int r_treasure, int c_treasure);
void giveHint(int r_player, int c_player, int r_treasure, int c_treasure);

int main()
{
    int c_player = 0, r_player = 0;
    srand(time(NULL));
    char gameMatrix[dimension][dimension];

    clearMatrix(gameMatrix);

    int r_treasure = rand() % dimension;
    int c_treasure = rand() % dimension;

    printf("DEBUG - Il tesoro è in: %d , %d\n", r_treasure + 1, c_treasure + 1);

    do
    {
        printf("\nDove si trova il tesoro?\n");
        
        do {
            printf("Riga (1-8): ");
            scanf("%d", &r_player);
            if (r_player < 1 || r_player > 8) {
                printf("Errore: inserisci un valore tra 1 e 8.\n");
            }
        } while (r_player < 1 || r_player > 8);

        do {
            printf("Colonna (1-8): ");
            scanf("%d", &c_player);
            if (c_player < 1 || c_player > 8) {
                printf("Errore: inserisci un valore tra 1 e 8.\n");
            }
        } while (c_player < 1 || c_player > 8);

        r_player--;
        c_player--;

        if (!checkWin(r_player, c_player, r_treasure, c_treasure)) {
            giveHint(r_player, c_player, r_treasure, c_treasure);
        }
    } while (!checkWin(r_player, c_player, r_treasure, c_treasure));

    printf("\n🎉 Tesoro trovato!! 🎉\n");

    return 0;
}

void clearMatrix(char matrix[dimension][dimension])
{
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            matrix[i][j] = ' ';
        }
    }
}

int checkWin(int r_player, int c_player, int r_treasure, int c_treasure)
{
    return (r_player == r_treasure && c_player == c_treasure);
}

void giveHint(int r_player, int c_player, int r_treasure, int c_treasure)
{
    int distance = abs(r_player - r_treasure) + abs(c_player - c_treasure);
    if (distance == 1)
        printf("Molto vicino! 🔥\n");
    else if (distance == 2)
        printf("Vicino! 😊\n");
    else
        printf("Lontano... ❄️\n");
}

void gamePrint(char matrix[dimension][dimension])
{
    printf("+---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < dimension; i++) {
        printf("|");
        for (int j = 0; j < dimension; j++) {
            if (matrix[i][j] == ' ') {
                printf("   ");
            }
            printf("|");
        }
        printf("\n+---+---+---+---+---+---+---+---+\n");
    }
    for (int j = 0; j < dimension; j++) {
        printf("  %d ", j + 1);
    }
    printf("\n\n");
}
