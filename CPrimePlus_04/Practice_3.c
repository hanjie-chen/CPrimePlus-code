#include "stdio.h"
int main(void)
{
    float number;
    scanf("%f",&number);
//    printf("%f\n",number);
    printf("The input is %.1f or %.1e.\n",number,number);
    printf("The input is %+.3f or %.3E.\n",number,number);
    return 0;
}