#include <stdio.h>
int main(void)
{
    int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};
//    指针指向内含2个int类型的数组
    int (* p1)[2] = zippo;
    int (* p2)[2] = &zippo[0];
//    和指向int类型的数组不同的是 其指针递增单位是一个数组
    printf("the address of p1 is %p and p1 + 1 is %p\n", p1, p1 + 1);
    printf("the address of p2 is %p and p2 + 1 is %p\n", p2, p2 + 1);
//    指针表示法和数组表示法的等价
    printf("p1[0] = %p, p1[0] + 1 = %p\n", p1[0], p1[0] + 1);
    printf("*p1 = %p, *p1 + 1= %p", *p1, *p1 + 1);
//    虽然p1是一个指针 但是依然可以使用数组表示法来表示一个数组元素
    printf("p1[0][0] = %d\n", p1[0][0]);
    printf("*p1[0] = %d\n", *p1[0]);
    printf("**p1 = %d\n", **p1);
//    zippo[m][n] = *(*(zippo + m) + n) || p1[m][n] = *(*(p1 + m) + n)
    printf("p1[2][1] = %d\n", p1[2][1]);
    printf("*(*(p1 + 2) + 1)= %d", *(*(p1 + 2) + 1));


    return 0;
}