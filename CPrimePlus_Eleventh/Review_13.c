#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 40
#define ANSWER "GRANT"

char * s_gets(char * st, int n);
void Deal_Char(char * string);

int main(void)
{
    char try[SIZE];

    puts("Who is buried in Grant's tomb");
    s_gets(try, SIZE);
    Deal_Char(try);
    puts(try);
//    strcmp函数比较两个字符串 如果一致那么返回0 否则是一个非0值
//    while(strcmp(try, ANSWER)) 这样写会更加的简洁
    while (strcmp(try, ANSWER) != 0)
    {
        puts("No, that's wrong. Try again.");
        s_gets(try, SIZE);
        Deal_Char(try);
    }
    puts("That's right.");


    return 0;
}
char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            ++i;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
void Deal_Char(char * string)
{
    while (*string)
    {
        *string = toupper(*string);
        string++;
    }
}