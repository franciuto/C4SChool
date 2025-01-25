#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dimensione 3
#define range 100

void fillMatrix(int matrix[dimensione][dimensione])
{
    int i, j;
    for (i = 0; i < dimensione; i++)
    {
        for (j = 0; j < dimensione; j++)
        {
            matrix[i][j] = (rand() % range);
        }
    }
}

void printMatrice(int matrix[dimensione][dimensione])
{
    int i, j;
    for (i = 0; i < dimensione; i++)
    {
        for (j = 0; j < dimensione; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int massimoMatrice(int matrix[dimensione][dimensione])
{
    int i, j, max = 0;
    for (i = 0; i < dimensione; i++)
    {
        for (j = 0; j < dimensione; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

int minimoMatrice(int matrix[dimensione][dimensione])
{
    int i, j, min = range;
    for (i = 0; i < dimensione; i++)
    {
        for (j = 0; j < dimensione; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
    }
    return min;
}

int main()
{
    srand(time(NULL));
    int i, j, max = 0, righe_max = 0, colonne_max = 0;
    int matrice[dimensione][dimensione];

    fillMatrix(matrice);

    for (i = 0; i < dimensione; i++)
    {
        for (j = 0; j < dimensione; j++)
        {
            if (matrice[i][j] > max)
            {
                max = matrice[i][j];
                righe_max = i;
                colonne_max = j;
            }
        }
    }
    printMatrice(matrice);
    printf("Massimo %d", massimoMatrice(matrice));
    printf("\n");
    printf("Minimo %d", minimoMatrice(matrice));
}