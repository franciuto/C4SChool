#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

    srand(time(NULL));

    int n_togess, p_guess, tries = 0;

    n_togess = (rand() % 100) + 1;

    do
    {
        printf("Inserisci la tua ipotesi: ");
        scanf("%d" , &p_guess);

        if (p_guess > n_togess)
        {
            printf("Il numero è maggiore di quello che devi trovare\n");
        }else if (p_guess < n_togess)
        {
            printf("Il numero è minore di quello che devi trovare\n");
        }
        
        
        tries++;
    } while (p_guess != n_togess);

    printf("\nCongratulazioni, hai vinto!!\nHai terminato il gioco in %d tentativi" , tries);
    
}