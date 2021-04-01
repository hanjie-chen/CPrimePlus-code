#include <stdio.h>

int main(void)
{
    const int number1 = 6;
//    volatile修饰符让程序只从内存中读取数值 不让其对变量进行优化
    volatile int number2 = 8;
    const volatile int number3 = 10;


    printf("%d\n", number1);
    printf("%d\n", number2);
    printf("%d\n", number3);

    return 0;
}