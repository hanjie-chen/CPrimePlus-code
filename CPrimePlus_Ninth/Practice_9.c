#include "stdio.h"
void To_Binary(int number);
void To_Binary_Format(int number_first, int number_second);
int main(void)
{
    int number_convert, number_format;

    printf("Please enter two integer:(q to quit)\n");
    printf("The first one is the number to be convert and the second one is the convert format\n");
//    实际上这个只需要输入一个其他的字符就会结束程序
    while (2 == scanf("%d %d", &number_convert, &number_format))
    {
        To_Binary_Format(number_convert, number_format);
        printf("\nPlease enter two integer:(q to quit)\n");
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
// 这个函数支持输入需要转换的进制数然后进行转化功能适配性更强了
void To_Binary_Format(int number_first, int number_second)
{
    int result;

    result = number_first % number_second;
//    记得这个大于等于符号 忘记了好几次
    if (number_first >= number_second)
        To_Binary_Format((number_first / number_second), number_second);
    printf("%d", result);

}