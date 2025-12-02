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
        // METODO 1: Pochi IP => random con retry per univocità
        int is_duplicato;
        for (size_t i = 0; i < (size_t)ip_gen_n; i++)
        {
            do
            {
                is_duplicato = 0;
                
                // Genera IP in base a netid o classe
                if (netid.ip_num != 0)
                {
                    generate_random_ip_with_netid(&ip_gen[i], ip_gen_class, netid);
                }
                else
                {
                    generate_random_ip_by_class(&ip_gen[i], ip_gen_class);
                }
                
                // Controlla duplicati
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
        // METODO 2: Tanti IP -> Pool completo + shuffle
        // TODO: implementare anche il caso con netid
        
        uint32_t pool_size = 0;
        ip_address_t *pool = generate_pool_by_class(ip_gen_class, &pool_size);
        
        if (pool == NULL)
        {
            free(ip_gen);
            return NULL;
        }
        
        // Verifica che ci siano abbastanza IP disponibili
        if ((uint32_t)ip_gen_n > pool_size)
        {
            fprintf(stderr, "Errore: richiesti %d IP ma solo %u disponibili\n", 
                    ip_gen_n, pool_size);
            free(pool);
            free(ip_gen);
            return NULL;
        }
        
        // Shuffle del pool (Fisher-Yates)
        shuffle_pool(pool, pool_size);
        
        // Copia i primi ip_gen_n elementi
        memcpy(ip_gen, pool, ip_gen_n * sizeof(ip_address_t));
        
        free(pool);
    }

    return ip_gen;
}

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

void generate_random_ip_with_netid(ip_address_t *ip, char class, ip_address_t netid)
{
    ip->class = class;
    
    uint32_t mask = 0xFFFFFFFF << (32 - netid.cidr);
    uint32_t network = netid.ip_num & mask;
    uint32_t host_bits = 32 - netid.cidr;
    uint32_t max_hosts = (1UL << host_bits) - 2;
    
    uint32_t random_host = 1 + (rand() % max_hosts);
    uint32_t new_ip = network | random_host;
    
    *ip = uint32_into_ip(new_ip);
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
// fisher-yates algorithm (chatgpt says it's the best one)
void shuffle_pool(ip_address_t *pool, uint32_t pool_size)
{
    for (uint32_t i = pool_size - 1; i > 0; i--)
    {
        // Genera indice casuale tra 0 e i
        uint32_t j = rand() % (i + 1);
        
        // Swap pool[i] con pool[j]
        ip_address_t temp = pool[i];
        pool[i] = pool[j];
        pool[j] = temp;
    }
}