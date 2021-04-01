#include <stdio.h>
#include <stdlib.h>

int Get_Height(FILE * fp);
int Get_Width(FILE * fp, int height);

int main(void)
{
    FILE * fp;
    int Height, Width;
    char list[10] = {' ', '.', '\'', ':', '~', '*', '=', '7', '%', '#'}; // 字符数组来存储数字-字符对应列表
//    打开文件
    if ((fp = fopen("chj", "r")) == NULL)
    {
        fprintf(stderr, "Error in opening the file chj.\n");
        exit(EXIT_FAILURE);
    }
//    获得数组的高度和宽度
    Height = Get_Height(fp);
    rewind(fp);
    Width = Get_Width(fp, Height);
    rewind(fp);
//    fprintf(stdout, "Height: %d Width: %d.\n", Height, Width);
    int array[Height][Width]; // 数字数组
    char picture[Height][Width + 1]; // 存储图片的字符串数组

    for (int height = 0; height < Height; ++height) {
        for (int width = 0; width < Width; ++width) {
//             读取文件里面的整形数
            fscanf(fp, "%d", &array[height][width]);
//            使用一个对应的列表给字符数组赋值
            picture[height][width] = list[array[height][width]];
        }
    }
//    给最后一个字符赋值'\0'时期成为一个字符串数组
    for (int height = 0; height < Height; ++height)
        picture[height][Width] = '\0';
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
    for (int height = 0; height < Height; ++height)
        fprintf(fp, "%s\n", picture[height]);
    fputs("The writing data is done.\n", stdout);
    if (fclose(fp) != 0)
        fprintf(stderr, "Error in closing the file chj.picture.\n");

    return 0;
}
int Get_Height(FILE * fp)
{
    int count = 0;
    char temp[256];

    while (fgets(temp, 256, fp))
        count++;

    return count;
}
int Get_Width(FILE * fp, int height)
{
    int count = 0;
    int temp;

    while (fscanf(fp, "%d", &temp) == 1)
        count++;

    return count / height;
}