#include <stdio.h>

#define ROWS 3
#define COLS 5

void init_array_2d(int rows, int cols, double array[rows][cols]);
void show_array_2d(int rows, int cols, const double array[rows][cols]);
void calculate_group_average(int rows, int cols, const double array[rows][cols]);
double calculate_average(int n, const double array[n]);
double calculate_total_average(int rows, int cols, const double array[rows][cols]);
double find_max_array(int rows, int cols, const double array[rows][cols]);

int main(void)
{
    double array[ROWS][COLS];

    printf("Please enter three group data and every group contain five double number.\n");
    init_array_2d(ROWS, COLS, array);
//    show_array_2d(ROWS, COLS, array);
    for (int i = 0; i < ROWS; ++i) {
        printf("The average of line %d is %.2f.\n", i + 1, calculate_average(COLS, array[i]));
    }
    printf("The average of array is %.2f.\n", calculate_total_average(ROWS, COLS, array));
    printf("The max of the array is %.2f.\n", find_max_array(ROWS, COLS, array));

    return 0;
}
void init_array_2d(int rows, int cols, double array[rows][cols])
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%lf", &array[i][j]);
        }
    }
}
void show_array_2d(int rows, int cols, const double array[rows][cols])
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%.2f ", array[i][j]);
        }printf("\n");
    }
}
void calculate_group_average(int rows, int cols, const double array[rows][cols])
{
    int i, j;
    double sub_total = 0;

    for (i = 0; i < rows; ++i)
    {
        for (j = 0, sub_total = 0; j < cols; ++j) {
            sub_total += array[i][j];
        }
        printf("The average of line %d is %.2f.\n", i + 1, (sub_total / (float) cols));
    }
}
double calculate_average(int n, const double array[n])
{
    double average = 0;
    double total = 0;

    for (int i = 0; i < n; ++i) {
        total += array[i];
    }
    average = (total / (float) n);

    return average;
}
double calculate_total_average(int rows, int cols, const double array[rows][cols])
{
    double total = 0;
    double average = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            total += array[i][j];
        }
    }
    average = total / (rows * cols);

    return average;
}
double find_max_array(int rows, int cols, const double array[rows][cols])
{
    double max = array[0][0];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (max < array[i][j])
                max = array[i][j];
        }
    }

    return max;
}