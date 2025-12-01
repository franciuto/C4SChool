#include <stdlib.h>

#ifndef IP_UTILS_H
#define IP_UTILS_H

typedef enum {
    IP_PRIVATE,
    IP_RESERVED,
    IP_PUBLIC,
} ip_type;

typedef struct {
    char ip_str[19];        // IP in formato stringa "xxx.xxx.xxx.xxx/xx"
    uint32_t ip_num;        // IP in formato numerico (per calcoli)

    char class;             // Classe: 'A', 'B', 'C', 'D', 'E'
    int cidr;

    ip_type type;
} ip_address_t;

uint32_t octets_to_uint32(int oct1, int oct2, int oct3, int oct4);

void uint32_to_ipstr(uint32_t ip_num, char *ip_str);
uint32_t ipstr_to_uint32(char *ip_str);

ip_address_t parse_ip (char *ip_str);
ip_address_t uint32_into_ip(uint32_t ip_num);

#endif