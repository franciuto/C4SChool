#include <stdlib.h>
#include <stdio.h>
#define righe 3
#define colonne 3

// Funzione per riempire la matrice da input
void fillMatrix(int matrice[righe][colonne])
{
    int i, j, numero;
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            printf("Inserisci elemento %d ; %d : ", i, j);
            scanf("%d", &numero);
            matrice[i][j] = numero;
        }
    }
}

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
    // Dichiarazioni
    int i, j, res = 0;
    int matrix1[righe][colonne];

    // Chiama la funzione che riempie la matrice e stampa
    fillMatrix(matrix1);
    print_matrix(matrix1);

    // Ciclo che itera sulle righe
    for (i = 0; i < righe; i++)
    {   
        // Ciclo che iitera sulle colonne
        for (j = 0; j < colonne; j++)
        {   
            // Se sto analizzando la diagonale
            if (j == i)
            {   
                // Se i valori sono uguali a zero allora non è diagonale
                if (matrix1[i][j] == 0)
                {
                    res++;              // Incremento res per tenere traccia
                }
            }
            // Altrimenti se non sto analizzando la diagonale controllo se i valori sono diversi da 0
            else if (matrix1[i][j] != 0)
            {
                res++;                 // Incremento res per tracciare
            }
        }
    }
    // Se res è stato incrementato allora una regola è stata rotta
    if (res != 0)
    {
        printf("La matrice non è diagonale");
    }
    else
    {
        printf("La matrice è diagonale");
    }
}
