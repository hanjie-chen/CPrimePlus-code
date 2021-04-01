#include "stdio.h"
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
void Menu_Print();
void Choose_BASIC_WAGE_PER_HOUR(int select_number);
float Calculate_Total_Wage(int work_time);
float Calculate_Tax(float total_wages);
int main(void)
{
    int select_number;
    int work_time;
    float total_wages;
    float tax;
    float net_income;
    while (1)
    {
//        打印菜单
        Menu_Print();
        scanf("%d", &select_number);
        if (select_number == 5)
            break;
//        选择每小时基本工资
        Choose_BASIC_WAGE_PER_HOUR(select_number);
//        输入工作时间
        printf("Please enter the work time a week(hour):");
        scanf("%d", &work_time);
//        计算总工资
        total_wages = Calculate_Total_Wage(work_time);
        printf("Your total wages is %.2f $.\n", total_wages);
//        计算税
        tax = Calculate_Tax(total_wages);
        printf("Your tax is %.2f $.\n", tax);
//        计算实际到手工资
        net_income = total_wages - tax;
        printf("Your net income is %.2f $.\n", net_income);
    }

    return 0;
}
void Menu_Print()
{
//        菜单部分
    printf("************************************************************************\n");
    printf("Please enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr                                1) $9.33/hr\n");
    printf("3) $10.00/hr                                4) $11.20/hr\n");
    printf("5) quit\n");
    printf("************************************************************************\n");
//        选择工作时薪
    printf("Your choice is:");
}
void Choose_BASIC_WAGE_PER_HOUR(int select_number)
{
    switch (select_number) {
        case 1:
            BASIC_WAGE_PER_HOUR = 8.75;
            break;
        case 2:
            BASIC_WAGE_PER_HOUR = 9.33;
            break;
        case 3:
            BASIC_WAGE_PER_HOUR = 10.00;
            break;
        case 4:
            BASIC_WAGE_PER_HOUR = 11.20;
            break;
    }
}
float Calculate_Total_Wage(int work_time)
{
    if (work_time <= FULL_BASIC_TIME)
        return work_time * BASIC_WAGE_PER_HOUR;
    else
        return FULL_BASIC_WAGE + (work_time - FULL_BASIC_TIME) * WORK_OVERTIME * BASIC_WAGE_PER_HOUR;
}
float Calculate_Tax(float total_wages)
{
    if (total_wages <= 300)
        return total_wages * TAX_FIRST_RATE;
    else if (total_wages > 300 && total_wages <= 450)
        return TAX_FIRST_ALL + (total_wages - TAX_FIRST_MONEY) * TAX_SECOND_RATE;
    else
        return TAX_SECOND_ALL + (total_wages - TAX_SECOND_MONEY) * TAX_Third_RATE;
}