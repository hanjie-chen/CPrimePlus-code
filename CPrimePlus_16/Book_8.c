#include <stdio.h>

int main(void)
{
    printf("This is the line %d.\n", __LINE__);
    printf("This is the file %s.\n", __FILE__);
#line 10 "chj.c" // 把当前行号设置为10 当前文件名设置为chj.c
    printf("This is the line %d.\n", __LINE__);
    printf("This is the file %s.\n", __FILE__);
//    下面的指定会让编译过程中断 并且发出一条错误信息
#if __STDC_VERSION__ != 201112L
#error Not C11
#endif

    return 0;
}