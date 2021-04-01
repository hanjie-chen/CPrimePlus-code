#include <stdio.h>

#define ROWS 3
#define COLS 5

void show_array_2d(const int array[][COLS], int n);
void init_array_2d(int array[][COLS], int n);
void double_array_2d(int array[][COLS], int n);

int main(void)
{
    int array[ROWS][COLS];
//    初始化数组
    init_array_2d(array, ROWS);
//    显示初始化数组
    printf("原数组：\n");
    show_array_2d(array, ROWS);
//    对数组翻倍操作
    double_array_2d(array, ROWS);
//    显示翻倍之后的数组
    printf("翻倍之后的数组\n");
    show_array_2d(array, ROWS);

    return 0;
}
void show_array_2d(const int array[][COLS], int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%d ", array[i][j]);
        }printf("\n");
    }
}
void init_array_2d(int array[][COLS], int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < COLS; ++j) {
            array[i][j] = i + j * 2;
        }
    }
}
void double_array_2d(int array[][COLS], int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < COLS; ++j) {
            array[i][j] *= 2;
        }
    }
}