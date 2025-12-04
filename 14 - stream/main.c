#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLOCK_SIZE 256
#define FILES_N 2

struct CopyStats
{
    size_t byte_copied;
    size_t read_errors;
    size_t write_errors;
    double elapsed;
};

int open_files(char *filename1, char *filename2, FILE *files[FILES_N])
{
    files[0] = fopen(filename1, "r");
    if (!files[0])
    {
        perror("error reading src file");
        return 1;
    }

    files[1] = fopen(filename2, "w");
    if (!files[1])
    {
        perror("error opening dst file");
        fclose(files[0]);
        return 2;
    }

    return 0;  
}

int copy_files(FILE *files[FILES_N], struct CopyStats *sp)
{
    unsigned char block[BLOCK_SIZE];
    size_t bytes_read;

    sp->byte_copied = 0;
    sp->read_errors = 0;
    sp->write_errors = 0;

    while ((bytes_read = fread(block, 1, BLOCK_SIZE, files[0])) > 0)
    {
        size_t bytes_written = fwrite(block, 1, bytes_read, files[1]);
        if (bytes_written != bytes_read)
        {
            // if byte written are not equal to the read one => not good
            perror("writing error");
            sp->write_errors++;
            return 3;
        }
        sp->byte_copied += bytes_written;
    }

    if (ferror(files[0]))
    {
        // if there are read problems
        perror("reading error");
        sp->read_errors++;
        return 4;
    }

    return 0;
}

void close_files(FILE *files[FILES_N]) {
    for (size_t i = 0; i < FILES_N; i++)
    {
        fclose(files[i]);
    }
    
}

int main(int argc, char *argv[])
{
    clock_t start, end;
    start = clock();
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s src dst\n", argv[0]);
        return 1;
    }

    FILE *files[FILES_N];
    struct CopyStats stats;

    if (open_files(argv[1], argv[FILES_N], files) != 0)
        return 2;

    if (copy_files(files, &stats) != 0)
    {
        close_files(files);
        return 3;
    }

    close_files(files);
    end = clock();

    stats.elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bytes copied: %zu\nRead Errors: %zu\nWrite errors: %zu\nTime Elapsed: %.5f", stats.byte_copied, stats.read_errors, stats.write_errors, stats.elapsed);
    return 0;
}
