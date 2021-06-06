#include "Practice_5.h"
#include <stdio.h>
#include <string.h>

#define STRING_LEN 30
char * s_gets(char * string, int n);
static void eat_line(void);

int main(void)
{
    char string[STRING_LEN];
    Item temp;
    Stack char_stack;
//    初始化栈
    InitializeStack(&char_stack);
    puts("This program will show the stack work by using a string");
    puts("Now, please enter the string:");
    s_gets(string, STRING_LEN);
//    对字符串进行压栈操作
    for (int i = 0; string[i] != '\0'; ++i) {
        temp.ch= string[i];
        PushStackNode(&char_stack, &temp);
    }
//    对栈进行出栈操作
    while (PopStackNode(&char_stack, &temp))
        printf("Now put the %c out\n", temp.ch);
//    清空栈
    DeleteAllNode(&char_stack);
    puts("Everything is clear!Bye~");

    return 0;
}
char * s_gets(char * string, int n)
{
    char * result;
    char * find;

    result = fgets(string, n, stdin);
    if (result)
    {
        find = strchr(string, '\n');
        if (find)
            * find = '\0';
        else
            eat_line();
    }

    return result;
}
static inline void eat_line(void)
{
    while (getchar() != '\n')
        continue;
}