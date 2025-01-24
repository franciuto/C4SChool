#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define dimension 4

void printMatrice(int matrix[dimension][dimension])
{
    int i, j;
    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int fillMatrix(int matrix_to_fill[dimension][dimension])
{
    int i, j;
    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            matrix_to_fill[i][j] = (rand() % 30) + 1;
        }
    }
}

int main()
{
    int righe, i, counter = 0;
    int matrice[dimension][dimension];
    int line_to_change[dimension];

    fillMatrix(matrice);
    printMatrice(matrice);

    for (righe = 0; righe < dimension; righe = righe + 2)
    {
        // Salvo la linea dispari nell'array
        for (i = 0; i < dimension; i++)
        {
            line_to_change[i] = matrice[righe + 1][i];
        }

        // Metto la riga pari in quella dispari
        for (i = 0; i < dimension; i++)
        {
            matrice[righe + 1][i] = matrice[righe][i];
        }

        // Metto la riga dispari in quella pari
        for (i = 0; i < dimension; i++)
        {
            matrice[righe][i] = line_to_change[i];
        }
    }

    printf("\n\n\nMatrice invertita pari le disparii\n");
    printMatrice(matrice);
}
