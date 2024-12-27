#include <stdio.h>

int main()
{
    // Dichiarazione variabili
    int n1, n2, n3;

    // Inserimento numeri
    printf("Inserisci il primo numero: ");
    scanf("%d", &n1);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &n2);
    printf("Inserisci il terzo numero: ");
    scanf("%d", &n3);

    int max = n1;
    
    //Confronto tra valori
    if (n2 > max)
    {
        max = n2;
    }
    if (n3 > max)
    {
        max = n3;
    }

    //Stampa del valore
    printf("Il numero maggiore è %d" , max);
}