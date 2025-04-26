#include <stdio.h>
#include <stdlib.h> // Malloc, sizeof
#include "my_net_lib.h"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

int main()
{
    char *ip_addr;
    switch (menu())
    {
    case 1:
        ip_addr = scanfIP();
        char *bin = ipToBinary(ip_addr);
        printf(YELLOW "Binary format: " RESET "%s", bin);
        free(bin);
        free(ip_addr);
    case 2:
        ip_addr = scanfIP();
        if (isValidIPv4(ip_addr) == 1)
        {
            printf(GREEN "IP is Valid" RESET);
        }
        else
        {
            printf(RED "IP is not valid" RESET);
        }
    case 3:
        int CIDR;
        ip_addr = scanfIP();
        printf(BLUE "Insert CIDR: " RESET);
        scanf("%d" , &CIDR);
        calculateNetworkAddress(ip_addr, CIDR);
    default:
        break;
    };
    return 1;
}
