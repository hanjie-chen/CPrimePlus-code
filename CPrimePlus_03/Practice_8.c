#include "stdio.h"
int main(void)
{
    float Cup_number;
    printf("请输入杯数：");
    scanf("%f",&Cup_number);
    printf("相当于%.2f品脱\n",Cup_number / 2);
    printf("相当于%.2f盎司\n",Cup_number * 8);
    printf("相当于%.2f大汤勺\n",Cup_number * 16);
    printf("相当于%.2f茶勺\n",Cup_number * 48);
    return 0;
}