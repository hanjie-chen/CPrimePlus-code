#include <stdio.h>

#define SIZE 80

char * Find_Char_First(char string[], char find); // 用于找到字符
char * s_gets(char * string, int n); // 用于安全输入字符串
char s_get_char(void); // 用于安全输入字符串

int main(void)
{
    char word[SIZE];
    char * location;
    char ch;

    puts("The program will find a character in a sentence or word like a function strchr()");
    puts("Please enter a empty line to finish:");
    while (s_gets(word, SIZE) && word[0] != '\0')
    {
        puts("Please enter a character:");
        ch = s_get_char();
        location = Find_Char_First(word, ch);
        if (location)
            printf("Well the location of %c in the word is %p\n", ch, location);
        else
            printf("Can't find %c in the word\n", ch);
        puts("Please enter a sentence:");
    }
    puts("Bye~");

    return 0;
}
char * Find_Char_First(char string[], char find)
{
    char * location;
    _Bool not_find = 1;

    while (*string)
    {
        if (*string == find)
        {
            location = string;
            not_find = 0;
            break;
        }

        string++;
    }
    if (not_find)
        location = NULL;

    return location;
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