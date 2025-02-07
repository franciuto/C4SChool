#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Costanti
#define righe 3     // M
#define colonne 4    // N
#define randRange 20

// Funzioni
void generateMatrice(int genMatrix[righe][colonne]);
void printMatrice(int matrix[righe][colonne]);
int inputHandler(int c);
void colExchanger(int matrix[righe][colonne], int c1, int c2);

int main ()
{
    srand(time(NULL));
    int mainMatrix[righe][colonne];

    // Genero e stampo
    generateMatrice(mainMatrix);
    printMatrice(mainMatrix);

    // Input, check input, calcolo indirizzo reale, inverto
    colExchanger(mainMatrix, (inputHandler(2) - 1), (inputHandler(1) - 1));

    printf("Matrice invertita\n");
    printMatrice(mainMatrix);

}

void colExchanger (int matrix[righe][colonne], int c1, int c2)
{
    int i, j;       // Pointers
    int buffer;     // Variabili locali
    for (i = 0; i < righe; i++)
    {
        buffer = matrix[i][c2];
        matrix[i][c2] = matrix[i][c1];
        matrix[i][c1] = buffer;
    }

}

int inputHandler(int c)
{
    int user_c;
    printf("Inserisci C%d: ", c);
    scanf("%d", &user_c);

    // Check input
    while (user_c < 1 || user_c > colonne)
    {
        printf("Colonna non valida");
        printf("\nInserisci colonna (1-%d): ", colonne);
        scanf("%d", &user_c);
    }
    return user_c;
}

void printMatrice(int matrix[righe][colonne])
{
    int i, j;       // Puntatori
    // Stampa scorrendo le righe e le colonne
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            printf("%d\t", matrix[i][j]);       // Uso \t per fare una tabulazione e avere tutto stampato in modo corretto
        }
        printf("\n");       // Vado a capo dopo ogni riga
    }
}

void generateMatrice(int genMatrix[righe][colonne])
{
    int i, j;    // Puntatori
    // Riempio la matrice di valori random scorrendo per righe e colonne
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            genMatrix[i][j] = (rand() % randRange) + 1;
        }
    }
}
