#include <stdio.h>
#include <string.h>

#define SIZE 40

void get_string(char string[], unsigned int n);

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
void get_string(char string[], unsigned int n)
{
    int i = 0;

    string[i] = getchar();
    while (string[i] != ' ' && string[i] != '\n' && i < n)
    {
        ++i;
        string[i] = getchar();
    }

    while (getchar() != '\n')
        continue;
}