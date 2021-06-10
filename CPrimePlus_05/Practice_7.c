#include "stdio.h"
double Calculate_Cube(double initial);
int main(void)
{
    double calculate_cube;
    scanf("%lf", &calculate_cube);
    printf("%lf\n", Calculate_Cube(calculate_cube));
    return 0;
}
double Calculate_Cube(double initial)
{
    return initial * initial *initial;
}