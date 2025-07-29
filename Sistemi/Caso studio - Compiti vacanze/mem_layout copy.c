#include <stdio.h> 
#include <stdlib.h>

char msg1[] = "Ciao Mondo!"; // 12 bytes, msg 1 = puntatore a primo char di "Ciao Mondo!" mentre la stringa in se è salvata in .data

char msg2[10]; // Variabile globale non inizializzata quindi viene salata in .bss

// Variabile globale inizializzata → segmento dati (.data)
int g_init = 10;

// Variabile globale non inizializzata → segmento BSS
int g_uninit;

// Variabile globale const → .rodata
const int g_const = 42;

// Funzione foo, riceve i parametri n e c come passati in stack e ritorna sempre tramite stack un puntatore a intero di grandezza 8 byte (64 bit)
int* foo(int n, char c){
    static int sta = 0;
    // sta è una variabile locale della funzione quindi sarebbe salvata in stack ma in realtà è static inizializzata quindi va in .data

    sta += n*c;
    return &sta; // come precedentemente analizzato vediamo come il programma ritorna l'indirizzo di memoria in cui si trova l'intero (sta)
}


int main() {
    // Variabile locale → stack
    int local = 5;

    // variabile locale viene salvata in stack
    const int local_const = 7;

    // Variabile dinamica → heap
    int* dynamic = malloc(sizeof(int));
    *dynamic = 20;

    char* pstr = "Ciao Mondo!";  // pstr ossia puntatore a char viene salvato nello stack, mentre la stringa alla quale punta si salva in rodata
    char msg3[] = "Ciao Mondo!"; // stessa cosa, msg3 è un puntatore al primo char dell'array msg3 che contiene la stringa "Ciao Mondo!" che viene però salvata in .rodata in quanto literal ma poi copiata nello stack in quanto array locale e non puntatore 
    // Stampa indirizzi
    // Non mi è chiaro a cosa serva il casting a void per ogni indirizzo
    // a cosa serve in questo caso la funzione foo
    // spiegami in generale cosa succede
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
