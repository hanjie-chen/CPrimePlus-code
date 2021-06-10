#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000

int main(void)
{
    double numbers[ARRAY_SIZE];
    double value;
    const char * file = "numbers.dat";
    long pos;
    FILE * io_file;
    int j;

//    对数组进行初始化
    for (int i = 0; i < ARRAY_SIZE; ++i)
        numbers[i] = 100.0 * i + 1.0 / (1.0 + i);
//    打开文件 如果文件不存在那么创建一个
    if ((io_file = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "Can't open the file %s for output.\n", file);
        exit(EXIT_FAILURE);
    }
//    以二进制数据的形式把数据写入到文件中去
    fwrite(numbers, sizeof(double), ARRAY_SIZE, io_file);
//    关闭文件
    if (fclose(io_file) != 0)
    {
        fprintf(stderr, "Error in closing %s.\n", file);
        exit(EXIT_FAILURE);
    }
//    以只读模式打开文件
    if ((io_file = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr, "Could open %s for random access.\n", file);
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Enter an index in the range of 0 ~ %d.\n", ARRAY_SIZE - 1);
//    根据每个数据的字节大小来定位 从而获取到相应位置的数据
    while (scanf("%d", &j) == 1 && j < ARRAY_SIZE && j >= 0)
    {
        pos =(long ) sizeof(double) * j;
        fseek(io_file, pos, SEEK_SET);
        fread(&value, sizeof(double), 1, io_file);
        fprintf(stdout, "The value there is %f.\n", value);
        fprintf(stdout, "Next index (out of range to quit):\n");
    }
    if (fclose(io_file) != 0)
        fprintf(stderr, "Can't close the file");
    puts("Bye~");

    return 0;
}