#include <stdio.h>

int main()
{

    // Dichiarazione variabili
    float costo1, importo;
    int qt;

    // Setup  + input costo1
    printf("Inserire il costo unitario: ");
    scanf("%f", &costo1);

    // Controllo se il valore inserito è corretto
    while (costo1 <= 0)
    {
        printf("Valore non valido\nInserire valore valido: ");
        scanf("%f", &costo1);
    }

    // Inserimento qt
    printf("Inserire quantità acquistata: ");
    scanf("%d", &qt);

    // Controllo che il valore sia positivo
    while (qt <= 0)
    {
        printf("Valore non valido\nInserire valore valido: ");
        scanf("%d", &qt);
    }

    importo = costo1 * qt;

    if (importo >= 100)
    {
        printf("Hai superato i 100€ hai diritto ad uno sconto del 5%%\n");
        importo = importo * 0.95;
        printf("L'importo da pagare e' %.2f€", importo);
    }
    else
    {
        printf("Non hai diritto a nessuno sconto\nL'importo da pagare e' %.2f€", importo);
    }
}
