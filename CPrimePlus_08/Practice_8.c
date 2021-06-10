#include "stdio.h"
#include "ctype.h"
void Print_Menu(void);
float Input_Number(void);
char Get_First(void);
void Get_Answer(char select_letter, float first_number, float second_number);
int main(void)
{
    float first_number;
    float second_number;
    char select_letter;

    while (1)
    {
//        打印菜单
        Print_Menu();
//        获取输入字符串的第一个字符
        select_letter = Get_First();
//        判断字符并且并且给出相应操作
        if ('q' == select_letter)
            break;
        else if (!('a' == select_letter || 's' == select_letter || 'm' == select_letter || 'd' == select_letter))
        {
            printf("Sorry, I can understand only a, s, m, d and q.\n");
            continue;
        }
//    输入数字并检查，如果不是数字那么重新输入
        printf("Enter the first number:");
        first_number = Input_Number();
        printf("Enter the second number:");
        second_number = Input_Number();
//        计算并且打印出结果
        Get_Answer(select_letter, first_number, second_number);
//        消耗在缓冲区的字符
        while (getchar() != '\n')
            continue;
    }
    printf("Bye~.\n");

    return 0;
}
void Print_Menu(void)
{
    printf("Enter the operation of your choice:\n");
    printf("a:add                    s:subtract\n");
    printf("m:multiply               d:divide\n");
    printf("q:quit\n");
}
float Input_Number(void)
{
    float number;
    char ch;

    while (1 != scanf("%f", &number))
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a number, Please enter a number like -173, 12.5, 3:");
    }

    return number;
}
char Get_First(void)
{
    char ch;

    while ((ch = getchar()) != '\n')
        if (!isspace(ch))
            return ch;

}
void Get_Answer(char select_letter, float first_number, float second_number)
{
    switch (select_letter) {
        case 'a':
            printf("%.2f + %.2f = %.2f\n", first_number, second_number, first_number + second_number);
            break;
        case 's':
            printf("%.2f - %.2f = %.2f\n", first_number, second_number, first_number - second_number);
            break;
        case 'm':
            printf("%.2f * %.2f = %.2f\n", first_number, second_number, first_number * second_number);
            break;
        case 'd':
            if (second_number == 0)
            {
                printf("Please enter a number bigger than 0:");
                second_number = Input_Number();
            }
            printf("%.2f / %.2f = %.2f\n", first_number, second_number, first_number / second_number);
            break;
    }
}