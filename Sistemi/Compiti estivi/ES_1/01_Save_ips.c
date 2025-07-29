// Standard library inclusion
#include <stdio.h> // printf, fgets
#include <stdlib.h>
#include <string.h>

#define FILEPATH "ip_list.txt"

int ip_conunt = 1;

void prompt(char *input_ip)
{
    printf("%d > ", ip_conunt);
    fgets(input_ip, 16, stdin);
}

void check_file(FILE *file_descriptor)
{
    if (file_descriptor == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
}

void file_print()
{
    FILE *file_descriptor = fopen(FILEPATH, "r");
    check_file(file_descriptor);
    printf("Content of \"ip_list.txt\"\n");
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, file_descriptor) != -1)
    {
        printf("%s", line);
    }
}

int main()
{
    // Buffer to save ip inputs
    char *input = malloc(16 * sizeof(char)); // FIX USING STATIC MEMORY

    // -- OPEN FILE --
    FILE *file_descriptor = fopen(FILEPATH, "a");
    // Check if file descriptor has been successfully returned
    check_file(file_descriptor);

    printf("- IPs saver by Francesco Fontanesi -");
    printf("\nAll IPs are saved in \"ip_list.txt\"");
    printf("\n\nInsert IPs (type: \"fine\" to save and exit):\n");
    while (1)
    {
        prompt(input);
        if (strcmp(input, "fine") == 10)
        {
            fclose(file_descriptor);
            free(input);
            file_print();
            break;
        }
        fprintf(file_descriptor, "%s", input);
        ip_conunt++;
    }
}