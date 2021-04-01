#include "stdio.h"
#define Dunbar_Number 150
int main(void)
{
    int friends = 5;
    int weeks;

    for (weeks = 1;friends <= Dunbar_Number; ++weeks) {
        friends -= weeks;
        friends *= 2;
        printf("第%d周博士的friends数量为：%d\n", weeks, friends);
    }

    return 0;
}