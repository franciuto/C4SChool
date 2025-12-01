// Francesco Fontanesi

// STANDARD HEADERS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// VAR INITIALIZATION
/* > MAX_INPUTS => Stored in .rodata because it is declared as const and so it's not editable (read only) */
/* > *mask_descr => Stored in .rodata because it is declared as const and so it's not editable (read only)
        - the pointer (mask_descr) is stored in .data because it's ini
   > last_result => Stored in .bss because it's not initialized */
const int MAX_INPUTS = 4;
const char *mask_descr = "Applico maschera 0xFF per normalizzare";
unsigned int last_result;

/* Function that checks if the passed string is composed only by '0' and '1'
    - Input: Pointer to string
    - Output: 1 if the string is a valid binary (only '0' or '1')
              0 if the string is not a valid binary
    -- Data location --
        - *s => .rodata because it's const
        - s => stack (it's a pointer) because it'a parameter
        - i => stack because it's a global variable
        - return value => stack
*/
int is_valid_binary(const char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] != '0' && s[i] != '1')
            return 0;
    return 1;
}

/* Function that converts a bit string int o an unsigned int
    - Input: Pointer to string
    - Output: int value of the passed string
    -- Data location --
        - val => stack because it's a local variable
        - i => stack because it's a local variable
        - return value => stack
*/
unsigned int binary_to_uint(const char *s)
{
    unsigned int val = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        val <<= 1;
        if (s[i] == '1')
            val |= 1;
    }
    return val;
}

/* Main function
    - Input: there should be argv and argc both passed using the stack
    - Output: 0 if there function is  executed correctly
    -- Data location --
        - *inputs = stack because it's a local variable of the main
        - results = stack because it's a local variable
        - count = stack because it's a local variable
        - buffer = stack because it's a local variable
        - n => stack
        - masked => stack
*/
int main()
{
    char *inputs[4] = {NULL};
    unsigned int results[4] = {0};
    int count = 0;
    char buffer[256];

    printf("Inserisci %d stringhe binarie (solo 0 e 1):\n", MAX_INPUTS);

    while (count < MAX_INPUTS)
    {
        printf(">> ");
        if (!fgets(buffer, sizeof(buffer), stdin))
            break;

        buffer[strcspn(buffer, "\n")] = 0;
        if (!is_valid_binary(buffer))
        {
            printf("Errore: caratteri non validi.\n");
            continue;
        }

        inputs[count] = malloc(strlen(buffer) + 1);
        if (!inputs[count])
        {
            fprintf(stderr, "Errore allocazione.\n");
            exit(1);
        }
        strcpy(inputs[count], buffer);

        unsigned int n = binary_to_uint(inputs[count]);
        unsigned int masked = n & 0xFF;

        results[count] = masked;
        last_result = masked;

        printf(" -> Valore: %u  (mascherato con 0xFF: %u)\n", n, masked);
        count++;
    }
    printf("\n%s\n", mask_descr);
    for (int i = 0; i < count; i++)
    {
        printf(" [%d] %s -> %u\n", i, inputs[i], results[i]);
        free(inputs[i]);
    }

    return 0;
}
