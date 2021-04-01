#include "stdio.h"
#define Hour_Minutes 60
int main(void)
{
    int total_minutes;
    printf("请输入现在经过了多久（单位：分钟）：");
    scanf("%d",&total_minutes);
    while (total_minutes > 0)
    {
        printf("经过了%d小时, %d分钟\n", total_minutes / Hour_Minutes, total_minutes % Hour_Minutes);
        printf("我们再来一次吧！（不想的话输入0或者0以下的数字即可）：");
        scanf("%d", &total_minutes);
    }
    printf("再见, Bye");
    return 0;
}