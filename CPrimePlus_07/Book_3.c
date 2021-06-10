#include "stdio.h"
#define RATE1 0.13230 //首次使用360kwh的费率
#define RATE2 0.15040 //然后使用108kwh的费率
#define RATE3 0.30025 //然后使用252kwh的费率
#define RATE4 0.34025 //超出720kwh的费率
#define BREAK1 360 //第一个分界点
#define BREAK2 468 //第二个分界点
#define BREAK3 720 //第三个分界点
#define BASE1 (RATE1 * BREAK1) //使用360kwh的费用
#define BASE2 (BASE1 + RATE2 * (BREAK2 - BREAK1)) //使用468kwh的费用
#define BASE3 (BASE2 + RATE3 * (BREAK3 - BREAK2)) //使用720kwh的费用
int main(void)
{
    double kwh;
    double bill;

    printf("请输入您使用了多少电：");
    scanf("%lf",&kwh);

    if (kwh <= BREAK1)
        bill = RATE1 * kwh;
    else if (kwh > BREAK1 && kwh <=BREAK2)
        bill = BASE1 + (kwh - BREAK1) * RATE2;
    else if (kwh > BREAK2 && kwh <= BREAK3)
        bill  = BASE2 + (kwh - BREAK2) * RATE3;
    else
        bill = BASE3 + (kwh - BREAK3) * RATE4;

    printf("您需要上交%.2lf的电费\n", bill);

    return 0;
}