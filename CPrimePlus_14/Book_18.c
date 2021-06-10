#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 81

char * s_gets(char * string, int n);
char show_menu(void);
void eat_line(void);
void show(void (* fp)(char *), char * string);
void ToUpper(char *); //把字符串中的字符全部转换为大写字母
void ToLower(char *); //把字符串中的字符全部转换为小写字母
void Trans_Pose(char *); //大小写转置
void Dummy(char *); // 啥都不干

int main(void)
{
    char line[LEN];
    char copy[LEN];
    char choice;
    void (* pt_function)(char *); // 一个指向函数的指针 该函数的返回值为空 接受一个指向char的指针作为参数

    puts("Please enter a string(empty line to quit)");
    while (s_gets(line, LEN) && line[0] != '\0')
    {
        while ((choice = show_menu()) != 'n')
        {
            switch (choice) {
                case 'u': pt_function = ToUpper;
                    break;
                case 'l': pt_function = ToLower;
                    break;
                case 't': pt_function = Trans_Pose;
                    break;
                case 'o': pt_function = Dummy;
                    break;
            }
            strcpy(copy, line);
            show(pt_function, copy);
        }
        puts("Enter a string(empty line to quit)");
    }
    puts("Bye~");

    return 0;
}
char * s_gets(char * string, int n)
{
    char * result;
    char * find;

    result = fgets(string, n, stdin);
    if (result)
    {
        find = strchr(string, '\n');
        if (find)
            * find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return result;
}
char show_menu(void)
{
    char ans;

    puts("Enter the Menu choice:");
    puts("u) uppercase   l)lowercase");
    puts("t) transposed case o) original case");
    puts("n) next string");
    ans = getchar();
    ans = tolower(ans);
    eat_line();
//    注意此处的while写法 可以代替下面在这种 非常方便
//    while(ans != 'u' && ans != 'l' && ans != 't' && ans != 'o' && ans != 'n')
    while (strchr("ulton", ans) == NULL)
    {
        puts("Please enter a u, l ,t, o or n:");
        ans = tolower(getchar());
        eat_line();
    }

    return ans;
}
void eat_line(void)
{
    while (getchar() != '\n')
        continue;
}
void ToUpper(char * string)
{
    while (*string)
    {
        * string = toupper(* string);
        string++;
    }
}
void ToLower(char * string)
{
    while (*string)
    {
        * string = tolower(* string);
        string++;
    }
}
void Trans_Pose(char * string)
{
    while (* string)
    {
        if (islower(* string))
            * string = toupper(* string);
        else if (isupper(* string))
            * string = tolower(* string);
        string++;
    }
}
void Dummy(char * string)
{
//    nothing to do
}
void show(void (* fp)(char *), char * string)
{
    fp(string);
    puts(string);
}