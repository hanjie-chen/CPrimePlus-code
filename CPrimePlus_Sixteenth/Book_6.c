#include <stdio.h>

#define JUST_CHECKING
#define LIMIT 4

int main(void)
{
    int total = 0;

//    通过这样子的方式可以调试代码 当移除JUST_CHECKING的定义的时候 就可以防止中间变量的打印
//    当需要重新调试的时候就可以重新插入定义 打印出中间值
//    个人感觉比注释每一条代码要方便的多 特别是代码量比较大的时候 中间变量比较多的时候
#undef JUST_CHECKING
    for (int i = 1; i <= LIMIT; ++i) {
        total += 2 * i * i + 1;
#ifdef JUST_CHECKING
        printf("i = %d, running total = %d\n", i, total);
#endif
    }
    printf("Grand total is %d\n", total);

    return 0;
}