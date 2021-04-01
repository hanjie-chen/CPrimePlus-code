#include <stdio.h>
void Inter_Change(int* number_first, int* number_second);
int main(void)
{
    int number_first = 5, number_second = 10;

    printf("Originally number_first is %d and number_second is %d.\n", number_first, number_second);
    Inter_Change(&number_first, &number_second);
    printf("Now number_first is %d and number_second is %d.\n", number_first, number_second);

    return 0;
}
void Inter_Change(int* number_first, int* number_second)
{
    int temp;

    temp = *number_first;
    *number_first = *number_second;
    *number_second = temp;
}