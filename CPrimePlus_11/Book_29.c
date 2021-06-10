#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int times;
//    atoi()函数把字符转换为整数
    times = atoi(argv[1]);
    if (argc < 2)
        puts("Please enter arguments!!");
    else if (times < 1)
        puts("Please enter an positive integer,such as 2, 3");
    else
        for (int i = 0; i < times; ++i)
            puts("Hello, good looking");

    return 0;
}