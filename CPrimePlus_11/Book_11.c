#include <stdio.h>

#define SIZE 10

int main(void)
{
    char name1[SIZE];
    char name2[SIZE];
    int count;

    printf("Please enter 2 names.\n");
//    这里的%10s %5s限定了读入的字符宽度 限定10个字符 5个字符
//    如果超过这个限制那么只读取前面10个字符 如果小于这个限制那么读到第一个空白字符为止
    count = scanf("%5s %10s", name1, name2);
    printf("I read the %d names: %s and %s", count, name1, name2);

    return 0;
}