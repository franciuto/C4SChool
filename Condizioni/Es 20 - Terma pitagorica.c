#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, num3;

    printf("Questo programma serve per identificare se un trio di numeri e' una terna pitagorica\nPer iniziare inserisci 3 numeri:\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);

    if (num1*num1 + num2*num2 == num3*num3 || num2*num2 + num3*num3 == num1*num1 || num1*num1 + num3*num3 == num2*num2)
    {
        printf("Il tuo trio costituisce una terna pitagorica.");
    }
    else
    {
        printf("Il tuo trio non costituisce una terna pitagorica");
    }

    return 0;

}