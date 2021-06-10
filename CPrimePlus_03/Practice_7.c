#include "stdio.h"
int main(void)
{
    float People_height;
    printf("请输入您的身高（英寸）：");
    scanf("%f",&People_height);
    printf("您的身高为（厘米）：%.2f\n",People_height*2.54);
    return 0;
}