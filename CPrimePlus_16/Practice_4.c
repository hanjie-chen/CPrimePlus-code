#include <stdio.h>
#include <time.h>

#define ARRAY_LENGTH 10000

double Time_Spend(double pre_time);

int main(void)
{
    double time_cost;
    double pre_time;
    int array[ARRAY_LENGTH];
    int count = 0;

    pre_time = (double)clock();
    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        array[i] = i * i / 2;
        if (i + 1 < ARRAY_LENGTH)
            array[i + 1] = array[i] * i;
//        增加for循环时间
        if (count < 10000000 && i % 10 == 0)
        {
            count++;
            i /= 2;
        }
    }
    putchar('\n');
    time_cost = Time_Spend(pre_time);
    printf("The time for iteration is %.7f seconds\n", time_cost);

    return 0;
}
double Time_Spend(double pre_time)
{
    double time_spend;

    time_spend = ((double)clock() - pre_time) / CLOCKS_PER_SEC;

    return time_spend;
}