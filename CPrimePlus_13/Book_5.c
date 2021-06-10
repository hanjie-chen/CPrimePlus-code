#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4096
#define STR_LEN 81

void append(FILE * source, FILE * dest);
char * s_gets(char * string, int n); // 用于把输入的字符变为字符串

int main(void)
{
    FILE * fp_dest, * fp_source; // 目标文件指针 源文件指针
    int files = 0; // 文件数量
    char filename_dest[STR_LEN]; // 目标文件名
    char filename_source[STR_LEN]; // 源文件名
    int ch;

    puts("Enter the name of destination file:");
    s_gets(filename_dest, STR_LEN);
//    如果发生文件打开和创建错误 那么退出整个程序 注意： a+ 表明如果文件不存在那么会新创建一个文件
    if ((fp_dest = fopen(filename_dest, "a+")) == NULL)
    {
        fprintf(stderr, "Can't open file: %s\n", filename_dest);
        exit(EXIT_FAILURE);
    }
//    如果创建缓冲区失败退出程序 setvbuf()函数会返回一个非0值
    if (setvbuf(fp_dest, NULL, _IOFBF, BUF_SIZE) != 0)
    {
        fputs("Can't create output buffer.", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Enter the name of first source file (Empty line to quit)");
    while (s_gets(filename_source, STR_LEN) && filename_source[0] != '\0')
    {
        if (strcmp(filename_source, filename_dest) == 0)
            fputs("Can't append file by itself.", stderr);
//        一定会执行这个打开文件的这条判断语句 只有执行了这个语句才能对这个分支进行判断
        else if ((fp_source = fopen(filename_source, "r")) == NULL)
            fprintf(stderr, "Can't open file %s by read only.\n", filename_source);
        else
        {
            if (setvbuf(fp_source, NULL, _IOFBF, BUF_SIZE) != 0)
            {
                fputs("Can't create input buffer", stderr);
                continue;
            }
            append(fp_source, fp_dest);
//            出现文件读取错误而不是读到文件结尾
//            文件结尾返回0 文件读写错误返回非0值
            if (ferror(fp_dest) != 0)
                fprintf(stderr, "Error in reading file %s\n", filename_dest);
            if (ferror(fp_source) != 0)
                fprintf(stderr, "Error in writing file %s\n", filename_source);
            fclose(fp_source);
            files++;
            printf("File %s already append.\n", filename_source);
            puts("Next file : (Empty line to quit)");
        }
    }
    printf("Done appending. %d files appended.\n", files);
//    重置指针的位置 使其回到首位
    rewind(fp_dest);
    printf("%s contents.\n", filename_dest);
    while ((ch = getc(fp_dest)) != EOF)
        putchar(ch);
    puts("Done displaying.\n");
    fclose(fp_dest);

    return 0;
}

void append(FILE * source, FILE * dest)
{
    size_t bytes;
    static char temp[BUF_SIZE];

    while ((bytes = fread(temp, sizeof(char ), BUF_SIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}

char * s_gets(char * string, int n)
{
    char * result;
    char * find;

    result = fgets(string, n, stdin);
    if (result)
    {
        find = strchr(string, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return result;
}