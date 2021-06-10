/* 有关于运算符优先级的总结在书本上P126
 * 这里仅仅简单说明一下其中的一种优先级
 * */
#include "stdio.h"
int main(void)
{
    int x_bigger;
//    关系运算符的优先级比赋值运算符的要高
    x_bigger = 5 > 7;
    printf("%d\n", x_bigger);
    return 0;
}