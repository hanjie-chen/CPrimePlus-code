#include <stdio.h>
#include <string.h>

#define SIZE 80
#define BUG_SIZE 13

char * s_gets(char * st, int n);

int main(void)
{
    char flower[SIZE];
    char addon[] = "s smell like old shoes";
    char bug[BUG_SIZE];
    int available;

    puts("What is your favorite flower?");
    s_gets(flower, SIZE);
    if (strlen(flower) + strlen(addon) <= SIZE - 1)
        strcat(flower, addon);
    puts(flower);
    puts("What is your favorite bug");
    s_gets(bug, BUG_SIZE);
    available = BUG_SIZE - strlen(bug) - 1;
    strncat(bug, addon, available);
    puts(bug);


    return 0;
}
char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);

    if(ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            ++i;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}