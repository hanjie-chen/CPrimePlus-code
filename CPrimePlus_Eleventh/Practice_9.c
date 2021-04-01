#include <stdio.h>
#include <string.h>

#define SIZE 40

void reverse_string(char string[]);
char * s_gets(char * string, int n);

int main(void)
{
    char string[SIZE];

    puts("This program will reverse the string you enter");
    puts("Please enter a sentence not more than 40 characters :(empty line to quit)");
    while (s_gets(string, SIZE) && string[0] != '\0')
    {
        reverse_string(string);
        puts("Now the string is :");
        puts(string);
        puts("Please enter a string:(empty line to quit)");
    }puts("Bye~");

    return 0;
}
void reverse_string(char string[])
{
    unsigned int length = strlen(string);
    char copy_string[length];

//    把字符串里面的字符拷贝到这个数组里面去 使其变成一个字符数组
    strncpy(copy_string, string, length);
    for (int i = 0; i < length; ++i) {
        string[i] = copy_string[length - i - 1];
    }

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