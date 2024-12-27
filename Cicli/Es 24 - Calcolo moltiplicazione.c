#include <stdio.h>

int main () {

    int f1, f2, p = 0;

    printf("Inserisci fattore 1: ");
    scanf("%d" , &f1);
    printf("Inserisci fattore 2: ");
    scanf("%d" , &f2);

    while (f2 > 0)
    {
        p = p + f1;
        f2--;
    }
    printf("Il prodotto è %d" , p);
}