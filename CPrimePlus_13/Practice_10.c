#include <stdio.h>
#include <stdlib.h>

#define SIZE 41
#define STR_LEN 256

int main(void)
{
    char filename[SIZE];
    char temp[STR_LEN];
    long int location;
    FILE * fp;

    fputs("This program will print the content from the location your entered to the end of line.\n", stdout);
    fputs("Please enter the file name.\n", stdout);
    scanf("%s", filename);
    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Error in opening the file %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    fputs("Please enter the location your want to start: (q or negative number to quit)", stdout);
    while (scanf("%ld", &location) == 1 && location > 0)
    {
        if (fseek(fp, location, SEEK_SET) != 0)
        {
            fprintf(stderr, "Don't try to move out of the file.\n");
            continue;
        }
        if (fgets(temp, STR_LEN, fp))
            fputs(temp, stdout);
        else
            fprintf(stderr, "Maybe you meet the end of the file or end of the line in %s.\n", filename);
        fputs("Please try again(q or negative number to quit).\n", stdout);
    }
    fputs("Done~.\n", stdout);
    if (fclose(fp) != 0)
        fprintf(stderr, "Error in closing the file %s.\n", filename);

    return 0;
}