#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int ch;
    FILE * fp;
    unsigned long int count = 0;

//    如果没有输入参数或者是错误输入参数
    if (argc != 2)
    {
        printf("Usage : %s filename.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
//    如果打开文件失败
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Can't open %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
//    getc()函数会自动移动是ch指向下一个字符
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters.\n", argv[1], count);

    return 0;
}