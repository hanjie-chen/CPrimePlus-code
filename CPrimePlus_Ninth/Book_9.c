#include <stdio.h>
void show(int number_1);
int main(void)
{
    int number_1 = 10;
    int number_2 = 5;

    printf("In main function number_1 is %d and &number_1 is %p\n", number_1, &number_1);
    printf("In main function number_2 is %d and &number_2 is %p\n", number_2, &number_2);
    show(number_1);

    return 0;
}
void show(int number_1)
{
    int number_2 = 5;

    printf("In show function number_1 is %d and &number_1 is %p\n", number_1, &number_1);
    printf("In show function number_2 is %d and &number_2 is %p\n", number_2, &number_2);
}