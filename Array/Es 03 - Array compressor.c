#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define array_size 50


int main () {
    
    srand(time(NULL));
    
    // Declarations
    int array[array_size];
    int compressed[array_size];
    int i, c, alreadySatisfied, matched = 0;

    // Fill the array with random numbers and print it
    printf("Array 1:\n");
    for (i = 0; i < array_size; i++)
    {
        array[i] = (rand() % 20) + 1;
        printf("%d ", array[i]);
    }

    // Cycle through the array 
    for (i = 0; i < array_size; i++)
    {  
        alreadySatisfied = 0;
        for (c = 0; c < array_size; c++)
        {
            if (array[i] == compressed[c])
            {
                alreadySatisfied++;
            }
        }
        if (alreadySatisfied == 0)
        {
            compressed[matched] = array[i];
            matched++;
        }
    }

    // Print the compressed array
    printf("\nArray 1 Compresso:\n");
    for ( i = 0; i < matched; i++)
    {
        printf("%d ", compressed[i]);
    }
        
    





}
