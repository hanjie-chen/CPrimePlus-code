#include "stdio.h"
#include "string.h"
int main(void)
{
    char name[25];
    printf("你好，请输入您的姓名：");
    scanf("%s",name);
    printf("[\"%s\"]\n",name);
    printf("[\"%20s\"]\n",name);
    printf("[\"%-20s\"]\n",name);
    printf("[%*s]\n",strlen(name)+3,name);
    return 0;
}