#include <stdio.h>

float somma (float n1, float n2);

int main () {
	float n1, n2, res;

	printf("Inserisci numero 1: ");
	scanf("%f" , &n1);
	printf("Inserisci numero 2: ");
	scanf("%f" , &n2);

	printf("%f" , somma(n1, n2));
}