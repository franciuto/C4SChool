#include <stdio.h>

int main () {

    //Variabili
    int user_request , i, prodotto;

    //Richiesta input
    printf("Inserire un numero di cui si vuole sapere la tabellina: ");
    scanf("%d", &user_request);

    //Ciclo per scrittura della tabellina
    for (i = 0; i <= 10; i++)
    {
        prodotto = user_request * i;

        printf("%2d * %2d = %3d\n" , user_request , i , prodotto);
    }
    
}