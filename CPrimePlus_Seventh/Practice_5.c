#include "stdio.h"
int main(void)
{
    char ch;
    unsigned int count = 0;

    while ((ch = getchar()) != '#')
    {
        switch (ch) {
            case '.':
                printf("!");
                count++;
                break;
            case '!':
                printf("!!");
                count++;
                break;
            default:
                putchar(ch);
        }
    }printf("\n");
    if (count >= 2)
        printf("There are %u times replace.\n", count);
    else
        printf("There is %u time replace.\n", count);

    return 0;
}