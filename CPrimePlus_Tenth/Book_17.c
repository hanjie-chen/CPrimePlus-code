#include <stdio.h>
#define ROWS 3
#define COLS 4
// 该函数可以计算变长数组和正常数组的综合值
int sum_array(int rows, int cols, int array[rows][cols]);
int main(void)
{
    int rows = 3;
    int cols = 10;
    int junks[ROWS][COLS] = {
            {2, 4, 6, 8},
            {3, 5, 7, 9},
            {12, 10, 8, 6}
    };
    int vla[rows][cols];
//    初始化变长数组
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            vla[i][j] = i * j + j;

    printf("3*4 array\n");
    printf("Sum of elements = %d\n", sum_array(ROWS, COLS, junks));

    printf("3*10 VLA\n");
    printf("Sum of elements = %d\n", sum_array(rows, cols, vla));

    return 0;
}
int sum_array(int rows, int cols, int array[rows][cols])
{
    int result = 0;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result += array[i][j];

    return result;
}