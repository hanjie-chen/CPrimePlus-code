#include <stdio.h>
#include <string.h>

#define SIZE 40

char * s_gets(char * string, int n);
void delete_string_space(char * string);

int main(void)
{
    char string[SIZE];

    puts("This program will delete the space in a string");
    puts("Please enter a sentence:(empty line to quit)");
    while (s_gets(string, SIZE) && string[0] != '\0')
    {
        delete_string_space(string);
        puts("Now the string is ");
        puts(string);
        puts("Please enter a sentence:(empty line to quit)");
    }
    puts("Bye~");

    return 0;
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
void delete_string_space(char * string)
{
    unsigned int length;

    length = strlen(string);
    for (int i = 0; i < length; ++i)
        if (string[i] == ' ')
            for (int j = i; j < length; ++j)
                string[j] = string[j + 1];
}