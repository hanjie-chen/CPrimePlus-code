#include "stdio.h"
int main(void)
{
    int number;
    int even_sum = 0;
    int odd_sum = 0;
    unsigned int even_count = 0;
    unsigned int odd_count = 0;

    scanf("%d", &number);
    while (number != 0)
    {
        if (number % 2 ==0)
        {
            even_count++;
            even_sum += number;
        }
        else
        {
            odd_count++;
            odd_sum += number;
        }

        scanf("%d", &number);
    }
    if (even_count != 0 && odd_count !=0)
        printf("The number of even is %d and average is %.2f, the number of odd is %d and average is %.2f",
               even_count, (float)even_sum / even_count, odd_count, (float)odd_sum / odd_count);
    else if (even_count == 0)
        printf("The number of even is %d and average is 0.00, the number of odd is %d and average is %.2f",
               even_count, odd_count, (float)odd_sum / odd_count);
    else if (odd_count == 0)
        printf("The number of even is %d and average is %.2f, the number of odd is %d and average is 0.00",
               even_count, (float)even_sum / even_count, odd_count);
    return 0;
}