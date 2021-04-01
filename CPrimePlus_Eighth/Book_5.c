/* 本程序的优点在于良好的交互体验
 * 使用了外置函数的形式保证了main函数的简洁
 * 并且保证了用户输入错误的情况下会有正确的提示
 * 2020/10/9 陈翰杰
 * */
#include "stdio.h"
#include "stdbool.h"
long Get_Long(void);
bool Bad_Limits(long begin, long end, long low, long high);
double Sum_Square(long number_small, long number_big);
int main(void)
{
    const long MIN = -10000000L;
    const long MAX = +10000000L;
    long start;
    long stop;
    double answer;

    printf("The program computes the sum of the squares of integers in a range.\n");
    printf("The lower bound should not be less than -10000000 and the upper bound should not be more than +10000000.\n");
    printf("Enter the limits (enter both 0 to quit):\n");
    printf("lower limits:");
    start = Get_Long();
    printf("upper limits:");
    stop = Get_Long();
    while (!(start == 0 && stop == 0))
    {
        if (Bad_Limits(start, stop, MIN, MAX))
            printf("Please try again.\n");
        else{
            answer = Sum_Square(start, stop);
            printf("The sum of the squares of integers from %ld to %ld is %g.\n", start, stop, answer);
        }
        printf("Enter the limits (enter both 0 to quit):\n");
        printf("lower limits:");
        start = Get_Long();
        printf("upper limits:");
        stop = Get_Long();
    }
    printf("Bye~.\n");

    return 0;
}
long Get_Long(void)
{
    long input;
    char ch;

    while (scanf("%ld", &input) != 1)
    {
//        使用while循环
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a integer.\n");
        printf("Please enter an integer value, such as 25, -178 or 3: ");
    }

    return input;
}
bool Bad_Limits(long begin, long end, long low, long high)
{
    bool not_good = false;

    if (begin > end)
    {
        printf("%ld isn't smaller than %ld.\n", end, begin);
        not_good = true;
    }
    if (begin < low || end < low)
    {
        printf("Values must be %ld or greater.\n", low);
        not_good = true;
    }
    if (begin > high || end > high)
    {
        printf("Values must be %ld or smaller.\n", high);
        not_good = true;
    }

    return not_good;
}
double Sum_Square(long number_small, long number_big)
{
    double total = 0;
    long i;

    for (i = number_small; i <= number_big; ++i) {
        total += (double)i * (double)i;
    }

    return total;
}