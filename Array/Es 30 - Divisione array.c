#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define array_size 50

int main()
{

    srand(time(NULL));

    int array[array_size];
    int div2[array_size];
    int div3[array_size];
    int i, match2 = 0, match3 = 0;

    for (i = 0; i < array_size; i++)
    {
        array[i] = (rand() % 40) + 1;
        printf("%d ", array[i]);
    }

    for (i = 0; i < array_size; i++)
    {
        if (array[i] % 2 == 0 && array[i] % 3 == 0)
        {
            div2[match2] = array[i];
            div3[match3] = array[i];
            match2++;
            match3++;
        }
        else if (array[i] % 2 == 0)
        {
            div2[match2] = array[i];
            match2++;
        }
        else if (array[i] % 3 == 0)
        {
            div3[match3] = array[i];
            match3++;
        }
    }

    printf("\nDivisibile per 2: \n");
    for (i = 0; i < match2; i++)
    {
        printf("%d ", div2[i]);
    }
    printf("\nDivisibile per 3: \n");
    for (i = 0; i < match3; i++)
    {
        printf("%d ", div3[i]);
    }

    
}