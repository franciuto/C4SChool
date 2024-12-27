#include <stdio.h>

int main()
{
    int n;
    printf("Inserire un numero da 1 a 7: ");
    scanf("%d" , &n);
    switch (n)
    {
    case 1:
        printf("Il %d giorno della settimana e' Lunedì" , n);
    break;
    case 2:
        printf("Il %d giorno della settimana e' Martedì" , n);
    break;
    case 3:
        printf("Il %d giorno della settimana e' Mercoledì" , n);
    break;
    case 4:
        printf("Il %d giorno della settimana e' Giovedì" , n);
    break;
    case 5:
        printf("Il %d giorno della settimana e' Venerdì" , n);
    break;
    case 6:
        printf("Il %d giorno della settimana e' Sabato" , n);
    break;
    case 7:
        printf("Il %d giorno della settimana e' Domenica" , n);
    break;
    
    default:
        printf("Il valore inserito non è valido");
        break;
    }    
}