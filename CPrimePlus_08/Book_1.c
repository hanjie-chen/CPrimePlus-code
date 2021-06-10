#include "stdio.h"
int main(void)
{
    char ch;

    while ((ch = getchar()) != EOF)
    {
        putchar(ch);
    }printf("\n");

    return 0;
}
