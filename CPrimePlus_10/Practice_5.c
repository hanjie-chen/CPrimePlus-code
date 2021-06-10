#include <stdio.h>
#define SIZE 10
double subtraction_array(const double array[], int n);
void show_array(const double array[], int n);
int main(void)
{
    double array[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        array[i] = i * i / 5.0 ;
    }
    show_array(array, SIZE);
    printf("The subtraction of array max and min is %.3f\n", subtraction_array(array, SIZE));

    return 0;
}
double subtraction_array(const double array[], int n)
{
    int i;
    double min, max;
    double subtraction;

    for (i = 1, min = max = array[0]; i < n; ++i)
    {
        if (min > array[i])
            min = array[i];
        if (max < array[i])
            max = array[i];
    }
    subtraction = max - min;

    return subtraction;
}
void show_array(const double array[], int n)
{
    for (int i = 0; i < n; ++i) {
        printf("%.2f ", array[i]);
    }printf("\n");
}