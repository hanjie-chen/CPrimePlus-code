#include <stdio.h>
#include <stdarg.h>
// 可变形参函数
double sum(int, ...);

int main(void)
{
    double sum1, sum2;

    sum1 = sum(3, 1.1, 2.5, 13.3);
    sum2 = sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
    printf("return value for sum(3, 1.1, 1.2, 1.3) is %g\n", sum1);
    printf("return value for sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1) is %g\n", sum2);

    return 0;
}
double sum(int count, ...)
{
    va_list ap; // 声明对象存储参数
    double result = 0;
//    把ap初始化为参数列表
    va_start(ap, count);
    for (int i = 0; i < count; ++i)
        result += va_arg(ap, double); // 逐个读取列表中每一项
//    清理列表 释放动态内存分配的空间
    va_end(ap);

    return result;
}