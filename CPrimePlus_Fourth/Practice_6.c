#include "stdio.h"
#include "string.h"
int main(void)
{
    char first_name[25],last_name[25];
    printf("请输入您的名：");
    scanf("%s",last_name);
    printf("请输入您的姓：");
    scanf("%s",first_name);
    printf("%s %s\n",last_name,first_name);
//    strlen()函数返回是unsigned long int 类型的值，所以使用%lu,前面的那个*由于必须为int类型，故将其强制类型转化
    printf("%*lu %*lu\n",(int)strlen(last_name),strlen(last_name),(int)strlen(first_name),strlen(first_name));
    printf("%s %s\n",last_name,first_name);
    printf("%-*lu %-*lu\n",(int)strlen(last_name),strlen(last_name),(int)strlen(first_name),strlen(first_name));
    return 0;
}