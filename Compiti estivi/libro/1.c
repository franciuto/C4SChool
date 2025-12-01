#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ASCII_MARKER 'a'
#define NUM_MARKER 'n'

int main () {
    srand(time(NULL));

    char string[40];
    printf("Livello 7, digitare una stringa: ");
    scanf("%s", string);

    int random_number = rand();
    printf("Livello 7, numero casuale: %d\n", random_number);

    int i = 0;
    char pkt1_data[160] = "";
    char buffer[20];

    while (string[i] != '\0')
    {
        int ascii = string[i];
        sprintf(buffer, "%xh ", ascii);
        strcat(pkt1_data, buffer);
        i++;
    }

    printf("Pkt1: %xh %s\n", ASCII_MARKER, pkt1_data);
    printf("Pkt2: %xh %x\n", NUM_MARKER, random_number);

    return 0;
}
