#include "stdio.h"
#include "math.h"
double calculate(double number_first, double number_second);
int main(void)
{
    double number_first, number_second;

    while (scanf("%lf %lf", &number_first, &number_second) == 2)
        printf("%lf\n", calculate(number_first, number_second));

    return 0;
}
double calculate(double number_first, double number_second)
{
    double result;

    result = fabs(number_first - number_second) / (number_first * number_second);

    return result;
}