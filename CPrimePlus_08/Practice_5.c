#include "stdio.h"
void Print_tips(int guess_number);
int main(void)
{
    int guess_number = 50;  //给一个初始值判断大小
    int boundary_small = 0; //记录初始最小边界
    int boundary_big = 100; //记录初始最大边界
    char respond;

    Print_tips(guess_number);
    while ((respond = getchar()) != 'y')
    {
        switch (respond) {
            case 'b':
//                如果太大，那个减小把上限变为guess_number
                boundary_big = guess_number;
                guess_number -= (guess_number - boundary_small) / 2;
                printf("Well, is it %d.\n", guess_number);
                break;
            case 's':
//                如果太小，那么把下限变为guess_number
                boundary_small = guess_number;
                guess_number += (boundary_big - guess_number) / 2;
                printf("Well, is it %d.\n", guess_number);
                break;
            default:
                printf("Sorry, I can understand only y, b, s.\n");
                break;
        }
//        跳过剩余的输入行，包括换行符
        while (getchar() != '\n')
            continue;
    }

    printf("I know I could do it.\n");

    return 0;
}
void Print_tips(int guess_number)
{
    printf("Please think an integer from 1 to 100, I will try to guess it.\n");
    printf("Respond with a y if my guess is right;\n");
    printf("Respond with a b if my guess is bigger.\n");
    printf("Respond with a s if my guess is smaller;\n");
    printf("Uh...is your number %d?.\n", guess_number);
}