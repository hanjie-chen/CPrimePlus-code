/* 该程序在run状态下无法使用ctrl+D来传入EOF
 * 在run状态下使用ctrl+D会结束整个程序
 * 但是在debug下却可以, 使用gcc编译后的文件也可以
 * */
#include "stdio.h"
int main(void)
{
    unsigned int count = 0;
    char ch;

    while ((ch = getchar()) != EOF)
        count++;
    printf("You have enter %d letters.\n", count);

    return 0;
}