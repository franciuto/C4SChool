#include <stdio.h>

int main()
{

    //Dichiarazione variabili
    int n;
    int i = 1;

    //Input del valore da utente
    printf("Inserire un numero: ");
    scanf("%d", &n);

    //Ciclo che viene eseguito n.volte = n
    while (n <= 0)
    {
        printf("\nIl numero inserito non è valido\nInserire numero positivo: ");
        scanf("%d", &n);
    }

    //Ciclo che calcola valori positivi minori di "n" e li stampa in ordine crescente
    while (i < n)
    {
        if (i % 2 == 0)
        {
            printf("%d\n", i);
        }
        i++;
    }
}