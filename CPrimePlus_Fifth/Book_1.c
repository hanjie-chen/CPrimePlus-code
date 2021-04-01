#include "stdio.h"
#include "limits.h"
#define SQUARES 64
int main(void)
{
    const double CROP = 2E16;
    double current,total;
    int count = 1;
    current = total = 1.0;
    printf("第几个格子   格子上的谷物数量    目前一共有几个谷物   占世界总量\n");
    while (count < SQUARES)
    {
        printf("%4d     %13.2e      %12.2e  %12.2e\n",count, current, total, total / CROP);
        count = count + 1;
        current = current * 2.0;
        total = total + current;
    }
    printf("Yeah,that's all\n");
    return 0;
}