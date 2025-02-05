#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define dimension 8

void gamePrint(char matrix[dimension][dimension]);
void clearMatrix(char matrix[dimension][dimension]);

int main()
{
    // Setup
    srand(time(NULL));
    char gameMatrix[dimension][dimension];

    // Clear matrix
    clearMatrix(gameMatrix);

    gamePrint(gameMatrix);

    /*
        // Place treasure
        int r_treasure = rand() % dimension;
        int c_treasure = rand() % dimension;
        gameMatrix[r_treasure][c_treasure] = 'X';



    */
}

void clearMatrix(char matrix[dimension][dimension])
{
    int i, j;
    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            matrix[i][j] == ' ';
        }
    }
}

void gamePrint(char matrix[dimension][dimension])
{
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
        printf("\n+---+---+---+---+---+---+---+\n");
    }
    for (j = 0; j < dimension; j++)
    {
        printf("  %d ", j + 1);
    }
    printf("\n\n");
}
