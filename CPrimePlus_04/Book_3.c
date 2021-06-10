#include "stdio.h"
#define TAXRATE 0.015 //注意，这里定义一个常量尽量使用大写来表示
int main(void)
{
    float pay;
    const int Mouths = 12;
    printf("请问你花费了多少钱？");
    scanf("%f",&pay);
    printf("您需要上交%.2f的税。\n",pay * TAXRATE);
    printf("一年有%d个月",Mouths);
    return 0;
}