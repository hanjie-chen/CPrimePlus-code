#include <stdio.h>
// 对函数声明中的数组使用const关键字 会让函数在处理数组是将其视为常量 但是并不要求原来传入的函数一个常量函数
// 如果编写的函数不用修改数组 那么在声明形参的时候最好使用const关键字
#define SIZE 5
int sum(const int a[], int n);
int main(void)
{
    int number_array[SIZE] = {1, 2, 3, 4, 5};
    int total;

    total = sum(number_array, SIZE);
    printf("The sum of number_array is %d", total);
    
    return 0;
}
// 在处理的时候如果不小心改变了数组中的值 那么编译器会报错
int sum(const int a[], int n)
{
    int total = 0;

    for (int i = 0; i < n; ++i) {
        total += a[i];
    }

    return total;
}