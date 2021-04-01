#include <stdio.h>
#define SIZE 4
int main(void)
{
    short dates[SIZE];
    short * pt_dates;
    double bills[SIZE];
    double * pt_bills;

    pt_dates = dates;
    pt_bills = bills;
    printf("%23s %15s\n", "short", "double");
//    指针+1增加的是一个存储单元 所以short是2个单位 double是8个单位
    for (int i = 0; i < SIZE; ++i)
        printf("pointers + %d : %10p %10p.\n", i, pt_dates + i, pt_bills + i);

    return 0;
}