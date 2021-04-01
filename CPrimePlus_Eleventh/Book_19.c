#include <stdio.h>
#include <string.h>

#define SIZE 40
#define ANSWER "Grant"

char * s_gets(char * st, int n);

int main(void)
{
    char try[SIZE];

    puts("Who is buried in Grant's tomb");
    s_gets(try, SIZE);
//    strcmp函数比较两个字符串 如果一致那么返回0 否则是一个非0值
//    while(strcmp(try, ANSWER)) 这样写会更加的简洁
    while (strcmp(try, ANSWER) != 0)
    {
        puts("No, that's wrong. Try again.");
        s_gets(try, SIZE);
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