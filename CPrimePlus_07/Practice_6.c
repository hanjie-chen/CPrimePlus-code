#include "stdio.h"
int main(void)
{
    char now_ch, last_ch;
    unsigned int count = 0;

    now_ch = getchar();
    last_ch = now_ch;
    while ((now_ch = getchar()) != '#')
    {
        if (last_ch == 'e')
        {
            if (now_ch == 'i')
                count++;
        } else{
            last_ch = now_ch;
        }
    }
    if (count >= 2)
        printf("There are %u 'ei'\n", count);
    else
        printf("There is %u 'ei'\n", count);

    return 0;
}