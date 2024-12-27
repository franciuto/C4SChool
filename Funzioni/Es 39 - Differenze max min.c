#include <stdio.h>

int diffmax(int n1, int n2, int n3) {
    int max, min;          // Declarations
    if (n1 > n2 && n1 > n3)         // Check first number
    {   
        // IF BIGGER
        max = n1;       // Set it in max
        if (n2 < n3)    // Compare the others
        {
            min = n2;   // If n2 is the smaller set it in min
        } else {min = n3;}  // Else set min to n3
        
    }else if (n2 > n3 && n2 > n1)
    {
        max = n2;
        if (n1 < n3)
        {
            min = n1;
        }else{min = n3;}
        
    } else
    {
        max = n3;
        if (n1 < n2)
        {
            min = n1;
        }else{min = n2;}
        
    }
    return max - min;       // Return the difference
}

int main() {
    int n1, n2, n3;         // Declarations
    printf("Inserire 3 numeri interi: "); 
    scanf("%d %d %d", &n1, &n2, &n3);         // Input Requests
    printf("La differenza tra il maggiore e il minore numeri è 3: %d" , diffmax(n1,n2,n3));   // Stampo chimanado la funzione
}
