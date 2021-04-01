#include "stdio.h"
int main(void)
{
    int sum = 0, count = 0;
    int days;
    scanf("%d",&days);
    while (count++ < days)
        sum = sum + count;
    printf("sum = %d\n", sum);

    return 0;
}