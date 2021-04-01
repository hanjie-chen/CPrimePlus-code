#include "stdio.h"
#include "stdbool.h"
_Bool Judge_Prime(int number);
int main(void)
{
    int number;
    int count = 0;

    printf("Please enter a positive integer:");
    scanf("%d", &number);
//    用于判断输入的是否为正整数，如果不是那么一直输入到正整数为止
    while (1)
    {
        if (number > 0)
            break;
        else
        {
            printf("Please enter a positive integer:");
            scanf("%d", &number);
        }
    }
//    使用判断函数判断每一个数是不是素数
    for (int i = 2; i <= number; ++i) {
        if (Judge_Prime(i))
        {
            count++;
            printf("%4d ", i);
            if (count == 10)
            {
                printf("\n");
                count = 0;
            }
        }
    }

    return 0;
}
_Bool Judge_Prime(int number)
{
    _Bool judge_prime = true;

    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0)
        {
            judge_prime = false;
        }
    }

    return judge_prime;
}