#include <stdio.h>

// I use a function that returns a float to handle the calculation
float calculate(float n1, char operation, float n2)
{
    // With a switch case i can do the calculation based on the operation
    switch (operation)
    {
    case '+':
        return n1 + n2;
        break;
    case '-':
        return n1 - n2;
        break;
    case '*':
        return n1 * n2;
        break;
    case '/':
        // Check if the division is valid
        if (n2 == 0)
        {
            printf("ERRORE: Divisione per zero");
            return 0.0;
        }
        return n1 / n2;
        break;
    default:
        return 0.0; // If the operation is not valid, return 0.0 (Not a number)
        break;
    }
}

int main()
{
    float n1, n2, result;
    char operation;
    // Welcome and input
    printf("Welcome in Simple Calculator\n\n");
    printf("Inserisci operazione: ");
    scanf("%f %c %f", &n1, &operation, &n2);
    result = calculate(n1, operation, n2);

    // If the result is a number i print it
    if (result != 0.0)
    {
        printf("= %.2f", result);
    }
    else    // I print that the operation is invalid
    {
        printf("Operazione non valida");
    }
}
