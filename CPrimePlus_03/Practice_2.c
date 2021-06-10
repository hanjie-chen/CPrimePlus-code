#include "stdio.h"
int main(void)
{
    unsigned int number;
    printf("请输入一个ASCII码中的数值：");
    scanf("%d",&number);
    printf("该值在ASCII码中的对应字符为：%c\n",number);
    return 0;
}