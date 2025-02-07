#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Costanti
#define dimensione 4
#define randRange 50

// Funzioni
void generateMatrice(int genMatrix[dimensione][dimensione]);
void printMatrice(int matrix[dimensione][dimensione]);

int main() {
    int x;
    int user_c
    srand(time(NULL));
    int mainMatrix[dimensione][dimensione];

    // Genero e stampo
    generateMatrice(mainMatrix);
    printMatrice(mainMatrix);

    // Input x
    printf("Inserisci X: ");
    scanf("%d" , &x);

    // Input colonna
    printf("Scegli la colonna (1-4): ");
    scanf("%d" , &user_c);

    while (user_c < 1 || user_c > dimensione) {
        printf("\nColonna errata");
        printf("Scegli la colonna (1-4): ");
        scanf("%d" , &user_c);
     
    }
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