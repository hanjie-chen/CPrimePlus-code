#include <stdio.h>
int main(void)
{
//    创建的是变长数组
    int size1 = 10;
    int array1[size1];
//    VLA是不能进行初始化的
//    int array2[size1] = { 0 };

    const int size2 = 10;
//    如果创建的是变长数组，那么会报错
    int array3[size2] = { 0 };

    return 0;
}