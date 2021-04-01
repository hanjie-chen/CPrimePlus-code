#include "stdio.h"
void To_Binary(int number);
int main(void)
{
    int number;

    printf("Please enter a integer:(q to quit)");
    while (1 == scanf("%d", &number));
    {
        printf("Binary of %d is ", number);
//        考虑到负数的情况
        if (number >= 0)
            To_Binary(number);
        else
        {
            putchar('-');
            To_Binary(-number);
        }
        putchar('\n');
        printf("Please enter a integer(q to quit):");
    }
    printf("Bye~.\n");

    return 0;
}
// 本函数可以不存储位数打印二进制数(陈某之前的实现都是用存储的形式的)
void To_Binary(int number)
{
    int judge;

    judge = number % 2;
    if (number >= 2)
        To_Binary(number / 2);
    putchar(judge == 0 ? '0' : '1');

}