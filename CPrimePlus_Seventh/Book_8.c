#include "stdio.h"
#define COVERAGE 350 // 每罐油漆可刷的面积
int main(void)
{
    int all_area;
    int cans;

    printf("Please enter the number of the square feet to be painted(enter the 'q' to quit):\n");
    while (scanf("%d", &all_area) == 1)
    {
        cans = all_area / COVERAGE;
//        使用三元条件运算符 expression1 ? expression2 : expression3
//        如果expression为真, 那么执行expression2，为假那, 那么执行expression3
        cans += ((all_area % COVERAGE == 0)) ? 0 : 1;
        printf("You need %d %s paint.\n", cans, cans == 1 ? "can" : "cans");
        printf("Please enter the number of the square feet to be painted(enter the 'q' to quit):\n");
    }
    printf("Bye~\n");

    return 0;
}