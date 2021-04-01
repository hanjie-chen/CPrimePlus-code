#include <stdio.h>

#define ROWS 3
#define COLS 5

void init_array_2d(double array[][COLS], int n);
void show_array_2d(const double array[][COLS], int n);
void calculate_group_average(const double array[][COLS], int n);
double calculate_average(const double array[], int n);
double calculate_total_average(const double array[][COLS], int n);
double find_max_array(const double array[][COLS], int n);

int main(void)
{
    double array[ROWS][COLS];

    printf("Please enter three group data and every group contain five double number.\n");
    init_array_2d(array, ROWS);
//    show_array_2d(array, ROWS);
    for (int i = 0; i < ROWS; ++i) {
        printf("The average of line %d is %.2f.\n", i + 1, calculate_average(array[i], COLS));
    }
    printf("The average of array is %.2f.\n", calculate_total_average(array, ROWS));
    printf("The max of the array is %.2f.\n", find_max_array(array, ROWS));

    return 0;
}
void init_array_2d(double array[][COLS], int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < COLS; ++j) {
            scanf("%lf", &array[i][j]);
        }
    }
}
void show_array_2d(const double array[][COLS], int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%.2f ", array[i][j]);
        }printf("\n");
    }
}
void calculate_group_average(const double array[][COLS], int n)
{
    int i, j;
    double sub_total = 0;

    for (i = 0; i < n; ++i)
    {
        for (j = 0, sub_total = 0; j < COLS; ++j) {
            sub_total += array[i][j];
        }
        printf("The average of line %d is %.2f.\n", i + 1, sub_total / COLS);
    }
}
double calculate_average(const double array[], int n)
{
    double average = 0;
    double total = 0;

    for (int i = 0; i < n; ++i) {
        total += array[i];
    }
    average = (total / (float) n);

    return average;
}
double calculate_total_average(const double array[][COLS], int n)
{
    double total = 0;
    double average = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < COLS; ++j) {
            total += array[i][j];
        }
    }
    average = total / (ROWS * COLS);

    return average;
}
double find_max_array(const double array[][COLS], int n)
{
    double max = array[0][0];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (max < array[i][j])
                max = array[i][j];
        }
    }

    return max;
}