#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define righe 3
#define colonne 3

void printMatrice(int matrix[righe][colonne])
{
    int i, j; // Dichiarazione variabili locali
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void generateMatrice(int genMatrix[righe][colonne])
{
    int i, j;
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            genMatrix[i][j] = (rand() % 30);
        }
    }
}

int main()
{
    int i, j, somma = 0;
    int matrice[righe][colonne];

    generateMatrice(matrice);
    printMatrice(matrice);

    printf("\n-SOMMA RIGHE -\n");
    // Somma righe
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            somma = somma + matrice[i][j];
        }
        printf("Somma riga %d: %d\n", i + 1, somma);
        somma = 0;
    }

    printf("\n-SOMMA COLONNE -\n");
    // Somma colonne
    for (i = 0; i < colonne; i++)
    {
        for (j = 0; j < righe; j++)
        {
            somma = somma + matrice[j][i];
        }
        printf("Somma colonna %d: %d\n", i + 1, somma);
        somma = 0;
    }
}
