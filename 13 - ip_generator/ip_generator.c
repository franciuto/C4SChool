#include "ip_utils.h"
#include "ip_generator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ip_address_t *generate_random_ips(int ip_gen_n, char ip_gen_class, ip_address_t netid)
{

    if (ip_gen_class == '?' || ip_gen_class == '\0')
    {
        ip_gen_class = DEFAULT_IP_GEN_CLASS;
    }

    // Alloca array per gli IP da generare
    ip_address_t *ip_gen = (ip_address_t *)malloc(ip_gen_n * sizeof(ip_address_t));
    if (ip_gen == NULL)
    {
        return NULL;
    }

    // Decide quale metodo usare in base al numero di IP
    if (ip_gen_n < THRESHOLD_USE_POOL)
    {
        int is_duplicato;
        // METODO 1: Pochi IP -> Random con retry per evitare duplicati
        for (size_t i = 0; i < (size_t)ip_gen_n; i++)
        {
            do
            {
                is_duplicato = 0;
                generate_random_ip_by_class(&ip_gen[i], ip_gen_class);
                for (size_t j = 0; j < i; j++)
                {
                    if (ip_gen[i].ip_num == ip_gen[j].ip_num)
                    {
                        is_duplicato = 1;
                        break;
                    }
                }
            } while (is_duplicato);
        }
    }
    else
    {
        // METODO 2: Tanti IP -> Genera pool completo e shuffle
        // TODO: calcolare range IP disponibili per la classe
        // TODO: generare pool ordinato
        // TODO: shuffle del pool
    }

    return ip_gen;
}

// ip_address_t generate_by_shuffling()

void generate_random_ip_by_class(ip_address_t *ip, char class)
{
    ip->class = class;

    uint8_t oct1, oct2, oct3, oct4;

    switch (class)
    {
    case 'A':
        // Classe A: 1.0.0.0 - 126.255.255.255 (escludi 127.x.x.x - loopback)
        oct1 = 1 + rand() % 126;
        oct2 = rand() % 256;
        oct3 = rand() % 256;
        oct4 = 1 + rand() % 254; // Evita 0 e 255
        break;

    case 'B':
        // Classe B: 128.0.0.0 - 191.255.255.255
        oct1 = 128 + rand() % 64;
        oct2 = rand() % 256;
        oct3 = rand() % 256;
        oct4 = 1 + rand() % 254;
        break;

    case 'C':
        // Classe C: 192.0.0.0 - 223.255.255.255
        oct1 = 192 + rand() % 32;
        oct2 = rand() % 256;
        oct3 = rand() % 256;
        oct4 = 1 + rand() % 254;
        break;

    case 'D':
        // Classe D (Multicast): 224.0.0.0 - 239.255.255.255
        oct1 = 224 + rand() % 16;
        oct2 = rand() % 256;
        oct3 = rand() % 256;
        oct4 = rand() % 256;
        break;

    case 'E':
        // Classe E (Riservata): 240.0.0.0 - 255.255.255.255
        oct1 = 240 + rand() % 16;
        oct2 = rand() % 256;
        oct3 = rand() % 256;
        oct4 = rand() % 256;
        break;

    default:
        // Default: genera IP casuale classe C
        oct1 = 192 + rand() % 32;
        oct2 = rand() % 256;
        oct3 = rand() % 256;
        oct4 = 1 + rand() % 254;
        break;
    }

    *ip = uint32_into_ip(octets_to_uint32(oct1, oct2, oct3, oct4));
}

void set_ip_type(int oct1, int oct2, char class, ip_address_t *ip)
{
    if ((oct1 == 10) ||
        (oct1 == 172 && oct2 >= 16 && oct2 <= 31) ||
        (oct1 == 192 && oct2 == 168))
    {
        ip->type = IP_PRIVATE;
    }
    else if (oct1 == 127 || class == 'D' || class == 'E')
    {
        ip->type = IP_RESERVED;
    }
    else
    {
        ip->type = IP_PUBLIC;
    }
}

/*
void generate_random_ip_with_netid(ip_address_t *ip, char class, char *netid)
{
    int octets[4] = {};

    int cidr = 0;
    char netid_copy[32];
    strncpy(netid_copy, netid, sizeof(netid_copy) - 1);
    netid_copy[sizeof(netid_copy) - 1] = '\0';

    char *ip_part = strtok(netid_copy, "/");
    char *cidr_part = strtok(NULL, "/");

    if (cidr_part != NULL)
    {
        cidr = atoi(cidr_part);
    }

    if (ip_part != NULL)
    {
        sscanf(ip_part, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);
    }

    char *ip_str = 0;

    for (size_t i = 0; i < 4; i++)
    {
        if (octets[i] != 0)
        {
            sprintf(ip_str, "%d", &octets[i]);
        }
        else
        {
            // genera random octet e append to string
        }
    }
}
*/
