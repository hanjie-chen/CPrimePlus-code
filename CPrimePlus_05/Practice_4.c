#include "stdio.h"
int main(void)
{
    float height;
    int feet;
    float inches;
    printf("Enter a height in centimeters:");
    scanf("%f", &height);
    while (height > 0)
    {
        feet = (int)(height / 30.48);
        inches = (height - (feet * 30.48)) / 2.54;
        printf("%.1f cm = %d feet, %.1f inches\n", height, feet, inches);
        printf("Enter a height in centimeters(<=0 to quit):");
        scanf("%f",&height);
    }printf("Bye~\n");
    return 0;
}