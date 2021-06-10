#include "stdio.h"
int main(void)
{
    double up_number;
    double sum = 0;
    printf("请输入一个他们的极限值：");
    scanf("%lf", &up_number);
    while (up_number > 0)
    {
        for (double i = 1.0; i <= up_number; ++i) {
            sum += 1.0 / i;
        }
        printf("%lf\n", sum);
        sum = 0;
        for (double i = 1.0; i <= up_number; ++i) {
            if ((int)i % 2 == 0)
                sum -= 1.0 / i;
            else
                sum += 1.0 / i;
        }
        printf("%lf\n", sum);
        printf("请输入一个他们的极限值：");
        scanf("%lf", &up_number);
    }
    printf("Bye~\n");

    return 0;
}