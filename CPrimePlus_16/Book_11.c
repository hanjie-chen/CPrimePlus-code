#include <stdio.h>
#include <math.h>

#define RAD_TO_DEG (180 / (4 * atanl(1)))
// 泛型平方根函数 根据传入的参数类型自动选择使用的平方根函数
#define SQRT(X) _Generic((X), long double: sqrtl, float: sqrtf, default:sqrt)(X)
// 泛型sin函数 根据传入的参数的类型自动选择不同的sin函数
#define SIN(X) _Generic((X),\
long double: sinl((X) / RAD_TO_DEG),\
float: sinf((X) / RAD_TO_DEG),\
default: sin((X) / RAD_TO_DEG))

int main(void)
{
    float x = 45.0f;
    double xx = 45.0;
    long double xxx = 45.0L;

    long double y = SQRT(x);
    long double yy = SQRT(xx);
    long double yyy = SQRT(xxx);

    printf("%.17Lf\n", y);
    printf("%.17Lf\n", yy);
    printf("%.17Lf\n", yyy);

    int i = 45;
    yy = SQRT(i);
    printf("%.17Lf\n", yy);
    yyy = SIN(xxx);
    printf("%.17Lf\n", yyy);

    return 0;
}