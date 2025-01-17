#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define righe_a 3
#define colonne_a 2
#define righe_b 2
#define colonne_b 3

// Funzione che riempie la matrice
void fill_matrix(int righe_var, int colonne_var, int matrix_to_fill[righe_var][colonne_var])
{
    for (int i = 0; i < righe_var; i++)
    {
        for (int j = 0; j < colonne_var; j++)
        {
            matrix_to_fill[i][j] = (rand() % 10) + 1;
        }
    }
}

// Funzione che stampa la matrice
void print_matrix(int righe_var, int colonne_var, int matrix_to_print[righe_var][colonne_var])
{
    for (int i = 0; i < righe_var; i++)
    {
        for (int j = 0; j < colonne_var; j++)
        {
            printf("%d ", matrix_to_print[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    int i, j, k;

    // Dichiarazione delle matrici
    int a_matrix[righe_a][colonne_a];
    int b_matrix[righe_b][colonne_b];
    int res_matrix[righe_a][colonne_b];

    // Riempi le matrici
    fill_matrix(righe_a, colonne_a, a_matrix);
    fill_matrix(righe_b, colonne_b, b_matrix);

    // Stampa le matrici
    printf("Matrice A:\n");
    print_matrix(righe_a, colonne_a, a_matrix);
    printf("\nMatrice B:\n");
    print_matrix(righe_b, colonne_b, b_matrix);

    // Inizializza la matrice risultato a 0
    for (i = 0; i < righe_a; i++)
    {
        for (j = 0; j < colonne_b; j++)
        {
            res_matrix[i][j] = 0;
        }
    }

    // Moltiplicazione delle matrici
    for (i = 0; i < righe_a; i++) 
    {
        for (j = 0; j < colonne_b; j++) 
        {
            for (k = 0; k < colonne_a; k++) 
            {
                res_matrix[i][j] += a_matrix[i][k] * b_matrix[k][j];
            }
        }
    }

    // Stampa la matrice risultato
    printf("\nRisultato:\n");
    print_matrix(righe_a, colonne_b, res_matrix);

    return 0;
}
