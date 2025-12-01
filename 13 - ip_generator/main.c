#include "ip_generator.h"
#include "ip_utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  int ip_gen_n = 0;
  char ip_gen_class = '?';
  char *ip_gen_netid = NULL;

  if (argc > 1)
  { // thinking about using a -f arg to open a file with already generated IPs
    for (size_t i = 1; i < argc; i++)
    {
      if (argv[i][0] == '-') // se è un trattino allora gaso
      {
        switch (argv[i][1])
        {
        case 'n':
          ip_gen_n = atoi(argv[++i]); // pre incremento, passo arg successivo
          break;
        case 'c':
          ip_gen_class = *argv[++i];
          break;
        case 'i':
          ip_gen_netid = argv[++i];  // Punta direttamente all'argomento
          break;
        default:
          break;
        }
      }
    }
  }

  // se nn valido imposto a 1
  if (ip_gen_n <= 0) {
    ip_gen_n = 1;
  }
  
  ip_address_t *ips;
  ips = generate_random_ips(ip_gen_n, ip_gen_class, parse_ip(ip_gen_netid));

  if (ips) {
    for (size_t i = 0; i < (size_t)ip_gen_n; i++) {
      const char *type_str = (ips[i].type == IP_PRIVATE) ? "PRIVATE" :
                              (ips[i].type == IP_RESERVED) ? "RESERVED" : "PUBLIC";
      printf("IP %zu: %s - Classe: %c - Tipo: %s\n",
             i + 1,
             ips[i].ip_str,
             ips[i].class,
             type_str);
    }
    free(ips);
  }
}
