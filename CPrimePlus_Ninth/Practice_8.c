#include <stdio.h>
double power_recursion(double number, int exp);
int main(void)
{
    double number, result;
    int exp;

    printf("Enter a number and the positive integer power to which.\n");
    printf("the number will be raised.Enter q to quit\n");
    while (2 == scanf("%lf%d", &number, &exp))
    {
        result = power_recursion(number, exp);
        printf("%.3g to the power %d is %.5g\n", number, exp, result);
        printf("Enter next pair of number or q to quit.\n");
    }
    printf("Hope you enjoy this power trip -- bye!\n");

    return 0;
}
double power_recursion(double number, int exp)
{
    double result = 1;
    double number_do, exp_do;

    if (exp >= 0)
    {
        if (0 == number && 0 == exp)
        {
            printf("Warning: 0的0次幂未定义！！\n");
            return 1;
        } else if (0 == number && 0 != exp)
            return 0;
        else if (0 != number && 0 == exp)
            return 1;
        else {
            number_do = number;
            exp_do = exp;
        }
    } else {
        number_do = 1 / number;
        exp_do = - exp;
    }
    result = number_do * power_recursion(number_do, exp_do - 1);

    return result;
}