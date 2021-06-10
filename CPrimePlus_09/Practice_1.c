#include <stdio.h>
double Min(double number_1, double number_2);
int main(void)
{
    double number_1, number_2;

    printf("Please enter two number and I will tell you which one is smaller.\n");
//    用于处理错误输入 当输入错误的时候回一直让你输入
    while (2 != scanf("%lf %lf", &number_1, &number_2))
    {
        scanf("%*s");
        printf("Please enter two number not character!!\n");
    }
    printf("The smaller one is %.2lf.\n", Min(number_1, number_2));

    return 0;
}
double Min(double number_1, double number_2)
{
    double min;

    min = number_1 < number_2 ? number_1 : number_2;

    return min;
}