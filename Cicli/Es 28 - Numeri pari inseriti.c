#include <stdio.h>

int main() {

    int n, c = 0, s = 0;

    while (s != 1)
    {
        printf("Inserisci un numero: ");
        scanf("%d" , &n);

        if (n%2 == 0)
        {
            c++;
        }
        else
        {
            s = 1;
        }
        
    }
    printf("Hai inserito %d numeri pari" , c);
    
}

