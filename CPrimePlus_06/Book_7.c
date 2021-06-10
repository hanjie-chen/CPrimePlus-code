#include "stdio.h"
int main(void)
{
    const int first_pay = 8;
    const int next_pay = 12;
    int ounces, cost;

    printf("ounces cost\n");
//    使用逗号运算符，让多个条件同时被满足
//    逗号也是一个序列点，即逗号左侧的内容发生在右侧之前
    for (ounces = 1, cost = first_pay;ounces < 16; ++ounces, cost += next_pay) {
        printf("%-5d $%4.2f\n", ounces, cost / 100.0);
    }

    return 0;
}