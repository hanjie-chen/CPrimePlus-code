#include <stdio.h>
#define SIZE 10
int Find_Max(const int array[], int n);
int main(void)
{
    int array[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        array[i] = i;
    }
    printf("The max of array is %d\n", Find_Max(array, SIZE));

    return 0;
}
int Find_Max(const int array[], int n)
{
    int max;
    int i;

    for (max = array[0], i = 1; i < n; ++i)
        if (max < array[i])
            max = array[i];

    return max;
}