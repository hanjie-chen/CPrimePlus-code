#include <stdio.h>

#define MAX 40

char * s_gets(char * string, int n);

int main(void)
{
    char first_name[MAX];
    char last_name[MAX];
    char result[2 * MAX + 10];
    double prize;

    puts("Enter your first name:");
    s_gets(first_name, MAX);
    puts("Enter your last name:");
    s_gets(last_name, MAX);
    puts("Enter your prize money:");
    scanf("%lf", &prize);
//    sprintf的用法和printf相同 只不过sprintf用于写入字符串 但是printf用于在显示器上面输出字符串
//    最前的那个参数代表要写入的字符串的地址
    sprintf(result, "%s %-19s: $%6.2f\n", last_name, first_name, prize);
    puts(result);

    return 0;
}
char * s_gets(char * string, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(string, n, stdin);
    if (ret_val)
    {
        while (string[i] != '\n' && string[i] != '\0')
            ++i;
        if (string[i] == '\n')
            string[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}