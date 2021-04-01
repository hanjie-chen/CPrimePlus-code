#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 40

int my_atoi(const char * string);
int my_pow(int base_number, int index_number);
char * s_gets(char * string, int n);

int main(int argc, char * argv[])
{
    char string_number[SIZE];
    int real_number;

    puts("This program test the function atoi write by me");
    puts("Please enter a string number and I will give the real number back(empty line to quit)");
    while (s_gets(string_number, SIZE) && string_number[0] != '\0')
    {
        real_number = my_atoi(string_number);
        printf("You entered %d\n", real_number);
        puts("Please enter a string number and I will give the real number back(empty line to quit)");
    }
    puts("Bye~");

    return 0;
}
int my_atoi(const char * string)
{
    int result = 0;
    unsigned long int string_length = strlen(string);
    int base_number;
    char * string_number = string;

    while (*string)
    {
        if (!isdigit(*string))
        {
            return 0;
        }
        string++;
    }
    for (int i = 0; i < string_length; ++i) {
        base_number = string_number[i] - 48;
        result += base_number * my_pow(10, string_length - i - 1);
    }

    return result;
}
int my_pow(int base_number, int index_number)
{
    int result = base_number;

    if (index_number == 0)
        return 1;
    for (int i = 1; i < index_number; ++i)
        result *= base_number;

    return result;
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