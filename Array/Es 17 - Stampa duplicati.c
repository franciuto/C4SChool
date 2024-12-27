#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Array_Size 30

int main()
{
    // Time randomizer
    srand(time(NULL));

    // Variables
    int array[Array_Size];
    int duplicate[Array_Size];
    int i, c, Found = 0, MatcCount = 0, g, already = 0;

    // Fill up array with random numbers
    for (i = 0; i < Array_Size; i++)
    {
        array[i] = (rand() % 20) + 1;
    }

    // Print the array
    for (i = 0; i < Array_Size; i++)
    {
        printf("%d ", array[i]);
    }

    // An iteration to cycle through the array (indicate the first cell to compare)
    for (i = 0; i < Array_Size; i++)
    {
        // Reset the variables
        Found = 0;
        already = 0;

        // An iteration to cycle through the array and compare the selected cell with the rest of the array
        for (c = 0; c < Array_Size; c++)
        {

            // If a match is found
            if (array[i] == array[c])
            {
                // Increment the found counter
                Found++;
            }

            // If there is one or more matches
            if (Found > 1)
            {
                // Check the entire array if the number is already in the duplicate array
                for (g = 0; g < Array_Size; g++)

                    if (array[i] == duplicate[g])
                    {
                        already++;
                    }

                // If there is no match in the duplicate array
                if (already == 0)
                {
                    duplicate[MatcCount] = array[i];
                    MatcCount++;
                }
            }
        }
    }

    // New line
    printf("\n\n");
    // Final print
    printf("Sono stati trovati %d numeri duplicati: ", MatcCount);
    for (i = 0; i < MatcCount; i++)
    {
        printf("%d ", duplicate[i]);
    }
}
