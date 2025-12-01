// Francesco Fontanesi -- FFO_LIB functions calls
#include <stdio.h>  // printf(), scanf()
#include <stdlib.h> // malloc()
#include "ffo_lib.h"

int main(/*int argc , char *argv[]*/)
{
    // *** Declarations ***
    int option; // Variable to contain the user choice

    // *** Print the menu ***
    printf("FFO_LIB - Call menu\n1) call contaVocali\n2) call getNetwork\n3) call generaTavolozzaRGB\nChoose an option: ");
    scanf("%d", &option);
    getchar();
    switch (option)
    {
    case 1:
        // -- Dynamic memory allocation --
        char *str = malloc(1000 * 1); // 1000 * 1 because 1 is equal to sizeof(char)
        printf("Insert the string: ");
        fgets(str, 1000, stdin); // %999s to avoid a buffer overflow because the buffer is 1000 so i can insert 999 chars + 1 terminator in this case 999 is the limit of chars to prompt for scanf
        printf("There are %d vowels", contaVocali(str));
        free(str);
        break;

    case 2:
        char ip_string[16] = {0};
        char netmask_string[16] = {0};
        printf("Insert ip address: ");
        scanf("%16s", ip_string);
        printf("Insert network mask: ");
        scanf("%16s", netmask_string);
        printf("The network part is :%s", getNetwork(ip_string, netmask_string));
        break;

    case 3:
        int terns;
        printf("Insert number of RGB terns: ");
        scanf("%d", &terns);
        uint32_t *palette = generaTavolozzaRGB(terns); 
        printf("Generated RGB colors:\n");
        for (size_t i = 0; i < terns; i++)
        {
            printf("%x" , palette[i]);
        }
        free(palette);
        break;

    default:
        printf("Option not valid");
        break;
    }

    return 0;
}