// Una volta inseriti due numeri interi calcolare se uno è multiplo dell'altro

#include <stdio.h>

int main()
{
    // Dichiarazione variabili
    int n1, n2;

    // Input di valori
    printf("Inserire valore 1: ");
    scanf("%d", &n1);
    printf("Inserire valore 2: ");
    scanf("%d", &n2);

    // Calcolo del modulo
    if (n1 % n2 == 0)
    {
        printf("%d e multiplo di %d", n1, n2);
    }
    else if (n2 % n1 == 0)
    {
        printf("%d e multiplo di %d", n2, n1);
    }
    else
    {
        printf("Non ci sono multipli");
    }
}
