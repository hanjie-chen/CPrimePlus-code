#include "stdio.h"
#include "float.h"
int main(void)
{
    double d_number = 1.0 / 3.0;
    float f_number = 1.0 / 3.0;
    printf("%.6f %.6f\n",d_number,f_number);
    printf("%.12f %.12f\n",d_number,f_number);
    printf("%.16f %.16f\n",d_number,f_number);
    printf("****************************************\n");
    printf("************假装是一条分割线***************\n");
    printf("****************************************\n");
    printf("float最小有效位数为：%d\n",FLT_DIG);
    printf("double最小有效位数为：%d\n",DBL_DIG);
    return 0;
}