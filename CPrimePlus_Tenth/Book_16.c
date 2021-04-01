#include <stdio.h>
#define ROWS 3
#define COLS 4
// []表示这个是一个指针
void sum_rows(int array[][COLS], int rows);
// 在函数声明阶段可以不写变量名 在函数定义阶段必须写上去
void sum_cols(int [][COLS], int );
// 想要函数处理数组 那就传入数组的首元素地址 二维数组的首元素地址是一个一维数组
void sum_total(int (* array)[COLS], int rows);
int main(void)
{
    int junks[ROWS][COLS] = {
            {2, 4, 6, 8},
            {3, 5, 7, 9},
            {12, 10, 8, 6}
    };

    sum_rows(junks, ROWS);
    sum_cols(junks, ROWS);
    sum_total(junks, ROWS);

    return 0;
}
void sum_rows(int array[][COLS], int rows)
{
    int result;

    for (int i = 0; i < rows; ++i) {
        result = 0;
        for (int j = 0; j < COLS; ++j) {
            result += array[i][j];
        }
        printf("row %d : sum = %d\n", i, result);
    }
}
void sum_cols(int array[][COLS], int rows)
{
    int result;

    for (int i = 0; i < COLS; ++i) {
        result = 0;
        for (int j = 0; j < rows; ++j) {
            result += array[j][i];
        }
        printf("col %d : sum = %d\n", i, result);
    }
}
void sum_total(int (* array)[COLS], int rows)
{
    int result = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < COLS; ++j) {
            result += array[i][j];
        }
    }
    printf("sum of all elements is %d\n", result);
}