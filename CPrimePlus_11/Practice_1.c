#include <stdio.h>
#include <string.h>

#define SIZE 40

char * get_string(char string[], unsigned int n);

int main(void)
{
    unsigned int number;
    char string[SIZE];

    puts("Now enter the words you want to say:");
    get_string(string, SIZE);
    puts("The word is :");
    puts(string);

    return 0;
}
char * get_string(char string[], unsigned int n)
{
    char * result;

    result = fgets(string, n, stdin);
    while (getchar() != '\n')
        continue;

    return result;
}