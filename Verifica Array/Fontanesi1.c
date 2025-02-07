#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define array_length 15

int main()
{
    srand(time(NULL));

    // Dichiarazioni
    int array[array_length];
    int array2[array_length] = {0};
    int i, media, somma = 0, match = 0;
    
    // Riempimento array
    for (i = 0; i < array_length; i++)
    {
        array[i] = (rand() % 101) - 50;
    }

    // Calcolo Somma
    for (i = 0; i < array_length; i++)
    {
        somma += array[i];
    }

    media = somma / array_length;       // Calcolo media

    // Riempimento secondo array
    for (i = 0; i < array_length; i++)
    {
        if (array[i] > media)
        {
            array2[match] = array[i];
            match++;
        }
    }

    // Stampe
    printf("Secondo array: ");
    for (i = 0; i < match; i++)
    {
        printf("%d ", array2[i]);
    }
    printf("\nContiene %d elementi", match);
}