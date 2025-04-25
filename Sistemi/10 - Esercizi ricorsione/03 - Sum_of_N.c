/* Program to sum the digits of a number */
#include <stdio.h>  // Basic I/O (pritnf / scanf)

int sum (int n) {
    //  Base case
    if (n == 0) {
        return n;
    }
    // Extract the last digit from n
    int to_sum = n % 10;
    
    // Recoursive condition
    return to_sum + sum(n / 10);
}

int main () {
    int numero;
    printf("Somma delle cifre di N\nN: ");
    scanf("%d" , &numero);
    printf("%d", sum(numero));
}