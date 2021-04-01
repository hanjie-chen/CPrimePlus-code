#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Book_8.h"

int main(void)
{
    int dice_count, sides_count; // 骰子数量 每个骰子的面数
    int roll_total; // 用于统计所有骰子的骰到的面数之和
    int status; // 用于记录输入函数的返回值
    int set_times; // 用于记录这个过程重复几次

//    重置种子数
    srand((unsigned int) time(0));
    printf("Enter the number of sets; enter q to stop : ");
    while (scanf("%d", &set_times) == 1 && set_times > 0)
    {
        printf("How many sides and how many dice ? ");
//        错误处理
        if ((status = scanf("%d %d", &sides_count, &dice_count)) != 2)
        {
            if (status == EOF)
                break;
            else
            {
                puts("You should have enter two integer.");
                puts("Please try again.");
                while (getchar() != '\n')
                    continue;
                puts("How many sides and how many dice ?");
                continue;
            }
        }
        printf("Here are %d sets of %d %d-sides throws.\n", set_times, dice_count, sides_count);

        for (int i = 0; i < set_times; ++i) {
            roll_total = roll_n_dice(dice_count, sides_count);
//        对输入进行错误处理
            if (roll_total < 0)
            {
                Error_Print();
                continue;
            }
            printf("%d ", roll_total);
            if ((i + 1) % 15 == 0)
                printf("\n");
        }printf("\n");
        printf("How many sets? enter q to stop : ");
    }
    printf("The roll() function was called %d times.\n", roll_count);
    puts("GOOD FORTUNE TO YOU!");

    return 0;
}