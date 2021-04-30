#include <stdio.h>
#include <string.h>

#define SIZE 10

void show_array(const int array[], int n);
//_Static_assert(sizeof(double) == 2 * sizeof(int), "double not twice int size");

int main(void)
{
    int source[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target[SIZE];
    double curious[SIZE / 2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 2.0e30};
//    使用memcpy()函数把数组source的值复制到数组target中去
    puts("memcpy() used:");
    puts("values(original data):");
    show_array(source, SIZE);
    memcpy(target, source, sizeof(int) * SIZE);
    puts("Target (copy of source):");
    show_array(target, SIZE);
//    使用memmove()函数拷贝自己的0~4的区域到2~6的区域
    puts("\nUsing memmove() with overlapping ranges:");
    memmove(source + 2, source, 5 * sizeof(int));
    puts("source -- elements 0 ~4 copy to 2~6:");
    show_array(source, SIZE);
//    把double类型的数组拷贝到int类型的数组中去
    puts("\nUsing memcpy() to copy double array to int array");
    memcpy(target, curious, sizeof(double) * (SIZE / 2));
    puts("The result is following:");
    show_array(target, SIZE / 2);
    show_array(target + 5, SIZE / 2);

    return 0;
}
void show_array(const int array[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", array[i]);
    putchar('\n');
}