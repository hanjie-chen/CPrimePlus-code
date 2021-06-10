#include <stdio.h>
#include <math.h>

#define SIZE 10

void Init_Array(double array[], int size);
void transform(double source[], double target[], int size, double (*pf)(double));
void Show_Array(double array[], int size);

int main(void)
{
    double source[SIZE], target[SIZE];

    Init_Array(source, SIZE);
    Show_Array(source, SIZE);
    transform(source, target, SIZE, sin);
    Show_Array(source, SIZE);
    Show_Array(target, SIZE);
    transform(source, target, SIZE, sqrt);
    Show_Array(source, SIZE);
    Show_Array(target, SIZE);

    return 0;
}
void transform(double source[], double target[], int size, double (*pf)(double))
{
    for (int i = 0; i < size; ++i)
        target[i] = pf(source[i]);
}
void Init_Array(double array[], int size)
{
    for (int i = 0; i < size; ++i)
        array[i] = i * i / 3.0;
}
void Show_Array(double array[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%.2f ", array[i]);
    printf("\n");
}