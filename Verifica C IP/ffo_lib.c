// Francesco Fontanesi -- FFO_LIB functions implementation
#include "ffo_lib.h"
#include <stdio.h>
#include <stdlib.h>

int contaVocali(const char *s)
{
    printf("%s", s);
    int count = 0; // Int variable to count the vowels
    while (*s != '\0')
    {
        char c = (char)*s;  // make a copy of s because is declared as const char ad so it's "read only"
        char lower = c | 0x20; // Mask with 0x20 that is equal to 0b00100000 in binary to turn everything to lowercase
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
        {
            count++;
        }
        s++;
    }
    return count;
}

char *getNetwork(const char *ip, const char *netmask)
{
    int ip_n[4];    // Array to hold the 4 octets of the ip
    int mask[4];    // Array to hold the 4 octets of the mask
    int network[4]; // Array to hold the final ip address
    char *result = calloc(16, 1);

    sscanf(ip, "%d.%d.%d.%d", &ip_n[0], &ip_n[1], &ip_n[2], &ip_n[3]);  // Get the ip octets
    sscanf(netmask, "%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]); // Get the mask octets

    for (int i = 0; i < 4; i++)
    {
        network[i] = ip_n[i] & mask[i]; // Mask octets calculation using bitwise AND
    }

    // Compose the final network address
    sprintf(result, "%d.%d.%d.%d", network[0], network[1], network[2], network[3]);
    return result;
}

uint32_t* generaTavolozzaRGB(int n) {
    uint32_t* colors = (uint32_t*)malloc(n * sizeof(uint32_t));
    // Generate random integers
    for (int i = 0; i < n; i++) {
        uint8_t r = rand() % 256;
        uint8_t g = rand() % 256;
        uint8_t b = rand() % 256;
        
        //  shift bitwise e OR per impacchettare r, g e b in un uint32_t: 0x00RRGGBB. Prima sposto nelle posizioni poi con l'or li combino
        colors[i] = (r << 16) | (g << 8) | b;
    }

    // Ritorno l'array con i valori rgb
    return colors;
}
