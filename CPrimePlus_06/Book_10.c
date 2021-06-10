#include "stdio.h"
double power(double number, int p);
int main(void)
{
    double number;
    int exp;

    printf("Enter a number and the positive integer power");
    printf(" to which\n the number will be raised.Enter q");
    printf(" to quit.\n");

    while (scanf("%lf %d", &number, &exp) == 2)
    {
        printf("%.3g to the power %d is %.5g\n", number, exp, power(number, exp));
        printf("Enter next pair of number or q to quit.\n");
    }
    printf("Bye~");

    return 0;
}
double power(double number, int p)
{
    double pow = 1;

    for (int i = 0; i < p; ++i)
        pow *= number;

    return pow;
}