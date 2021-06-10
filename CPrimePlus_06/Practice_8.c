#include "stdio.h"
#include "math.h"
int main(void)
{
    double number_first, number_second;
    double result;
    while (scanf("%lf %lf", &number_first, &number_second) == 2)
    {
        result = fabs(number_first - number_second) / (number_first * number_second);
        printf("%lf\n", result);
    }
    return 0;
}