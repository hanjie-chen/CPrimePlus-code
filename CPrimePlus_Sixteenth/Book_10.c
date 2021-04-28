#include <stdio.h>
#include <math.h>

#define RAD_TO_DEG (180/(4 * atan(1))) // 计算出π的大小
// 极坐标
typedef struct polar_v{
    double magnitude;
    double angle;
} Polar_V;
// 直角坐标
typedef struct rect_v {
    double x;
    double y;
} Rect_V;

Polar_V rect_to_polar(Rect_V);

int main(void)
{
    Rect_V input;
    Polar_V output;

    puts("Enter x and y coordinates; enter q to quit:");
    while (scanf("%lf %lf", &input.x, &input.y) == 2)
    {
        output = rect_to_polar(input);
        printf("magnitude = %0.2f, angle = %0.2f\n", output.magnitude, output.angle);
    }puts("Bye~");

    return 0;
}
// 直角坐标转换极坐标
Polar_V rect_to_polar(Rect_V rv)
{
    Polar_V result;

    result.magnitude = sqrt(rv.x * rv.x + rv.y * rv.y);
    if (result.magnitude == 0)
        result.angle = 0;
    else
        result.angle = RAD_TO_DEG * atan2(rv.x, rv.y); // 使用了atan2函数之后可以判断正负号

    return result;
}