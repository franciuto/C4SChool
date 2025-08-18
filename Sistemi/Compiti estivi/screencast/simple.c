#include <stdio.h>
#include <stdlib.h>

// Materie: Italiano, Storia, Geografia, Scienze, Inglese

int main() {
    int n_materie = 0;
    printf("N. Materie: ");
    scanf("%d", &n_materie);

    char **materie = calloc(n_materie, sizeof(char*));
    int *voti_per_materia = calloc(n_materie, sizeof(int));
    float **voti = calloc(n_materie, sizeof(float*));

    for (int i = 0; i < n_materie; i++)
    {
        materie[i] = calloc(20, sizeof(char));
        printf("inserisci %d materia: ", i+1);
        scanf("%19s", materie[i]);
    }
    for (int i = 0; i < n_materie; i++)
    {
        int n_voti_materia = 1;
        printf("Quanti voti vuoi inserire in %s: ", materie[i]);
        scanf("%d", &n_voti_materia);
        voti[i] = calloc(n_voti_materia, sizeof(float));
        voti_per_materia[i] = n_voti_materia;

        for (int j = 0; j < n_voti_materia; j++)
        {
            printf("Inserisci voto %d: ", j + 1);
            scanf("%f", &voti[i][j]);
        }
        
    }
    
    printf("Materie: %d", n_materie);
    for (int i = 0; i < n_materie; i++)
    {
        printf("\n%s", materie[i]);
        for (int j = 0; j < voti_per_materia[i]; j++)
        {
            printf("\n%.2f", voti[i][j]);
        }
        
    }
    
}
