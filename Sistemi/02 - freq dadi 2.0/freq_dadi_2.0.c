#include <time.h>
#include <stdio.h>  // Printf e scanf
#include <stdlib.h> // Rand e srand

int main()
{
    srand(time(NULL));

    // Var declaration
    int launches, dices, faces;
    int i, dices_counter, random_res;

    // USER INPUT
    // Ask for number of dices
    printf("Dadi da lanciare: ");
    scanf("%d", &dices);
    // Ask for faces
    printf("Facce per ogni dado: ");
    scanf("%d", &faces);
    // Ask for number of launches
    printf("Numero di lanci: ");
    scanf("%d", &launches);

    // ARRAY DECLARATION & DEFINITION
    // Declare a variable length array
    int result[faces + 1];
    // I use a for to set every value to 0 because it's not possible initialize a variable lenght aray
    for (i = 0; i <= faces; i++)
    {
        result[i] = 0;
    }

    // Simulazione dei lanci
    for (i = 0; i < launches; i++)
    {
        for (dices_counter = 0; dices_counter < dices; dices_counter++)
        {
            random_res = (rand() % faces) + 1; // Generate a number between 1 and faces
            result[random_res]++;
        }
    }

    // Stampa dei risultati
    for (i = 1; i <= faces; i++)
    {
        printf("Faccia %d: %d\n", i, result[i]);
    }
}