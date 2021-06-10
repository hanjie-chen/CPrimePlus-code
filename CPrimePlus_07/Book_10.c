#include "stdio.h"
int main(void)
{
    int number;

//    C语言并不推荐使用goto语句, 因为goto语句容易导致混乱, 因为C语言可是使用其他的方式来代替。
//    但是在BASIC语言和FORTRAN语言中国goto语言是不可或缺的, 因为这两种语言中没有复合语句, 即花括号括成的内容为一条语句
//    实际上break和continue是goto语句的特殊形式
    printf("Please enter a number:");
    scanf("%d", &number);
    if (number > 12)
        goto part1;
    else
        goto part2;
    part1: printf("CHJ666\n");
    part2: printf("CHJ777\n");

    return 0;
}