#include "stdio.h"
int main(void)
{
    char ch;
    unsigned int count = 0;

    while ((ch = getchar()) != EOF)
    {
        count++;
        printf("%d ", ch);
        if (count == 10)
        {
            printf("\n");
            count = 0;
        }
    }printf("Bye~.\n");

    return 0;
}