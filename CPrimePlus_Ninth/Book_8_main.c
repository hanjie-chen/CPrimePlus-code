/* 自从知道了<> 和 ""的区别之后 才发现之前写的都是错误的
 * 这里在重新说明一下 <>是从编译器自带的库函数中寻找 ""是从本项目的路径下寻找如果没有找到的还是会从编译器自带的库函数中去寻找
 * 以后改正 以后改正
 * 2020/11/2 陈翰杰
 * */
#include <stdio.h>
#include "Book_8.h"
int main(void)
{
    int nights;
    int codes;
    double hotel_rate;

    while ((codes = menu()) != QUIT)
    {
        switch (codes) {
            case 1:hotel_rate = HOTEL1;
                break;
            case 2:hotel_rate = HOTEL2;
                break;
            case 3:hotel_rate = HOTEL3;
                break;
            case 4:hotel_rate = HOTEL4;
                break;
            default:hotel_rate = 0.0;
                printf("Oops! what's fuck");
                break;
        }
        nights = get_nights();
        show_price(hotel_rate, nights);
    }
    printf("Thank you and goodbye~.\n");

    return 0;
}
