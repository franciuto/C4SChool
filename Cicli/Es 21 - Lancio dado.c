#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    srand(time(NULL));

    int i, d1, counter = 0, extraction;
    int facce[100];

    for (i = 0; i < 100; i++)
    {

        d1 = (rand() % 6) + 1;
        facce[i] = d1;
        if (facce[i] == 5)
            {
                counter++;
            }

    }
    i = 0;

    while (facce[i] != 5)
    {
        extraction = facce[i];
        i++;
    }
    
    printf("Il numero 5 è uscito %d volte", counter);
    printf("\nIl numero 5 è uscito alla %d estrazione" , extraction);
}