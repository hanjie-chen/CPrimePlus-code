#include "stdio.h"
#define SIZE 8
int main(void)
{
    double array_first[SIZE], array_second[SIZE];

    printf("请输入8个数值：\n");
    for (int i = 0; i < 8; ++i) {
        scanf("%lf", &array_first[i]);
    }
    array_second[0] = array_first[0];
    for (int i = 1; i < 8; ++i) {
        array_second[i] = array_second[i - 1] + array_first[i];
    }
//    显示两个数组，本来是想用一个函数来表达的，但是还没有看到那一块的东西
    for (int i = 0; i < 8; ++i) {
        printf("%lf ",array_first[i]);
    }printf("\n");
    for (int i = 0; i < 8; ++i) {
        printf("%lf ",array_second[i]);
    }printf("\n");

    return 0;
}