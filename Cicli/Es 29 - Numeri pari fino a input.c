#include <stdio.h>

int main () {

    int userinput, i, p = 0;
    printf("Inserisci un numero: ");
    scanf("%d" , &userinput);

    printf("I numeri pari prima del numero da te scelto sono:\n");

    for (i=0; i <= userinput; i++)
    {   
        printf("%d\n" , p);
        p = p + 2;
       
    }
}