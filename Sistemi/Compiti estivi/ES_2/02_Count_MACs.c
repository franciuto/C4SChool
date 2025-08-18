#include <stdio.h>  // scanf(), printf(), fopen(), fclose(), fgets()
#include <stdlib.h> // exit()

// File path stored as a constant so it can be changed hard coded
#define FILEPATH "mac_list.txt"

// --- Functions ---
void check_file(FILE *file_descriptor);

int main() 
{
    // - OPEN FILE -
    FILE *file_descriptor = fopen(FILEPATH, "r");
    // Check if the file descriptor has been successfully returned by fopen()
    check_file(file_descriptor);

    int mac_found = 0;
    char line[19]; // 17 chars for MAC + '\n' + '\0'

    while (fgets(line, sizeof(line), file_descriptor) != NULL)
    {
        printf("%s", line);
        mac_found++;
    }

    printf("\n%d MAC Addresses found\n", mac_found);
    fclose(file_descriptor);

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
