#include "stdio.h"
int main(void)
{
    float height;
    char name[25];
    printf("请输入您的身高：（单位：厘米）");
    scanf("%f",&height);
    printf("请输入您的姓名：");
    scanf("%s",name);
    printf("好吧！%s先生/女士，您的身高为%.2f米",name,height/100);
    return 0;
}