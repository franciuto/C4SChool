#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define arrayLenght 30

// Funzione che ritorna void perchè passando come parametro un'array e modificandolo le modifiche vengono riportate sull'array passato
void generaArray(int array_to_fill[], int lenght)
{
    int i;
    for (i = 0; i < lenght; i++)
    {
        array_to_fill[i] = (rand() % 50) + 1;
    }
}

void invertiArray(int array_to_reverse[], int lenght)
{
    int counter = 0, buffer;
    lenght--; // Parto da 29 per rientrare nell'array
    while (counter < lenght)
    {                                                         // Itero finchè non si arriva alla metà con l'inversione altrimenti si sovrascrive
        buffer = array_to_reverse[lenght];                    // Salvo il valore dell'ultimo elemento in una variabile
        array_to_reverse[lenght] = array_to_reverse[counter]; // Metto il primo al posto dell'ultimo
        array_to_reverse[counter] = buffer;                   // Metto l'ultimo al posto del primo
        lenght--;
        counter++;
    }
}

int contaPari(int array_to_count[], int lenght) {
    int i, pari = 0;
    for (i = 0; i < lenght; i++)
    {
        if (array_to_count[i] % 2 == 0)
        {
            pari++;
        }
    }
    return pari;
}

int main()
{
    srand(time(NULL));
    // Dichiarazioni
    int array1[arrayLenght];
    int i;

    // Chiamo la funzione per riempire l'array con numeri casuali
    generaArray(array1, arrayLenght);

    printf("Array Generato:\n");
    for (i = 0; i < arrayLenght; i++)
    {
        printf("%d ", array1[i]);
    }
    printf("\n");

    // Chiamo la funzione per invertire l'array
    invertiArray(array1, arrayLenght);
    printf("Array Invertito:\n");
    for (i = 0; i < arrayLenght; i++)
    {
        printf("%d ", array1[i]);
    }
    printf("\n");
    
    // Chiamo la funzione per contare i numeri pari
    printf("Sono presenti %d numeri pari", contaPari(array1, arrayLenght));
}
