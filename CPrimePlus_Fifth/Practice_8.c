#include "stdio.h"
int main(void)
{
    int constant;
    int change;
    printf("This program computes moduli.\n");
    printf("Enter an integer to serve as the second operand:");
    scanf("%d", &constant);
    printf("Now enter the first operand:");
    scanf("%d", &change);
    printf("%d %% %d is %d\n", change, constant, change % constant);
    while (change > 0)
    {
        printf("Now enter the first operand:(<=0 to quit)");
        scanf("%d", &change);
//        使用两个%%来打印出一个%，因为一个%其实是一个声明，并不是一个字符
        printf("%d %% %d is %d\n", change, constant, change % constant);
    }
    return 0;
}