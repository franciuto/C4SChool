#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dimensione 6

void fillMatrix(int matrix[dimensione][dimensione])
{
    int i, j;
    for (i = 0; i < dimensione; i++)
    {
        for (j = 0; j < dimensione; j++)
        {
            matrix[i][j] = (rand() % 30) + 1;
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
    printf("Il valore massimo è: %d" , max);
    printf("\nAlle coordinate %d , %d: " , righe_max + 1, colonne_max + 1);
}