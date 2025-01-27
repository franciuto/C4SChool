#include <stdio.h>
#include <stdlib.h>

#define N 3

// Stampa matrice
void inputMatrice(int matrix[N][N])
{
    int i, j, to_insert;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("Inserisci elemento a %d , %d: ", i, j);
            scanf("%d", &to_insert);
            matrix[i][j] = to_insert;
        }
    }
}
// Stampa matrice
void printMatrice(int matrix[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int i, j, superiore = 0, inferiore = 0;
    int matrice[N][N];

    inputMatrice(matrice);
    printMatrice(matrice);

    // Controllo se la matrice e' diagonale superiore o inferiore
    for (i = 0; i < N; i++)         // Scorro le righe
    {
        for (j = 0; j < N; j++)     // Scorro le colonne
        {
            if (i == j)             // Se incontro la diagonale, salto l'elemento
            {
                continue;         
            }
            if (i > j && matrice[i][j] == 0)    // Altrimenti se sono sotto la diagonale e l'elemento e' 0 aumento il controllo per la superiore
            {
                superiore++;
            }
            else if (i < j && matrice[i][j] == 0)   // Se sono sopra e l'elemetno e' 0 aumento il controllo per l'inferiore
            {
                inferiore++;
            }
        }
    }

    // Determino il risultato
    if (superiore == ((N * N) - N) / 2)     // Calcolo e confronto con il numero degli elementi sotto la diagonale
    {
        printf("La matrice è triangolare superiore\n");
    }
    else if (inferiore == ((N * N) - N) / 2)        // Stessa cosa per il sopra
    {
        printf("La matrice è triangolare inferiore\n");
    }
    else
    {
        printf("La matrice non è né triangolare superiore né triangolare inferiore\n");
    }
}
