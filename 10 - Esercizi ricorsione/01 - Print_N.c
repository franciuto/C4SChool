/* Program to print numbers until N using recursion */
#include <stdio.h>  // Basic I/O (pritnf / scanf)

void before(int n) {
    // Base case
    if (n == 0) {
        printf("0 ");
        return;
    }
    // Recoursive call
    before(n - 1);
    printf("%d " , n);
}

int main () {
    int number;
    printf("Stampa numeri fino a N.\nN: ");
    scanf("%d" , &number);
    before(number);
}