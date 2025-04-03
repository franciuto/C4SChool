/* Program to print the base 2 conversion of N*/
#include <stdio.h>  // Basic I/O (pritnf / scanf)

void to_binary (long n) {
    // Base case
    if (n == 0) {
        return;
    }
    
    // Recoursive condition
    to_binary(n / 2);
    printf("%ld" , n % 2);
}

int main () {
    long n;
    printf("Conversione in base binaria di N\nN: ");
    scanf("%ld" , &n);
    to_binary(n);
}