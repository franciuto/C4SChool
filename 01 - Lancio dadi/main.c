// Esempio applicativo di LUT (Look Up Table)

// Lancio del dado che conta e stampa le frequenze ottenute (dado a 6 facce)
#include <time.h>
#include <stdio.h>		// Printf e scanf
#include <stdlib.h>		// Rand e srand
#define faces 6	

int main () {
	srand(time(NULL));

	// Var declaration
	int launches, random, i;
	int result[faces] = {0};

	// Ask for number of launches
	printf("Inserisci numero di lanci: ");
	scanf("%d" , &launches);

	// Generate random face
	for (int i = 0; i < launches; ++i)
	{
		random = (rand() % 6);
		result[random]++;
	}

	for (int i = 0; i < faces; ++i)
	{
		printf("Faccia %d: %d\n", i, result[i]);
	}
}