/* Fontanesi Francesco - Recursive library*/
/* All functions uses recursive calls*/
#include <stdio.h>  // printf    
#include "recursive_lib.h"

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