#include <stdio.h>
#include <stdlib.h>
#include "Practice_7.h"

// 用于记录投掷了几次
int roll_count = 0;
// 用于计算每次投掷出了哪个点数
static int roll(int sides)
{
    int roll;

    roll = rand() % sides + 1;
    ++roll_count;

    return roll;
}
// 用于计算所有骰子都投掷一次 每次的面数之和
int roll_n_dice(int dice_count, int sides)
{
    int total = 0;
//    如果骰子的面数小于2
    if (sides < 2)
    {
        puts("Need at least 2 sides");
        return -2;
    }
//    如果骰子的个数小于1
    if (dice_count < 1)
    {
        puts("Need at least 1 dice");
        return -1;
    }
    for (int i = 0; i < dice_count; ++i)
        total += roll(sides);

    return total;
}
void Error_Print(void)
{
    puts("Please try again.");
    puts("How many sides ? Enter 0 to quit.");
}