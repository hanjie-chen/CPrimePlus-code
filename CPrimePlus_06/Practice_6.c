#include "stdio.h"
int main(void)
{
    int start_number, end_number;

    printf("请输入开始的数字：");
    scanf("%d", &start_number);
    printf("请输入结束的数字");
    scanf("%d", &end_number);

    for (int i = start_number; i <= end_number ; ++i) {
        printf("-------------------\n");
        printf("|%-5d|%-5d|%-5d|\n", i, i * i, i * i * i);
    }printf("-------------------\n");

    return 0;
}