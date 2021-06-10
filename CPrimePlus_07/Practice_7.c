/* 我们定义这么多的常量,是由这个程序的性质决定的
 * 这个是一个计算税率的程序，许多的规定如果只体现在在数值上的话,虽然写出的程序会比较简单
 * 但是不好修改, 所以我们直接将其定义为常量，这样的话，只需要修改常量的值, 那么
 * 在程序中便会自动代替, 极大的方便我们后期维护和修改代码
 * 2020/9/22 陈翰杰
 * */
#include "stdio.h"
#define BASIC_WAGE_PER_HOUR 10.0
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
int main(void)
{
    int work_time;
    float total_wages;
    float tax;
    float net_income;

    printf("Please enter the work time a week(hour):");
    scanf("%d", &work_time);
    if (work_time <= FULL_BASIC_TIME)
        total_wages = work_time * BASIC_WAGE_PER_HOUR;
    else
        total_wages = FULL_BASIC_WAGE + (work_time - FULL_BASIC_TIME) * WORK_OVERTIME * BASIC_WAGE_PER_HOUR;
    printf("Your total wages is %.2f $.\n", total_wages);

    if (total_wages <= 300)
        tax = total_wages * TAX_FIRST_RATE;
    else if (total_wages > 300 && total_wages <= 450)
        tax = TAX_FIRST_ALL + (total_wages - TAX_FIRST_MONEY) * TAX_SECOND_RATE;
    else
        tax = TAX_SECOND_ALL + (total_wages - TAX_SECOND_MONEY) * TAX_Third_RATE;
    printf("Your tax is %.2f $.\n", tax);

    net_income = total_wages - tax;
    printf("Your net income is %.2f $.\n", net_income);

    return 0;
}