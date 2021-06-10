#include <stdio.h>
void Large_Of(double * number_1, double * number_2);
int main(void)
{
    double number_first, number_second;

    printf("This program is make two number become the same one which is bigger.\n");
    printf("Please enter two numbers:");
//    处理错误输入
    while (scanf("%lf %lf", &number_first, &number_second) != 2)
    {
        printf("Warning: Please enter two numbers not other character!!\n");
        printf("Please enter two numbers:");
        while (getchar() != '\n')
            continue;
    }
    Large_Of(&number_first, &number_second);
    printf("Now in the main function the number_first is %lf and the number_second is %lf", number_first, number_second);

    return 0;
}
void Large_Of(double * number_1, double * number_2)
{
//    方法一 使用if else语句
    if (*number_1 >= *number_2)
        *number_2 = *number_1;
    else
        *number_1 = *number_2;
//    方法二 使用三元表达式
//    *number_1 >= *number_2 ? (*number_2 = *number_1) : (*number_1 = *number_2);
}