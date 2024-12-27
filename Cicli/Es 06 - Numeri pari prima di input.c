#include <stdio.h>

int main () {

    int userinput, i;
    printf("Inserisci un numero: ");
    scanf("%d" , &userinput);

    printf("I numeri pari prima del numero da te scelto sono:\n");

    for (i=1; i < userinput; i++)
    {
        if (i%2==0)
        {
            printf("%d\n" , i);
        }
        
    }
}