#include "stdio.h"
int main(void)
{
    char ch;
    unsigned int count = 0;

    while ((ch = getchar()) != '#')
    {
        if (ch == '.')
        {
            printf("!");
            count++;
        }
        else if (ch == '!')
        {
            printf("!!");
            count++;
        }
        else
            putchar(ch);
    }printf("\n");
    printf("There are %u times replace.\n", count);

    return 0;
}