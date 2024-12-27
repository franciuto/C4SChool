#include <stdio.h>

int main()
{

    int n1, d1, n2, d2, somma;
    printf("Inserisci il primo numeratore: ");
    scanf("%d", &n1);
    printf("Inserisci il primo denominatore: ");
    scanf("%d", &d1);
    printf("Inserisci il secondo numeratore: ");
    scanf("%d", &n2);
    printf("Inserisci il secondo denominatore: ");
    scanf("%d", &d2);

    somma = ((n1 * d2) + (n2 * d1)) / (d1 * d2);

    printf("La somma è %d \n" , somma);

}