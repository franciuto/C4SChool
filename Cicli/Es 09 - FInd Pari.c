#include <stdio.h>

int main () {

    int n, c = 0;
    printf("Inserisci numero: ");
    scanf("%d" , &n);

    while (n%2 == 0)
    {
        c++;
        scanf("%d" , &n);
    }
    
    printf("Hai inserito %d numeri pari" , c);

}