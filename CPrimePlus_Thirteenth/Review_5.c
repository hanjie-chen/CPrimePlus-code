#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

int main(int argc, char *argv[])
{
    FILE * fp;
    char temp[SIZE];
    char * return_value;
    char ch;

    if (argc != 3 || strlen(argv[1]) != 2)
    {
        fprintf(stderr, "Please enter 2 argument, the first is a character and the second is filename\n");
        exit(EXIT_FAILURE);
    }
    ch = argv[1][0];
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Error in opening file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    do
    {
        return_value = fgets(temp, SIZE, fp);
        if (return_value)
            if (strchr(temp, ch))
                fputs(temp, stdout);
    }while (return_value);
    if (fclose(fp) != 0)
        fprintf(stderr, "Error in closing file %s.\n", argv[2]);

    return 0;
}