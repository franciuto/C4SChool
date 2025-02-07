#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define array_length 10

int main()
{
    srand(time(NULL));

    // Dichiarazioni
    int array[array_length];
    int n1, n2, i;

    // Riempimento array + stampa
    for (i = 0; i < array_length; i++)
    {
        array[i] = (rand() % 10) + 1;
        printf("%d ", array[i]); 
    }

    printf("\n");

    // Salvataggio ultimi 2 elementi
    n1 = array[array_length - 2];
    n2 = array[array_length - 1];

    // Spostamento destra
    for (i = array_length - 1; i >= 2; i--)
    {
        array[i] = array[i - 2];
    }

    // Aggiungo elementi salvati
    array[0] = n1;
    array[1] = n2;

    // Stampa
    for (i = 0; i < array_length; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}