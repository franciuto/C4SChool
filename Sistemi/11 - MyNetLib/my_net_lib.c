#include "my_net_lib.h"
#include <stdint.h> //unit8_t
#include <stdlib.h> // system
#include <string.h> // strtok
#include <stdio.h>  // printf, scanf, sprintf

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

void clear_screen()
{
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Linux/macOS
#endif
}

int menu()
{
    int choice;
    clear_screen();
    printf("~~ My Net Lib - Francesco Fontanesi ~~");
    printf("\n\n-- IP SECTION --\n1. Binary converter\n2. Validator\n3. Network finder\n\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 3)
    {
        printf(RED "Invalid option!" RESET "\nChoose again (1/2): ");
        scanf("%d", &choice);
    }
    return choice;
}

char *scanfIP()
{
    int a, b, c, d;                               // Chars to store the octets
    char *ip_scanned = malloc(20 * sizeof(char)); // Char string to hold the ip
    printf(BLUE "Insert IP address: " RESET);
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    sprintf(ip_scanned, "%d.%d.%d.%d", a, b, c, d); // Save in the buffer the output of printf
    return ip_scanned;
}

char *ipToBinary(char *ip)
{
    int octets[4]; // Array to contain all the 4 octets
    char *octet;   // Temp char to hold the current octet
    char *binary = malloc(4 * 8 + 3 + 1);
    int i = 0; // Simple counter

    octet = strtok(ip, "."); // Extract the string
    while (octet != NULL && i < 4)
    {
        octets[i] = atoi(octet); // Convert the extracted octet to an integer
        i++;
        octet = strtok(NULL, "."); // Proceed with the next octet
    }

    for (i = 0; i < 4; i++)
    {
        int val = octets[i]; // Save into var the current int octet
        char temp[8];        // Array of 8 chars to store the octets in binary

        for (int j = 7; j >= 0; j--)
        {
            temp[j] = (val % 2) + '0'; // Converts to binary
            val = val / 2;
        }

        strcat(binary, temp); // Concat to the binary string

        // Add the space
        if (i < 3)
        {
            strcat(binary, " ");
        }
    }
    return binary;
}

int isValidIPv4(char *ip)
{
    int octets[4]; // Array to contain all the 4 octets
    char *octet;   // Temp char to hold the current octet
    int i = 0;
    int dot_counter = 0; // Count dots

    // Check if the ip is in the correct format counting '.'
    while (*ip)
    {
        if (*ip == '.')
        {
            dot_counter++;
        }
        ip++;
    }

    if (dot_counter != 3)
    {
        return 0;
    }

    // Extract octets
    octet = strtok(ip, "."); // Extract the string
    while (octet != NULL && i < 4)
    {
        octets[i] = atoi(octet); // Convert the extracted octet to an integer
        i++;
        octet = strtok(NULL, "."); // Proceed with the next octet
    }

    if (i != 4) // If there are not enough octets is not valid
    {
        return 0;
    }

    for (i = 0; i < 4; i++)
    {
        if (octets[i] > 255 || octets[i] < 0) // If a number is bigger than 255 or smaller than 0 the ip is not valid
        {
            return 0;
        }
    }
    return 1;
}

void calculateNetworkAddress(char *ip, int cidr)
{
    char *octet;
    uint32_t ip_number = 0;
    int i = 0;

    // Convert the ip in a 32 bit integer
    octet = strtok(ip, ".");
    while (octet != NULL && i < 4)
    {
        ip_number = (ip_number << 8) | (uint8_t)atoi(octet);
        i++;
        octet = strtok(NULL, ".");
    }

    // Calculate the subnet mask from CIDR
    uint32_t mask = 0;
    if (cidr > 0)
    {
        mask = ~((1u << (32 - cidr)) - 1);  
    }

    // Calculate the network address using a bitwise AND
    uint32_t network = ip_number & mask;

    // Print the ip
    printf(GREEN "Network address: " RESET "%d.%d.%d.%d/%d\n",
           (network >> 24) & 0xFF,
           (network >> 16) & 0xFF,
           (network >> 8) & 0xFF,
           network & 0xFF,
           cidr);
}