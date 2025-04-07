#include <stdio.h>    // Input/output
#include <time.h>     // srand, time()
#include <stdlib.h>   // rand
#define DIM 10        // Vector dimension
#define RRANGE 20     // Random range

int check_odd (int *vector, int index) {
    // Base case: all numbers have been checked and no even number was found
    if (index < 0)
    {
        return 1;
    }

    // If the current number is even, return 0 (stop the recursion)
    if (vector[index] % 2 == 0)
    {
        return 0;
    }
    
    // Recursive call: check the previous number in the array
    return check_odd(vector, index - 1);
}

int main () {
    srand(time(NULL));
    int i, random;

    int v[DIM] = {1,1,1,1,1,1,1,1,1,1};
    
    printf("%d", check_odd(v, DIM - 1));
}