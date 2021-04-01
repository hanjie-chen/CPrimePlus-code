#include <stdio.h>
void Sort(double * number_1, double * number_2, double * number_3);
int main(void)
{
    double number_first, number_second, number_third;

    printf("This program make the biggest number in number_first and smallest in number_third, so the second one in number_second.\n");
    printf("Please enter three numbers:");
//    下面这个是对错误输入进行处理
    while (3 != scanf("%lf %lf %lf", &number_first, &number_second, &number_third))
    {
        printf("Please enter numbers without character.\n");
        while (getchar() != '\n')
            continue;
    }
    Sort(&number_first, &number_second, &number_third);
    printf("Now the number_first is %lf, the number_second is %lf, the number_third is %lf\n", number_first, number_second, number_third);

    return 0;
}
void Sort(double * number_1, double * number_2, double * number_3)
{
    double min, max, middle;

    min = max = *number_1;
    if (min >= *number_2)
    {
        min = *number_2;
        if (min >= *number_3)
            min = *number_3;
    }
    if (max <= *number_2)
    {
        max = *number_2;
        if (max <= *number_3)
            max = *number_3;
    }
    middle = (*number_1 + *number_2 + *number_3) - (min + max);

    *number_1 = min;
    *number_2 = middle;
    *number_3 = max;
}