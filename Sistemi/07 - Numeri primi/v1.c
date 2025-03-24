#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define LENGHT 1000000001

int prime[LENGHT] = {0};

int is_primo(int n){
    int i;

    if (n <= 1) return 0; // 1 e numeri minori non sono primi
    if (n == 2 || n == 3) return 1; // 2 e 3 sono primi
    if (n % 2 == 0) return 0; // Numeri pari maggiori di 2 non sono prim

	if (n % 2 == 0)
		return 0; // Because the number is even
	for(i=3; i <= (int)sqrt(n); i += 2){
		if (n % i == 0)
			return 0; // No because it has been found
    }

	return 1;

}

int main () {
    int max, i,c = 0, res, found = 0;
    printf("Trova numeri primi fino a: ");
    scanf("%d" , &max);

    clock_t start = clock();
    for (i = 0; i < max; i++){
        res = is_primo(i);
        if (res == 1) {
            prime[c] = i;
            c++; 
            found++;
        }
    }    
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    i = 0;
    while (i < 20)
    {
        printf(" %d" , prime[i]);
        i++;
    }
    printf("Sono stati trovati %d" , found);
    printf("\nRuntime calcolo: %f secondi" , time_spent);

}