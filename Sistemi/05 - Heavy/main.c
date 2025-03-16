#include <stdio.h>  // printf
#include <stdlib.h> // srand, rand
#include <time.h>   // time

#define N 10000      // Dimensioni delle matrici (N x N)
#define MAX_RAND 5000  // Valore massimo per i numeri casuali

int a_matrix[N][N];
int b_matrix[N][N];
int res[N][N];

int main() {
    srand(time(NULL));
    int i, r, k;

    // Inizializza le matrici A e B con valori casuali
    for (i = 0; i < N; i++) {
        for (r = 0; r < N; r++) {
            a_matrix[i][r] = (rand() % MAX_RAND) + 1;
            b_matrix[i][r] = (rand() % MAX_RAND) + 1;
        }
    }

    // Moltiplicazione delle matrici A e B
    for (i = 0; i < N; i++) {
        for (r = 0; r < N; r++) {
            res[i][r] = 0;  // Inizializza l'elemento res[i][r] a 0
            for (k = 0; k < N; k++) {
                res[i][r] += a_matrix[i][k] * b_matrix[k][r];
            }
        }
    }
    return 0;
}