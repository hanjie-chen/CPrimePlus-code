#include <stdio.h>

#define ROWS 3
#define COLS 5
#define STARS "****************************"

void init_array_2d(int rows, int cols, double array[rows][cols]);
void show_array_2d(int rows, int cols, const double array[rows][cols]);
void copy_array_2d(int rows, int cols, const double source[rows][cols], double target[rows][cols]);

int main(void)
{
    double source[ROWS][COLS];
    double target[ROWS][COLS];
//    初始化源数组
    init_array_2d(ROWS, COLS, source);
//    显示初始化源数组
    printf("%s\n", STARS);
    printf("源数组如下所示：\n");
    printf("%s\n", STARS);
    show_array_2d(ROWS, COLS, source);
//    拷贝数组到目标数组中去
    copy_array_2d(ROWS, COLS, source, target);
//    显示目标数组
    printf("%s\n", STARS);
    printf("目标数组如下所示：\n");
    printf("%s\n", STARS);
    show_array_2d(ROWS, COLS, target);

    return 0;
}
void init_array_2d(int rows, int cols, double array[rows][cols])
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = (i + j) * 7.0 / 9.0;
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
void copy_array_2d(int rows, int cols, const double source[rows][cols], double target[rows][cols])
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            target[i][j] = source[i][j];
        }
    }
}