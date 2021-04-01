#include <stdio.h>
#define SIZE 4
int main(void)
{
//    初始化列表中的值少于数组个数时 编译器把剩余的位置都初始化为0
    int some_data[SIZE] = {1024, 2048};

    printf("%2s%14s\n", "i", "some_data[i]");
    for (int i = 0; i < 4; ++i) {
        printf("%2d%14d\n", i, some_data[i]);
    }

    return 0;
}