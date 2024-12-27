#include <stdio.h>

int isNumeroPerfetto(int n)
{
    int i, sum = 0;

    // Find the divisors and add them to the sum
    for (i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    // If it's a perfect number return 1, else return 0
    if (n == sum)
    {
        return 1;
    }
    return 0;
}

int main()
{
    // User Input
    int n;
    printf("Is Numero perfetto?\nInserisci un numero: ");
    scanf("%d", &n);
    // Check for correct input
    while (n <= 0)
    {
        printf("Valore inserito non valido, inserisci un numero maggiore di 0: ");
        scanf("%d", &n);
    }
    
    // Print the result
    if (isNumeroPerfetto(n) == 1)
    {
        printf("Il numero è perfetto");
    }
    else
    {
        printf("Il numero non è perfetto");
    }
}
