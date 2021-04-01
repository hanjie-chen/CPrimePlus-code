#include <stdio.h>
int data[2] = {100, 200};
int more_data[2] = {300, 400};
int main(void)
{
    int * p1, * p2, * p3;

    p1 = p2 = data;
    p3 = more_data;
//    这个程序演示了*p++ *++p (*p)++ 的作用情况 前两者把指针指向下一个数值 第三者把自己的地址所占的数值给递增了
    printf("*p1 = %d, *p2 = %d, *p3 = %d\n", *p1, *p2, *p3);
    printf("*p1++ = %d, *++p2 = %d, (*p3)++ = %d\n", *p1++, *++p2, (*p3)++);
    printf("*p1 = %d, *p2 = %d, *p3 = %d\n", *p1, *p2, *p3);

    return 0;
}