#include <stdio.h>

int main ()
{

    int n;
    int sum = 0;
    printf("Inserire un numero: ");
    scanf("%d", &n);
    while (n >= 0 )
    {
        sum = sum + n;
        n = n - 1;
    }
    printf("La somma dei numeri naturali fino al numero inserito e' %d" , sum);
    
    
}