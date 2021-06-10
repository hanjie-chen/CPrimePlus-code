#include <stdio.h>
#include <stdlib.h>

#define SIZE 40

void fill_array(double array[], int n);
void show_array(double array[], int n);
int my_compare(const void *, const void *);

int main(void)
{
    double values[SIZE];

    fill_array(values, SIZE);
    puts("Random list:");
    show_array(values, SIZE);
    qsort(values, SIZE, sizeof(double ), my_compare);
    puts("\nSorted lists:");
    show_array(values, SIZE);

    return 0;
}
void fill_array(double array[], int n)
{
    for (int i = 0; i < n; ++i)
        array[i] = (double)rand() / ((double) rand() + 0.1);
}
void show_array(double array[], int n)
{
    for (int i = 0; i < n; ++i) {
        printf("%9.4f ", array[i]);
        if (i % 6 == 5)
            putchar('\n');
    }
    if (n % 6 == 0)
        putchar('\n');
}
int my_compare(const void * p1, const void * p2)
{
//    强制转换为double类型的数好用于比较
    const double * value1 = (const double *)p1;
    const double * value2 = (const double *)p2;

    if (*value1 < *value2)
        return -1;
    else if (*value1 == *value2)
        return 0;
    else
        return 1;
}