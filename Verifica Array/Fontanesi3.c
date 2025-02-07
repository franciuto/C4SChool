#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define array_length 6

int main()
{
    srand(time(NULL));

    // Dichiarazioni
    int array[array_length];
    int array2[array_length];
    int i, moltiplicazione, max;

    // Riempimento array + stampa
    for (i = 0; i < array_length; i++)
    {
        array[i] = (rand() % 10) + 1;
        array2[i] = (rand() % 10) + 1;
        printf("%d ", array[i]);  
    }
    printf("\n");
    for (i = 0; i < array_length; i++)
    {
        printf("%d ", array2[i]);
    }

    for (i = 0; i < array_length; i++)
    {
        moltiplicazione = array[i] * array2[i];
        max = moltiplicazione;
        if (moltiplicazione > max)
        {
            max = moltiplicazione;
        }
    }
    printf("\n%d", max);
    

}