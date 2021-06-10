#include "stdio.h"
int main(void)
{
    char ch;
    unsigned int count = 0;

    while ((ch = getchar()) != '#')
    {
        if (ch == '\n')
            continue;
        count++;
        printf("%c is %3d ", ch, ch);
        if (count % 8 == 0)
            printf("\n");
    }

    return 0;
}