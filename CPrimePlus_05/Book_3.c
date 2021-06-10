/* 本例讲解递增运算符：++（--递减运算符同理）
 * 递增运算符有两种，一种是前缀模式：++i;一种是后缀模式：i++;
 * 两种模式的区别在于递增行为发生的时间不同
 * 该运算符值只能影响可以修改的左值
 * */
#include "stdio.h"
int main(void)
{
    int a = 1, b = 1;
    int pre_a, b_post;
    pre_a = ++a;  //前缀：使用a的值之前递增a
    b_post = b++;  //后缀：使用b的值之后递增b
    printf("a pre_a b b_post\n");
    printf("%d %5d %d %5d\n", a, pre_a, b, b_post);
    return 0;
}