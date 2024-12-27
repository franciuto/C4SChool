/*Crea una funzione isNumeroPerfetto che accetta un numero intero e restituisce 1 se il numero è perfetto (un numero uguale alla somma dei suoi divisori propri, ovvero escluso il numero stesso) e 0 altrimenti. Nel main, chiedi all'utente di inserire un numero, utilizza la funzione per verificare se è un numero perfetto e stampa il risultato.
1 = Perfetto
0 = non perfetto
*/

#include <stdio.h>

int isNumeroPerfetto(int n)
{
    int i, sum = 0;
    for (i = 0; i < n / 2; i++)
    {
        if (n % i == 0)
        {
            if (i != n)
            {
                sum += i;
            }
            sum += i;
        }
    }
    if (n == sum) {
        return 1;
    }
    return 0;    
}

int main()
{
    int n;

    printf("Is Numero perfetto?\nInserisci un numero: ");
    scanf("%d", &n);

    printf("%d", isNumeroPerfetto(n));
}
