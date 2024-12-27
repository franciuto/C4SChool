#include <stdio.h>

int main()
{

    // Dichiaro variabile input
    int n;

    // Input utente
    printf("Inserisci un numero: ");
    scanf("%d", &n);

    //Controllo input negativo
    while (n < 1)
    {
        printf("Il numero non può essere negativo");
        scanf("%d" , &n);
    }

    //Condizione se input è uguale a uno
    if (n  == 1)
    {
        printf("*");
        return 0;
    }
    

    // Dichiaro variabili
    int r = n;               // Dichiaro "r" da usare come counter per comporre una linea di "n" elementi
    int linecounter = n - 2; // Dichiaro "linecounter" che uso come counter delle righe con spazio da stampare in modo che quando sarà = 0 saprò che ho finito di stampare le linee "particolari" e posso stampare quell

    printf("\n"); // Separo con una linea vuota il campo input dal quadrato

    // Stampo una linea con tanti "*" definiti da "r"
    while (r > 0)
    {
        printf("* ");
        r--;
    }
    printf("\n");       //Vado a capo

    //Ciclo che scrive linee "modificate" con vuoto finchè "linecounter = 0" ossia finchè n - 2 = 0 (perchè le 2 linee tolte sono la prima e la seconda che vanno stampate come intere)
    while (linecounter > 0)
    {
        printf("*");

        int space = (n - 2);        //Setup della variabile "space" a (n - 2) * 2 perchè tolti i due simboli all'inizio e alla fine gli spazi vuoti sono uguali a n - 2 e poi * 2 perchè per compensare l'allineamento dei caratteri "*" che vengono stampati con uno spazio dopo (vedi "printf" linea 22) è necessario che anche gli spazi siano in relazione 2 spazi per un "*"
        while (space > 0)       //Ciclo che scrive gli spazi tra un "*" e l'altro utilizzando la variabile "space"
        {
            printf("  ");
            space--;
        }

        printf(" *\n");     //Si va a capo per stampare la line "modificata" successiva
        linecounter--;
    }

    r = n;      //Reset di r al valore originale inserito
    
     // Stampo una linea con tanti "*" definiti da "r"
    while (r > 0)
    {
        printf("* ");
        r--;
    }
    printf("\n");

    return 0;
}