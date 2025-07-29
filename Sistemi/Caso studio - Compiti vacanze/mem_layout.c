#include <stdio.h> 
#include <stdlib.h>

char msg1[] = "Ciao Mondo!"; //12

char msg2[10];

// Variabile globale inizializzata → segmento dati (.data)
int g_init = 10;

// Variabile globale non inizializzata → segmento BSS
int g_uninit;

// Variabile globale const → .rodata o .data (a seconda del compilatore)
const int g_const = 42;


int* foo(int n, char c){
    static int sta = 0;

    sta += n*c;
    return &sta;
}


int main() {
    // Variabile locale → stack
    int local = 5;

    // Variabile locale const → stack
    const int local_const = 7;

    // Variabile dinamica → heap
    int* dynamic = malloc(sizeof(int));
    *dynamic = 20;

    char* pstr = "Ciao Mondo!";
    char msg3[] = "Ciao Mondo!";
    // Stampa indirizzi
    printf("Indirizzo di msg1         (string)            : %p\n", (void*)msg1);
    printf("Indirizzo di msg2         (string)            : %p\n", (void*)msg2);
    printf("Indirizzo di msg3         (string)            : %p\n", (void*)msg3);
    printf("Indirizzo puntato da pstr (pString      )     : %p\n", (void*)pstr);

    printf("Indirizzo di msg1         (      )            : %p\n", (void*)&msg1);
    printf("Indirizzo di msg2         (      )            : %p\n", (void*)&msg2);
    printf("Indirizzo di msg3         (      )            : %p\n", (void*)&msg3);
    printf("Indirizzo di pstr         (pString      )     : %p\n", (void*)&pstr);

    printf("Indirizzo di foo()        (code/text)         : %p\n", (void*)foo);
    printf("Indirizzo di sta          (static)            : %p\n", (void*)foo(10,'a'));

    printf("Indirizzo di g_init       (global init)       : %p\n", (void*)&g_init);
    printf("Indirizzo di g_uninit     (global uninit/BSS) : %p\n", (void*)&g_uninit);
    printf("Indirizzo di g_const      (global const)      : %p\n", (void*)&g_const);
    printf("Indirizzo di local        (stack)             : %p\n", (void*)&local);
    printf("Indirizzo di local_const  (stack const)       : %p\n", (void*)&local_const);
    printf("Indirizzo di dynamic      (heap)              : %p\n", (void*)dynamic);

    free(dynamic);
    return 0;
}
