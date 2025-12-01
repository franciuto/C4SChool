/* Program to print a reversed array */
#include <stdio.h>  // Basic I/O (pritnf() / scanf())
#include <time.h>   // Srand, time()
#include <stdlib.h> // Rand
#define DIM 10 
#define RANGE 20

void invert_vect (int *v , int dimension) {
    // Base case
    if (dimension < 0) {
        return;
    }
    
    // Recoursive condition
    printf("%d " , v[dimension]);
    invert_vect(v , dimension - 1);
}

int main () {
    int i;
    // Seed initialization
    srand(time(NULL));
    int arr[DIM];
    // Fill array with random and print it
    for (i = 0; i < DIM; i++) {
        arr[i] = rand() % 20;
        printf("%d " , arr[i]);
    }
    printf("\nInversione di array\n");
    invert_vect(arr, DIM - 1);
}