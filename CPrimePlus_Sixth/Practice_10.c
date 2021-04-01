#include "stdio.h"
int calculate_sum(int low_number, int up_number);
int main(void)
{
    int low_number, up_number;

    printf("Enter lower and upper integer limits:");
    scanf("%d %d", &low_number, &up_number);
    printf("The sums of the squares from %d to %d is %d\n",
            low_number * low_number, up_number * up_number, calculate_sum(low_number, up_number));

    printf("Enter the next set of limits:");
    scanf("%d %d", &low_number, &up_number);
    for ( ; low_number != up_number;printf("Enter the next set of limits:"), scanf("%d %d", &low_number, &up_number)) {
        printf("The sums of the squares from %d to %d is %d\n",
               low_number * low_number, up_number * up_number, calculate_sum(low_number, up_number));
    }
    printf("Done\n");

    return 0;
}
int calculate_sum(int low_number, int up_number)
{
    int sum = 0;

    for (int i = low_number; i <= up_number; ++i) {
        sum += i * i;
    }

    return sum;
}