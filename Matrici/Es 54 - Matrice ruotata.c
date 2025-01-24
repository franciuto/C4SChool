#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define dimensione 10

void fillMatrix(int matrix[dimensione][dimensione])
{
    int i, j;
    for (i = 0; i < dimensione; i++)
    {
        for (j = 0; j < dimensione; j++)
        {
            matrix[i][j] = (rand() % 100) + 1;
        }
    }
}

void printMatrix(int printMatric[dimensione][dimensione])
{
    int i, j;
    for (i = 0; i < dimensione; i++)
    {
        for (j = 0; j < dimensione; j++)
        {
            printf("%d\t", printMatric[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    int i, j, r = (dimensione - 1);
    int matrix[dimensione][dimensione];
    int modifiedMatrix[dimensione][dimensione];

    fillMatrix(matrix);

    for (i = 0; i < dimensione; i++)
    {
        for (j = 0; j < dimensione; j++)
        {
            modifiedMatrix[j][r] = matrix[i][j];
        }
        r--;
    }
    
    printMatrix(matrix);
    printf("\nMatrice ruotata di 90 gradi (Orario)\n");
    printMatrix(modifiedMatrix);
}