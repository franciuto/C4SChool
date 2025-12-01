#include "ip_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ip_address_t parse_ip(char *ip_str)
{
    ip_address_t parsed_ip = {0};
    if (!ip_str) return parsed_ip;
    
    // Copia in buffer locale per rimuovere CIDR prima del parsing
    char temp_str[32];
    strncpy(temp_str, ip_str, sizeof(temp_str) - 1);
    temp_str[sizeof(temp_str) - 1] = '\0';
    
    // Gestisci CIDR se presente
    char *slash = strchr(temp_str, '/');
    if (slash != NULL) {
        parsed_ip.cidr = atoi(slash + 1);
        *slash = '\0';  // Rimuove /XX dalla stringa
    }
    
    // Copia solo l'IP senza CIDR nel risultato
    strncpy(parsed_ip.ip_str, temp_str, sizeof(parsed_ip.ip_str) - 1);
    parsed_ip.ip_str[sizeof(parsed_ip.ip_str) - 1] = '\0';
    
    // Converti IP pulito in uint32
    parsed_ip.ip_num = ipstr_to_uint32(temp_str);
    
    int first_octet = (parsed_ip.ip_num >> 24) & 0xFF;
    if (first_octet >= 1 && first_octet <= 126) {
        parsed_ip.class = 'A';
    } else if (first_octet >= 128 && first_octet <= 191) {
        parsed_ip.class = 'B';
    } else if (first_octet >= 192 && first_octet <= 223) {
        parsed_ip.class = 'C';
    } else if (first_octet >= 224 && first_octet <= 239) {
        parsed_ip.class = 'D';
    } else if (first_octet >= 240 && first_octet <= 255) {
        parsed_ip.class = 'E';
    } else {
        parsed_ip.class = '?';
    }


    return parsed_ip;
}

uint32_t octets_to_uint32(int oct1, int oct2, int oct3, int oct4)
{
    return ((uint32_t)oct1 << 24) | ((uint32_t)oct2 << 16) |
           ((uint32_t)oct3 << 8) | (uint32_t)oct4;
}

void uint32_to_ipstr(uint32_t ip_num, char *ip_str)
{
    sprintf(ip_str, "%d.%d.%d.%d",
            (ip_num >> 24) & 0xFF,
            (ip_num >> 16) & 0xFF,
            (ip_num >> 8) & 0xFF,
            ip_num & 0xFF);
}

uint32_t ipstr_to_uint32(char *ip_str)
{
    int oct1, oct2, oct3, oct4;
    if (sscanf(ip_str, "%d.%d.%d.%d", &oct1, &oct2, &oct3, &oct4) != 4) {
        return 0;
    }
    return octets_to_uint32(oct1, oct2, oct3, oct4);
}

ip_address_t uint32_into_ip(uint32_t ip_num)
{
    ip_address_t parsed_ip = {0};
    
    // Converti uint32 in stringa IP
    uint32_to_ipstr(ip_num, parsed_ip.ip_str);
    
    // Salva il valore numerico
    parsed_ip.ip_num = ip_num;
    
    // Determina la classe dall'ottetto più significativo
    int first_octet = (ip_num >> 24) & 0xFF;
    if (first_octet >= 1 && first_octet <= 126) {
        parsed_ip.class = 'A';
    } else if (first_octet >= 128 && first_octet <= 191) {
        parsed_ip.class = 'B';
    } else if (first_octet >= 192 && first_octet <= 223) {
        parsed_ip.class = 'C';
    } else if (first_octet >= 224 && first_octet <= 239) {
        parsed_ip.class = 'D';
    } else if (first_octet >= 240 && first_octet <= 255) {
        parsed_ip.class = 'E';
    } else {
        parsed_ip.class = '?';
    }
    
    parsed_ip.cidr = 0;
    
    return parsed_ip;
}
