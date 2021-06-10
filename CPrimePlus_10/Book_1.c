#include <stdio.h>
#define MONTHS 12
int main(void)
{
//    使用初始化列表来初始化数组
    int days[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < MONTHS; ++i) {
        printf("Month %2d has %2d days.\n", i + 1, days[i]);
    }

    return 0;
}