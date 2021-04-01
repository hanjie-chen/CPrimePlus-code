#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIM 81

void To_Upper(char * string);
unsigned int Punctuation_Count(const char * string);

int main(void)
{
    char line[LIM];
    char * find;

    puts("Please enter a line:");
    fgets(line, LIM, stdin);
//    寻找换行符在字符数组中的位置
    find = strchr(line, '\n');
//    如果找到了一个换行符 那么把这个换行符修改为\0 让这个变为一个字符串
    if (find)
        * find = '\0';
    To_Upper(line);
    puts(line);
    printf("The line has %u punctuation characters.\n", Punctuation_Count(line));

    return 0;
}
void To_Upper(char * string)
{
    while (* string)
    {
        * string = toupper(* string);
        string++;
    }
}
unsigned int Punctuation_Count(const char * string)
{
    unsigned int count = 0;

    while (* string)
    {
        if (ispunct(*string))
            count++;
        string++;
    }

    return count;
}