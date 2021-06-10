#include <stdio.h>
// 请不要写出类似的代码 这个代码只是为例说明 当变量名相同时内层块会隐藏外层快的定义
int main(void)
{
    int number = 30;

    printf("number in outer block: %d at %p\n", number, &number);
//    内层块会隐藏外层块的定义
    {
        int number = 40; // 新的number 隐藏了原来的number
        printf("number in inner block: %d at %p\n", number, &number);
    }
    printf("number in outer block: %d at %p\n", number, &number);

    while (number++ < 33)
    {
        int number = 100; // 声明在块内的number会隐藏外层的number 并且在下次循环开始前被销毁
        number++;
        printf("number in while loop block: %d at %p\n", number, &number);
    }
    printf("number in outer block: %d at %p\n", number, &number);

    return 0;
}