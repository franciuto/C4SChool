#include <stdio.h>

int isNumeroPerfetto(int n)
{
    int i, sum = 0;
    for (i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    if (n == sum)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    printf("Is Numero perfetto?\nInserisci un numero: ");
    scanf("%d", &n);
    while (n <= 0)
    {
        printf("Valore inserito non valido, inserisci un numero maggiore di 0: ");
        scanf("%d", &n);
    }
    if (isNumeroPerfetto(n) == 1)
    {
        printf("Il numero è perfetto");
    }
    else
    {
        printf("Il numero non è perfetto");
    }
}
