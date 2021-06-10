#include <stdio.h>
#include <string.h>

#define SIZE 40

char * string_in(const char * big_string, const char * small_string);
char * s_gets(char * string, int n);

int main(void)
{
    char string_first[SIZE];
    char string_second[SIZE];
    char * is_contain;

    puts("This program will find a string whether be contained in another string");
//    重复两次代码的原因是当这两次输入都是空字符的时候 防止两者对比进入if语句
    puts("Enter two empty line to quit");
    puts("Please enter the first string:");
    s_gets(string_first, SIZE);
    puts("Please enter the second string:");
    s_gets(string_second, SIZE);

    while (string_first[0] != '\0' && string_second[0] != '\0')
    {
        is_contain = string_in(string_first, string_second);
        if (is_contain)
            printf("Find the second string in first string at the %p\n", is_contain);
        else
            puts("The second string is not in the first string");
        puts("Enter two empty line to quit");
        puts("Please enter the first string:");
        s_gets(string_first, SIZE);
        puts("Please enter the second string:");
        s_gets(string_second, SIZE);
    }
    puts("Bye~");

    return 0;
}
char * string_in(const char * big_string, const char * small_string)
{
    char * result;
    unsigned int small_string_length;

    small_string_length = strlen(small_string);
    while (*big_string)
    {
//        如果找到了small_string 那么就让result=big_string位置的指针
        if (strncmp(big_string, small_string, small_string_length) == 0)
        {
            result = big_string;
            break;
        }
        else
            result = NULL;

        big_string++;
    }

    return result;
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