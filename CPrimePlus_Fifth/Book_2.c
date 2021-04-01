#include "stdio.h"
int main(void)
{
    int n = 0;
    size_t intsize; //size_t是一个无符号整形数，但并不是一个新类型，而是通过typedef来定义的，如果系统不支持%zd可以使用%u\%lu来替换

    intsize = sizeof(int);
    printf("n = %d, n has %zd bytes; all ints have %zd bytes.\n", n, sizeof(n), intsize);

    return 0;
}