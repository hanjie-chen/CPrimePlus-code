#include "stdio.h"
int main()
{
    float drink_number,drink_quality,drink_water;
    printf("请问，你刚刚喝了多少夸脱水：");
    scanf("%f",&drink_number);
    drink_quality = drink_number * 950;
    printf("你已经喝了%.2f克的水了\n",drink_quality);
    drink_water = drink_quality / (3E-23) ;
    printf("在你喝下的水中包含了%e个水分子\n",drink_water);
    return 0;
}