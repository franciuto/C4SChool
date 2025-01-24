#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define righe 4
#define colonne 3

void printMatrix(int *matrix, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            // Calcola l'indice corretto per accedere all'elemento
            printf("%d\t", *(matrix + i * col + j));
        }
        printf("\n");
    }
}

void fillMatrix(int matrix[righe][colonne])
{
    int i, j;
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            matrix[i][j] = (rand() % 30) + 1;
        }
    }
}

void trasposta(int matrice[righe][colonne], int trasposta[colonne][righe])
{
    int i, j;
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            trasposta[j][i] = matrice[i][j];
        }
    }
}

int main()
{
    srand(time(NULL));
    int original_matrice[righe][colonne];
    int trasposta_matrice[colonne][righe];

    fillMatrix(original_matrice);

    printf("Matrice originale:\n");
    printMatrix((int *)original_matrice, righe, colonne);

    printf("\nMatrice trasposta:\n");
    trasposta(original_matrice, trasposta_matrice);
    printMatrix((int *)trasposta_matrice, colonne, righe);

    return 0;
}
