#include "stdio.h"
#include "limits.h"
int main(void)
{
    printf("limits.h中规定的最大整数为%d\n",INT_MAX);
    printf("limits.h中规定的最小整数为%d\n",INT_MIN);
    printf("limits.h中规定的unsigned int的最大值%u\n",UINT_MAX);
    printf("Limits.h中规定的最小的长整数为%lld\n",LLONG_MIN);

    return 0;
}