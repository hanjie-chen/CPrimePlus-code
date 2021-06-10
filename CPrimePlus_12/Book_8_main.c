#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Book_8.h"

int main(void)
{
    int dice_count, sides_count; // 骰子数量 每个骰子的面数
    int roll_total; // 用于统计所有骰子的骰到的面数之和
    int status; // 用于记录输入函数的返回值
//    重置种子数
    srand((unsigned int) time(0));
    puts("Enter the number of sides per dice, 0 to stop.");
    while (scanf("%d", &sides_count) == 1 && sides_count > 0)
    {
        puts("How many dice ?");
//        错误处理
        if ((status = scanf("%d", &dice_count)) != 1)
        {
            if (status == EOF)
                break;
            else
            {
                puts("You should have enter a integer.");
                puts("Please try again.");
                while (getchar() != '\n')
                    continue;
                puts("How many sides ? 0 to quit");
                continue;
            }
        }
        roll_total = roll_n_dice(dice_count, sides_count);
//        对输入进行错误处理
        if (roll_total < 0)
        {
            Error_Print();
            continue;
        }
        printf("You have rolled total is %d using %d %d-sided dice.\n", roll_total, dice_count, sides_count);

        puts("How many sides ? Enter 0 to quit.");
    }
    printf("The roll() function was called %d times.\n", roll_count);
    puts("GOOD FORTUNE TO YOU!");

    return 0;
}