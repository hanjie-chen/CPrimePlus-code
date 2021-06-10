#include <stdio.h>
#define SIZE_SOURCE 7
#define SIZE_TARGET 3

void copy_pointers(const double * source_start, const double * source_end, double * target);
void init_array(double array[], int n);
void show_array(const double array[], int n);

int main(void)
{
    double source[SIZE_SOURCE];
    double target[SIZE_TARGET];

    init_array(source, SIZE_SOURCE);
    show_array(source, SIZE_SOURCE);
    copy_pointers(source + 2, source + 5, target);
    show_array(target, SIZE_TARGET);

    return 0;
}
void copy_pointers(const double * source_start, const double * source_end, double * target)
{
    for (const double * p = source_start; p < source_end; ++p) {
        *target = *p;
//        指针指向一下个位置 不然会一直重写原来的地方的值的大小
        target++;
    }
}
void init_array(double array[], int n)
{
    for (int i = 0; i < n; ++i) {
        array[i] = i * i * i / 8.0;
    }
}
void show_array(const double array[], int n)
{
    for (int i = 0; i < n; ++i) {
        printf("%.3f ", array[i]);
    }printf("\n");
}