#include <stdio.h>

int moltiplicazione(int a, int b) {
    
    if (b == 0) {
        return 0;
    }
    
    return a + moltiplicazione(a, b - 1);
}

int main() {
    int a, b;
    scanf("%d" , &a);
    scanf("%d" , &b);
    int risultato = moltiplicazione(a, b);
    printf("Il risultato di %d * %d è: %d\n", a, b, risultato);
    return 0;
}
