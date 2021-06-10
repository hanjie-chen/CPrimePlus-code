#include "stdio.h"
unsigned long int Fibonacci(unsigned long int number);
int main(void)
{
    unsigned long int sequence_number;

    printf("This program is calculate Fibonacci array.\n");
    printf("Please enter a sequence:(q to quit)");
    while (1 == scanf("%ld", &sequence_number))
    {
        printf("The Fibonacci number is %ld\n", Fibonacci(sequence_number));
        printf("Please enter a sequence:(q to quit)");
    }
    printf("Done~.\n");

    return 0;
}
// 这个函数是双递归的形式 也就是说调用自己的话变量的数量会以指数的方式来消耗内存
// 所以当这个太大的时候回需要等很长的时间 在追求效率的程序中最好慎重考虑递归
unsigned long int Fibonacci(unsigned long int number)
{
    unsigned long int result;

//    使用数学定义的方式来描述
    if (number > 2)
        result = Fibonacci(number -1) + Fibonacci(number - 2);
    else
        result = 1;

    return result;
}