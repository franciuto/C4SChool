#include <stdio.h>  // printf(), fgets(), fopen(), fclose()
#include <string.h> // strcmp(), strcspn()
#include <stdlib.h> // exit()

// File path stored as a constant so it can be changed hard coded
#define FILEPATH "arp_table.txt"

// --- Functions ---
void check_file(FILE *file_descriptor);
void prompt(char *input_ip_mac);
void file_print();

int main()
{
    // Static 34 buffer to save ip-mac couple
    char input[34];

    // - OPEN FILE -
    FILE *file_descriptor = fopen(FILEPATH, "a");
    // Check if the file descriptor has been successfully returned by fopen()
    check_file(file_descriptor);

    // Intro
    printf("- ARP Table simulator by Francesco Fontanesi -\n");
    printf("All IPs and MAC couples are saved in \"%s\"\n", FILEPATH);
    printf("\nInsert IPs-MAC Couples (type: \"fine\" to save and exit):\n");

    while (1)
    {
        prompt(input);
        if (strcmp(input, "fine") == 0)
        {
            fclose(file_descriptor);
            file_print();
            break;
        }
        fprintf(file_descriptor, "%s\n", input);
    }

    return 0;
}

// --- Function Definitions ---

/*
Function: check_file
Description: This function checks if the file descriptor passed through input is valid by comparing it with NULL
Input: FILE Pointer (file descriptor)
Output: Void, if the file descriptor is not valid, the function prints an error and exits with error code 1 the program
*/
void check_file(FILE *file_descriptor)
{
    if (file_descriptor == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
}

/*
Function: prompt
Description: This function prompts user to insert the ip address
Input: pointer to a static buffer to contain the user input (size 34 Bytes)
Output: Void because the result is stored in the static buffer given as input
*/
void prompt(char *input_ip_mac)
{
    printf("\n> ");
    if (fgets(input_ip_mac, 34, stdin) != NULL)
    {
        // Remove trailing newline, if present
        input_ip_mac[strcspn(input_ip_mac, "\n")] = '\0';
    }
}

/*
Function: file_print
Description: This function prints the content of the file (filepath indicated in FILEPATH constant)
Input: Void
Output: Void, the function just prints the content of the file
*/
void file_print()
{
    FILE *file_descriptor = fopen(FILEPATH, "r");
    check_file(file_descriptor);

    printf("\nContent of \"%s\":\n", FILEPATH);

    char line[34]; // 34 because IP+MAC couple fits within this buffer
    while (fgets(line, sizeof(line), file_descriptor) != NULL)
    {
        printf("%s", line);
    }

    fclose(file_descriptor);
}
