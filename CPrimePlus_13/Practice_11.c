#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

int main(int argc, char * argv[])
{
    FILE * fp;
    char temp[SIZE];
    int count = 0;

    if (argc != 3)
    {
        fprintf(stderr, "The program will find the appoint string in a file.\n");
        fprintf(stderr, "Usage: %s + string + filename.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Error in opening the file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Here is the lines contains %s.\n", argv[1]);
    while (fgets(temp, SIZE, fp))
    {
        if (strstr(temp, argv[1]))
        {
            fputs(temp, stdout);
            count++;
        }
    }
    fputs("Done.\n", stdout);
    if (0 == count)
        fputs("Sorry sir!The program did not find the string in the file.\n", stdout);
    if (fclose(fp) != 0)
        fprintf(stderr, "Error in closing the file %s.\n", argv[2]);

    return 0;
}