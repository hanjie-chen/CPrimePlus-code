#include <stdio.h>
#define ROWS 3
#define COLS 4
void init_array(double array[][COLS], int n);
void show_array(const double array[][COLS], int n);
void copy_array(const double source[], double target[], int n);

int main(void)
{
    double source[ROWS][COLS];
    double target[ROWS][COLS];

    init_array(source, ROWS);
    show_array(source, ROWS);
    copy_array(source[0], target[0], COLS);
    copy_array(source[1], target[1], COLS);
    copy_array(source[2], target[2], COLS);
    printf("*******************************************\n");
    show_array(target, ROWS);

    return 0;
}
void init_array(double array[][COLS], int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < COLS; ++j) {
            array[i][j] = (i + j) / 7.0;
        }
    }
}
void show_array(const double array[][COLS], int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%.2f ", array[i][j]);
        }printf("\n");
    }
}
void copy_array(const double source[], double target[], int n)
{
    for (int i = 0; i < n; ++i) {
        target[i] = source[i];
    }
}