#include <stdio.h>

int main()
{

    int n_toins, reference, c = 1, ins, max_counter = 0, min_counter = 0, equal_counter = 0;

    printf("Quanti numeri vuoi inserire: ");
    scanf("%d", &n_toins);
    printf("Che numero vuoi usare come confronto: ");
    scanf("%d", &reference);

    while (n_toins > 0)
    {
        printf("Inserisci il %d numero: ", c);
        scanf("%d", &ins);
        c++;
        n_toins--;

        if (ins > reference)
        {
            max_counter++;
        }
        else if (ins < reference)
        {
            min_counter++;
        }
        else
        {
            equal_counter++;
        }
    }
    printf("\nI numeri uguali sono %d\nI numeri maggiori sono %d\nI numeri minori sono %d" , equal_counter , max_counter , min_counter);
}