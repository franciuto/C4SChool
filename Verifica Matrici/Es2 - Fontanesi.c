#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Costanti
#define dimensione 4
#define randRange 50

// Funzioni
void generateMatrice(int genMatrix[dimensione][dimensione]);
void printMatrice(int matrix[dimensione][dimensione]);
int contaPariPerRiga(int matrix[dimensione][dimensione], int user_row);

int main ()
{
    srand(time(NULL));
    int user_row;
    int mainMatrix[dimensione][dimensione];

    // Genero e stampo
    generateMatrice(mainMatrix);
    printMatrice(mainMatrix);

    // Input request
    printf("Inserisci riga (1-4): ");
    scanf("%d", &user_row);

    // Check input
    while (user_row < 1 || user_row > dimensione)
    {
        printf("Riga non valida");
        printf("\nInserisci riga (1-4): ");
        scanf("%d", &user_row);
    }

    // Chiamo la funzione sottraendo uno all'input per ottenere l'indirizzo reale
    printf("Gli elementi pari della riga %d sono: %d", user_row, contaPariPerRiga((mainMatrix), user_row - 1));
}

int contaPariPerRiga(int matrix[dimensione][dimensione], int user_row)
{
    int i, j;
    int pari_counter = 0;

    for (j = 0; j < dimensione; j++)
    {
        if (matrix[user_row][j] % 2 == 0)
        {
            pari_counter++;
        }
    }
    return pari_counter;
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