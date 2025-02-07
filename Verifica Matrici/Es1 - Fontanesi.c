#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Costanti
#define dimensione 4
#define randRange 50

// Funzioni
void generateMatrice(int genMatrix[dimensione][dimensione]);
void printMatrice(int matrix[dimensione][dimensione]);
int differenzaMaxMin(int matrix[dimensione][dimensione]);

int main ()
{   
    // Setup
    srand(time(NULL));\
    int mainMatrix[dimensione][dimensione];

    // Genero e stampo
    generateMatrice(mainMatrix);
    printMatrice(mainMatrix);

    printf("\nDifferenza: %d", differenzaMaxMin(mainMatrix));

}

int differenzaMaxMin(int matrix[dimensione][dimensione])
{
    int i, j;           // Puntatori
    int massimo = 0, minimo = randRange;        // Variabili locali
    for (i = 0; i < dimensione; i++)
    {   
        // Determino massimo e minimo
        for (j = 0; j < dimensione; j++)
        {
            if (matrix[i][j] > massimo)
            {
                massimo = matrix[i][j];
            }
            else if (matrix[i][j] < minimo)
            {
                minimo = matrix[i][j];
            }
        }
    }
    // Debug
    printf("Numero minimo: %d", minimo);
    printf("\nNumero massimo: %d", massimo);
    
    // Ritorno risultato
    return (massimo - minimo);
}

void printMatrice(int matrix[dimensione][dimensione])
{
    int i, j;       // Dichiarazione variabili locali
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
    int i, j;    // Dichiarazione variabili locali
    // Riempio la matrice di valori random scorrendo per righe e colonne
    for (i = 0; i < dimensione; i++)
    {
        for (j = 0; j < dimensione; j++)
        {
            genMatrix[i][j] = (rand() % randRange) + 1;
        }
    }
}
