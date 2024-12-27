#include <stdio.h>
#include <stdlib.h>

// Dichiarazioni variabili
float PrezzoTotale, PrezzoScontato;

int calcolo(int sconto)
{
    PrezzoScontato = PrezzoTotale - ((PrezzoTotale / 100) * sconto);
}

int main()
{
    // Sezione input
    printf("Benvenuto su calcolatore sconto\nInserisci il prezzo totale della spesa: ");
    scanf("%f", &PrezzoTotale);

    // Controllo spesa
    if (PrezzoTotale < 50)
    {
        calcolo(5);
    }
    else if (PrezzoTotale < 65)
    {
        calcolo(6);
    }
    else if (PrezzoTotale < 80)
    {
        calcolo(7);
    }
    else
    {
        calcolo(10);
    }

    printf("L'importo da pagare e' %.2f Euro", PrezzoScontato);
}