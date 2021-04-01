#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    FILE * source_fp, * dest_fp;
    int ch;

    if ((source_fp = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Error in opening the source file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((dest_fp = fopen(argv[2], "wb")) == NULL)
    {
        fprintf(stderr, "Error in opening the destination file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(source_fp)) != EOF)
        putc(ch, dest_fp);
    fprintf(stdout, "The copy is done. Contents was already copied from %s to %s.\n", argv[1], argv[2]);
    if (fclose(source_fp) != 0)
        fprintf(stderr, "Error in closing the file %s.\n", argv[1]);
    if (fclose(dest_fp) != 0)
        fprintf(stderr, "Error in closing the file %s.\n", argv[2]);

    return 0;
}