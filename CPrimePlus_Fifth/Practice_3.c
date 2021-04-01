#include "stdio.h"
const int WEEk = 7;
int main(void)
{
    int total_days;
    printf("请输入总共的天数：");
    scanf("%d",&total_days);
    while (total_days > 0)
    {
        printf("是第%d周的第%d天\n", total_days / WEEk, total_days % WEEk);
        printf("要不要再试一次？（不要的话输入一个0或者0以下的值即可哦）：");
        scanf("%d", &total_days);
    }
    printf("Bye~\n");
    return 0;
}