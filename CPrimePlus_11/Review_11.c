#include <stdio.h>
#include <string.h>

#define SIZE 40

char * s_gets(char * string, int n);

int main(void)
{
    char * str;

    s_gets(str, 40);
    puts(str);

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
            *find= '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return result;
}