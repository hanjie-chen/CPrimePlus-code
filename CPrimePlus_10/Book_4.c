#include <stdio.h>
#define MONTHS 12
int main(void)
{
//    只把下标为5的位置的数初始化为212 C99新增特性
    int array[6] = { [5] = 212};
//    如果初始化器后面有更多的值 这些值会用于初始化后面的元素； 最后的初始化会取代之前的初始化 比如这里的二月份
    int days[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29};

    for (int i = 0; i < 6; ++i) {
        printf("%d ", array[i]);
    }printf("\n");
    for (int i = 0; i < MONTHS; ++i) {
        printf("%d %d\n", i, days[i]);
    }

    return 0;
}