#include <stdio.h>

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

    result = fgets(string, n, stdin);
    if (result)
    {
        while (*string != '\0' && *string != '\n')
            ++string;
        if (*string == '\n')
            *string = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return result;
}