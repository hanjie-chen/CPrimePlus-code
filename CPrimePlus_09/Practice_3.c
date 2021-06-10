#include <stdio.h>
double Calculate_Harmonic(double number_1, double number_2);
int main(void)
{
    double number_first, number_second;

    printf("This program calculate the harmonic number of two numbers.\n");
    printf("Please enter two numbers:");
    while (2 != scanf("%lf %lf", &number_first, &number_second))
    {
        printf("Please enter two number without character.\n");
//        下面这个是用于消除错误输入的 和scanf("%*s")不同的是这个是读取到\n停止的 而scanf是读取到空格就停止了
        while (getchar() != '\n')
            continue;
    }
    printf("The Harmonic number of %lf and %lf is %lf.\n", number_first, number_second, Calculate_Harmonic(number_first, number_second));

    return 0;
}
double Calculate_Harmonic(double number_1, double number_2)
{
    double reciprocal_1, reciprocal_2, average;
    double result;

    reciprocal_1 = 1.0 / number_1;
    reciprocal_2 = 1.0 / number_2;
    average = (reciprocal_1 + reciprocal_2) / 2.0;
    result = 1.0 / average;

    return result;
}