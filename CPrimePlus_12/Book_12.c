#include <stdlib.h>

#define SIZE 10
// 下面的两种表达方式在 C99 标准中是完全一致的
// 即使用数组表示法和指针表示法都可以使用这两个限定符
void test_function1(int * const array1, int * restrict array2, int n);
void test_function2(int array1[const], int array2[restrict], int n);

int main(void)
{
    int array[SIZE] = {0};
    int * restrict star = (int *)calloc(SIZE, sizeof(int));
    int * copy = array;
//    使用了restrict关键字 编译器会将for中的两条语句合并以一条 star[i] += 8
//    因为restrict关键字是指向该数据块唯一并且初始的方式 即程序中不会有其他的指针来改变这个数据值
//    但是copy和array不行 因为不满足上述的两个条件
    for (int i = 0; i < 10; ++i) {
        copy[i] += 5;
        star[i] += 5;
        array[i] *= 2;
        copy[i] += 3;
        star[i] += 3;
    }
    free(star);

    return 0;
}