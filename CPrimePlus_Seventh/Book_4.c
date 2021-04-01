#include "stdio.h"
int main(void)
{
    int number;
    scanf("%d", &number);
//    如果没有花括号, else语句之和最近的一个if来匹配;
    if (number > 6)
        if (number < 12)
            printf("You're closed!.\n");
        else
            printf("Sorry, you're lose a turn.\n");
    return 0;
}