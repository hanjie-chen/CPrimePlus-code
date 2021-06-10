#include "stdio.h"
#include "ctype.h"
int main(void)
{
    char ch;
    unsigned int big_count = 0;
    unsigned int small_count = 0;

    while ((ch = getchar()) != EOF)
    {
        if (islower(ch))
            small_count++;
        else if (isupper(ch))
            big_count++;
    }
    printf("You have enter %d Big letter and %d small letter.\n", big_count, small_count);

    return 0;
}