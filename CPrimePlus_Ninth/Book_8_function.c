#include <stdio.h>
#include "Book_8.h"

int menu(void)
{
    int code, status;

    printf("\n%s%s\n", STARS, STARS);
    printf("Enter the number of the desired hotel:\n");
    printf("1) Fairfield Arms       2) Hotel Olympic\n");
    printf("3) Chertworthy Plaza    4) The Stockton\n");
    printf("5) quit\n");
    printf("%s%s\n", STARS, STARS);
//    当输入不在预期之内的进入循环 修正到出现预期结果为止
    while ((status = scanf("%d", &code)) != 1 || (code < 1 || code > 5))
    {
//        下面这个是用于消除错误输入和之前的while(getchar() != '\n)相比这个是读取到空格就停止了 所以适用于读取一个数字的情况
        if (status != 1)
            scanf("%*s");
        printf("Enter a integer from 1 to 5, please.\n");
    }

    return code;
}

int get_nights(void)
{
    int nights;

    printf("How many nights are needed? ");
    while (scanf("%d", &nights) != 1)
    {
        scanf("%*s");
        printf("Please enter a integer, such as 2.\n");
    }

    return nights;
}

void show_price(double rate, int nights)
{
    double total =0.00;
    double factor=1.00;

    for (int i = 1; i < nights; ++i, factor *= DISCOUNT) {
        total += rate * factor;
    }
    printf("The total cost will be %0.2f.\n", total);
}
