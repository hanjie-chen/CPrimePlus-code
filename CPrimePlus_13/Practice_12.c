#include <stdio.h>
#include <stdlib.h>

#define WIDTH 30
#define HEIGHT 20

int main(void)
{
    FILE * fp;
    int array[HEIGHT][WIDTH]; // 数字数组
    char picture[HEIGHT][WIDTH + 1]; // 存储图片的字符串数组
    char list[10] = {' ', '.', '\'', ':', '~', '*', '=', '7', '%', '#'}; // 字符数组来存储数字-字符对应列表

    if ((fp = fopen("chj", "r")) == NULL)
    {
        fprintf(stderr, "Error in opening the file chj.\n");
        exit(EXIT_FAILURE);
    }
    for (int height = 0; height < HEIGHT; ++height) {
        for (int width = 0; width < WIDTH; ++width) {
//             读取文件里面的整形数
            fscanf(fp, "%d", &array[height][width]);
//            使用一个对应的列表给字符数组赋值
            picture[height][width] = list[array[height][width]];
        }
    }
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