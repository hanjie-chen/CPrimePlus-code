#include <stdio.h>
#define COLS 4
int sum_2d(const int array[][COLS], int rows);
int sum(const int array[], int n);
int main(void)
{
    int total1, total2, total3;
    int * pt1;
    int (* pt2)[COLS];
//    复合字面量创建数组 并且使用指针记录地址
    pt1 = (int [2]){10, 20};
    pt2 = (int [2][COLS]){{1, 2, 3, -9}, {4, 5, 6, -8}};

    total1 = sum(pt1, 2);
    total2 = sum_2d(pt2, 2);
    total3 = sum((int []){4, 4, 4, 5, 5, 5}, 6);
    printf("total1 = %d\n", total1);
    printf("total2 = %d\n", total2);
    printf("total3 = %d\n", total3);

    return 0;
}
int sum_2d(const int array[][COLS], int rows)
{
    int result = 0;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < COLS; ++j)
            result += array[i][j];

    return result;
}
int sum(const int array[], int n)
{
    int result = 0;

    for (int i = 0; i < n; ++i)
        result += array[i];

    return result;
}