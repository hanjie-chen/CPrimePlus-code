#include <stdio.h>
#include <stdlib.h>

#define WIDTH 30
#define HEIGHT 20

void Deal_Distortion(int array[][WIDTH], int Height);

int main(void)
{
    FILE * fp;
    int array[HEIGHT][WIDTH]; // 数字数组
    char picture[HEIGHT][WIDTH + 1]; // 存储图片的字符串数组
    char list[10] = {' ', '.', '\'', ':', '~', '*', '=', '&', '%', '#'}; // 字符数组来存储数字-字符对应列表

    if ((fp = fopen("chj", "r")) == NULL)
    {
        fprintf(stderr, "Error in opening the file chj.\n");
        exit(EXIT_FAILURE);
    }
//    读取文件里面的整形数
    for (int height = 0; height < HEIGHT; ++height)
        for (int width = 0; width < WIDTH; ++width)
            fscanf(fp, "%d", &array[height][width]);
//    对这个数据进行处理 把失真的像素点还原回去
    Deal_Distortion(array, HEIGHT);
//    使用一个对应的列表给字符数组赋值
    for (int height = 0; height < HEIGHT; ++height)
        for (int width = 0; width < WIDTH; ++width)
            picture[height][width] = list[array[height][width]];

//    给最后一个字符赋值'\0'时期成为一个字符串数组
    for (int height = 0; height < HEIGHT; ++height)
        picture[height][WIDTH] = '\0';
    fputs("The reading date is done.\n", stdout);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Error in closing the file chj.\n");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen("picture", "w")) == NULL)
    {
        fprintf(stderr, "Error in creating the file chj.picture.\n");
        exit(EXIT_FAILURE);
    }
//    使用fprintf函数吧字符串和换行符写入到文件中去。
    for (int height = 0; height < HEIGHT; ++height)
        fprintf(fp, "%s\n", picture[height]);
    fputs("The writing data is done.\n", stdout);
    if (fclose(fp) != 0)
        fprintf(stderr, "Error in closing the file chj.picture.\n");

    return 0;
}
// 这个函数是用于处理失真用的
// 原理非常简单就是计算周围的点与该点的差值之和
// 但是我感觉这个算法应该是可以被改进的 因为有很多重复计算
// 希望下次可以找时间改进这个算法 2021/3/20
void Deal_Distortion(int array[][WIDTH], int Height)
{
//    使用4个变量来记录该点和周围的上下左右的点的差值的绝对值
    int up, down, left, right;

//先处理四个角上面的点 2个相邻点
//    左上角的点
    if ((abs(array[0][0] - array[0][1]) + abs(array[0][0] - array[1][0])) > 2)
        array[0][0] = (array[0][1] + array[1][0]) / 2;
//    左下角的点
    if ((abs(array[Height - 1][0] - array[Height - 1][1]) + abs(array[Height - 1][0] - array[Height - 2][0])) > 2)
        array[Height - 1][0] = (array[Height - 1][1] + array[Height - 2][0]) / 2;
//    右上角的点
    if ((abs(array[0][WIDTH - 1] - array[0][WIDTH - 2]) + abs(array[0][WIDTH - 1] - array[1][WIDTH - 1])) > 2)
        array[0][WIDTH - 1] = (array[0][WIDTH - 2] + array[1][WIDTH - 1]) / 2;
//    右下角的点
    if ((abs(array[Height - 1][WIDTH - 1] - array[Height - 2][WIDTH - 1]) + abs(array[Height - 1][WIDTH - 1] - array[Height - 1][WIDTH - 2])) > 2)
        array[Height - 1][WIDTH - 1] = (array[Height - 2][WIDTH - 1] + array[Height - 1][WIDTH - 2]) / 2;
//然后处理在边上的点 3个相邻点
//    上面点
    for (int width = 1; width <= WIDTH - 2; ++width) {
        down = abs(array[0][width] - array[1][width]);
        left = abs(array[0][width] - array[0][width - 1]);
        right = abs(array[0][width] - array[0][width + 1]);
        if (down + left + right > 3)
            array[0][width] = (array[1][width] + array[0][width - 1] + array[0][width + 1]) / 3;
    }
//    下面点
    for (int width = 1; width <= WIDTH - 2; ++width) {
        up = abs(array[Height - 1][width] - array[Height - 2][width]);
        left = abs(array[Height - 1][width] - array[Height - 1][width - 1]);
        right = abs(array[Height - 1][width] - array[Height - 1][width + 1]);
        if (up + left + right > 3)
            array[Height - 1][width] = (array[Height - 2][width] + array[Height - 1][width - 1] + array[Height - 1][width + 1]) / 3;
    }
//    左边点
    for (int height = 1; height <= Height - 2; ++height) {
        up = abs(array[height][0] - array[height - 1][0]);
        down = abs(array[height][0] - array[height + 1][0]);
        right = abs(array[height][0] - array[height][1]);
        if (up + down + right > 3)
            array[height][0] = (array[height - 1][0] + array[height + 1][0] + array[height][1]) / 3;
    }
//    右边点
    for (int height = 1; height <= Height - 2; ++height) {
        up = abs(array[height][WIDTH - 1] - array[height - 1][WIDTH - 1]);
        down = abs(array[height][WIDTH - 1] - array[height + 1][WIDTH - 1]);
        left = abs(array[height][WIDTH - 1] - array[height][WIDTH - 2]);
        if (up + down + left > 3)
            array[height][WIDTH - 1] = (array[height - 1][WIDTH - 1] + array[height + 1][WIDTH - 1] + array[height][WIDTH - 2]) / 3;
    }
//然后处理中间的点 存在4个相邻点
    for (int height = 1; height <= Height - 2; ++height) {
        for (int width = 1; width <= WIDTH - 2; ++width) {
            up = abs(array[height][width] - array[height - 1][width]);
            down = abs(array[height][width] - array[height + 1][width]);
            left = abs(array[height][width] - array[height][width - 1]);
            right = abs(array[height][width] - array[height][width + 1]);
            if (up + down + left + right > 4)
                array[height][width] = (array[height - 1][width] + array[height + 1][width] + array[height][width - 1]
                        + array[height][width + 1]) / 4;
        }
    }

}
