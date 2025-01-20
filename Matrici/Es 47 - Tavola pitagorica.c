#include <stdlib.h>
#include <stdio.h>
#define righe 10
#define colonne 10

// Funzione che stampa la matrice passata
void print_matrix(int matrice[righe][colonne])
{
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int i, j;
    int tavola_pitagorica[righe][colonne];
    
    // Itera per righe
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            tavola_pitagorica[i][j] = (i + 1) * (j + 1);
        }
    }
    // Stampa
    print_matrix(tavola_pitagorica);
}
