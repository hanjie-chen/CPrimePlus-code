#include "stdio.h"
int main(void)
{
    unsigned int width,precision;
    int number = 256;
    double weight = 242.2;

    printf("Enter a field width:\n");
    scanf("%d",&width);
//    其中*表示可以用来代表前面的位数，用于控制打印出来的结果
    printf("The number is :%*d\n",width,number);
    printf("Enter a width and a precision:\n");
    scanf("%d %d",&width,&precision);
//    前一个*表示所有长度，后一个表示小数部分的长度
    printf("Weight = %*.*f\n",width,precision,weight);
    return 0;
}