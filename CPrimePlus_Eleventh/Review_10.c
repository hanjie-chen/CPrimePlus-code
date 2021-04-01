#include <stdio.h>

unsigned int my_string_length(char * string);

int main(void)
{
    char string[40] = "apple is a company";
    unsigned int length;

    length = my_string_length(string);
    printf("The length of string is %u\n", length);

    return 0;
}
unsigned int my_string_length(char * string)
{
    unsigned int result = 0;

    while (*string++ != '\0')
        result++;

    return result;
}