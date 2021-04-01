#include "stdio.h"
int main(void)
{
    int number;
    unsigned int count = 0;
    printf("请输入一个整数，好让我们来对其操作：");
    scanf("%d",&number);
    while (count++ < 11)
    {
        printf("%d\n", number);
        number++;
    }
    return 0;
}