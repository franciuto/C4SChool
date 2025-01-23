#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Definizione dimensioni matrice
#define righe 6
#define colonne 6

// Funzione per generare la matrice con numeri random da 1 a 50
void generateMatrix(int genMatrix[righe][colonne])
{
    int i, j;
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            genMatrix[i][j] = (rand() % 50) - 1;
        }
    }
}

// Funzione per stampare la matrice
void printMatrix(int printMatric[righe][colonne])
{
    int i, j;
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            printf("%d\t", printMatric[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    int matrice[righe][colonne];
    int i, j, sommaPrincipale = 0, sommaSecondaria = 0;

    generateMatrix(matrice);
    printMatrix(matrice);

    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            if (i == j)
            {
                sommaPrincipale += matrice[i][j];
            }
            if (i + j == righe - 1)
            {
                sommaSecondaria += matrice[i][j];
            }
        }
    }
    printf("Diagonale principale: %d\n Diagonale Secondaria %d", sommaPrincipale, sommaSecondaria);
}