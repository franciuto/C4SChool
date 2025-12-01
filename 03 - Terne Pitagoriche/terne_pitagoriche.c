#include <stdio.h>  //printf, scanf

void trovaTernePitagoriche(int N)
{
    int a, b, c;

    for (a = 1; a <= N; a++)
    {
        for (b = a; b <= N; b++)
        { // Start from b = a to skip duplicates
            for (c = b; c <= N; c++)
            { // Start from c = b to skip duplicates
                if (a * a + b * b == c * c)
                {
                    printf("Terna pitagorica: %d, %d, %d\n", a, b, c);
                }
            }
        }
    }
}

int main()
{
    int N;

    printf("Inserisci un numero N: ");
    scanf("%d", &N);

    if (N < 5)
    {
        printf("Non ci sono terne pitagoriche per N < 5.\n");
    }
    else
    {
        trovaTernePitagoriche(N);
    }
}