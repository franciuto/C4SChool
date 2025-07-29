// Standard library inclusion
#include <stdio.h> // printf(), scanf(), fgets(), fopen(), fclose()
#include <stdlib.h> // exit()
#include <string.h> // strcmp()

// File path stored as a constant so it can be changed
#define FILEPATH "ip_list.txt"

int ip_conunt = 1;

/*
Function: prompt
Description: This function prompts user to insert the ip adress
Input: pointer to a static buffer to contain the user input (size 16 Bytes)
Output: Void because the result is stored in the static buffer given as input
*/
void prompt(char *input_ip)
{   
    printf("%d > ", ip_conunt);
    scanf("%16s", input_ip);
}

/*
Function: check_file
Description: This function checks if the file descriptor passed trought input is valid by comparing it with NULL
Input: FILE Pointer (file descriptor)
Output: Void, if the file descriptor is not valid, the function prints an error and exits with error code 1 the program
*/
void check_file(FILE *file_descriptor)
{
    if (file_descriptor == NULL)
    {
        printf("Error opening file");
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
    printf("Content of \"ip_list.txt\"\n");
    char line[15]; // 15 because an ip is max 15 char long
    // Using this approach because "getline" is a POSIX only function
    while (fgets(line, sizeof(line), file_descriptor) != NULL)
    {
        printf("%s", line);
    }
}

int main()
{
    // Buffer to save ip inputs
    char input[16];

    // -- OPEN FILE --
    FILE *file_descriptor = fopen(FILEPATH, "w");
    // Check if file descriptor has been successfully returned from fopen
    check_file(file_descriptor);

    // Intro
    printf("- IPs saver by Francesco Fontanesi -");
    printf("\nAll IPs are saved in \"ip_list.txt\"");
    printf("\n\nInsert IPs (type: \"fine\" to save and exit):\n");

    while (1)
    {
        prompt(input);
        if (strcmp(input, "fine") == 0)
        {
            fclose(file_descriptor);
            file_print();
            break;
        }
        fprintf(file_descriptor, "%s", input);
        ip_conunt++;
    }
}