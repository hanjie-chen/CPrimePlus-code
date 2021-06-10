#include "stdio.h"
#include "ctype.h"
float BASIC_WAGE_PER_HOUR;
#define FULL_BASIC_TIME 40.0
#define FULL_BASIC_WAGE FULL_BASIC_TIME * BASIC_WAGE_PER_HOUR
#define WORK_OVERTIME 1.5
#define TAX_FIRST_RATE 0.15
#define TAX_FIRST_MONEY 300
#define TAX_FIRST_ALL TAX_FIRST_RATE * TAX_FIRST_MONEY
#define TAX_SECOND_RATE 0.20
#define TAX_SECOND_MONEY 450
#define TAX_SECOND_ALL TAX_SECOND_RATE * (TAX_SECOND_MONEY - TAX_FIRST_MONEY) + TAX_FIRST_ALL
#define TAX_Third_RATE 0.25
void Print_Menu(void);
void Choice_Basic_Wage(int select_number);
float Calculate_Total_Wages(int work_time);
float Calculate_Tax(float total_wages);
float Calculate_Net_Income(float total_wages, float tax);
char Get_First(void);
int main(void)
{
    char select_letter;
    int work_time;
    float total_wages;
    float tax;
    float net_income;
    while (1)
    {
//        菜单部分
        Print_Menu();
//        选择工作时薪
        printf("Your choice is:");
        select_letter = Get_First();
        if ('q' == select_letter)
            break;
        else if (!('t' == select_letter || 's' == select_letter || 'm' == select_letter || 'l' == select_letter))
        {
            printf("Sorry, I can understand only t, s, m, l, q.\n");
            printf("Please enter again.\n");
            continue;
        }
        Choice_Basic_Wage(select_letter);
//        ***************************
//        计算总工资，上交的税，和实际工资
//        ***************************
        printf("Please enter the work time a week(hour):");
        scanf("%d", &work_time);
//        根据时间计算总工资
        total_wages = Calculate_Total_Wages(work_time);
        printf("Your total wages is %.2f $.\n", total_wages);
//        根据总工资计算税率
        tax = Calculate_Tax(total_wages);
        printf("Your tax is %.2f $.\n", tax);
//        根据总工资和税率计算纯收入
        net_income = Calculate_Net_Income(total_wages, tax);
        printf("Your net income is %.2f $.\n", net_income);
    }
    printf("Bye~.\n");

    return 0;
}
void Print_Menu(void)
{
    printf("************************************************************************\n");
    printf("Please enter the number corresponding to the desired pay rate or action:\n");
    printf("t:$8.75/hour                                s:$9.33/hour\n");
    printf("m:$10.00/hour                               l:$11.20/hour\n");
    printf("q:quit\n");
    printf("************************************************************************\n");
}
char Get_First(void)
{
    char ch;
    while ((ch = getchar()) != EOF)
        if (!isspace(ch))
            return ch;
}
void Choice_Basic_Wage(int select_number)
{
    switch (select_number) {
        case 't':
            BASIC_WAGE_PER_HOUR = 8.75;
            break;
        case 's':
            BASIC_WAGE_PER_HOUR = 9.33;
            break;
        case 'm':
            BASIC_WAGE_PER_HOUR = 10.00;
            break;
        case 'l':
            BASIC_WAGE_PER_HOUR = 11.20;
            break;
    }
}
float Calculate_Total_Wages(int work_time)
{
    float total_wages;

    if (work_time <= FULL_BASIC_TIME)
        total_wages = work_time * BASIC_WAGE_PER_HOUR;
    else
        total_wages = FULL_BASIC_WAGE + (work_time - FULL_BASIC_TIME) * WORK_OVERTIME * BASIC_WAGE_PER_HOUR;

    return total_wages;
}
float Calculate_Tax(float total_wages)
{
    float tax;

    if (total_wages <= 300)
        tax = total_wages * TAX_FIRST_RATE;
    else if (total_wages > 300 && total_wages <= 450)
        tax = TAX_FIRST_ALL + (total_wages - TAX_FIRST_MONEY) * TAX_SECOND_RATE;
    else
        tax = TAX_SECOND_ALL + (total_wages - TAX_SECOND_MONEY) * TAX_Third_RATE;

    return tax;
}
float Calculate_Net_Income(float total_wages, float tax)
{
    float net_income;

    net_income = total_wages - tax;

    return net_income;
}
