#include <stdio.h>
#include "Practice_2.h"

static int compute_mode;
static int distance;
static float fuel_used;

int main(void)
{
    int mode;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        set_mode(mode);
        get_info();
        show_info();
        printf("Enter 0 for metric mode, 1 for US mode: ");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    puts("Done");

    return 0;
}

void set_mode(int mode)
{
    if (mode == 0 || mode == 1)
        compute_mode = mode;
    else
    {
        if (compute_mode == 0)
            printf("Invalid mode specified. Mode 0(metric) used.\n");
        else if (compute_mode == 1)
            printf("Invalid mode specified. Mode 1(US) used.\n");
    }
}
void get_info(void)
{
    if (compute_mode == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%d", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%f", &fuel_used);
    }
    else if (compute_mode == 1)
    {
        printf("Enter the distance traveled in miles: ");
        scanf("%d", &distance);
        printf("Enter thr fuel used int gallons: ");
        scanf("%f", &fuel_used);
    }

}
void show_info(void)
{
    if (compute_mode == 0)
        printf("Fuel consumption is %.2f liters per 100 km\n", fuel_used / (distance / 100.0));
    else if (compute_mode == 1)
        printf("Fuel consumption is %.1f miles per gallons\n", ((float)distance) / fuel_used);
}
