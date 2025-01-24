#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define dimension 3

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

void inputMatrice(int matrix[dimension][dimension])
{
    int i, j, to_insert;
    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            printf("Inserisci elemento a %d , %d: ", i, j);
            scanf("%d", &to_insert);
            matrix[i][j] = to_insert;
        }
    }
}
int main()
{
    int i, j, counter = 0;
    int matrice[dimension][dimension];

    inputMatrice(matrice);
    printMatrice(matrice);

    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            if (matrice[i][j] == matrice[j][i])
            {
                counter++;
            }
        }
    }
    if (counter == 0)
    {
        printf("\nLa matrice non è simmetrica");
    }
    else
    {
        printf("\nLa matrice è simmetrica");
    }
}
