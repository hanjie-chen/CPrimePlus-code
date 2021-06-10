#include <stdio.h>
#include <stdlib.h>

#define LIM 30

char * s_gets(char * string, int n);

int main(void)
{
    char * end;
    char number[LIM];
    long int value;

//    printf("%d\n", atoi("123"));
//    printf("%d\n", atoi("fuck"));
//    printf("%d\n", atoi("chj123"));
//    printf("%d\n", atoi("24chj"));
//    atol atof的工作原理和atoi类似 前者把字符串转换为long 后者把字符串转换为double
    puts("Enter a number (empty line to quit) :");
    while (s_gets(number, LIM) && number[0] != '\0')
    {
        value = strtol(number, &end, 10);
        printf("base 10 input, base 10 output: %ld, stopped at %s (%d)\n", value, end, *end);
        value = strtol(number, &end, 16);
        printf("base 16 input, base 10 output: %ld, stopped at %s (%d)\n", value, end, *end);
        puts("Next number:");
    }puts("Bye~");

    return 0;
}
char * s_gets(char * string, int n)
{
    char * result;
    int i = 0;

    result = fgets(string, n, stdin);
    if (result)
    {
        while (string[i] != '\0' && string[i] != '\n')
            ++i;
        if (string[i] == '\n')
            string[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return result;
}