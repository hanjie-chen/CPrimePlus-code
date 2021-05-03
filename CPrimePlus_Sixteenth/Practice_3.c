#include <stdio.h>
#include <math.h>

#define Pi (4 * atan(1)) // 定义π

typedef struct {
    double angle;   // 角度
    double radius;  // 半径长度
}Polar_Coordinate;
typedef struct {
    double x_axis;  // x 轴
    double y_axis;  // y 轴
}Rectangle_Coordinate;

Rectangle_Coordinate Polar_to_Rect(Polar_Coordinate);

int main(void)
{
    Polar_Coordinate input;
    Rectangle_Coordinate output;

    puts("This program will change the polar coordinate to rectangle coordinate");
    puts("Please enter the radius and the angle(0~360):");
    while (scanf("%lf %lf", &input.radius, &input.angle) == 2)
    {
        output = Polar_to_Rect(input);
        printf("The x-axis is %.2f and the y-axis is %.2f\n", output.x_axis, output.y_axis);
        puts("Please enter the radius and the angle(0~360):(q to quit)");
    }
    puts("Bye~");

    return 0;
}
Rectangle_Coordinate Polar_to_Rect(Polar_Coordinate input)
{
    Rectangle_Coordinate result;
    double radian;

    radian = (input.angle / 180) * Pi;          // 角度值转变为弧度制
    result.x_axis = input.radius * cos(radian); // cos函数接受弧度
    result.y_axis = input.radius * sin(radian); // sin函数接受弧度

    return result;
}