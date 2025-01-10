#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ArrayLenght 30

// Funzione che ritorna void perchè modificando un'array passato si modifica anche quello originale
void generaArray(int array_to_fill[], int lenght)
{
    int i;
    for (i = 0; i < lenght; i++)
    {
        array_to_fill[i] = (rand() % 50) + 1;
    }
}
// Funzione calcola la somma ritornando un'intero (somma)
int sommaArray(int array_to_sum[], int lenght)
{
    int i, somma = 0;
    for (i = 0; i < lenght; i++)
    {
        somma += array_to_sum[i];
    }
    return somma;
}

int main()
{
    int i;
    int array1[ArrayLenght]; // Dichiaro l'array
    srand(time(NULL));

    generaArray(array1, ArrayLenght); // Chiamo la funzione per riempire l'array
    // Stampo l'array generato
    printf("Array generato: ");
    for (i = 0; i < ArrayLenght; i++)
    {
        printf("%d ", array1[i]);
    }
    // Stampo la somma
    printf("La somma degli elementi è: ");
    printf("%d", sommaArray(array1, ArrayLenght));
}