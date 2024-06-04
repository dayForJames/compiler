#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

// #include "../include/new_asm.h"
#include "../include/token.h"

int
main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Please write which file to compile\n");
        return 1;
    }

    FILE* file_ptr;
    file_ptr = fopen(argv[1], "r");

    if (file_ptr == NULL)
    {
        printf("CAN'T OPEN FILE\n");
        return 1;
    }

    struct stat stbuf;

    if (stat(argv[1], &stbuf) == -1)
    {
        printf("YOU HAVE NO RIGHTS TO %s\n", argv[1]);
        return -1;
    }

    size_t file_size = stbuf.st_size;

    char* buf = malloc(file_size);

    int fread_result = fread(buf, sizeof(char), file_size / sizeof(char), file_ptr);

    fclose(file_ptr);

    int tokens_len = 0;
    Token* tokens = tokenize(buf, &tokens_len);

    // for (int i = 0; i < tokens_len; i++)
    // {
    //     printf("%s\n", tokens[i].value);
    // }
    
    return 0;
}