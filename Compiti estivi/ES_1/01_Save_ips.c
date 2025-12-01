// Standard library inclusion
#include <stdio.h>  // printf(), scanf(), fgets(), fopen(), fclose()
#include <stdlib.h> // exit()
#include <string.h> // strcmp()

// File path stored as a constant so it can be changed
#define FILEPATH "ip_list.txt"

// Global counter for IP numbering
int ip_count = 1;

// --- Functions ---
void prompt(char *input_ip);
void check_file(FILE *file_descriptor);
void file_print();

int main()
{
    // Buffer to save ip inputs
    char input[16];

    // -- OPEN FILE --
    FILE *file_descriptor = fopen(FILEPATH, "w");
    // Check if file descriptor has been successfully returned from fopen
    check_file(file_descriptor);

    // Intro
    printf("- IPs saver by Francesco Fontanesi -\n");
    printf("All IPs are saved in \"%s\"\n", FILEPATH);
    printf("\nInsert IPs (type: \"fine\" to save and exit):\n");

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
        ip_count++;
    }

    return 0;
}

// --- Function Definitions ---

/*
Function: prompt
Description: This function prompts user to insert the ip address
Input: pointer to a static buffer to contain the user input (size 16 Bytes)
Output: Void because the result is stored in the static buffer given as input
*/
void prompt(char *input_ip)
{   
    printf("%d > ", ip_count);
    scanf("%15s", input_ip); // limit to 15 chars to avoid overflow
}

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

    char line[16]; // buffer for IP strings
    while (fgets(line, sizeof(line), file_descriptor) != NULL)
    {
        printf("%s", line);
    }

    fclose(file_descriptor);
}
