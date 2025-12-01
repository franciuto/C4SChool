/* Program to sum number until N */
#include <stdio.h>  // Basic I/O (pritnf / scanf)

int sum_until (int n) {
    // Base case
    if (n == 0) {
        return n;
    }
    // Recoursive call
    return n + sum_until(n - 1);
}


int main () {
    int numero;
    printf("Somma numeri fino a N\nN: ");
    scanf("%d" , &numero);

    printf("%d" , sum_until(numero));
}