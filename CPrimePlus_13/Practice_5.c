#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4096

void append(FILE * source, FILE * dest);

int main(int argc, char * argv[])
{
    FILE * fp_dest, * fp_source; // 目标文件指针 源文件指针
    int ch;

    if (argc < 3)
    {
        fprintf(stderr, "Please enter at least two filename, the second file will be added in the end of the first file.\n");
        fprintf(stderr, "Usage: %s filename1 filename2 filename3....\n", argv[0]);
        exit(EXIT_FAILURE);
    }
//    如果发生文件打开和创建错误 那么退出整个程序 注意： a+ 表明如果文件不存在那么会新创建一个文件
    if ((fp_dest = fopen(argv[1], "a+")) == NULL)
    {
        fprintf(stderr, "Can't open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
//    如果创建缓冲区失败退出程序 setvbuf()函数会返回一个非0值
    if (setvbuf(fp_dest, NULL, _IOFBF, BUF_SIZE) != 0)
    {
        fputs("Can't create output buffer.", stderr);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < argc - 2; ++i)
    {
        if (strcmp(argv[1], argv[i + 2]) == 0)
            fputs("Can't append file by itself.", stderr);
//        一定会执行这个打开文件的这条判断语句 只有执行了这个语句才能对这个分支进行判断
        else if ((fp_source = fopen(argv[i + 2], "r")) == NULL)
            fprintf(stderr, "Can't open file %s by read only.\n", argv[i + 2]);
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
                fprintf(stderr, "Error in reading file %s\n", argv[1]);
            if (ferror(fp_source) != 0)
                fprintf(stderr, "Error in writing file %s\n", argv[i + 2]);
            fclose(fp_source);
            printf("File %s already append.\n", argv[i + 2]);
        }
    }
    printf("Done appending. %d files appended.\n", argc - 2);
//    重置指针的位置 使其回到首位
    rewind(fp_dest);
    printf("%s contents.\n", argv[1]);
    while ((ch = getc(fp_dest)) != EOF)
        putchar(ch);
    puts("Done displaying.\n");
    if (fclose(fp_dest) != 0)
        fprintf(stderr, "Error in closing the file %s.\n", argv[1]);

    return 0;
}

void append(FILE * source, FILE * dest)
{
    size_t bytes;
    static char temp[BUF_SIZE];

    while ((bytes = fread(temp, sizeof(char ), BUF_SIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}
