#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void show_array(const double array[], int n);
double * new_dynamic_array(int n, ...);

int main(void)
{
    double * p1;
    double * p2;

    p1 = new_dynamic_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_dynamic_array(4, 100.0, 20.0, 8.08, -1890.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);

    return 0;
}
void show_array(const double array[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%.2f ", array[i]);
    putchar('\n');
}
double * new_dynamic_array(int n, ...)
{
    double * result;
    va_list ap; // 声明一个存储参数的对象

    result = (double *) malloc(n * sizeof(double));
    va_start(ap, n); // 把对象初始化对列表参数
//    检索所有的n个double类型的参数
    for (int i = 0; i < n; ++i)
        result[i] = va_arg(ap, double );
    va_end(ap); // 清理工作

    return result;
}