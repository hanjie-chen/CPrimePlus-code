#include "stdio.h"
const double kelvin_centigrade = 273.16;
void Temperatures(double fahrenheit);
int main(void)
{
    double fahrenheit;
    printf("请输入一个华氏温度：");
//    scanf返回读取数据的数量，所以读取数据scanf返回1，如果不是则返回其他的
    while (scanf("%lf", &fahrenheit) == 1)
    {
        Temperatures(fahrenheit);
        printf("请输入一个华氏温度(输入q或者是其他字符退出)：");
    }
    return 0;
}
void Temperatures(double fahrenheit)
{
    double centigrade;
    double kelvin;
    centigrade = 5.0 / 9.0 * (fahrenheit - 32.0);
    kelvin = centigrade + kelvin_centigrade;
    printf("华氏温度 = %.2f℉ 摄氏温度 = %.2f℃ 开氏温度 = %.2fK\n", fahrenheit, centigrade, kelvin);
}