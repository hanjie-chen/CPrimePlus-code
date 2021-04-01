#include "stdio.h"
float wage_line;
float full_tax_revenue;
//两种税率
#define LOW_TAX 0.15
#define HIGH_TAX 0.28
//单身汉纳税类别
#define BACHELOR_WAGE_LINE 17850
#define BACHELOR_FULL_TAX_REVENUE BACHELOR_WAGE_LINE * LOW_TAX
//户主纳税类别
#define HOUSEHOLDER_WAGE_LINE 23900
#define HOUSEHOLDER_FULL_TAX_REVENUE HOUSEHOLDER_WAGE_LINE * LOW_TAX
//已婚公有纳税类别
#define MARRIED_WAGE_LINE 29750
#define MARRIED_FULL_TAX_REVENUE MARRIED_WAGE_LINE * LOW_TAX
//已婚离异纳税类别
#define DIVORCE_WAGE_LINE 14875
#define DIVORCE_FULL_TAX_REVENUE DIVORCE_WAGE_LINE * LOW_TAX
void Menu_Print();
void Choose_Wage_And_Revenue(int marital_status);
float Calculate_Tax(float total_wage);
int main(void)
{
    int marital_status;
    float total_wage;
    float tax;

    while (1)
    {
//        打印菜单栏, 并且让用户选择自己的婚姻状态
        Menu_Print();
        scanf("%d", &marital_status);
        if (marital_status == 5)
            break;
//        根据婚姻状态选择出纳税种类
        Choose_Wage_And_Revenue(marital_status);
//        输入用户总收入
        printf("Please enter your total wage:");
        scanf("%f", &total_wage);
//        计算用户需要上交多少税收
        tax = Calculate_Tax(total_wage);
        printf("The tax you have to pay are %.2f\n", tax);
    }
    printf("Bye~.\n");

    return 0;
}
void Menu_Print()
{
    printf("*******************************************************************\n");
    printf("1:Bachelor                                      2:House holder\n");
    printf("3:Married                                       4:Divorced\n");
    printf("5:quit\n");
    printf("*******************************************************************\n");
    printf("Please enter number to choose your Marital status:");
}
void Choose_Wage_And_Revenue(int marital_status)
{
    switch (marital_status) {
        case 1:
            wage_line = BACHELOR_WAGE_LINE;
            full_tax_revenue = BACHELOR_FULL_TAX_REVENUE;
            break;
        case 2:
            wage_line = HOUSEHOLDER_WAGE_LINE;
            full_tax_revenue = HOUSEHOLDER_FULL_TAX_REVENUE;
            break;
        case 3:
            wage_line = MARRIED_WAGE_LINE;
            full_tax_revenue = MARRIED_FULL_TAX_REVENUE;
            break;
        case 4:
            wage_line = DIVORCE_WAGE_LINE;
            full_tax_revenue = DIVORCE_FULL_TAX_REVENUE;
            break;
    }
}
float Calculate_Tax(float total_wage)
{
    if (total_wage < wage_line)
        return total_wage * LOW_TAX;
    else
        return full_tax_revenue + (total_wage - wage_line) * HIGH_TAX;
}