/* 赋值运算符中 x += 20 与 x = x + 20是一样的意思
 * 同理 %= *= /= ...
 * 使用这样的形式会让代码更加的紧凑，并且生成的机器代码更加的高效
 * */
#include "stdio.h"
int main(void)
{
    int number = 20;

    number += 20;
    printf("%d\n", number);
    number %= 3;
    printf("%d\n", number);
    number *= 20;
    printf("%d\n", number);
    number /= 7;
    printf("%d\n", number);

    return 0;
}