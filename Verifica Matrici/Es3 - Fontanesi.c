#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Costanti
#define dimensione 4
#define randRange 10

// Funzioni
void generateMatrice(int genMatrix[dimensione][dimensione]);
void printMatrice(int matrix[dimensione][dimensione]);
int sommaSottoDiagonale(int [dimensione][dimensione]);

int main ()
{
    srand(time(NULL));
    int mainMatrix[dimensione][dimensione];

    // Genero e stampo
    generateMatrice(mainMatrix);
    printMatrice(mainMatrix);

    printf("La somma sotto la diagonale principale %d ", sommaSottoDiagonale(mainMatrix));

}

int sommaSottoDiagonale(int matrix[dimensione][dimensione])
{
    int i, j;       // Puntatori
    int somma = 0;      // Variabile locale
    for (i = 0; i < dimensione; i++)
    {
        for (j = 0; j < dimensione; j++)
        {
            // Se non ho incontrato la diagonale aggiungo alla somma
            if (i != j)
            {
                somma = somma + matrix[i][j];
            }
            else        // Se la incontro passo alla prossima riga
            {
                break;
            }
        }
    }
    return somma;
}


void printMatrice(int matrix[dimensione][dimensione])
{
    int i, j;       // Puntatori
    // Stampa scorrendo le righe e le colonne
    for (i = 0; i < dimensione; i++)
    {
        for (j = 0; j < dimensione; j++)
        {
            printf("%d\t", matrix[i][j]);       // Uso \t per fare una tabulazione e avere tutto stampato in modo corretto
        }
        printf("\n");       // Vado a capo dopo ogni riga
    }
}


void generateMatrice(int genMatrix[dimensione][dimensione])
{
    int i, j;    // Puntatori
    // Riempio la matrice di valori random scorrendo per righe e colonne
    for (i = 0; i < dimensione; i++)
    {
        for (j = 0; j < dimensione; j++)
        {
            genMatrix[i][j] = (rand() % randRange) + 1;
        }
    }
}
