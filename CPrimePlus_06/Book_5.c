/* 本案例讲解for循环的几种不同的用法
 * */
#include "stdio.h"
int main(void)
{
//    使用字符串递增
    for (char i = 'a'; i <= 'z'; ++i) {
        printf("%c ", i);
    }printf("\n");
//    递增数不一定为1
    for (int i = 0; i < 20; i = i + 2) {
        printf("%d ", i);
    }printf("\n");
//    可以省去一个或者是多个表达式,主义省去第二个表达式，会被视为条件为真，会进入死循环
    for (int i = 1; i < 25; ) {
        i = i * 2;
        printf("%d ", i);
    }printf("\n");
//    第一个表达式不一定为赋值表达式，但是一定只会执行一次，下面这段代码会让读者一直猜数字直到6为止
    int number;
    for (printf("Keep trying numbers!\n"); number != 6; ) {
        scanf("%d", &number);
    }printf("That's the one I want!\n");

    return 0;
}