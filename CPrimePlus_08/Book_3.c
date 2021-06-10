#include "stdio.h"
int main(void)
{
    int guess_number = 1;
    char respond;

    printf("Please enter an integer from 1 to 100, I will try to guess it.\n");
    printf("Respond with a y if my guess is right and with an n if my guess is wrong.\n");
    printf("Uh...is your number %d?.\n", guess_number);
    while ((respond = getchar()) != 'y')
    {
        if (respond == 'n')
            printf("Well, then, is it %d?\n", ++guess_number);
        else
            printf("Sorry, I can understand only y or n.\n");
//        跳过剩余的输入行，包括换行符
        while (getchar() != '\n')
            continue;
    }

    printf("I know I could do it.\n");

    return 0;
}