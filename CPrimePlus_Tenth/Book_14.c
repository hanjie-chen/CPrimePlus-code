#include <stdio.h>
int main(void)
{
    const int number = 13;
    int * p1 = &number;

    *p1 = 10;
    printf("The number is %d\n", *p1);
    printf("The number is %d\n", number);
    printf("the address of p1 is %p and the address is number is %p\n", p1, &number);
    if (*p1 == number)
        printf("1\n");
    else
        printf("0\n");

    return 0;
}