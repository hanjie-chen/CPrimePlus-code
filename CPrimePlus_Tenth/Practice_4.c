#include <stdio.h>
#define SIZE 10
int Find_Max_subscripts(const double array[], int n);
int main(void)
{
    double array[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        array[i] = i * i / 3.0;
    }
    printf("The subscripts of max number in array is %d.\n", Find_Max_subscripts(array, SIZE));

    return 0;
}
int Find_Max_subscripts(const double array[], int n)
{
    int i;
    int max_subscripts;
    double max;

    for (i = 1, max = array[0], max_subscripts = 0; i < n; ++i) {
        if (max < array[i])
        {
            max = array[i];
            max_subscripts = i;
        }
    }

    return max_subscripts;
}