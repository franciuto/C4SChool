#include <stdio.h>
#define righe 2
#define colonne 3

int main()
{
    int i, j;
    int matrix[righe][colonne];

    // Fill the matrix
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            printf("Inserisci elemento %d , %d: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the matrix
    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < colonne; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
