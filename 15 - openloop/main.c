#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    FILE *fp;
    size_t open_counter;
    int file_descriptor;
} f_stats;

typedef struct
{
    size_t succ_open_n;
    size_t fail_open_n;
    f_stats *files;
    size_t list_dimension;
} OpenInfo;

int main(int argc, char *argv[])
{
    OpenInfo open = {0};
    size_t capacity = 0; 

    while (1)
    {
        if(argc < 2)return 1;
        
        FILE *fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            perror("fopen");
            open.fail_open_n++;
            break;
        }

        // check for size + realloc if needed
        if (open.succ_open_n >= capacity)
        {
            // capacity * 2
            capacity = capacity == 0 ? 64 : capacity * 2;
            f_stats *new_files = realloc(open.files, capacity * sizeof(f_stats));

            if (new_files == NULL)
            {
                perror("realloc");
                fclose(fp);
                break;
            }

            open.files = new_files;
        }

        open.files[open.succ_open_n].fp = fp;
        open.files[open.succ_open_n].open_counter = open.succ_open_n;
        open.files[open.succ_open_n].file_descriptor = fileno(fp);

        open.succ_open_n++;
        open.list_dimension = capacity;
    }

    // close all
    for (size_t i = 0; i < open.succ_open_n; i++)
    {
        if (fclose(open.files[i].fp) != 0)
        {
            fprintf(stderr, "Errore chiusura file #%zu (fd=%d)\n",
                    i, open.files[i].file_descriptor);
        }
    }

    printf("Aperture riuscite: %zu\nAperture fallite: %zu\n", open.succ_open_n, open.fail_open_n);
    printf("File descriptor usati: %d -> %d\n",
           open.succ_open_n > 0 ? open.files[0].file_descriptor : -1,
           open.succ_open_n > 0 ? open.files[open.succ_open_n - 1].file_descriptor : -1);

    free(open.files);
    return 0;
}