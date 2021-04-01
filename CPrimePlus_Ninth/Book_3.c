#include "stdio.h"
// 两种形式的函数原型申明 都是ANSI C可以接受的形式
int Find_Min_type_1(int, int);
int Find_Min_type_2(int number_1, int number_2);
int main(void)
{
    int number_1, number_2;

    printf("Please enter two integers(use 'q' to quit):");
//    虽然可以将其改进为更加友好的输入界面，但是本章重点在于函数，故不做深入
    while (2 == scanf("%d %d", &number_1, &number_2))
    {
        printf("The lesser of %d and %d is %d\n", number_1, number_2, Find_Min_type_1(number_1, number_2));
        printf("Of course, it is %d, Do you think others ?\n", Find_Min_type_2(number_1, number_2));
        printf("Please enter two integers(use 'q' to quit):");
    }
    printf("Bye~.\n"); 

    return 0;
}
int Find_Min_type_1(int number_1, int number_2)
{
    int min;

    if (number_1 < number_2)
        min = number_1;
    else
        min = number_2;

    return min;
}
int Find_Min_type_2(int number_1, int number_2)
{
    int min;

    if (number_1 < number_2)
        min = number_1;
    else
        min = number_2;

    return min;
}
