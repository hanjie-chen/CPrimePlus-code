#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int main(void)
{
    int ch;
    FILE * fp;
    char filename[SIZE];
    unsigned long int count = 0;

    fputs("This program will print the file contents and count the number of the file.\n", stdout);
    fputs("Please enter the file name:", stdout);
    scanf("%s", filename);
    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Error in opening file %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    if (fclose(fp) != 0)
        fprintf(stderr, "Error in closing the file %s.\n", filename);
    fprintf(stdout, "The file %s have %lu characters.\n", filename, count);

    return 0;
}