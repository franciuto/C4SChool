#include <stdio.h> // Printf, Scanf
#include <stdlib.h> // Malloc, Calloc, Free
#include <stdbool.h> // Bool
#include <time.h> // Clock
#include <math.h> // sqrt

double smart_method(bool *eratostene, unsigned long long max);
double classic_method(bool *classic, unsigned long long max);

int main()
{
    unsigned long long max, i, eratostene_found = 0, classic_found = 0; // Inizializzato a 0
    double time_elapsed;    
    
    // User input3
    printf("Quanti numeri primi vuoi calcolare: ");
    scanf("%llu", &max);
    printf("\n");
    
    // Dynamic memory allocation to store bool values
    bool *eratostene = (bool *) malloc((max + 1) * sizeof(bool));
    bool *classic_method_mem = (bool*) malloc((max + 1) * sizeof(bool));
    
    // Check for allocation
    if (!eratostene || !classic_method_mem)
    {
        printf("Errore allocazione di memoria");
        return 1;
    }
    
    // Initialize values as true
    for (i = 0; i <= max; i++)
    {
        eratostene[i] = true;
        classic_method_mem[i] = true;
    }
    
    // Apply the smart method
    printf("------- ERASTOTENE -------\n");
    printf("Tempo impiegato da erastotene: %f\n", smart_method(eratostene, max));
    
    // Count prime number found by erastotene
    for (i = 2; i <= max; i++)
    {
        if (eratostene[i])
        {
            eratostene_found++;
        }
    }
    printf("Numeri primi trovati da eratostene: %llu\n\n", eratostene_found);
    
    // Apply the other method
    printf("------- METODO CLASSICO -------\n");
    printf("Tempo impiegato nel metodo classico %f\n" , classic_method(classic_method_mem, max));

    // Count prime number found by the classic method
    for (i = 2; i <= max; i++){
        if (classic_method_mem[i]) {
            classic_found++;
        }
    }
    printf("Numeri primi trovati con il metodo classico: %llu", classic_found);
    // Free the mem
    free(eratostene);
    free(classic_method_mem);
    return 0;
}

double smart_method(bool *eratostene, unsigned long long max)
{
    // Var declaration
    unsigned long long i, j;
    clock_t start = clock();
    
    // 0 and 1 aren't prime numbers
    eratostene[0] = false;
    eratostene[1] = false;
    
    // Apply the eratostene method
    for (i = 2; i * i <= max; i++)
    {
        if (eratostene[i])
        {
            // Indicate non primes numbers
            for (j = i * i; j <= max; j += i)
            {
                eratostene[j] = false;
            }
        }
    }
    clock_t end = clock();
    double era_time = (double)(end - start) / CLOCKS_PER_SEC;
    return era_time;
}

double classic_method(bool *classic, unsigned long long max)
{
    clock_t start = clock();
    unsigned long long n;
    
    // Sets everything as non prime
    for (n = 0; n <= max; n++) {
        classic[n] = false;
    }
    
    // Test every num
    for (n = 2; n <= max; n++) {
        unsigned long long i;
        int is_prime = 1;
        
        if (n <= 1) is_prime = 0;            
        else if (n == 2 || n == 3) is_prime = 1;  
        else if (n % 2 == 0) is_prime = 0;    
        else {
            for (i = 3; i <= (unsigned long long)sqrt(n); i += 2) {
                if (n % i == 0) {
                    is_prime = 0;         
                    break;
                }
            }
        }
        
        classic[n] = is_prime;
    }
    
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    return time_spent;
}