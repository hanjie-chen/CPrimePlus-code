#include <stdio.h>
int main(void)
{
//    编译器自动匹配初始化大小
    const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31};

    for (int i = 0; i < (sizeof(days) / sizeof(days[0])); ++i) {
        printf("Mouth %d has %d days\n", i + 1, days[i]);
    }

    return 0;
}