#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 20

int main(void)
{
    char source_filename[SIZE];
    char dest_filename[SIZE];
    FILE * source_fp, * dest_fp;
    char ch;

    fprintf(stdout, "This program will copy one file to another and make the character to be capital.\n");
    fputs("Please enter the filename:", stdout);
    scanf("%s", source_filename);
//    用于生成输出文件名 其中-5是为了拼接后缀
    strncpy(dest_filename, source_filename, SIZE - 5);
    dest_filename[SIZE - 5] = '\0';
    strcat(dest_filename, ".cpy");
    if ((source_fp = fopen(source_filename, "r")) == NULL)
    {
        fprintf(stderr, "Error in opening the file %s.\n", source_filename);
        exit(EXIT_FAILURE);
    }
    if ((dest_fp = fopen(dest_filename, "w")) == NULL)
    {
        fprintf(stderr, "Error in creating the file %s.\n", dest_filename);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(source_fp)) != EOF)
    {
        if (isupper(ch))
            putc(ch, dest_fp);
        else
            putc(toupper(ch), dest_fp);
    }
    fputs("The copy is done, please looking for the file which filename finished by .cpy.\n", stdout);
    if (fclose(source_fp) != 0)
        fprintf(stderr, "Error in closing the file %s.\n", source_filename);
    if (fclose(dest_fp) != 0)
        fprintf(stderr, "Error in closing the file %s.\n", dest_filename);

    return 0;
}