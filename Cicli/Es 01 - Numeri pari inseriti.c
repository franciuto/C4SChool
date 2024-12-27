#include <stdio.h>

int main () {

    int n, c = 0;
    printf("Inserisci numero: ");

    do
    {
        scanf("%d" , &n);
        if (n%2 == 0)
        {
            c++;
        }
        
        
    }
    while (n%2 == 0);
    
    printf("Hai inserito %d numeri pari" , c);
}
