#include "stdio.h"
int main(void)
{
    int mice;
    mice = 1.6 + 1.7;
    printf("%d\n",mice); //自动类型转换
    mice = (int)1.6 + (int)1.7; //使用强制类型转换符
    printf("%d\n",mice);
    return 0;
}