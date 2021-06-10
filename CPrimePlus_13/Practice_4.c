#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    FILE * fp;
    int ch;

    if (argc < 2)
    {
        fputs("Please enter the filename.\n", stderr);
        fprintf(stderr, "Usage: %s name + filename1 + filename2 + ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < argc - 1; ++i) {
        if ((fp = fopen(argv[i + 1], "r")) == NULL)
        {
            fprintf(stderr, "Error in opening the file %s.\n", argv[i + 1]);
            continue;
        }
        fprintf(stdout, "Here is the contents of file %s.\n", argv[i + 1]);
        while ((ch = getc(fp)) != EOF)
            putc(ch, stdout);
        fputs("\n*******************************\n", stdout);
        if (fclose(fp) != 0)
        {
            fprintf(stderr, "Error in closing the file %s.\n", argv[i + 1]);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}