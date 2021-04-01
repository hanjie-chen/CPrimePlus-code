#include <stdio.h>

// argc是argument count的缩写
// argv是argument vector的缩写
int main(int argc, char *argv[])
{
//    注意 在本系统下 argv[0]的值是程序本身的名称
//    而argv[1] 则是后面输入的字符串参数
//    如何使用双引号括起来的一句话会被当做一个参数
    printf("The command lien has %d arguments.\n", argc - 1);
    for (int i = 1; i < argc; ++i) {
        printf("%d: %s\n", i, argv[i]);
    }printf("\n");

    return 0;
}