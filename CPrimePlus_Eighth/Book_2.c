/* 注意改文件编译之后的文件放在cmake-build-debug中
 * 而读取文件需要同级目录下所以是Book_1.c这个文件是读取不到的
 * 而使用终端编译的话，就可以明确在同级目录下
 * */
#include "stdio.h"
#include "stdlib.h"
int main(void)
{
    int ch;
    FILE * fp;
    char filename[50];

    printf("Please enter the name of file:");
    scanf("%s", filename);
    printf("%s\n", filename);
    fp = fopen(filename, "r"); // 打开待读取文件
    if (fp == NULL)
    {
        printf("Failed to open the file,Bye~.\n");
        exit(1); //退出程序
    }
//    getc(fp)从文件中获取一个字符
    while ((ch = getc(fp)) != EOF)
        putchar(ch);
    fclose(fp); //关闭文件

    return 0;
}