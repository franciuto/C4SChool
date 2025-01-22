#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define righe 6
#define colonne 6

void generaMatrice(int matrix[righe][colonne])
{
    int i, j;
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            matrix[i][j] = (rand() % 100) + 1;
        }
    }
}

void printMatrice(int matrix[righe][colonne])
{
    int i, j;
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    int matrice1[righe][colonne];
    int toFind, i, j;

    // Genera e stampa matrice
    generaMatrice(matrice1);
    printMatrice(matrice1);

    // Richiesta input
    printf("Inserisci numero da cercare: ");
    scanf("%d", &toFind);

    // Find in matrix
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            if (matrice1[i][j] == toFind)
            {
                printf("Elemento %d trovato in %d , %d", toFind, i + 1, j + 1);
                printf("\n");
            }
        }
    }
}
