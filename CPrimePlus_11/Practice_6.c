#include <stdio.h>

#define SIZE 40

_Bool is_within(char * string, char ch);
char * s_gets(char * string, int n); // 用于安全输入字符串
char s_get_char(void); // 用于安全输入字符串

int main(void)
{
    char word[SIZE];
    char ch;
    _Bool ch_in;

    puts("The program will find a character whether in a sentence or word ");
    puts("Please enter a empty line to finish:");
    while (s_gets(word, SIZE) && word[0] != '\0')
    {
        puts("Please enter a character:");
        ch = s_get_char();
        ch_in = is_within(word, ch);
        if (ch_in)
            printf("Well the %c is in the word\n", ch);
        else
            printf("Can't find %c in the word\n", ch);
        puts("Please enter a sentence:");
    }
    puts("Bye~");
    return 0;
}
_Bool is_within(char * string, char ch)
{
    _Bool in = 0;

    while (*string)
    {
        if (*string == ch)
        {
            in = 1;
            break;
        }
        string++;
    }

    return in;
}
char * s_gets(char * string, int n)
{
    char * result;
    int i = 0;

    result = fgets(string, n, stdin);
    if (result)
    {
        while (string[i] != '\n' && string[i] != '\0')
            ++i;
        if (string[i] == '\n')
            string[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return result;
}
char s_get_char(void)
{
    char ch;

    ch = getchar();
    while (getchar() != '\n')
        continue;

    return ch;
}