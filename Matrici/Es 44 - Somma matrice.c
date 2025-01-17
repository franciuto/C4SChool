#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define righe 3
#define colonne 3

// Funzione che riempie la matrice
int fill_matrix(int matrix_to_fill[righe][colonne])
{
    int i, j;
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            matrix_to_fill[i][j] = (rand() % 30) + 1;
        }
    }
}

// Funzione che stampa la matrice
int print_matrix(int matrix_to_print[righe][colonne])
{
    int i, j;
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            printf("%d ", matrix_to_print[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    int i, j;
    int a_matrix[righe][colonne];
    int b_matrix[righe][colonne];
    int res_matrix[righe][colonne];

    // Riempi matrice
    fill_matrix(a_matrix);
    fill_matrix(b_matrix);

    // Stampa matrice
    print_matrix(a_matrix);
    printf("\n");
    print_matrix(b_matrix);

    // Somma elementi
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            res_matrix[i][j] = a_matrix[i][j] + b_matrix[i][j];
        }
    }

    // Stampa matrice
    printf("\n\n");
    print_matrix(res_matrix);
}
