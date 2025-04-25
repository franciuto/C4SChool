/* Fontanesi Francesco - Recursive library*/
/* All functions uses recursive calls*/
#include <stdio.h>  // printf    

#include "recursive_lib.h"

/* Function to print all the integers from 0 to N*/
void print_to_n (int n) {
    // Base case
    if (n == 0) {
        printf("0 ");
        return;
    }
    // Recursive call
    print_to_n(n - 1);
    printf("%d ", n);
}

/* Function to sum all the integers from 0 to N */
int sum_until (int n) {
    // Base case
    if (n == 0) {
        return n;
    }
    // Recursive call
    return n + sum_until(n - 1);
}

/* Function to sum the digits of a number*/
int sum_digits (int n) {
    // Base case
    if (n == 0)
    {
        return n;
    }
    // Extract the last digit of n
    int to_sum = n % 10;

    // Recoursive condition
    return to_sum + sum_digits(n / 10);
}