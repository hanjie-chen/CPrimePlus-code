#include <stdio.h>
#include <stdlib.h>

#define SIZE 256

int main(int argc, char * argv[])
{
    FILE * fp1, * fp2;
    char temp[SIZE];
    char * return_value1, * return_value2;

    if (argc < 3)
    {
        fprintf(stderr, "Please enter at least two argument value.\n");
        fprintf(stderr, "Usage: %s filename1 filename2.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Error in opening the file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Error in opening the file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    do {
        return_value1 = fgets(temp, SIZE, fp1);
        if (return_value1)
            fputs(temp, stdout);
        return_value2 = fgets(temp, SIZE, fp2);
        if (return_value2)
            fputs(temp, stdout);
    }while (return_value1 || return_value2);
    fprintf(stdout, "The print is finished.\n");
    if (fclose(fp1) != 0 || fclose(fp2) != 0)
        fprintf(stderr, "Error in closing file.\n");

    return 0;
}