#include "stdio.h"
#define American_Europe (3.785/1.609)*100
int main(void)
{
    float distance,gasoline;
    printf("请输入您行驶的距离：（单位：英里）");
    scanf("%f",&distance);
    printf("请输入您消耗的汽油量：（单位：加仑）");
    scanf("%f",&gasoline);
    printf("您每加仑汽油行驶的路程为：%.1f（英里），即每100公里消耗%.1f升汽油\n",distance/gasoline,(gasoline/distance)*American_Europe);

    return 0;
}