#include "stdio.h"
int main(void)
{
    int number;
//    可以运行，但是实际上将逗号视为逗号表达式，相当于 number = 249; 500;
    number = 249, 500;
    printf("%d\n", number);
//    整个逗号表达式的值是右侧的值
    number = (111, 222);
    printf("%d\n", number);
    return 0;
}