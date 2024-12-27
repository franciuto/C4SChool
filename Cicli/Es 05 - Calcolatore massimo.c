#include <stdio.h>

// Dati 10 numeri in input decreta il massimo

int main()
{

    float max = 0;
    float n;
    int c = 10;
    int ins = 1;

    while (c != 0)
    {
        printf("Inserire %d numero: ", ins);
        scanf("%f", &n);

        if (n > max)
        {
            max = n;
        }

        ins++;
        c--;
    }
    printf("Il massimo tra i 10 numeri inseriti è %.2f" , max);
}