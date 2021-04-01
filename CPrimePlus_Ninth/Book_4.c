#include "stdio.h"
void Up_And_Down(int number);
int main(void)
{
    Up_And_Down(1);
    return 0;
}
// 注意：每一层次的递归调用的number都是该层次私有的（可以从地址中看出）
void Up_And_Down(int number)
{
    printf("Level %d: number location is %p.\n", number, &number);
    if (number < 4)
        Up_And_Down(number + 1);
    printf("Level %d: number location is %p.\n", number, &number);
}