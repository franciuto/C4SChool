#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define dimension 8

void gamePrint(char matrix[dimension][dimension]);
void clearMatrix(char matrix[dimension][dimension]);
int checkWin(int r_player, int c_player);

int main()
{
    int c_player, r_player;
    // Setup
    srand(time(NULL));
    char gameMatrix[dimension][dimension];

    // Clear matrix
    clearMatrix(gameMatrix);

    // Place treasure
    int r_treasure = rand() % dimension;
    int c_treasure = rand() % dimension;

    do
    {
        // Input request
        printf("Dove si trova il tesoro?");
        printf("Riga: ");
        scanf("%d" , &r_player);
        printf("Colonna: ");
        scanf("%d" , &c_player);

        while (r_player > 8 || r_player < 1 || c_player > 8 || c_player < 1)
        {
            
        }
        
    } while (checkWin(r_player , c_player))
    
    
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

int checkWin(int r_player, int c_player) {



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
