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

uint32_t calculate_pool_size_by_class(char class)
{
    switch (class)
    {
    case 'A':
        // 1.0.0.1 - 126.255.255.254
        // 126 reti × 256 × 256 × 254 host validi
        return 126UL * 256 * 256 * 254;
    
    case 'B':
        // 128.0.0.1 - 191.255.255.254
        // 64 × 256 reti × 256 × 254 host
        return 64UL * 256 * 256 * 254;
    
    case 'C':
        // 192.0.0.1 - 223.255.255.254
        // 32 × 256 × 256 reti × 254 host
        return 32UL * 256 * 256 * 254;
    
    case 'D':
        return 16UL * 256 * 256 * 256;
    
    case 'E':
        return 16UL * 256 * 256 * 256;
    
    default:
        return 32UL * 256 * 256 * 254; // Classe C di default
    }
}

// Genera un pool di tutti gli IP validi per la classe
ip_address_t *generate_pool_by_class(char class, uint32_t *pool_size)
{
    *pool_size = calculate_pool_size_by_class(class);
    
    ip_address_t *pool = (ip_address_t *)malloc(*pool_size * sizeof(ip_address_t));
    if (pool == NULL)
    {
        return NULL;
    }

    uint32_t index = 0;
    uint8_t oct1_start, oct1_end;
    
    // Determina il range del primo ottetto
    switch (class)
    {
    case 'A':
        oct1_start = 1;
        oct1_end = 126;
        break;
    case 'B':
        oct1_start = 128;
        oct1_end = 191;
        break;
    case 'C':
        oct1_start = 192;
        oct1_end = 223;
        break;
    case 'D':
        oct1_start = 224;
        oct1_end = 239;
        break;
    case 'E':
        oct1_start = 240;
        oct1_end = 255;
        break;
    default:
        oct1_start = 192;
        oct1_end = 223;
        break;
    }

    // Genera tutti gli IP validi
    for (uint16_t oct1 = oct1_start; oct1 <= oct1_end; oct1++)
    {
        for (uint16_t oct2 = 0; oct2 < 256; oct2++)
        {
            for (uint16_t oct3 = 0; oct3 < 256; oct3++)
            {
                // Per classi A, B, C evita .0 e .255
                uint16_t oct4_start = (class == 'D' || class == 'E') ? 0 : 1;
                uint16_t oct4_end = (class == 'D' || class == 'E') ? 255 : 254;
                
                for (uint16_t oct4 = oct4_start; oct4 <= oct4_end; oct4++)
                {
                    pool[index] = uint32_into_ip(octets_to_uint32(oct1, oct2, oct3, oct4));
                    index++;
                }
            }
        }
    }

    return pool;
}