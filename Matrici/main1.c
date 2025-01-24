#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define dimensione 4

void fillMatrix(int matrix[dimensione][dimensione])
{
    int i, j;
    for (i = 0; i < dimensione; i++)
    {
        for (j = 0; j < dimensione; j++)
        {
            matrix[i][j] = (rand() % 30) + 1;
        }
    }
}

int main () 
{
    int i, j;
    
}