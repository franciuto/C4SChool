#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define arrayLenght 50

int main () {

    srand(time(NULL));

    int array[50];
    int i, h, k, sum;

    for (i = 0; i < arrayLenght; i++)
    {
        array[i] = (rand() % 100) - 1;
        printf("%d ", array[i]);
    }
    
    printf("\nInserire primo puntatore: ");
    scanf("%d", &k);
    printf("Inserire secondo puntatore: ");
    scanf("%d", &h);

    while (h < 0 || h > arrayLenght -1 || k < 0 || k > arrayLenght -1)
    {   
        printf("Errore, inserire un numero compreso tra 0 e %d\n" , arrayLenght - 1);
        printf("Inserire primo puntatore: ");
        scanf("%d", &k);
        printf("Inserire secondo puntatore: ");
        scanf("%d", &h);
    }

    sum = array[k] + array[h];
    printf("La somma di %d e %d è: %d\n", array[k], array[h], sum);
        
}