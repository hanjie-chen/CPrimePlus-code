#include <stdio.h>
#include <string.h>

#define SIZE 40

char * my_strncpy(char * destination, char * source, unsigned int n);
char * s_gets(char * string, int n);
unsigned int s_get_number(void);

int main(void)
{
    char word1[SIZE];
    char word2[SIZE];
    unsigned int number;

    puts("This program will copy designed letters form one string to another");
    puts("Please enter a sentence not more than 40 characters(empty line to quit)");
    while (s_gets(word2, SIZE) && word2[0] != '\0')
    {
        puts("Please enter the how many letters you want to copy");
        number = s_get_number();
        my_strncpy(word1, word2, number);
        puts("Now the copy string is ");
        puts(word1);
        puts("Please enter a sentence not more than 40 characters(empty line to quit)");
    }
    puts("Bye~");

    return 0;
}
char * my_strncpy(char * destination, char * source, unsigned int n)
{
    char * start = destination;
//    注意strlen函数不把'\0'计算进长度
    if (strlen(source) >= n) //对源字符串进行截断
    {
        for (int i = 0; i < n; ++i) {
            *destination = source[i];
            destination++;
        }
    }
    else if(strlen(source) < n) //对源字符串进行\0填充
    {
        for (int i = 0; i < n; ++i) {
            if (i < strlen(source))
                *destination = source[i];
            else
                *destination = '\0';
            destination++;
        }

    }

    return start;
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
unsigned int s_get_number(void)
{
    unsigned int number;

    scanf("%u", &number);
    while (getchar() != '\n')
        continue;

    return number;
}