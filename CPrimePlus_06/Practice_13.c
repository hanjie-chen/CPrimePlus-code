#include "stdio.h"
#define SIZE 8
int main(void)
{
    int number[SIZE];
    int j;
    number[0] = 1;

    for (int i = 1; i < 8; ++i)
        number[i] = number[i - 1] * 2;
    j = 7;
    do{
        printf("%d ", number[j]);
        --j;
    }while (j >= 0);

    return 0;
}