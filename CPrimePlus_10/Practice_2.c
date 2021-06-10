#include <stdio.h>
void show_array(const double array[], int n);
void copy_array(const double source[], double target[], int n);
void copy_pointer(const double * source, double * target, int n);
void copy_pointers(const double * source_start, double * target, const double * source_end);
int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

//    show_array(source, 5);
    copy_array(source, target1, 5);
//    show_array(target1, 5);
    copy_pointer(source, target2, 5);
//    show_array(target2, 5);
    copy_pointers(source, target3, source + 5);
//    show_array(target3, 5);

    return 0;
}
void show_array(const double array[], int n)
{
    for (int i = 0; i < n; ++i) {
        printf("%.2f ", array[i]);
    }printf("\n");
}
void copy_array(const double source[], double target[], int n)
{
    for (int i = 0; i < n; ++i) {
        target[i] = source[i];
    }
}
void copy_pointer(const double * source, double * target, int n)
{
    for (int i = 0; i < n; ++i) {
        *(target + i) = *(source + i);
    }
}
void copy_pointers(const double * source_start, double * target, const double * source_end)
{
    for (const double * p = source_start; p < source_end; ++p) {
        *target = *p;
//        指针指向一下个位置 不然会一直重写原来的地方的值的大小
        target++;
    }
}