#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    srand(time(NULL));
    
    //Dichiarazione variabili
    int d1, d2;
    float puntata = 0, budget = 0, sum = 0, budget_iniziale = 0 , guadagnato = 0, perso = 0;

    // Print Regole + Budget
  printf(
      "Benvenuto sul gioco dei dadi\n\nREGOLAMENTO\nUna volta tirati i due "
      "dadi se i valori sono:\n - 11, 12 o 2 la puntata viene raddoppiata\n - "
      "6 o 7 la puntata è persa\n - Altrimenti la puntata è recuperata\n"
      "Con puntata = 0 si termina la partita\n\n");
  printf("Inserisci il tuo budget: ");
  scanf("%f", &budget);
  //Controllo che il budget sia maggiore e diverso da zero
  while (budget <= 0) {
        printf("Il budget inserito non è sufficiente\nInserisci il tuo budget ");
        scanf("%f", &budget);
        budget_iniziale = budget;
    }

    //Eseguo il codice finchè l'utente ha budget
    do
    {
        //Puntata dell'utente
        printf("\nIl tuo budget è %.2f€\nInserisci la tua puntata: ", budget);
        scanf("%f", &puntata);

        //Controllo che la puntata dell'utente non sia maggiore del suo budget
        while (puntata > budget)
        {
            printf("\nPuntata non valida");
            printf("\nIl tuo budget è %.2f€\nInserisci la tua puntata: ", budget);
            scanf("%f", &puntata);
        }

        //Condizione che permette all'utente di interrompere in ogni momento la partita puntando "0"
        if (puntata == 0){break;}
        
        //"Tiro" i dadi assegnando un valore randomico da 1 a 6
        d1 = (rand() % 6) + 1;
        d2 = (rand() % 6) + 1;
        sum = d1 + d2; //Sommo i due dadi per avere il valore complessivo

        //Verifico le regole del gioco
        if (sum == 11 || sum == 12 || sum == 2)
        {
            printf("\nHai raddoppiato la puntata\n");
            budget += puntata;  //Aggiungo al budget la puntata raddoppiata
            guadagnato += puntata;  //Aggiungo al guadagno la parte guadagnata (Per tracciare la statistica)
        }
        else if (sum == 6 || sum == 7)
        {
            printf("\nHai perso la puntata\n");
            budget -= puntata;  //Sottraggo dal budget la puntata
            perso += puntata;   //Aggiungo la puntata al denaro perso dall'utente (Per tracciare la statistica)
        }
        else
        {
            printf("\nHai recuperato la puntata\n");
        }
     } while (budget != 0);

  //Statistiche di fine partita
  printf("\n-----------------");
  printf("\nHai chiuso la partita con un budget di %.2f€\nHai guadagnato %.2f€\nHai perso %.2f€" , budget , guadagnato , perso);
}