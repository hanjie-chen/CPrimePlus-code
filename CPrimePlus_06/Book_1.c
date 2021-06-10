/* 对于比较浮点数最好使用>, <来比较不要有等号的存在，因为浮点数舍入误差会导致原本相等的数字不相等
 * 对于这种情况，最好使用fabs函数来判断
 * */
#include "stdio.h"
#include "math.h"
int main(void)
{
    const double ANSWER = 3.14159;
    double response;
    printf("What's the value to the pi ?\n");
    scanf("%lf", &response);
    while (fabs(ANSWER - response) > 0.0001)
    {
        printf("Try Again!\n");
        scanf("%lf", &response);
    }
    printf("Close enough.\n");
    return 0;
}