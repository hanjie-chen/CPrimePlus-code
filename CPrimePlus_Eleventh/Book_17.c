#include <stdio.h>
#include <string.h>

#define SIZE 80

char * s_gets(char * st, int n);

int main(void)
{
    char flower[SIZE];
    char addon[] = "s smell like old shoes";

    puts("What's is your favorite flower ?");
    if (s_gets(flower, SIZE))
    {
//        strcat函数把两个字符串连接在一个 把第二个字符串添加到第一个字符串的末尾
        strcat(flower, addon);
        puts(flower);
        puts(addon);
    } else
        puts("End of file encountered !");
    puts("Bye~");

    return 0;
}
char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
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