#include <stdio.h>
#include <string.h>

#define SIZE 40
#define LIM 5

char * s_gets(char * string, int size);

int main(void)
{
    char words[LIM][SIZE];
    char temp[SIZE];
    int i = 0;

    printf("Please enter %d words beginning with q:\n", LIM);
    while (i < LIM && s_gets(temp, SIZE))
    {
        if (temp[0] != 'q')
            printf("%s don't begin with q\n", temp);
        else
        {
//            strcpy函数拷贝整个字符串
            strcpy(words[i], temp);
            ++i;
        }
    }
    puts("Here are the words accepted:");
    for (i = 0; i < LIM; ++i) {
        puts(words[i]);
    }

    return 0;
}
char * s_gets(char * string, int size)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(string, size, stdin);
    if (ret_val)
    {
        while (string[i] != '\0' && string[i] != '\n')
            ++i;
        if (string[i] == '\n')
            string[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}