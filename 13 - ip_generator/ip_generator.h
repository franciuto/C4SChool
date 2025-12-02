#include <stdio.h>
#include "ip_utils.h"

#define DEFAULT_IP_GEN_CLASS 'C'
#define THRESHOLD_USE_POOL 10000


#ifndef IP_GENERATOR_H
#define IP_GENERATOR_H

ip_address_t *generate_random_ips(int ip_gen_n, char ip_gen_class, ip_address_t netid);

void generate_random_ip_by_class(ip_address_t *ip, char class);

void generate_random_ip_with_netid(ip_address_t *ip, char class, ip_address_t netid);

char *find_ip_type(int oct1, int oct2, char class);

// Shuffle usando Fisher-Yates algorithm
void shuffle_pool(ip_address_t *pool, uint32_t pool_size);


#endif