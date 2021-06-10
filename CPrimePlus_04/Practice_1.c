#include "stdio.h"
int main(void)
{
    char first_name[20],last_name[20];
    printf("请输入您的姓：");
    scanf("%s",first_name);
    printf("请输入您的名：");
    scanf("%s",last_name);
    printf("你好! %s，%s\n",last_name,first_name);
    return 0;
}