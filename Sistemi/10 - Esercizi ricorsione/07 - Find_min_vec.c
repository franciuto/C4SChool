/* Program to find the minimum value in a vectors */

#include <stdio.h>    // Input/output
#include <time.h>     // srand, time()
#include <stdlib.h>   // rand
#define DIM 10        // Vector dimension
#define RRANGE 20     // Random range

int find_smaller (int *vector , int start, int end) {
    // Base case
    if (start == end) {
        return vector[start];
    }
}

int main () {
    srand(time(NULL));
    int v[DIM];
    int i;
    for (i = 0; i < DIM; i++)
    {
        v[i] = rand() % RRANGE;
        printf("%d " , v[i]);
    }

    printf("\n%d" , find_smaller(v, 0 , DIM - 1));
}