#include <stdio.h>

int main ()
{
    int x;
    printf("Digita una cifra minore di 3: ");
    scanf("%d" , &x);
    switch(x) {

        //Switch si fa solo su int o char
        //non supporta operatori logici
        case 1:
            printf("Il numero inserito è uno");
            break;
        case 2:
            printf("Il numero inserito è due");
            break;
        case 3:
            printf("Il numero inserito è tre");
            break;
    default:
    printf("Non riconosco il valore digitato");
    }

}

