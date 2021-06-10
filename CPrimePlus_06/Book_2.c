/* 使用了stdbool.h之后便可以使用bool关键字了，这样写出的代码可以喝C++兼容
 * */
#include "stdio.h"
#include "stdbool.h"
int main(void)
{
    int number;
    bool input_is_good;

    input_is_good = true;
    while (input_is_good)
    {
        printf("YES you are right\n");
        input_is_good = (scanf("%d", &number) == 1);
    }
    return 0;
}