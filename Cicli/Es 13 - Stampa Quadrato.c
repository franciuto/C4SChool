#include <stdio.h>

int main()
{

    //Dichiarazione variabili
    int r;      //Variabile per scrittura linea

    //Input iniziai
    printf("Inserisci un numero per la lunghezza del quadrato: ");
    scanf("%d", &r);
    
    //Assegnazioni variabili
    int l = r;      //Counter linee
    int p = r;      //Counter valore iniziale

    //Ciclo while per scrittura di tutte le linee
    while (l > 0)
    {
        //Ciclo while per una riga
        while (r > 0)
        {
            printf("* ");
            r--;
        }
        r = p;      //Reset 
        printf("\n");
        l--;
    }
}