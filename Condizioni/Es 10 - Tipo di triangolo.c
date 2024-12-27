#include <stdio.h>

int main()
{ // Dichiarazione variabili
    float l1, l2, l3;

    // Input
    printf("Inserire primo angolo: ");
    scanf("%f", &l1);
    printf("Inserire secondo angolo: ");
    scanf("%f", &l2);
    printf("Inserire terzo angolo: ");
    scanf("%f", &l3);

    // Verifica condizione angolo
    if (l1 == l2 && l2 == l3)
    {
        printf("Il triangolo è equilatero");
    }
    else if (l1 == l2 || l1 == l3 || l2 == l3)
    {
        printf("Il triangolo è isoscele");
    }
    else
    {
        printf("Il triangolo è scaleno");
    }
}