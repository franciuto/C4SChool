#include <stdio.h>

int cifraMaggiore(int numero) {
    // Declaration
    int max = 0, last_n;

    // Loop until the number is 0 (every digit has been checked)
    while (numero > 0) {
        last_n = numero % 10;   // Extract last digit by deviding by 10 and taking the remainder
        if (last_n > max){      // If greater than max set max to last_n
            max = last_n;
        }
        numero /= 10;           // Remove last digit
    }
    return max;
}

int main () {
    int numero;
    // Input
    printf("Inserisci numero: ");
    scanf("%d", &numero);
    // Output
    printf("%d" , cifraMaggiore(numero));

}
