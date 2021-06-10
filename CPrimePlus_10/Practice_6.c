#include <stdio.h>
#define SIZE 10
void show_array(const double array[], int n);
void reverse_array(double array[], int n);

int main(void)
{
    double array[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        array[i] = i * i * i / 6.0;
    }
    show_array(array, SIZE);
    reverse_array(array, SIZE);
    show_array(array, SIZE);

    return 0;
}
void show_array(const double array[], int n)
{
    for (int i = 0; i < n; ++i) {
        printf("%.2f ", array[i]);
    }printf("\n");
}
void reverse_array(double array[], int n)
{
    double temp;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (array[j] < array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}