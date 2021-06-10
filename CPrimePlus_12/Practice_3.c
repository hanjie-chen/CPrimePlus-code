#include <stdio.h>

void get_info(int compute_mode);

int main(void)
{
    int mode = 1;
    int pre_mode = 1;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    if (mode != 0 && mode != 1)
    {
        mode = pre_mode;
        if (mode == 0)
            puts("Invalid mode specified.Mode 0(metric) used.");
        else if (mode == 1)
            puts("Invalid mode specified.Mode 1(US) used.");
    }
    while (mode >= 0)
    {
        get_info(mode);
        printf("Enter 0 for metric mode, 1 for US mode: ");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
        if (mode != 0 && mode != 1 && mode != -1)
        {
            mode = pre_mode;
            if (mode == 0)
                puts("Invalid mode specified.Mode 0(metric) used.");
            else if (mode == 1)
                puts("Invalid mode specified.Mode 1(US) used.");
        }
        pre_mode = mode;
    }
    puts("Done");

    return 0;
}

void get_info(int compute_mode)
{
    int distance;
    float fuel_used;

    if (compute_mode == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%d", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%f", &fuel_used);
        printf("Fuel consumption is %.2f liters per 100 km\n", fuel_used / (distance / 100.0));
    }
    else if (compute_mode == 1)
    {
        printf("Enter the distance traveled in miles: ");
        scanf("%d", &distance);
        printf("Enter thr fuel used int gallons: ");
        scanf("%f", &fuel_used);
        printf("Fuel consumption is %.1f miles per gallons\n", ((float)distance) / fuel_used);
    }

}
